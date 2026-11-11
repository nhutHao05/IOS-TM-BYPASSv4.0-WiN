# Kiểm tra DLL MobileBackup2 trong môi trường không mạng

`src/probe_matrix.c` gọi trực tiếp DLL gốc có VMProtect. Bộ thử không sửa mã `imobiledevice.dll` hay `plist.dll`. Nó chỉ thay ba hàm truyền tải trong `usbmuxd.dll` bằng callback: `usbmuxd_send`, `usbmuxd_recv`, `usbmuxd_recv_timeout`.

Client giả giữ cấu trúc con trỏ cần thiết để đi qua các lớp MobileBackup2 → DeviceLink → PropertyList → Service → iDeviceConnection. Không có iPhone, thiết bị USB, kết nối máy chủ hay thông tin đăng nhập thật. Container tắt mạng và không gắn USB.

Các hàm được kiểm tra:

| API | Số ca |
| --- | ---: |
| `mobilebackup2_send_request` | 18 |
| `mobilebackup2_send_message` | 11 |
| `mobilebackup2_send_status_response` | 5 |
| `mobilebackup2_send_raw` | 9 |
| `mobilebackup2_receive_raw` | 9 |

52 ca đều khớp với mô hình từ mã nguồn libimobiledevice 1.3.0 được lưu trong `reference/`. Đây là kết quả đối chiếu trên tập đầu vào này, không phải bằng chứng đã khôi phục toàn bộ mã nguồn DLL.

Gói tin trong `output/*.frame` có tiền tố độ dài 4 byte theo thứ tự byte mạng, sau đó là binary plist thật do thư viện tạo. `check_results.py` kiểm tra độ dài, nội dung plist, mã trả về, dữ liệu raw, đầu vào plist không bị đổi và cách báo lỗi.

Ca mã trạng thái `-6` được kiểm tra theo cùng mẫu bit 64 bit: Python đọc integer binary plist là `-6`, còn `plist_get_uint_val` của thư viện trả `18446744073709551610`. Cả hai giá trị được ghi trong kết quả để tránh che sự khác biệt diễn giải kiểu số.

Kết quả đáng chú ý:

- Request Restore của helper được đóng thành `DLMessageProcessMessage` với các trường `TargetIdentifier`, `SourceIdentifier`, `Options` và `MessageName="Restore"`.
- Các tùy chọn `RestoreSystemFiles=false`, `RestoreDontCopyBackup=true`, `RestorePreserveSettings=true`, `Password="mdm"` được giữ nguyên trong payload.
- Lớp request chấp nhận cả tên lệnh không biết và Options dạng array; việc đóng gói không chứng minh thiết bị sẽ chấp nhận lệnh đó.
- Với `Unback`, `Password` được chép thêm ra cấp ngoài; với `EnableCloudBackup`, `CloudBackupState` được xử lý tương tự, khớp mã nguồn tham chiếu.
- Các hàm raw có cách xử lý EOF/lỗi khác nhau giữa gửi và nhận; mô hình kiểm tra tính cả lớp iDevice và Service, không chỉ một API giả trả thành công.

Chạy lại trong workspace đã có image phân tích:

```bash
./run_offline.sh
```

Docker dùng storage driver VFS, cần khoảng 3 GiB trống để tạo container Wine. Script sẽ báo thiếu dung lượng trước khi tạo bản sao image. Nhật ký, gói tin và kết quả nằm trong `output/` cùng `differential-results.json`.

Các thử nghiệm này chưa giải mã backup nhúng, chưa thay thế `Manifest.plist` tương ứng và chưa kiểm chứng khả năng xóa MDM trên thiết bị thật.
