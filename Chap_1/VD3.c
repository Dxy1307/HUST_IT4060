// Chuỗi ký tự sau là phản hồi của lệnh PASV trong
// giao thức FTP, hãy xác định giá trị địa chỉ IP và cổng.
// 227 Entering Passive Mode (213,229,112,130,216,4)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char PASV[] = "227 Entering Passive Mode (213,229,112,130,216,4)";
    char *res = strchr(PASV, '(');

    char *p1 = strtok(res, "(),");
    char *p2 = strtok(NULL, "(),");
    char *p3 = strtok(NULL, "(),");
    char *p4 = strtok(NULL, "(),");
    printf("IP: %s.%s.%s.%s\n", p1, p2, p3, p4);

    char *i1 = strtok(NULL, "(),");
    char *i2 = strtok(NULL, "(),");
    printf("Port: %d\n", atoi(i1) * 256 + atoi(i2));
}
// Dxy