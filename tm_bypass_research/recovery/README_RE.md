# TM-BYPASS: bản ghi nghiên cứu và bộ công cụ RE

Phạm vi: phân tích tệp người dùng cung cấp, tập trung vào luồng MDM sau khi cài ứng dụng Windows. Không có iPhone thật trong môi trường này. Không gọi API máy chủ nhà cung cấp.

## Kết quả có thể đọc lại

- `csharp_reviewed/`: C# của ứng dụng, đã đặt tên phân tích cho các lớp và hàm quan trọng. Kiểm tra biên dịch với thư viện tham chiếu .NET Framework 4.8: không lỗi, 14 cảnh báo. Đây là kiểm tra cú pháp/phụ thuộc; không phải chạy thử chức năng ứng dụng.
- `csharp_by_token/`: 362 mục hàm, giữ token để đối chiếu với IL. Bao gồm cả các mục extern và các hàm bảo vệ bị ẩn trong bản xuất theo lớp.
- `native_c_reviewed/`: mã giả C của 64 hàm gốc trong vùng `.text` của `MDM_SETUP.exe`. Các đoạn unwind nối chuỗi đã được nhóm về hàm chủ. Tên hàm, kiểu dữ liệu suy luận và tên biến không phải mã nguồn gốc.
- `native_c_reviewed/140004070.c`: `RunBackupRestoreRecovered`, gồm ghép cặp, dịch vụ MobileBackup2, tùy chọn Restore, vòng lặp trao đổi file, đọc kết quả và dọn tài nguyên.
- `dll_calls/`: 480 lời gọi API đã được nhận diện và kiểm tra ABI. Bản sao phân tích gỡ các byte bảo vệ tương ứng, gồm chín wrapper gọi đuôi. `c_partial/` vẫn có thân hàm ảo hóa và cảnh báo; không xem 370 đoạn mã giả ở đây là mã nguồn DLL hoàn chỉnh.
- `dll_probes/`: 52 ca đối chiếu năm API MobileBackup2 của DLL gốc với mã nguồn libimobiledevice 1.3.0, giữ nguyên DLL và libplist, chỉ giả lập ba hàm truyền tải usbmuxd. Tham khảo `dll_probes/README.md` và `differential-results.json`.
- `file_sender/method-research.md`: nghiên cứu luồng Restore và truyền file. Thực thi mã máy hàm gửi file cho 14 ca dữ liệu, ba ca lỗi; kiểm tra tám tình huống Status.plist và chín nhánh mode dispatch. Payload thu lại khớp byte với đầu vào trong cả 14 ca thành công.
- `verification.json`, `native-verification.json`: kết quả kiểm tra có giới hạn rõ ràng.
- `analyst-name-map.json`, `native-call-semantics.json`: bằng chứng cho các tên và thay đổi trong bản sao phân tích.
- Hai tệp `*.analysis-only.exe` phục vụ decompiler. Không xem chúng là bản ứng dụng có thể chạy hoặc một bản bypass đã kiểm chứng.

## Các lớp bảo vệ đã xử lý

1. Giải mã section .NET, sửa metadata để bộ đọc chuẩn chấp nhận, giải mã constants và assembly chứa tài nguyên.
2. Thay 1.444 lời gọi giải mã chuỗi bằng `ldstr`, giữ độ dài lệnh, vị trí nhánh, header và vùng exception. Có 819 giá trị chuỗi khác nhau thực sự được dùng tại các vị trí này.
3. Chuyển metadata có ENCLog/ENCMap sang dạng stream không nén `#-`, thêm tên phân tích và tên tham số setter mà không thay token.
4. Với helper native, dùng ảnh bộ nhớ đã unpack, xác định 542 đích API bằng Unicorn. Đo tiếp cách stub xử lý stack và địa chỉ trả về, rồi gỡ 258 lệnh push phụ cùng 284 byte bẫy trả về trong bản sao dành cho phân tích.
5. Dùng Ghidra đọc mã đã bỏ padding, gắn tên/prototype API theo bằng chứng và nhóm các unwind range nối chuỗi. Mã giả đã đọc được toàn bộ luồng Restore của helper.

## Cơ chế MDM quan sát được

`MainFormRecovered.OnMdmClick` → kiểm tra serial → `DeviceOperationsRecovered.RunMdmBackupRestore` → chuẩn bị thư mục và giải nén tools/backup → lấy `Info.plist` và `Manifest.plist` từ máy chủ → chạy `MDM_SETUP.exe` → MobileBackup2 Restore → dọn thư mục.

Helper tạo tùy chọn `RestoreSystemFiles=false`, `RestoreDontCopyBackup=true`, `RestorePreserveSettings=true`, `Password="mdm"`. Kết quả này khớp giữa mã máy giả lập, XML thu trước lớp truyền tải của DLL và mã giả C vừa khôi phục. Tham khảo `../native_runtime/wire/restore_wire.xml`.

Helper in “IKEY MDM Successful” khi nhận kết quả Restore có `ErrorCode=0`. Caller C# chờ tiến trình kết thúc và không kiểm tra `ExitCode`. Hai điểm này không chứng minh thiết bị đã hết quản lý MDM.

## Bộ công cụ đã dùng

`toolchain.json` ghi phiên bản, vai trò và hash tệp công cụ. ILSpy/Roslyn dùng để khôi phục và kiểm tra C#; dnfile/dncil/pefile để kiểm tra metadata và IL; Capstone/Unicorn để phân tích mã x64; Ghidra để xuất C; Wine trong container không mạng để quan sát unpack và kiểm tra lớp đóng gói giao thức; NoVmp để thăm dò VMProtect.

NoVmp chưa xuất được VTIL cho hàm DLL mục tiêu: báo `Whoooops hit switch case...`; đường tối ưu constant không hoàn tất trong giới hạn chạy đã thử. Không ghi nhận đây là devirtualize thành công. Ghidra được khởi chạy bằng `run_ghidra.sh`; Java 21 hiện có chứa module compiler dù không có launcher `javac` trong PATH.

Các mẫu Windows không chạy trực tiếp trên host. Những lần cần thực thi dùng Wine cô lập, không mạng, không USB và không đưa thông tin đăng nhập nhà cung cấp vào yêu cầu từ xa.

## Tái lập kiểm tra trong workspace này

Từ thư mục nghiên cứu `work/tm_bypass_research`:

```bash
PYTHONPATH=deps python recovery/verify_recovery.py
python recovery/verify_native_recovery.py
```

Để đo lại import stub:

```bash
emulator_venv/bin/python recovery/recover_call_semantics.py
```

Ghidra project cuối là `recovery/ghidra_projects/native_reviewed.gpr`. Script xuất mã là `recovery/ghidra_scripts/RecoverNative.java`, đầu vào là `native-calls.tsv` và `native-groups.tsv`. Không bật phân tích tự động toàn bộ các section VMProtect khi chỉ cần đọc helper.

## Phần chưa thể gọi là đã giải mã hết

- `imobiledevice.dll` vẫn còn các hàm ảo hóa. Đã quan sát được yêu cầu Restore cụ thể; chưa khôi phục toàn bộ mã nguồn DLL.
- Cả 287 export của DLL đều đi qua điểm vào VM. Có 274 điểm nhảy được thấy khi quét tuyến tính; hai con số đếm hai tập khác nhau. Kiểm tra 52 ca chỉ xác nhận các hợp đồng API được thử, không chứng minh toàn bộ DLL tương đương mã nguồn tham chiếu.
- Backup nhúng được mã hóa, không kèm `Manifest.plist` tương ứng. Mật khẩu `mdm` chưa đủ để khôi phục `BackupKeyBag` và `ManifestKey`. Các file quản lý được nhận diện bằng hash tên đường dẫn; chưa đọc được nội dung plaintext của chúng.
- Mã nguồn phía máy chủ không nằm trong gói client. Decompile client không tự khôi phục được backend đó.
- Chưa có thử nghiệm thiết bị thật, chưa xác nhận bypass trên iPhone SE 2 / iOS 27.0.1. Công cụ nghiên cứu Python ở `../../mdm-re-lab` là một nhánh độc lập; khả năng bỏ MDM chưa được kiểm chứng.
