#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <malloc.h>
#include <string.h>
#include <sys/socket.h>
#include <resolv.h>
#include <netdb.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

int main() {
    FILE* in = fopen("message.txt", "w");   
    char message[1024];
        printf("Enter the message\n");
        scanf("%s", message);
        fprintf(in, "%s", message);
        system("openssl enc -aes-256-cbc -salt -in message.txt -out message.txt.enc");   
    return 0;
}

