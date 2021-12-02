#include <iostream>
#include <algorithm>
#include <string.h>
int main()
{
    char cArr[][5] = {'1','1','1','1',0, '2','2','2','2',0,'3','3','3','3',0};
    char arrayClear[5] = {};

    for(int i =0; i < 3; i++)
    {
        printf("%s\n", cArr[i]);
    }
    for ( int i =0; i < 3; i++)
    {
        std::fill_n(cArr[i], 5, 0);
    }
    for(int i =0; i < 3; i++)
    {
        printf("%s\n", cArr[i]);
        printf("%p\n", cArr[i]);
    }

    char test[5] = {'A','B','C','D',0};
    std::string key;
    key = test;
    printf("%s\n", key.c_str());
    std::transform(key.begin(),key.end(),key.begin(),::tolower);
    printf("%s\n", key.c_str());
}