# Nguồn tham chiếu và mã phục hồi

## libimobiledevice

Các bản nguồn tham chiếu sau lấy từ tag `1.3.0` của https://github.com/libimobiledevice/libimobiledevice:

- `tm_bypass_research/native_runtime/idevicebackup2_upstream_1_3_0.c`
- `tm_bypass_research/recovery/dll_probes/reference/mobilebackup2.upstream-1.3.0.c`
- `tm_bypass_research/recovery/dll_probes/reference/idevice.upstream-1.3.0.c`
- `tm_bypass_research/recovery/dll_probes/reference/idevice.upstream-1.3.0.h`
- `tm_bypass_research/recovery/dll_probes/reference/service.upstream-1.3.0.c`

Các file giữ thông báo bản quyền của tác giả gốc. Header của các file này nêu GNU Lesser General Public License 2.1 hoặc mới hơn. Hai file COPYING và COPYING.LESSER của tag tham chiếu được lưu trong `licenses/`.

## TM-BYPASS và các thành phần liên quan

Các file C# trong `csharp_reviewed/`, `csharp_by_token/` và mã giả C trong `native_c_reviewed/`, `dll_calls/c_partial/` được phục hồi từ mẫu người dùng cung cấp để phân tích. Tên lớp, biến và hàm có hậu tố Recovered hoặc tên dạng `native_*` có thể do người phân tích đặt. Không khẳng định đây là mã nguồn gốc do tác giả công cụ phát hành.

Quyền tác giả đối với mã của các bên thứ ba vẫn thuộc chủ thể tương ứng. Việc đặt các file cạnh nhau trong repo không chuyển chúng sang cùng một giấy phép.

## Công cụ phân tích

ILSpy, Ghidra, NoVmp, Wine, Unicorn, Capstone và các gói Python là các dự án riêng. Repository ghi phiên bản/hash trong `toolchain.json`; không phân phối lại các bộ công cụ hoặc executable đã tải về.
