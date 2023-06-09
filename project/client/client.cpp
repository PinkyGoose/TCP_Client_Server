#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define SERVER_ADRESS "127.0.0.1"
#define SERVER_PORT 5002

const int MESSAGE_MEMORY = 1024;

int main(int argc, char *argv[])
{
    if(argc < 1) {
        perror("Требуется дополнительный аргумент - имя файла");
        exit(-1);
    }
    char buf[MESSAGE_MEMORY];
    FILE *fp;
    int sock;
    struct sockaddr_in addr;
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0)
    {
        perror("socket");
        exit(1);
    }
    addr.sin_family = AF_INET;
    addr.sin_port = htons(SERVER_PORT);
    addr.sin_addr.s_addr = inet_addr(SERVER_ADRESS);
    if (connect(sock, (struct sockaddr *)&addr, sizeof(addr)) < 0)
    {
        perror("connect");
        exit(2);
    }

    char str[MESSAGE_MEMORY];//переменная буфер
    //
    if ((fp = fopen(argv[1], "r")) == NULL)
    {
        printf("Cannot open file.\n");
        exit(1);
    }

    send(sock, argv[1], sizeof(str), 0);
    recv(sock, buf, sizeof(str), 0);
    while (!feof(fp))
    {
        if (fgets(str, MESSAGE_MEMORY, fp)){
            char buf[sizeof(str)];

        send(sock, str, sizeof(str), 0);
        recv(sock, buf, sizeof(str), 0);
        }
    }
    
    printf("Успешно\n");
    fclose(fp);

    close(sock);
    return 0;
}