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

### 2.3 Ứng dụng TCP server/client
- Các hàm được sử dụng để tạo ứng dụng server/client hoạt động theo giao thức TCP

- **Hàm socket()**
    + ứng dụng phải tạo socket trước khi có thể gửi nhận dữ liệu

    + syntax:

            int socket {
                int domain, // giao thức AF_INET hoặc AF_INET6
                int type, // kiểu socket SOCK_STREAM hoặc SOCK_DGRAM
                int protocol, // giao thức IPPROTO_TCP hoặc IPPROTO_UDP
            } => trả về giá trị mô tả của socket nếu thành công, -1 nếu lỗi (biến errno chứa mã lỗi, cần khai báo errno.h truy cập errno)

            // socket TCP
            int s1 = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
            if (s1 == -1) {
                printf("Không tạo được socket\n");
                return 1;
            }

            // socket UDP
            int s2 = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
            if(s2 == -1) {
                printf("Không tạo được socket\n");
                return 1;
            }

- **Cách xác định lỗi**
    + đa số trả về -1 nếu lỗi
    + biến **errno** trả về mã lỗi xảy ra gần nhất (lib errno.h)
    + hàm **strerror(int errnum)** trả về chuỗi ký tự mô tả mã lỗi (lib string.h)
    + hàm perror(const char *s) in ra chuỗi ký tự mô tả mã lỗi gần nhất, s là chuỗi ký tự tiền tố, có thể NULL (lib stdio.h)

- **Hàm bind()**
    + gắn socket với cấu trúc địa chỉ trong ứng dụng server

    + syntax:

            int bind(
                int sockfd, // mô tả của socket
                const struct sockaddr *addr, // con trỏ cấu trúc địa chỉ
                socklen_t addrlen // độ dài cấu trúc địa chỉ
            ) => trả về 0 nếu thành công, -1 nếu lỗi

    + khai báo địa chỉ của server = cấu trúc địa chỉ sockaddr_in (IPv4) hoặc sockaddr_in6 (IPv6) => ép kiểu sang sockaddr

- **Hàm listen()**
    + chuyển socket sang trạng thái chờ kết nối

    + syntax:

            int listen (
                int fd, // mô tả của socket
                int n   // chiều dài hàng đợi chờ kết nối
            ) => trả về 0 nếu thành công, -1 nếu lỗi

    + Example:
        
            // listener là socket đã được khởi tạo
            listen(listener, 5);

- **Hàm accept()**
    + chấp nhận kết nối đang nằm trong hàng đợi

    + syntax:

            int accept (
                int sockfd, // socket chờ kết nối đã được khởi tạo
                struct sockaddr *addr, // con trỏ địa chỉ client
                socklen_t *addrlen // con trỏ độ dài địa chỉ client
            ) => trả về mô tả của socket nếu thành công (giá trị kiểu int), -1 nếu lỗi

    + nếu con trỏ **addr** và **addrlen** là NULL, hàm **accept()** sẽ không lấy địa chỉ của client

    + socket trả về được sử dụng để truyền nhận dữ liệu giữa server và client

    + hàm **accept()** cần được gọi nhiều lần để chấp nhận nhiều kết nối

    + Example:

            // s là socket đã được khởi tạo để chờ các kết nối
            int s1 = accept(s, NULL, NULL);
            // s1 là socket đại diện cho kết nối giữa server  và client1 
            // trong TH này không cần quan tâm địa chỉ của client1

            struct sockaddr_int clientAddr;
            int clientAddrLen = sizeof(clientAddr);
            int s2 = accept(s, (struct sockaddr *)&clientAddr, &clientAddrLen);
            // s2 là socket đại diện cho kết nối giữa server và client2
            // clientAddr chứa dữ liệu địa chỉ của client2 (IP và cổng)

- **Hàm send()**
    + truyền dữ liệu trên socket

    + syntax:

            ssize_t send (
                int sockfd, // socket ở trạng thái đã kết nối
                const void *buf, // buffer chứa dữ liệu cần gửi
                size_t len, // số byte cần gửi
                int flags, // cờ quy định cách truyền, mặc định là 0
            ) => trả về số byte đã gửi nếu thành công, -1 nếu lỗi

    + Example:

            // client là socket đã được chấp nhận bởi server
            
            // gửi đi 1 chuỗi ký tự
            char* str = "Hello Network Programming";
            int ret = send(client, str, strlen(str), 0);
            if(ret != -1)
                printf(" %d bytes are sent", ret);

            // gửi đi 1 mảng dữ liệu
            char buf[256];
            for(int i = 0; i < 10; i++)
                buf[i] = i;
            ret = send(client, buf, 10, 0);

            // gửi đi biến dữ liệu bất kỳ
            double d = 1.234;
            ret = send(client, &d, sizeof(d), 0);

- **Hàm write()**
    + truyền dữ liệu trên socket

    + syntax:

            ssize_t write (
                int fd, // socket ở trạng thái đã kết nối
                const void *buf, // buffer chứa dữ liệu cần gửi
                size_t n    // số byte cần gửi
            ) => trả về số byte nếu thành công, -1 nếu lỗi

    + Example: tương tự **send()** chỉ khác không có tham số cuối

- **Hàm recv()**
    + nhận dữ liệu từ socket

    + syntax:

            ssize_t recv (
                int sockfd, // socket đã kết nối
                void *buf, // buffer chứa dữ liệu sẽ nhận được
                size_t n, // số byte muốn nhận (độ dài của buffer)
                int flags, // cờ quy định cách nhận, mặc định là 0
            ) => trả về số byte đã nhận nếu thành công, 0 nếu kết nối bị đóng, -1 nếu lỗi

    + Example:

            // client là socket đã được chấp nhận bởi server
            char buf[256];
            // nhận 1 buffer dữ liệu
            int ret = recv(client, buf, sizeof(buf), 0);

            // nhận biến dữ liệu bất kỳ
            double d;
            ret = recv(client, &d, sizeof(d), 0);

            // nhận dữ liệu đến khi ngắt kết nối
            while(true) {
                ret = recv(client, buf, sizeof(buf), 0);
                // ktra điều kiện kết nối
                if(ret <= 0)
                    break;
                // xử lý dữ liệu nhận được
            }

- **Hàm read()**
    + nhận dữ liệu từ socket

    + syntax:

            ssize_t read(
                int fd, // socket đã kết nối
                void* buf, // buffer chứa dữ liệu sẽ nhận được
                size_t nbytes // số byte muốn nhận (độ dài của buffer)
            ) => trả về số byte đã nhận nếu thành công, 0 nếu kết nối bị đóng, -1 nếu lỗi

    + Example: như hàm **recv()** nhưng không có tham số cuối

- **Hàm close()**
    + đóng kết nối

    + syntax:

            int close(
                int sockfd // socket cần đóng
            ) => trả về 0 nếu thành công, -1 nếu lỗi

- **Hàm shutdown()**
    + đóng kết nối

    + syntax:

            int shutdown(
                int sockfd, // socket cần đóng kết nối
                int how, // cách thức đóng
            ) => 0 nếu thành công, -1 nếu lỗi

    + các giá trị của tham số **how**:
        + SHUT_RD: không nhận thêm dữ liệu
        + SHUT_WR: không truyền thêm dữ liệu
        + SHUT_RDWR: không truyền và nhận thêm dữ liệu
    
    + lệnh **shutdown(fd, SHUT_RDWR)** tương đương lệnh close(fd)

- **Hàm connect()**
    + thiết lập kết nối đến server thông qua socket

    + syntax:

            int connect(
                int sockfd, // socket đã được tạo
                const struct sockaddr *addr, // con trỏ địa chỉ server
                socklen_t addrlen // độ dài cấu trúc địa chỉ
            ) => trả về 0 nếu thành công, -1 nếu lỗi

    + Địa chỉ server có thể xác định thông qua:
        + khai báo cấu trúc địa chỉ IP và cổng
        + phân giải tên miền

    + Example:
        + Ex_1:

                // khai báo socket
                int client = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

                // khai báo địa chỉ của server
                struct sockaddr_in addr;
                addr.sin_family = AF_INET;
                addr.sin_addr.s_addr = inet_addr("127.0.0.1");
                addr.sin_port = htons(9000);

                // kết nối đến server
                int res = connect(client, (struct sockaddr*)&addr, sizeof(addr));
                if(res == -1) {
                    printf("Khong ket noi duoc den server");
                    return 1;
                }

        + Ex_2:

                // khai báo socket
                int client = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
                // Phân giải tên miền thành IP
                struct addrinfo *res;
                int ret = getaddrinfo("httpbin.org", "http", NULL, &res);
                if(ret == -1 || res == NULL) {
                    printf("Failed to get IP address\n");
                    return 1;
                }
                // kết nối đến server
                ret = connect(client, res->ai_addr, res->ai_addrlen);
                if(ret == -1) {
                    printf("Khong ket noi duoc den server");
                    return 1;
                }

- **Truyền dữ liệu sử dụng TCP - Ứng dụng server**
    + tạo socket qua hàm **socket()**
    + gắn socket vào một giao diện mạng thông qua hàm bind()
    + chuyển socket sang trạng thái đợi kết nối qua hàm **listen()**
    + chấp nhận kết nối từ client thông qua hàm **accept()**
    + gửi dữ liệu tới client thông qua hàm **send()/write()**
    + nhận dữ liệu từ client thông qua hàm **recv()/read()**
    + đóng socket khi việc truyền nhận kết thúc = hàm **close()**

- **Ứng dụng client**
    + Tạo socket qua hàm **socket()**
    + điền thông tin về server vào cấu trúc **sockaddr_in**
    + kết nối tới server qua hàm **connect()**
    + Gửi dữ liệu tới server thông qua hàm **send()**
    + nhận dữ liệu từ server thông qua hàm **recv()**
    + đóng socket khi việc truyền nhận kết thúc bằng hàm **close()**

### 2.4 Ứng dụng UDP Sender/Receiver
- Giao thức UDP là giao thức không kết nối (connectionless)
- Ứng dụng không cần phải thiết lập kết nối trước khi gửi tin
- Ứng dụng có thể nhận được tin từ bất kỳ máy tính nào trong mạng
- Trình tự gửi thông tin ở bên gửi như sau:

    + socket() -> Xác định địa chỉ/Phân giải tên miền -> sendto()

- **Ứng dụng UDP Sender - Hàm sendto()**
    + Gửi dữ liệu qua socket theo giao thức UDP
    + syntax:

            ssize_t sendto(
                int sockfd, // socket đã được khởi tạo
                const void *buf, // buffer chứa dữ liệu cần gửi
                size_t len, // số byte cần gửi
                int flags, // cờ quy định cách gửi, mặc định là 0
                const struct sockaddr *addr, // con trỏ địa chỉ bên nhận
                socklen_t addr_len // độ dài cấu trúc địa chỉ
            ) => hàm trả về số byte đã gửi nếu thành công, -1 nếu lỗi

- **Ứng dụng UDP Receiver**
    + Trình tự nhận thông tin ở bên nhận như sau:

        + socket() -> bind() -> recvfrom()

- **Ứng dụng UDP Receiver - Hàm recvfrom()**
    + nhận dữ liệu qua socket theo giao thức UDP
    + syntax:

            ssize_t recvfrom(
                int sockfd, // socket đã khởi tạo
                void *buf, // buf chứa dữ liệu nhận được
                size_t len, // số byte muốn nhận (kích thước buffer)
                int flags, // cờ quy định cách nhận, mặc định là 0
                struct sockaddr *src_addr, // con trỏ địa chỉ bên gửi
                socklen_t *addr_len // con trỏ độ dài địa chỉ
            ) => trả về số byte đã nhận nếu thành công, -1 nếu lỗi

- **Chú ý**
    + lệnh nhận dữ liệu

            recv(client, buf, sizeof(buf), 0)
            recv(client, buf, sizeoff(buf), 0, NULL, NULL)
            => 2 lệnh này tương đương, có thể sử dụng thay thế
    
    + lệnh truyền dữ liệu

            send(client, buf, strlen(buf), 0)
            sendto(client, buf, strlen(buf), 0, NULL, 0)
            => 2 lệnh này tương đương, có thể sử dụng thay thế

- **Kịch bản kiểm thử giao thức hướng dòng - TCP**
    + Bên nhận tạm dừng chương trình trước khi nhận dữ liệu
    + Bên truyền thực hiện truyền 2 lần liên tiếp
    + Bên nhận tiếp tục chương trình và sẽ nhận được cả 2 gói tin trong một lần nhận

- **Kịch bản kiểm thử giao thức hướng thông điệp - UDP**
    + Bên nhận tạm dừng chương trình trước khi nhận dữ liệu
    + Bên truyền thực hiện truyền 2 lần liên tiếp
    + Bên nhận tiếp tục chương trình và sẽ nhận được 2 gói tin trong 2 lần nhận

- **Bài tập**

# Dxy