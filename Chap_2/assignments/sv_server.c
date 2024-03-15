// lesson 4
// Viết chương trình sv_server, nhận dữ liệu từ sv_client, in ra
// màn hình và đồng thời ghi vào file sv_log.txt. Dữ liệu được ghi
// trên một dòng với mỗi client, kèm theo địa chỉ IP và thời gian
// client đã gửi. Tham số cổng và tên file log được nhập từ tham số
// dòng lệnh.
// Ví dụ dữ liệu trong file log:
// 127.0.0.1 2023-04-10 09:00:00 20201234 Nguyen Van A 2002-04-10 3.99
// 127.0.0.1 2023-04-10 09:00:10 20205678 Tran Van B 2002-08-18 3.50
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <time.h>

typedef struct {
    char mssv[20];
    char ho_ten[50];
    char ngay_sinh[20];
    float diem_tb;
} SinhVien;

void log_data(char *ip_addr, char *log_file, SinhVien sv) {
    FILE *fp = fopen(log_file, "a");
    if (fp == NULL) {
        perror("fopen() failed");
        exit(1);
    }

    time_t rawtime;
    struct tm *timeinfo;
    time(&rawtime);
    timeinfo = localtime(&rawtime);

    char time_str[20];
    strftime(time_str, sizeof(time_str), "%Y-%m-%d %H:%M:%S", timeinfo);

    fprintf(fp, "%s %s %s %s %s %.2f\n", ip_addr, time_str, sv.mssv, sv.ho_ten, sv.ngay_sinh, sv.diem_tb);
    fclose(fp);
}

int main(int argc, char *argv[]) {
    int listener = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (listener == -1) {
        perror("socket() failed");
        return 1;
    }

    struct sockaddr_in addr, client_addr;
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

    while(1) {
        socklen_t client_len = sizeof(client_addr);
        int client = accept(listener, (struct sockaddr *)&client_addr, &client_len);
        if (client < 0) {
            perror("accept() failed");
            return 1;
        }

        SinhVien sv;
        recv(client, (char *)&sv, sizeof(SinhVien), 0);
        printf("Received data from client:\nMSSV: %s\nHo ten: %s\nNgay sinh: %s\nDiem TB: %.2f\n", sv.mssv, sv.ho_ten, sv.ngay_sinh, sv.diem_tb);
        char client_ip[INET_ADDRSTRLEN];
        inet_ntop(AF_INET, &(client_addr.sin_addr), client_ip, INET_ADDRSTRLEN);
        printf("Client IP: %s\n", client_ip);

        log_data(client_ip, argv[2], sv);

        close(client);
    }

    close(listener);
    return 0;
}
// Dxy