#include <iostream>
#include <string>
#include <stdlib.h>
#include <string.h>
const char* APP_AA_MUSIC_AUDIO_CLIENT_ID            = "com.hkmc.linux.applications.aa_music";

void function(std::string str)
{
    //
}

int main()
{
    // function(APP_AA_MUSIC_AUDIO_CLIENT_ID);
    // int num = 10;
    // int * i_ptr = &num;
    // void *t_conn = static_cast<void *>(i_ptr);
    // if(t_conn == nullptr)
    // {
    //     std::cout << "true" << "\n";
    // }
    // else std::cout << "false" <<"\n";

    const char * temp = "안녕하세요";
    const char * cstr = temp;
    printf("%lu\n", strlen(temp));
    for(int i =0; i < strlen(temp); i++)
    {
        int c1,c2,c3;
        c1 = 236;
        c2 = 149;
        c3 = 136;
        printf("%c%c%c\n", c1,c2,c3);
        printf("%c %u %u\n", (u_int8_t)*(cstr+i), (u_int8_t)*(cstr+i),*(cstr+i));
        printf("%c%c%c\n", *(cstr+i), *(cstr+i+1),*(cstr+i+2));
    }
}