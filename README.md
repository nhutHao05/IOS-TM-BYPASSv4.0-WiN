# TM-BYPASS v4.0 Windows — nguồn phục hồi và bộ RE

Repository lưu kết quả dịch ngược TM-BYPASS v4.0 Windows: C# phục hồi, mã giả C, script phân tích, bộ thử giao thức và báo cáo phương pháp. **Chưa xác nhận xóa MDM trên thiết bị thật hoặc iOS 27.0.1.**

## Nội dung chính

| Thư mục | Nội dung |
| --- | --- |
| `tm_bypass_research/recovery/csharp_reviewed/` | C# theo lớp, đã đặt tên phân tích và sửa metadata để decompiler đọc được |
| `tm_bypass_research/recovery/csharp_by_token/` | 362 mục hàm .NET để đối chiếu token; có 352 thân IL |
| `tm_bypass_research/recovery/native_c_reviewed/` | Mã giả C của 64 hàm helper `MDM_SETUP.exe` |
| `tm_bypass_research/recovery/dll_calls/` | 480 lời gọi API đã được đo; các đoạn mã giả DLL vẫn còn phần ảo hóa |
| `tm_bypass_research/recovery/dll_probes/` | Bộ thử 52 ca trên năm API MobileBackup2 |
| `tm_bypass_research/recovery/file_sender/` | Bằng chứng truyền file và báo cáo phương pháp Restore |
| `mdm-re-lab/` | Bản mẫu Python để inspect thiết bị/backup, thu bằng chứng và thử giao thức |
| `tooling/rea/` | Bộ cài REA 6.8.0, Ghidra 12.1.4, JDK 21, Triton/Z3 và bằng chứng chạy trên mẫu |

## Phương pháp đã quan sát

Ứng dụng giải nén backup có sẵn, ghi `Info.plist` và `Manifest.plist` nhận từ máy chủ, rồi gọi helper. Helper chọn MobileBackup2 **Restore** và phục vụ các yêu cầu trao đổi file từ thiết bị. Hàm gửi file chuyển nguyên payload theo khối tối đa 32 KiB.

Thông báo “IKEY MDM Successful” dựa vào kết quả Restore, chưa có bước xác minh độc lập rằng thiết bị đã hết quản lý MDM trong luồng đã phân tích.

Đọc báo cáo:

- [Phương pháp và luồng Restore](tm_bypass_research/recovery/file_sender/method-research.md)
- [Tổng quan quá trình RE](tm_bypass_research/recovery/README_RE.md)
- [Kiểm tra DLL và giới hạn phép thử](tm_bypass_research/recovery/dll_probes/README.md)
- [Trạng thái nghiên cứu](tm_bypass_research/recovery/research-status.json)

## Kết quả đã kiểm tra trong môi trường nghiên cứu

- 1.444 lời gọi giải mã chuỗi .NET được thay bằng chuỗi rõ; đối chiếu 352 thân IL ngoài các vị trí thay thế. Có 819 giá trị chuỗi khác nhau được dùng tại các lời gọi này.
- Bản C# trước khi che thông tin đăng nhập kiểm tra biên dịch: 0 lỗi, 14 cảnh báo. Đây là kiểm tra cú pháp/phụ thuộc, không phải chạy thử ứng dụng.
- Helper native: 542 stub gọi API được đo; DLL: 480 lời gọi API được đo, gồm chín wrapper gọi đuôi.
- 52/52 ca đối chiếu năm API MobileBackup2 khớp mô hình từ nguồn tham chiếu libimobiledevice 1.3.0, với biên truyền tải usbmuxd giả lập.
- 14/14 ca truyền file giữ nguyên byte payload; ba ca kiểm soát lỗi, tám tình huống Status.plist và chín ca dispatch chế độ đã được kiểm tra bằng mã máy.

Các con số, hash và giới hạn được giữ trong các file `verification.json`, `native-verification.json`, `dll_calls/verification.json`, `dll_probes/differential-results.json` và `file_sender/*-evidence.json`. Chúng là kết quả trên mẫu và môi trường gốc; không phải chứng nhận cho mọi thiết bị hoặc mọi bản build.

## Phạm vi của bản nguồn công khai

- Thông tin đăng nhập máy chủ được hardcode trong mẫu đã được thay bằng `REDACTED_VENDOR_CREDENTIAL`. Mật khẩu backup `mdm` và dữ liệu thử nghiệm tổng hợp được giữ vì là tham số giao thức đã quan sát.
- Không đưa lên repo các EXE/DLL gốc, ảnh bộ nhớ, backup thiết bị, venv, toolchain tải sẵn hoặc file khóa thật. [Danh sách hash đầu vào riêng](docs/private-input-hashes.json) giúp đối chiếu mẫu.
- [Manifest nguồn xuất bản](docs/source-manifest.json) ghi hash file gốc, hash bản công khai và số lần che credential. Hash của báo cáo phân tích gốc có thể khác bản công khai đã che dữ liệu.
- C# và C là kết quả decompile/mã giả với tên do người phân tích đặt. Một số đoạn phụ thuộc tài nguyên, thư viện hoặc nội dung bị ảo hóa; đây chưa phải mã nguồn gốc đầy đủ hay bản ứng dụng sẵn chạy.
- Backup nhúng chưa giải mã được vì thiếu `Manifest.plist` tương ứng có dữ liệu khóa cần thiết. Backend không nằm trong gói client.

## Chạy các script

Để cài bộ REA và provider native, xem [hướng dẫn và kết quả kiểm tra REA](tooling/rea/README.md). Bộ cài giữ cấu hình trong thư mục được chọn và dùng CLI trực tiếp.

Các script RE chủ yếu dùng Python 3.11/3.12. Tạo môi trường riêng:

```bash
python3 -m venv .venv-re
. .venv-re/bin/activate
python -m pip install -r requirements-re.txt
```

Ví dụ kiểm tra mã máy, sau khi bổ sung **ảnh bộ nhớ của đúng mẫu** tại đường dẫn được ghi trong `docs/private-input-hashes.json`:

```bash
python tm_bypass_research/recovery/probe_file_sender.py
python tm_bypass_research/recovery/probe_mode_dispatch.py
```

Các ảnh bộ nhớ không được đính kèm. Một số bước ban đầu còn cần đầu ra trung gian như `constants.bin`, assembly tài nguyên, ILSpy, .NET runtime và thư viện tham chiếu; xem `toolchain.json` và script tương ứng. Không coi việc clone repo là đã có đầy đủ dữ liệu để giải mã backup.

Để dùng bản mẫu Python độc lập:

```bash
python -m pip install -r mdm-re-lab/requirements.txt
python mdm-re-lab/mdmlab.py --help
```

`inspect` phục vụ đọc và ghi báo cáo; các lệnh `apply-cloud` và `restore` có thể thay đổi thiết bị. Xem mô tả cụ thể trong [README của bản mẫu](mdm-re-lab/README.md).

## Nguồn tham chiếu và quyền tác giả

Các file nguồn upstream giữ nguyên thông báo tác giả và giấy phép của dự án gốc. Xem [THIRD_PARTY_NOTICES.md](THIRD_PARTY_NOTICES.md). Repository không tự gán một giấy phép chung cho mã decompile của bên thứ ba.
