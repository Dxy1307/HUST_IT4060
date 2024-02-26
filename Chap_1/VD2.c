// Lệnh gửi từ client là chuỗi ký tự có dạng “CMD X Y” 
// trong đó CMD là các lệnh ADD, SUB, MUL, DIV, X
// và Y là 2 số thực. Viết đoạn chương trình kiểm tra một
// chuỗi ký tự có theo cú pháp trên không, xác định các giá trị của CMD, X và Y.
#include <stdio.h>
#include <string.h>

int main() {
    printf("Nhap lenh gui tu client: ");
    char *resp;
    fgets(resp, 16, stdin);
    char cmd[16], temp[16];
    float x, y;
    int n = sscanf(resp, "%s%f%f%s", cmd, &x, &y, temp);
    printf("%d\n", n);
    printf("%s\n", cmd);
    printf("%f\n", x);
    printf("%f\n", y);

    if (n == 3) {
        if(strcmp(cmd, "ADD") == 0 || strcmp(cmd, "SUB") == 0
            || strcmp(cmd, "MUL") == 0 || strcmp(cmd, "DIV") == 0) {
                printf("Dung cu phap\n");
        } else {
            printf("Khong ho tro cu phap\n");
        }
    } else {
        printf("Sai cu phap\n");
    }
}
// Dxy