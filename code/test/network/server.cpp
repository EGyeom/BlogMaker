#include <cstdio>
#include <sys/types.h>
#include <sys/socket.h> //socket
#include <unistd.h> //write, read
#include <stdlib.h> //atoi
#include <sys/stat.h>
#include <fcntl.h> // open
#include <arpa/inet.h>
#include <string.h>

#define LOG(...) fprintf(stderr,"[%s][%d] : ",__func__, __LINE__),fprintf(stderr,__VA_ARGS__), fprintf(stderr,"\n")

int main()
{
    sockaddr_in server_addr;
    sockaddr_in client_addr;
    int serverSock;
    int clientSock;

    serverSock = socket(PF_INET,SOCK_STREAM,0);
    if(serverSock == -1)
    {
        LOG("%s", "SOCKET CREATE ERROR");
    }
    
    int serverSockSize = sizeof(server_addr);
    memset(&server_addr,0, sizeof(serverSockSize));
    memset(&client_addr,0, sizeof(client_addr));

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr("10.238.7.163");
    server_addr.sin_port = htons(5002);

    if(bind(serverSock,(sockaddr *)&server_addr,serverSockSize) == -1)
    {
        LOG("%s", "BIND ERROR");
    }
    LOG("%lld %lld", server_addr.sin_addr.s_addr, server_addr.sin_port);
    if(listen(serverSock,5) == -1)
    {
        LOG("%s", "LISTEN ERROR");
    }

    uint clientSockSize = sizeof(client_addr);

    clientSock = accept(serverSock, (sockaddr *)&clientSock, &clientSockSize);
    if(clientSock == -1)
    {
        LOG("%s", "accept Error");
    }

    write(clientSock,"HELLO CLIENT !",sizeof("HELLO CLIENT !"));
    close(clientSock);
    return 0;
}