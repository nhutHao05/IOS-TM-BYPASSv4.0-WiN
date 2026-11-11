# Lần ngược nguồn dữ liệu manifest và khóa backup

Mục tiêu của bước này là tìm thêm dữ liệu chưa phục hồi được, không giả định rằng thiếu file trên đĩa nghĩa là không thể tiếp tục RE. Cần các giá trị keybag và wrapped ManifestKey tương thích với ciphertext; `Manifest.plist` là một vật chứa các giá trị đó, không phải tên file bắt buộc của mọi phương án phục hồi.

## Bằng chứng mới

| Hướng kiểm tra | Quan sát | Giới hạn kết luận |
| --- | --- | --- |
| Tài nguyên và binary đã có | Rà 532 blob có nội dung độc lập, tổng 474.806.690 byte; 647 đường dẫn/blob được ghi nhận gồm các bản trùng nội dung. Không có omission do giới hạn traversal trong lần chạy này. | Chỉ áp dụng cho các đầu vào và dạng archive/resource được mô tả; không bao phủ mọi dạng mã hóa hoặc giá trị tạo lúc chạy. |
| Manifest/keybag được nhúng nguyên dạng | Không thấy plist chứa key material hoặc chuỗi TLV đạt điều kiện keybag của bộ dò trong phạm vi trên. | Đây là kết quả tìm kiếm có phạm vi, chưa chứng minh không có dữ liệu bị biến đổi, chia nhỏ hoặc còn bị bảo vệ. |
| Kiểm soát dương | Bộ dò nhận được keybag 1.336 byte của manifest mẫu bên ngoài; manifest đó `IsEncrypted=false`, không có ManifestKey. | Mẫu kiểm soát không thuộc backup TM-BYPASS; không được dùng làm khóa ứng viên để tuyên bố giải mã. |
| Chuỗi `BackupManifestKey` | Có trong một số binary libimobiledevice. Nguồn tham chiếu `mobilebackup.c` dùng nó làm tên trường chứa manifest của MobileBackup cũ. | Tên có chữ Key không tự chứng minh có AES key; chưa gỡ hết VMProtect của DLL. |
| `vendor/irestores.exe` | REA đọc được Go 1.22.2, module `github.com/dnicolson/irestore/cmd/irestore`. Có metadata trường BackupKeyBag/ManifestKey. | Metadata kiểu dữ liệu chưa phải giá trị các trường. |
| Mã máy của `irestores.exe` | `backup.Open` mở Manifest.plist bên ngoài, unmarshal, rồi chuyển dữ liệu cho `keybag.Read`. `decryptDatabase` gọi AES unwrap và AES-CBC. Chín vị trí lệnh đã được đối chiếu với byte gốc. | Đây là bộ đọc/giải mã cần dữ liệu đầu vào, chưa thấy bằng chứng nó chứa sẵn keybag khớp backup nhúng. |

Các đầu vào chính được rà là ZIP Windows do người dùng cung cấp, EXE sau giải mã section, resource assembly sau giải mã, constant buffer, hai ảnh bộ nhớ native đã unpack. Các ZIP/TAR và resource ByteArray nhận diện được được duyệt tiếp trong bộ nhớ. Không chạy executable, gọi API vendor hoặc dùng thiết bị trong bước này.

## Nguồn manifest trong luồng MDM

Theo mã C# đã phục hồi:

1. `ResolveMdmManifestEndpoint`, token `0x06000066`, nhận địa chỉ endpoint từ HTTP response đầu tiên.
2. `WriteMdmManifestPlist`, token `0x0600006b`, gửi các giá trị nhận dạng/phiên bản thiết bị đến endpoint đó; đọc toàn bộ response bằng StreamReader.
3. Nội dung response được đưa trực tiếp vào `File.WriteAllText(...Manifest.plist, contents)`. Trong thân hàm này không có bước tự tạo keybag, PBKDF hay unwrap khóa.
4. `RunMdmBackupRestore` chuẩn bị backup nhúng, ghi Info/Manifest, gọi helper rồi gọi `DeleteMdmWorkingDirectory`. Metadata nhận được có thể bị xóa sau khi helper kết thúc.

Điều này chỉ rõ ranh giới cần quan sát tiếp: nội dung response trước khi ghi file, file ngay sau khi ghi, hoặc giá trị bộ nhớ tại ranh giới đó. Nó chưa chứng minh mọi dữ liệu khóa chỉ tồn tại ở server. Chưa quan sát một response thật để xác nhận các trường cụ thể mà backend trả về.

`irestores.exe` được gọi từ một nhánh C# khác (`Recovered_06_005f_Name` và `Recovered_06_00c5_Name`), không phải chuỗi gọi của `RunMdmBackupRestore` đang nghiên cứu. Không gộp nhánh đó vào cơ chế MDM chỉ vì cùng package.

## Các địa chỉ kiểm tra trong irestores.exe

SHA-256: `9eefa8dcb46223dd673791249f01954bf6e0976afba12e1d49d82e6c07b76b0d`.

- `backup.Open`: `0x140134000`.
- Tại `0x1401340d4`, lệnh LEA trỏ tới string `Manifest.plist` ở `0x140296eea`; độ dài dùng là 14.
- Các call lần lượt: `path.Join` ở `0x1401340f3`, `os.OpenFile` ở `0x140134100`, `plist.Unmarshal` ở `0x140134166`, `keybag.Read` ở `0x140134188`.
- `backup.decryptDatabase`: `0x140134400`; gọi `aeswrap.Unwrap` ở `0x1401344ac`, `aes.NewCipher` ở `0x140134567`, `cipher.NewCBCDecrypter` ở `0x14013458a`.

Nguồn đối chiếu được ghim ở [dnicolson/irestore, backup.go](https://github.com/dnicolson/irestore/blob/4c56b5fdaf622d20ffd38e7a0118f54afbf88d3a/backup/backup.go). Binary ghi module `(devel)`, không có bằng chứng đây chính xác là commit tạo binary. Quan sát call/address ở trên đến từ byte của file trong package, không chỉ từ nguồn tham chiếu.

## Bước thu dữ liệu đã chuẩn bị

`tooling/rea/capture_manifest.py` theo dõi một thư mục lab được chọn và giữ lại bản Manifest.plist đọc được có cả BackupKeyBag/ManifestKey. Script chỉ đọc file nguồn và lưu bản sao riêng; không chạy TM-BYPASS hoặc tự gọi backend. Có thể truyền một encrypted Manifest.db để kiểm tra ứng viên bằng unwrap khóa thực và giải mã header SQLite, tái sử dụng bộ Keybag trong `mdm-re-lab`.

Đã thử tích hợp với manifest tổng hợp: bỏ qua lần ghi dở, giữ được manifest hoàn chỉnh sau khi thư mục nguồn bị xóa, chấp nhận khóa đúng, từ chối mật khẩu sai, wrapped key bị sửa và ciphertext không khớp. Phép thử được chạy trên Linux; chưa thử watcher trong một phiên TM-BYPASS trên Windows. Polling có thể bỏ lỡ file bị xóa giữa hai lần kiểm tra.

Một response có cấu trúc hợp lệ chưa đủ để coi là đúng backup. Cần giải mã được Manifest.db mang SHA-256 `47554d1339205e89ab34e96ddafa8f2b0acf484e81b42a20df93bf09c04f4e83`. Header khớp kiểm tra được tương thích khóa; sau đó còn phải chạy kiểm tra SQLite và đọc record để nghiên cứu giá trị plaintext.

## Tái lập và bằng chứng

- `audit_manifest_material.py` và `manifest-material-audit.json`: phạm vi, hash, marker, kết quả và giới hạn bộ dò.
- `manifest-material-control.json`: kiểm soát dương dùng dữ liệu bên ngoài, tách khỏi phạm vi mẫu chính.
- `irestores-go-evidence.json`: Evidence REA `ev_baadcfea71972370b2ba133bcdb37b0b460f5f9d45bb2eb514fd55683e09c7f2`.
- `irestores-static-trace.json`, `irestores-backup-open.asm`, `irestores-decrypt-database.asm`: đối chiếu mã máy.

```bash
PYTHONPATH=tm_bypass_research/deps python3 tm_bypass_research/recovery/audit_manifest_material.py --output manifest-material-audit.json
```

Đầu vào riêng không nằm trong repo công khai. Bản mã giả và các báo cáo không thay thế dữ liệu ciphertext/keybag cần cho phép giải mã. Hiện vẫn chưa phục hồi được plaintext backup hoặc xác nhận xóa MDM trên thiết bị.
