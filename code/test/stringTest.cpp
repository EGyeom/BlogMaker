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
    function(APP_AA_MUSIC_AUDIO_CLIENT_ID);
    int num = 10;
    int * i_ptr = &num;
    void *t_conn = static_cast<void *>(i_ptr);
    if(t_conn == nullptr)
    {
        std::cout << "true" << "\n";
    }
    else std::cout << "false" <<"\n";
}