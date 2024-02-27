// Ví dụ về phân giải tên miền (IPv4, IPv6)
#include <stdio.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <string.h>

int main() {
    struct addrinfo *res, *p;
    int ret = getaddrinfo("facebook.com", "http", NULL, &res);
    if(ret != 0) {
        printf("Khong phan giai duoc\n");
        return 1;
    }

    // Duyệt danh sách kết quả
    p = res;
    while(p != NULL) {
        if(p -> ai_family == AF_INET) {
            printf("IPv4\n");
            struct sockaddr_in addr;
            memcpy(&addr, p->ai_addr, sizeof(addr));
            printf("IP: %s\n", inet_ntoa(addr.sin_addr));
        } else if(p -> ai_family == AF_INET6) {
            printf("IPv6\n");
            void* addr;
            char ipstr[INET6_ADDRSTRLEN];
            struct sockaddr_in6* IPv6 = (struct sockaddr_in6*)p -> ai_addr;
            addr = &(IPv6->sin6_addr);
            inet_ntop(p->ai_family, addr, ipstr, sizeof(ipstr));
            printf("IP: %s\n", ipstr);
        }
        p = p->ai_next;
    }

    freeaddrinfo(res);

    return 0;
}
// Dxy