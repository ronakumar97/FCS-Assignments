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
    FILE* in = fopen("message.txt", "r");   
    char message[1024];
    char buff[255];
    system("openssl enc -d -aes-256-cbc -salt -in message.txt.enc -out message.txt");
    system("cat message.txt");
    return 0;
}