# IT4060 - Lập trình mạng

## Chương 1: Giới thiệu về lập trình mạng

### 1.1 Khái niệm lập trình mạng
- **Khái niệm** - lập trình mạng bao gồm các kỹ thuật lập trình nhằm xây dựng ứng dụng, phần mềm với mục đích khai thác hiệu quả tài nguyên mạng máy tính

- **Các vấn đề cần quan tâm**
    + Thông tin truyền nhận trên mạng
    + Các giao thức truyền thông (Protocols)
        + Giao thức chuẩn (HTTP, FTP, SMTP, POP3, ...)
        + Giao thức tự định nghĩa
    + Các kỹ thuật truyền nhận dữ liệu
    + Các kỹ thuật nâng cao
        + nén dữ liệu
        + mã hóa dữ liệu
        + truyền nhận dữ liệu song song

### 1.2 Nhắc lại một số kiên thức Mạng máy tính
- **TCP/IP**
    + là bộ giao thức truyền thông được sử dụng trên Internet và hầu hết các mạng thương mại.
    + Được chia thành các tầng gồm nhiều giao thức, thuận tiện cho việc quản lý và phát triển.
    + là thể hiện đơn giản hóa mô hình lý thuyết OSI.
    + gồm 4 tầng: 
        + Tầng ứng dụng - Application Layer
        + Tầng giao vận - Transport Layer
        + Tầng Internet
        + Tầng truy cập mạng - Network Access Layer

- ***Tầng ứng dụng***
    + Đóng gói dữ liệu người dùng theo giao thức riêng và chuyển xuống tần dưới.
    + Các giao thức thông dụng: HTTP, FTP, SMTP, POP3, DNS, SSH, IMAP,...
    + Việc lập trình mạng sẽ xây dựng ứng dụng tuân theo một trong các giao thức ở tầng này hoặc giao thức do người phát triển tự định nghĩa

- ***Tầng giao vận***
    + Cung cấp dịch vụ truyền dữ liệu giữa ứng dụng - ứng dụng
    + Đơn vị dữ liệu là các đoạn (segment, datagram)
    + Các giao thức ở tầng này: TCP, UDP
    + Việc lập trình mạng sẽ sử dụng dịch vụ do các giao thức ở tầng này cung cấp để truyền dữ liệu

- ***Tầng Internet***
    + Định tuyến và truyền các gói tin liên mạng
    + Cung cấp dịch vụ truyền dữ liệu giữa máy tính - máy tính trong cùng nhánh mạng hoặc giữa các nhánh mạng
    + Đơn vị dữ liệu là các gói tin (packet)
    + Các giao thức ở tầng này: IPv4, IPv6
    + Việc lập trình mạng sẽ rất ít khi can thiệp vào tầng này, trừ khi phát triển một giao thức liên mạng mới

- ***Tầng truy cập mạng***
    + Cung cấp dịch vụ truyền dữ liệu giữa các nút mạng trên cùng một nhánh mạng vật lý
    + Đơn vị dữ liệu là các khung (frame)
    + Phụ thuộc rất nhiều vào phương tiện kết nối vật lý
    + Các giao thức ở tầng này: MAC, LLC, ADSL, 802.11, ...
    + Việc lập trình mạng ở tầng này là xây dựng các trình điều khiển phần cứng tương ứng, thường do nhà sản xuất thực hiện.

- **Bộ giao thức Internet**
    + Dữ liệu được gửi đi qua mỗi tầng sẽ được thêm phần thông tin điều khiển (header).
    + Dữ liệu nhận được qua mỗi tầng sẽ được bóc tách thông tin điều khiển.

- **Internet Protocol**
    + Giao thức mạng thông dụng nhất trên thế giới
    + Chức năng:
        + Định địa chỉ các máy chủ
        + Định tuyến các gói dữ liệu trên mạng
    + IPv4, IPv6
    + hỗ trợ trên tất cả các hệ điều hành
    + công cụ sử dụng để lập trình ứng dụng mạng

- **Giao thức IPv4**
    + sử dụng trong hệ thống chuyển mạch gói
    + truyền dữ liệu theo kiểu Best-Effort: không đảm bảo tính trật tự, trùng lặp, tin cậy của gói tin
    + kiểm tra tính toàn vẹn của dữ liệu qua checksum

- ***Địa chỉ IPv4***
    + sử dụng 32 bit để đánh địa chỉ các máy tính trong mạng
    + gồm: phần mạng, phần host
    + dành riêng 1 vài dải đặc biệt không sử dụng
    + chia thành 4 nhóm 8 bit
    + 5 lớp địa chỉ: A, B, C, D, E
        + A, B, C: trao đổi thông tin thông thường
        + D: multicast
        + E: để dành

- ***Mặt nạ mạng***
- ***Các dải địa chỉ đặc biệt***

- **IPv6**
    + Khắc phục vđề thiếu địa chỉ của IPv4
    + dần phổ biến, chưa thay thế hoàn toàn IPv4
    + sử dụng 128 bit để đánh địa chỉ, dưới dạng các cụm số hexa phân cách bởi dấu :

- **Giao thức TCP**
    + Giao thức lõi chạy ở tầng giao vận
    + chạy bên dưới tầng ứng dụng và trên nền IP
    + cung cấp dịch vụ truyền dữ liệu theo dòng tin cậy giữa các ứng dụng
    + chia dữ liệu thành các gói nhỏ, thêm thông tin kiểm soát và gửi đi trên đường truyền
    + lập trình mạng sử dụng giao thức này để trao đổi thông tin

    + Hướng kết nối: 2 bên phải thiết lập kênh truyền trước khi truyền dữ liệu, gọi là quá trình bắt tay 3 bước
    + truyền dữ liệu theo dòng
    + đúng trật tự
    + tin cậy, chính xác
    + độ trễ lớn, khó đáp ứng được tính thời gian thực

- **Cổng**
    + TCP sử dụng cổng để chuyển dữ liệu tới đúng ứng dụng hoặc dịch vụ
    + một cổng có thể mở nhiều kết nối => có thể sử dụng nhiều cổng

- **UDP**
    + Cũng là giao thức lõi trong TCP/IP
    + cung cấp dịch vụ truyền dữ liệu giữa các ứng dụng
    + UDP chia nhỏ dữ liệu ra thành các datagram
    + Không cần thiết lập kết nối trước khi truyền
    + nhanh, chiếm ít tài nguyên dễ xử lý
    + sử dụng trong các ứng dụng khắt khe về thời gian, chấp nhận sai sót: audio, video, game, ...
    + hạn chế:
        + không có cơ chế báo gửi
        + không đảm bảo trật tự các datagram
        + không phát hiện được mất mát hoặc trùng lặp thông tin

- **Hệ thống phân giải tên miền DNS**
    + Domain Name System: hệ thống phân cấp làm nhiệm vụ ánh xạ tên miền sang địa chỉ IP và ngược lại.

### 1.3 Lập trình trong môi trường Ubuntu/Linux

## Chương 2: Lập trình socket cơ bản

### 2.1 Khái niệm socket
- Socket là điểm cuối (end-point) trong liên kết truyền thông 2 chiều (two-way communication) biểu diễn kết nối giữa client-server
- Các lớp socket được ràng buộc với một cổng port (thể hiện là một con số cụ thể) để các tầng TCP có thể định danh ứng dụng mà dữ liệu sẽ được gửi tới
- Socket là giao diện lập trình mạng được hỗ trợ bởi nhiều ngôn ngữ, hệ điều hành khác nhau
- Socket có thể được sử dụng để chờ các kết nối trong ứng dụng server hoặc để thiết lập kết nối trong ứng dụng client

### 2.2 Cấu trúc địa chỉ socket
- Socket cần được gắn địa chỉ để thực hiện chức năng truyền nhận dữ liệu trên mạng
- Cấu trúc địa chỉ lưu trữ địa chỉ IP và cổng
- Các cấu trúc địa chỉ
    + struct sockaddr => Mô tả địa chỉ nói chung
    + struct sockaddr_in => mô tả địa chỉ IPv4
    + struct sockaddr_in6 => mô tả địa chỉ IPv6
- **Cấu trúc địa chỉ IPv4**: file IPv4_structure.c
- **Ví dụ khai báo địa chỉ**: file Ex_decla_addr.c
- **Cấu trúc địa chỉ IPv6**: lưu trữ địa chỉ IPv6 của ứng dụng đích cần nối đến (file IPv6_structure.c)

- **Các hàm chuyển đổi địa chỉ**
    + cần khai báo tệp <arpa/inet.h>
    + chuyển đổi địa chỉ IP dạng xâu sang số nguyên 32 bit (IPv4):
    
            in_addr_t inet_addr (
                const char *cp // xâu ký tự chứa địa chỉ IPv4
            ) => hàm trả về địa chỉ dạng số nguyên, -1 nếu lỗi
    
    + chuyển đổi địa chỉ IP dạng xâu sang cấu trúc in_addr:

            int inet_aton (
                const char *cp, // xâu ký tự chứa địa chỉ IP
                struct in_addr *inp // cấu trúc địa chỉ IP
            ) => trả về 1 nếu thành công, 0 nếu lỗi
    
    + chuyển đổi địa chỉ từ dạng in_addr sang dạng xâu (IPv4):

            char *inet_ntoa (
                struct in_addr in // cấu trúc địa chỉ IPv4
            ) => trả về chuỗi ký tự chứa địa chỉ

    + chuyển đổi từ dạng số sang dạng xâu (cho IPv4 và IPv6):

            const char *inet_ntop (
                int af, // AF_INET hoặc AF_INET6
                const void* cp, // con trỏ in_addr hoặc in6_addr
                char *buf, // xây ký tự chứa địa chỉ
                socklen_t len // INET_ADDRSTRLEN hoặc INET6_ADDRSTRLEn
            ) => trả về xâu ký tự chứa địa chỉ, trả nề NULL nếu lỗi

    + chuyển đổi từ dạng xâu sang dạng số (cho IPv4 và IPv6)

            int inet_pton (
                int af, // AF_INET hoặc AF_INET6
                const char *cp, // xâu địa chỉ
                void *buf // con trỏ in_addr hoặc in6_addr
            ) => trả về 1 nếu thành công, 0 nếu xâu ký tự không hợp lệ, -1 nếu gặp lỗi khác

- **Các hàm chuyển đổi big-endian <-> little-endian**
    + chuyển đổi little-endian => big-endian (network order)

            // chuyển đổi 4 byte từ little => big
            uint32_t htonl (uint32_t hostlong)
            // chuyển đổi 2 byte từ little => big
            uint16_t htons (uint16_t hostshort)
    
    + chuyển đổi big => little (host order)

            // chuyển 4 byte từ big => little
            uint32_t ntohl (uint32_t netlong)
            // chuyển 2 byte từ big => little
            uint16_t ntohs (uint16_t netshort)

- **Phân giải tên miền**
    + địa chỉ của máy đích được cho dưới dạng tên miền
    + ứng dụng cần thực hiện phân giải tên miền để có địa chỉ IP thích hợp
    + hàm **getaddrinfo()** sử dụng để phân giải tên miền ra các địa chỉ IP
    + cần thêm tệp tiêu đề **netdb.h**

            int getaddrinfo(
                const char* nodename, // tên miền hoặc địa chỉ cần phân giải
                const char* servname, // dịch vụ hoặc cổng
                const struct addrinfo* hints, // cấu trúc gợi ý
                struct addrinfo** res         // kết quả
            );
    + thành công trả về 0, lỗi sử dụng hàm **gai_strerror()** để in ra thông báo lỗi
    + giải phóng: hàm **freeaddrinfo()**
    + cấu trúc **addrinfo**: danh sách liên kết đơn chứa thông tin về tên miền tương ứng
        
            struct addrinfo {
                int ai_flags;   // thường là AI_CANONNAME
                int ai_family;  // thường là AF_INET
                int ai_socktype;    // loại socket
                int ai_protocol;    // giao thức giao vận
                socklen_t ai_addrlen;   // chiều dài của ai_addr
                char* ai_canonname;     // tên miền
                struct sockaddr* ai_addr;   // địa chỉ socket đã phân giải
                struct addrinfo* ai_next;   // con trỏ tới cấu trúc sau
            }
    
    + Sử dụng cấu trúc gợi ý để lọc kết quả

            struct addrinfo hints;
            // IPv4: AF_INET
            // IPv6: AF_INET6
            // Không xác định: AF_UNSPEC
            hints.ai_family = AF_UNSPEC;
            // TCP: SOCK_STREAM
            // UDP: SOCK_DGRAM
            // Không xác định: 0
            hints.ai_socktype = SOCK_STREAM
            // TCP: IPPROTO_TCP
            // UDP: IPPROTO_UDP
            // Không xác định: 0
            hints.ai_protocol: IPPROTO_TCP
# Dxy