#include <cstdio>
#include <sys/types.h>
#include <sys/socket.h> //socket
#include <unistd.h> //write, read
#include <stdlib.h> //atoi
#include <sys/stat.h>
#include <fcntl.h> // open
#include <arpa/inet.h>
#include <string.h>

#define LOGS(...) fprintf(stderr,"[%s] : ", "server"), fprintf(stderr,__VA_ARGS__), fprintf(stderr,"\n")
#define LOGC(...) fprintf(stderr,"[%s] : ", "client"), fprintf(stderr,__VA_ARGS__), fprintf(stderr,"\n")

int main()
{
    int serverSock;
    int str_len = 0;

    sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    char buf[256] = {0,};
    serverSock = socket(PF_INET,SOCK_STREAM,0);
    server_addr.sin_addr.s_addr = inet_addr("10.238.7.163");
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(5002);
    LOGC("%d", serverSock);
    LOGC("%lld %lld",server_addr.sin_addr.s_addr, server_addr.sin_port);
    if(connect(serverSock,(sockaddr *)&server_addr, (sizeof(server_addr)) == -1))
    {
        LOGC("%s", "Connect FAIL!");
    }
    else LOGC("%s", "Connect !");
    str_len = read(serverSock,buf,sizeof(buf) -1);
    buf[str_len] = 0;
    LOGS("%s", buf);

    close(serverSock);
    
    return 0;
}