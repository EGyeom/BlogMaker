#include <bits/stdc++.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    struct stat st = {};
    stat("save.txt",&st);
    size_t filesize = st.st_size;
    char num_buff[256] = {0};

    int fd = open("save.txt", O_RDONLY);
    if(fd < 0) return 0;

    char * buff = new char[filesize];

    read(fd,buff,filesize);

    close(fd);

    fd = open("test.txt", O_RDWR|O_CREAT|O_TRUNC, 00777);

    for(int i =0; i < filesize-1; i++)
    {
        int num = (int)(uint8_t)*(buff+i);
        sprintf(num_buff,"%d\n",num);
        write(fd,num_buff,strlen(num_buff));
    }

    printf("%s", buff);
}