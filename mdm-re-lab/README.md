# MDM RE Lab — bản mẫu 0.1

Bản mẫu Windows/Python được viết từ kết quả phân tích TM-BYPASS v4.0. Đây là bộ công cụ để tái hiện giao thức, thu bằng chứng và tiếp tục nghiên cứu. Chưa có bằng chứng bypass MDM trên iPhone SE 2 / iOS 27.0.1.

## Phạm vi hiện tại

| Lệnh | Hành vi |
|---|---|
| `devices` | Liệt kê thiết bị USB qua dịch vụ Apple |
| `inspect` | Đọc model, iOS, build, cloud configuration và danh sách profile; lưu request/response |
| `apply-cloud` | Gửi thử `SetCloudConfiguration`, đọc lại trước/sau và giữ nguyên error chain của thiết bị |
| `inspect-backup` | Kiểm tra cấu trúc, snapshot và dữ liệu khóa cần thiết |
| `restore` | Tái hiện request MobileBackup2 của helper; có thực hiện restore và có thể ghi đè dữ liệu trên thiết bị |
| `decrypt-backup` | Giải mã Manifest.db và các file quản lý từ backup mã hóa khi có manifest và mật khẩu phù hợp |

`Acknowledged`, `readback_matches` và restore hoàn tất không được coi là bằng chứng gỡ enrollment. Báo cáo luôn giữ `mdm_enrollment_removed = not_established` cho đến khi có cách xác minh độc lập.

## iOS 27 thay đổi điều kiện nghiên cứu

Apple công bố từ iOS 27, backup không chứa và restore không khôi phục enrollment profile, management configuration hoặc supervision status. Thiết bị thuộc Automated Device Enrollment nhận lại trạng thái quản lý từ hệ thống tổ chức. Vì vậy, thiếu manifest không còn là trở ngại duy nhất: cơ chế backup cũ của TM-BYPASS cũng không phải một bypass được xác nhận cho iOS 27.

Nguồn:

- https://support.apple.com/guide/deployment/device-management-updates-depd638aa061/web — mục Backup restoration.
- https://support.apple.com/guide/deployment/back-up-managed-apple-devices-depd44f04xc3/web
- https://github.com/fled-dev/MDMPatcher-Enhanced — dự án ghi rõ không hỗ trợ iOS 27.
- https://github.com/supermario3D1/mdmpatcher-linux — hướng MCInstall trên iOS 27 được dự án đánh dấu experimental; mã nguồn không thay thế bằng chứng chạy trên thiết bị.

`candidate-cloud.json` là payload thử nghiệm cho MCInstall, dùng những cờ đã quan sát khi RE. Đây không phải payload backup đã giải mã và chưa được xác nhận có khả năng gỡ MDM trên iOS 27.

## Chạy trên Windows

Cần Python 3.11+ và dịch vụ/driver thiết bị Apple hoạt động. Dùng Apple Devices/iTunes phù hợp với máy tính để thiết bị USB được nhận và pairing/Trust được thiết lập.

```powershell
py -m venv .venv
.\.venv\Scripts\python.exe -m pip install -r requirements.txt
.\.venv\Scripts\python.exe mdmlab.py devices
.\.venv\Scripts\python.exe mdmlab.py inspect --udid <UDID> --out runs\before.json
```

Thử nghiệm có ghi trạng thái cục bộ:

```powershell
.\.venv\Scripts\python.exe mdmlab.py apply-cloud --udid <UDID> --payload candidate-cloud.json --out runs\cloud-experiment.json
```

Không có lệnh erase/reset/downgrade. `restore` thực sự khôi phục backup, nên dùng bản sao backup trong môi trường nghiên cứu:

```powershell
.\.venv\Scripts\python.exe mdmlab.py inspect-backup C:\Lab\Backup\<SOURCE-UDID>
$env:MDMLAB_BACKUP_PASSWORD = "mdm"
.\.venv\Scripts\python.exe mdmlab.py restore --udid <TARGET-UDID> --backup C:\Lab\Backup\<SOURCE-UDID> --out runs\restore.json
```

Mật khẩu `mdm` mặc định phản ánh helper đã RE; backup của người dùng có thể dùng mật khẩu khác qua `MDMLAB_BACKUP_PASSWORD`. Báo cáo không ghi mật khẩu.

## Giải mã payload cũ khi bổ sung được manifest

Thư mục backup cần có đúng `Info.plist`, `Manifest.plist`, `Status.plist`, `Manifest.db` và các file dữ liệu. Với encrypted Manifest.db, manifest phải cung cấp `BackupKeyBag` và `ManifestKey` tương ứng.

```powershell
.\.venv\Scripts\python.exe mdmlab.py decrypt-backup C:\Lab\Backup\<SOURCE-UDID> --out C:\Lab\Decrypted
```

Bộ giải mã hỗ trợ keybag PBKDF2-SHA1, bước tăng cường PBKDF2-SHA256 nếu có DPSL/DPIC, AES key unwrap và AES-CBC. Header SQLite, kích thước database và `quick_check` được kiểm tra trước khi đọc các record quản lý. File gốc được giữ nguyên.

## Request restore được tái hiện

```json
{
  "MessageName": "Restore",
  "TargetIdentifier": "<TARGET-UDID>",
  "SourceIdentifier": "<SOURCE-UDID>",
  "Options": {
    "RestoreSystemFiles": false,
    "RestoreDontCopyBackup": true,
    "RestorePreserveSettings": true,
    "Password": "<provided>"
  }
}
```

Backend dùng `pymobiledevice3==11.51.0`; phần restore sử dụng API DeviceLink của phiên bản này để giữ đúng các trường đã quan sát. Không gọi API của nhà cung cấp, không dùng credential tìm thấy trong binary, không phân phối EXE/DLL hoặc backup của TM-BYPASS.

`protocol/restore-reference.json` giữ request đã bắt từ DLL cùng nguồn gốc mẫu và địa chỉ gọi trong helper. UDID trong bản ghi là dữ liệu giả. Bài kiểm tra restore đối chiếu trực tiếp với bản ghi này.

## Kiểm chứng

```powershell
.\.venv\Scripts\python.exe -m unittest -v
```

Kiểm tra bao gồm round-trip một encrypted backup tổng hợp, lỗi mật khẩu, đối chiếu restore profile, raw error chain của MCInstall, trường hợp ACK nhưng không thay đổi trạng thái, và xử lý ErrorCode thật của DeviceLink. Chưa chạy các thao tác trên iPhone SE 2 thật.
