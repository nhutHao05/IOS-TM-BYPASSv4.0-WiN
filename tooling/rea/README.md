# Bộ REA dùng cho TM-BYPASS

Đã cài và chạy trên Linux x86-64 trong môi trường nghiên cứu. REA kết nối được Ghidra và xuất mã giả của hàm kiểm tra `Status.plist` trong bản helper dành riêng cho phân tích.

| Thành phần | Phiên bản | Vai trò |
| --- | --- | --- |
| [REA](https://github.com/morluto/rea) | CLI `rea-agents` 6.8.0 | Điều phối phân tích, metadata .NET, bằng chứng và provider Ghidra |
| [Ghidra](https://github.com/NationalSecurityAgency/ghidra) | 12.1.4 | Disassembly, xref và decompile native |
| [Temurin JDK](https://github.com/adoptium/temurin21-binaries) | 21.0.13+9 | Java SDK cho Ghidra và bridge REA |
| [Triton](https://github.com/JonathanSalwan/Triton) | `triton-library` 1.0.0rc4 | Thực thi tượng trưng mã máy; đây là Triton cho phân tích binary |
| [Z3](https://github.com/Z3Prover/z3) | `z3-solver` 5.4.1.0 | Giải và kiểm tra ràng buộc nhánh |

Checkout mã nguồn REA được ghim tại commit `0909d89c966c30955fd0906b622ff25f3700789f`. CLI dùng bản npm 6.8.0; không biên dịch lại toàn bộ checkout upstream. ILSpy, .NET, Capstone, Unicorn, Wine và NoVmp của các bước trước được ghi riêng trong `tm_bypass_research/recovery/toolchain.json`.

## Cài lại

Cần Linux x86-64, Python 3.12+, Git, `ps`, npm và Node đáp ứng `^22.23.4 || ^24.22.1 || >=26.12.1`. Máy nghiên cứu đã dùng Node 24.22.1. Bộ cài này không cài hoặc nâng cấp Node toàn cục.

Từ thư mục gốc repo:

```bash
python3 tooling/rea/setup_re.py
bash tooling/rea/rea.sh doctor --provider ghidra --format json
```

Mặc định mọi thành phần được đặt trong `tooling/rea/installed/`. Có thể chọn nơi khác bằng `setup_re.py --root /absolute/path`, sau đó đặt `TM_RE_TOOLS_ROOT=/absolute/path` khi gọi `rea.sh`. Script kiểm tra SHA-256 của hai archive Ghidra/JDK trước khi giải nén, giữ checkout REA đang có nếu khác commit và ghi báo cáo doctor. Cần khoảng 2 GiB dung lượng trống cho một lần cài mới, tùy cache npm/uv. Archive tạm được xóa sau khi cài.

Không chạy `rea setup` trong quy trình này; cấu hình Codex toàn cục không bị sửa. CLI dùng trực tiếp được trong phiên hiện tại. `rea.sh --mcp` khởi động server stdio nếu một client khác cần đăng ký MCP; việc đăng ký không tự xảy ra khi clone repo.

## Kiểm tra bằng mẫu thật

Các EXE và ảnh bộ nhớ không được phân phối trong repo. Cần đúng đầu vào đã đo ở nghiên cứu trước, không dùng file có cùng tên nhưng khác build.

```bash
bash tooling/rea/rea.sh inspect-managed-artifact /absolute/path/TM-BYPASS.analysis-only.exe --format json
bash tooling/rea/rea.sh inspect-managed-native-boundaries /absolute/path/TM-BYPASS.analysis-only.exe --format json
bash tooling/rea/rea.sh decompile /absolute/path/MDM_SETUP.analysis-only.exe 0x140002b10 --provider ghidra --format json
```

Phép kiểm tra native đã sử dụng `helper-seeds.tsv` qua biến `REA_GHIDRA_SEED_FILE` với đường dẫn tuyệt đối. Ghidra báo hàm đã có sẵn, không tạo mới từ seed. Bản phân tích helper đã thay 542 byte đệm theo các phép đo trước; hash đầu vào được giữ trong Evidence. Đây không phải decompile trực tiếp EXE còn đóng gói và cũng không phải chạy helper trên Windows.

Kiểm tra Triton/Z3:

```bash
tooling/rea/installed/symbolic-venv/bin/python tooling/rea/symbolic_mode_probe.py /absolute/path/MDM_SETUP.exe.memory_ready.bin --output symbolic-proof.json
```

Probe đọc hai lệnh gốc tại `0x140004751` và `0x140004755`: `cmp r12d, 7; ja ...`. Với mode 1, nhánh unsigned-above không được lấy. Triton tìm một mode cho nhánh còn lại; Z3 kiểm tra lại cả hai điều kiện. Không có tiến trình Windows hay kết nối thiết bị nào được khởi động bởi probe.

## Bằng chứng và phần còn thiếu

- [Tổng hợp kiểm tra](verification.json): doctor, metadata, provider và kiểm tra tượng trưng.
- [REA/Ghidra: mã giả hàm kiểm tra trạng thái](ghidra-helper-status.json): Evidence thực tế từ provider Ghidra 12.1.4. Hàm đọc `SnapshotState` và so sánh chính xác với `finished`, khớp kết quả giả lập tám ca đã có.
- [Triton/Z3: kiểm tra nhánh thật](symbolic-mode-proof.json).

Parser .NET báo coverage `partial`: mẫu còn hai dòng Module và hai dòng Assembly thay vì số dòng hợp lệ. Kết quả phân loại/PInvoke đã đọc được không có nghĩa toàn bộ metadata hợp lệ.

Bộ công cụ đã sẵn sàng cho các bước RE tiếp theo. DLL còn phần VMProtect chưa gỡ hết; NoVmp từng dừng ở nhánh tượng trưng. Triton/Z3 đã kiểm tra được nhánh helper, chưa chứng minh giải được toàn bộ VMProtect. Backup vẫn thiếu `Manifest.plist` tương ứng chứa keybag/khóa manifest, và backend không nằm trong gói client. Không có kiểm tra xóa MDM trên thiết bị thật trong đợt cài này.
