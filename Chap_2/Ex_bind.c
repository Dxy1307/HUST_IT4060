#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <errno.h>
#include <netinet/in.h>


int main() {
    int listener = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

    // khai báo cấu trúc địa chỉ của server
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = htonl(INADDR_ANY);
    addr.sin_port = htons(9000);

    // gắn địa chỉ với socket
    bind(listener, (struct sockaddr *)&addr, sizeof(addr));
}