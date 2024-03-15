// lesson 3
// Viết chương trình sv_client, cho phép người dùng nhập dữ liệu
// là thông tin của sinh viên bao gồm MSSV, họ tên, ngày sinh, và
// điểm trung bình các môn học. Các thông tin trên được đóng gói
//và gửi sang sv_server. Địa chỉ và cổng của server được nhập từ
// tham số dòng lệnh.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <unistd.h>

typedef struct {
    char mssv[20];
    char ho_ten[50];
    char ngay_sinh[20];
    float diem_tb;
} SinhVien;

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

    SinhVien sv;
    printf("Nhap MSSV: ");
    scanf("%s", sv.mssv);
    printf("Nhap ho ten: ");
    // scanf("%s", sv.ho_ten);
    getchar(); // Consume the newline character left by the previous scanf
    fgets(sv.ho_ten, sizeof(sv.ho_ten), stdin);
    sv.ho_ten[strcspn(sv.ho_ten, "\n")] = '\0';
    printf("Nhap ngay sinh (yyyy-mm-dd): ");
    scanf("%s", sv.ngay_sinh);
    printf("Nhap diem trung binh: ");
    scanf("%f", &sv.diem_tb);

    send(client, (char *)&sv, sizeof(SinhVien), 0);

    close(client);

    return 0;
}
// Dxy