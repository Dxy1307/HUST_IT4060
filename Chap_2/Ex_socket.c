#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <errno.h>
#include <string.h>

int main() {
   int listener = socket(AF_INET, SOCK_STREAM, -1);
   if(listener != -1) {
    printf("Socket crated: %d\n", listener);
   } else {
    printf("Failed to create socket: %d - %s\n", errno, strerror(errno));
    perror("socket() failed");
    exit(1);
   }
}