// lesson 1
// Viết chương trình tcp_client, kết nối đến một máy chủ xác định 
// bởi địa chỉ IP và cổng. Sau đó nhận dữ liệu từ bàn phím và gửi đến server.
// Tham số được truyền vào từ dòng lệnh có dạng
// tcp_client <địa chỉ IP> <cổng>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int client = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr(argv[1]);
    addr.sin_port = htons(atoi(argv[2]));

    int ret = connect(client, (struct sockaddr *)&addr, sizeof(addr));
    if(ret == -1) {
        perror("connect() failed");
        return 1;
    }

    char buf[256];
    while(1) {
        printf("Nhap chuoi ky tu: ");
        fgets(buf, sizeof(buf), stdin);

        send(client, buf, strlen(buf), 0);

        if(strncmp(buf, "exit", 4) == 0)
            break;
    }

    close(client);

    return 0;
}
// Dxy