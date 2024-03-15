// lesson 2
// Viết chương trình tcp_server, đợi kết nối ở cổng xác
// định bởi tham số dòng lệnh. Mỗi khi có client kết nối
// đến, thì gửi xâu chào được chỉ ra trong một tệp tin xác
// định, sau đó ghi toàn bộ nội dung client gửi đến vào một
// tệp tin khác được chỉ ra trong tham số dòng lệnh
// tcp_server <cổng> <tệp tin chứa câu chào>
// <tệp tin lưu nội dung client gửi đến>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char *argv[]) {

    int listener = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (listener == -1) {
        perror("socket() failed");
        return 1;
    }

    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = htonl(INADDR_ANY);
    addr.sin_port = htons(atoi(argv[1]));

    if (bind(listener, (struct sockaddr *)&addr, sizeof(addr))) {
        perror("bind() failed");
        return 1;
    }

    if (listen(listener, 5)) {
        perror("listen() failed");
        return 1;
    }
    
    // mở file chứa câu chào
    FILE *greeting_file = fopen(argv[2], "r");
    if (greeting_file == NULL)
        perror("ERROR opening greeting file");

    // mở file để ghi dữ liệu từ client
    FILE *client_data_file = fopen(argv[3], "w");
    if (client_data_file == NULL)
        perror("ERROR opening client data file");

    char buf[1024];

    while(1) {
        int client = accept(listener, NULL, NULL);

        memset(buf, 0, 1024);
        while (fgets(buf, 1024 - 1, greeting_file) != NULL) {
            write(client, buf, strlen(buf));
        }

        memset(buf, 0, 1024);
        while(1) {
            int ret = recv(client, buf, sizeof(buf), 0);
            if(ret <= 0) 
                break;
            if(ret < sizeof(buf))
                buf[ret] = 0;

            fputs(buf, client_data_file);
            fflush(client_data_file);
            puts(buf);
        }

        close(client);
    }

    fclose(greeting_file);
    fclose(client_data_file);
    close(listener);

    return 0;
}
// Dxy