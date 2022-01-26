#include <bits/stdc++.h>

void function()
{
    // std::cout << ptr << "\n";
    const char * text = "\t\u202F\u204FWrold";
    int maxLength = 256;
    printf("%d\n", strlen("helloworld"));
    const char * wtf = "\t";
    printf("%d\n", strlen(wtf));
    int ret = maxLength;
    int maxLastPoistion = maxLength -4 -1;//unicode(-4),last(-1)
    int i;
    // printf("%x\n", (uint8_t)uni);
    for(i = 0; i < maxLastPoistion; i++)
    {
        uint8_t c = text[i];
        printf("%x ", c);
        if      ((c>=0)   && (c<=127)) {i+=0;}
        else if ((c & 0xE0) == 0xC0) {i+=1;} //2Byte
        else if ((c & 0xF0) == 0xE0) {i+=2;} //3Byte
        else if ((c & 0xF8) == 0xF0) {i+=3;} //4Byte
        else {break;}
        printf("%d\n", i);
    }

    if(i >= maxLastPoistion)
    {
        ret = i;
    }
    printf("%s : maxLength:%d, strlen:%d, i:%d \n",text,maxLength, ret,i);
    printf("\n\n\n\n\n");
    return ;
}


void function2()
{
    // std::cout << ptr << "\n";
    const char * text = "\t\u202F\u204FWrold";
    int maxLength = strlen(text);
    printf("%d\n", strlen("helloworld"));
    const char * wtf = "\t";
    printf("%d\n", strlen(wtf));
    int ret = maxLength;
    int maxLastPoistion = maxLength -4 -1;//unicode(-4),last(-1)
    // printf("%x\n", (uint8_t)uni);
    for(int i = 0; i < maxLastPoistion; i++)
    {
        uint8_t c = text[i];
        printf("%x ", c);
        if      (c<=127) {i+=0;}
        else if ((c & 0xE0) == 0xC0) {i+=1;} //2Byte
        else if ((c & 0xF0) == 0xE0) {i+=2;} //3Byte
        else if ((c & 0xF8) == 0xF0) {i+=3;} //4Byte
        else {
            ret = i;
            break;
            }
        printf("i : %d, ret :%d\n", i, ret);
        ret = i+1;
    }

    // if(i >= maxLastPoistion)
    // {
    //     ret = i;
    // }
    printf("%s : maxLength:%d, strlen:%d\n",text,maxLength, ret);

    return;
}

int main()
{
    int length1 = 1;
    int length2 = 2;
    // void * temp[2][2] = {{(void*)"helloworld1", (void*)&length1}, {(void*)"helloworld2",(void*)&length2}};
    // void * text[2] = {(void*)"helloworld1", (void*)"helloworld2"};
    // for(int i =0; i < 2; i++)
    // {
    //     printf("%d\n", *(int*)temp[i][1]);
    // }

    // uint8_t str[] = "helloworld";
    // char name[] = "helloworldName";
    // char * test = "hellojorld";
    // const char * test2 = "hello1234";
    // std::cout << typeid("hello").name() << "\n";
    // std::cout << typeid(const char*).name() <<"\n";
    // std::cout << typeid(test2).name() << "\n";
    // std::cout << name <<"\n";
    // const char * text = "\t\u202FHello\u204FWrold";
    // int maxLength = strlen(text);
    // printf("%d\n", strlen("helloworld"));
    // const char * wtf = "\t";
    // printf("%d\n", strlen(wtf));
    // int ret = maxLength;
    // int maxLastPoistion = maxLength -4 -1;//unicode(-4),last(-1)
    // int i;
    // // printf("%x\n", (uint8_t)uni);
    // for(i = 0; i < maxLastPoistion; i++)
    // {
    //     uint8_t c = text[i];
    //     printf("%x ", c);
    //     if      ((c>=0)   && (c<=127)) {i+=0;}
    //     else if ((c & 0xE0) == 0xC0) {i+=1;} //2Byte
    //     else if ((c & 0xF0) == 0xE0) {i+=2;} //3Byte
    //     else if ((c & 0xF8) == 0xF0) {i+=3;} //4Byte
    //     else {break;}
    //     printf("%d\n", i);
    // }

    // if(i >= maxLastPoistion)
    // {
    //     ret = i;
    // }
    // printf("%s : maxLength:%d, strlen:%d, i:%d \n",text,maxLength, ret,i);

    // return i;

    function();
    function2();
    // function(str);

}