# include <stdio.h>
# include <stdlib.h>
# include <arpa/inet.h>

void main() {
    // Khai báo địa chỉ trong ứng dụng server
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_port = htons(9090);

    // Khai báo địa chỉ trong ứng dụng client
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    addr.sin_port = htons(9090);
}