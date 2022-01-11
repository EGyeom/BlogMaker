#include <iostream>
#include <cstdio>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <string>
#include <unistd.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <regex>

#define _WIRELESS_DEVICE_INFO_H_

#define WLD_DEVICE_LIST_MAX  (10)
#define WLD_DEVICE_ID_LEN    (18)
#define WLD_DEVICE_NAME_LEN  (32*3+2) //BMS_MAX_DEV_NAME_LEN  ((32 * 3) + 2)//32 unicode char + terminator //ischo 20181019,utf-8 3byte
#define WLD_BT_ADDRESS_LEN   (18)
#define WLD_MAC_ADDRESS_LEN  (18)

#define WIRELESS_DEV_LIST_FILE "/backup/save/BlogMaker/code/test/wireless_dev_list.dat"

//current WLDeviceInfo Version
#define WLD_INFO_VERSION_MAJOR 1
#define WLD_INFO_VERSION_MINOR 0


typedef char AAPhoneSerial[100];
typedef char AAPhoneMac[54];
typedef unsigned char HUBTMac[6];
typedef struct{
    int32_t totalCount;
    int32_t currentPosition;
    int32_t mStatus;
    AAPhoneSerial knownPhoneList[100];
    uint16_t vendorId; //DealerMode
    AAPhoneMac phoneMac;
    HUBTMac huBTMac;
    //std::string phoneMac;
} AAPhoneListData;


typedef enum
{
    WLD_Unknown  = 0x0,
    WLD_AA       = 0x1,
    WLD_CP       = 0x2
} WLDeviceType;

typedef enum
{
    WLD_STATE_NONE             = 0x0,
    WLD_STATE_NOT_USE_PP       = 0x1,
    WLD_STATE_USE_PP           = 0x2
} WLDeviceState;

typedef struct
{
    char WLDBtAddr[WLD_BT_ADDRESS_LEN];  //key
    char WLDevID[WLD_DEVICE_ID_LEN];
    char WLDevName[WLD_DEVICE_NAME_LEN];
    char WLDMacAddr[WLD_MAC_ADDRESS_LEN];
    WLDeviceType WLDType = WLD_Unknown; //191224 mobis chansub, fix qac issue
    bool WLDAutoConnection;
    bool WLDAddedByOOB;
    int8_t WLDLastConnection;//AUDD20V-50571
    int8_t WLDevState;//AUDD20V-66281 :carplay enable/disable on iPhone
    int8_t resolved;//AUDD20V-50571
} WLDeviceInfo;

typedef struct
{
    bool inUse;
    WLDeviceInfo WLDInfo;
    int WLDConnectState=0;
    bool WLDReady;
} WLDevice;

typedef struct
{
    WLDevice WLDevices[WLD_DEVICE_LIST_MAX];
    int devCnt=0;   //191224 mobis chansub, fix qac issue
} WLDeviceList;

//OLDVersion structure
//Version 0.0
typedef struct
{
    char WLDBtAddr[WLD_BT_ADDRESS_LEN];  //key
    char WLDevID[WLD_DEVICE_ID_LEN];
    char WLDevName[WLD_DEVICE_NAME_LEN];
    char WLDMacAddr[WLD_MAC_ADDRESS_LEN];
    WLDeviceType WLDType = WLD_Unknown; //191224 mobis chansub, fix qac issue
    bool WLDAutoConnection;
    bool WLDAddedByOOB;
} V_0_0_WLDeviceInfo;
//Version 0.0

 WLDeviceList mWPDevList;
 WLDeviceList testList;
void saveDevInfoFile(const char * path)
{
    int32_t fd;
    fd = open(path,O_RDWR|O_CREAT);
    if(fd < 0 ){
        printf("file open error\n");
        return;
    }
    memset(&(mWPDevList), 0, sizeof(WLDeviceList));
    strncpy(mWPDevList.WLDevices[0].WLDInfo.WLDevID,"hello1", strlen("hello1"));
    strncpy(mWPDevList.WLDevices[0].WLDInfo.WLDevName,"hello1", strlen("hello1"));
    strncpy(mWPDevList.WLDevices[0].WLDInfo.WLDBtAddr,"hello1", strlen("hello1"));
    mWPDevList.WLDevices[0].WLDInfo.WLDType                 = WLD_Unknown;
    mWPDevList.WLDevices[0].WLDInfo.WLDAutoConnection       = false;
    mWPDevList.WLDevices[0].WLDInfo.WLDLastConnection       = true;

    strncpy(mWPDevList.WLDevices[1].WLDInfo.WLDevID,"hello2", strlen("hello1"));
    strncpy(mWPDevList.WLDevices[1].WLDInfo.WLDevName,"hello2", strlen("hello1"));
    strncpy(mWPDevList.WLDevices[1].WLDInfo.WLDBtAddr,"hello2", strlen("hello1"));
    mWPDevList.WLDevices[1].WLDInfo.WLDType                 = WLD_AA;
    mWPDevList.WLDevices[1].WLDInfo.WLDAutoConnection       = true;
    mWPDevList.WLDevices[1].WLDInfo.WLDLastConnection       = false;

    strncpy(mWPDevList.WLDevices[2].WLDInfo.WLDevID,"hello3", strlen("hello1"));
    strncpy(mWPDevList.WLDevices[2].WLDInfo.WLDevName,"hello3", strlen("hello1"));
    strncpy(mWPDevList.WLDevices[2].WLDInfo.WLDBtAddr,"hello3", strlen("hello1"));
    mWPDevList.WLDevices[2].WLDInfo.WLDType                 = WLD_CP;
    mWPDevList.WLDevices[2].WLDInfo.WLDAutoConnection       = false;
    mWPDevList.WLDevices[2].WLDInfo.WLDLastConnection       = false;

    uint8_t major = WLD_INFO_VERSION_MAJOR;
    uint8_t minor = WLD_INFO_VERSION_MINOR;
    write(fd, &major, sizeof(uint8_t));
    write(fd, &minor, sizeof(uint8_t));
    u_int8_t tempCheckSum = 0xFF;
    for(size_t i=0; i < WLD_DEVICE_LIST_MAX; i++){
        printf("\n");
        const char * ptr = (char*)&mWPDevList.WLDevices[i];
        printf("         device id - %s\n", mWPDevList.WLDevices[i].WLDInfo.WLDevID);
        printf("         device name - %s\n", mWPDevList.WLDevices[i].WLDInfo.WLDevName);
        printf("         device bt - %s\n", mWPDevList.WLDevices[i].WLDInfo.WLDBtAddr);
        printf("         device type - %d\n", mWPDevList.WLDevices[i].WLDInfo.WLDType);
        printf("         device auto - %d\n", mWPDevList.WLDevices[i].WLDInfo.WLDAutoConnection);
        printf("         device last - %d\n", mWPDevList.WLDevices[i].WLDInfo.WLDLastConnection);
        printf("         device state - %d\n", mWPDevList.WLDevices[i].WLDInfo.WLDevState);
        // printf("----checksum----\n");
        for(int j =0; j < sizeof(mWPDevList.WLDevices[i]); j++)
        {
            // printf("%d ", *(ptr+j));
            tempCheckSum += (uint8_t)*(ptr+j);
        }
        // if(i == WLD_DEVICE_LIST_MAX -1)
        // {
        //     mWPDevList.WLDevices[WLD_DEVICE_LIST_MAX -1].WLDInfo.WLDType = (WLDeviceType)tempCheckSum;
        // }
        write(fd, &(mWPDevList.WLDevices[i].WLDInfo), sizeof(WLDeviceInfo));
        printf("\n");
    }
    // printf("%x\n",qwerty);
    printf("%x\n",tempCheckSum);
    // tempCheckSum &= 0xFF;
    printf("%x\n",tempCheckSum);
    u_int8_t temp = ~tempCheckSum;
    printf("%x\n", temp);
    printf("%x\n", (temp+tempCheckSum));
    write(fd, &tempCheckSum, sizeof(int));
    // ptr = "hello1";
    // for(int i =0; i < sizeof("hello1"); i++)
    // {
    //     printf("%d ", *(ptr+i));
    // }
    
    // printf("tempCheckSum : %d\n", mWPDevList.WLDevices[WLD_DEVICE_LIST_MAX -1].WLDInfo.WLDType);
    close(fd);
    system("sync");
}

void loadDevicesFromFile(const char * path)
{
    int mWLDInfoListMaxSize = sizeof(WLDeviceInfo) * WLD_DEVICE_LIST_MAX;
    if(access(WIRELESS_DEV_LIST_FILE,0) != 0) //check file exist or not
    {
        saveDevInfoFile(path);//for create file
        return;
    }

    size_t oldsize = sizeof(V_0_0_WLDeviceInfo)*WLD_DEVICE_LIST_MAX;
    struct stat st = {};
    stat(WIRELESS_DEV_LIST_FILE, &st);
    size_t filesize = st.st_size;
    
    int32_t fd = open(path,O_RDONLY);
    if(fd <0){
        return;
    }

    uint8_t major = 0;
    uint8_t minor = 0;
    read(fd, &major,sizeof(uint8_t));
    read(fd, &minor,sizeof(uint8_t));
    
    WLDeviceInfo buff[WLD_DEVICE_LIST_MAX];
    memset(buff, 0, mWLDInfoListMaxSize);

    read(fd, buff,mWLDInfoListMaxSize);

    int tempCheckSum = 0;
    for(int i =0; i < WLD_DEVICE_LIST_MAX-1; i++)
    {
        char * ptr = (char*)&buff[i];
        for(int j =0; j < sizeof(WLDeviceInfo); j++)
        {
            tempCheckSum += (int)*(ptr+j);
        }
    }
    int savedCheckSum = 0;
    read(fd,&savedCheckSum, sizeof(int));
    printf("checksum = %d \t\t readvalue = %d \n", tempCheckSum,savedCheckSum);
    close(fd);

    if(savedCheckSum == tempCheckSum)
    {
        for(size_t i=0; i < WLD_DEVICE_LIST_MAX-1; i++)
        {
            printf("\n");
            memcpy(&(testList.WLDevices[i].WLDInfo), &(buff[i]), sizeof(WLDeviceInfo));
            printf("         device id - %s\n", testList.WLDevices[i].WLDInfo.WLDevID);
            printf("         device name - %s\n", testList.WLDevices[i].WLDInfo.WLDevName);
            printf("         device bt - %s\n", testList.WLDevices[i].WLDInfo.WLDBtAddr);
            printf("         device mac - %s\n", testList.WLDevices[i].WLDInfo.WLDMacAddr);
            printf("         device type - %d\n", testList.WLDevices[i].WLDInfo.WLDType);
            printf("         device auto - %d\n", testList.WLDevices[i].WLDInfo.WLDAutoConnection);
            printf("         device last - %d\n", testList.WLDevices[i].WLDInfo.WLDLastConnection);
            printf("         device state - %d\n", testList.WLDevices[i].WLDInfo.WLDevState);
            printf("         device OOB - %d\n", testList.WLDevices[i].WLDInfo.WLDAddedByOOB);
            testList.devCnt++;
        }
    }
    else printf("checkSum ERROR !! \n");

}

bool mmMapOpen()
{
    int  mMMapSize = sizeof(AAPhoneListData)+1;
    void* shBuffer = NULL;
    int retval = 0;
    int fd = -1; //S_IRUSR|S_IWUSR
    bool fileCreated = false;
    fd = open("/backup/save/BlogMaker/code/test/aaPhoneList.txt", O_RDWR); //S_IRUSR|S_IWUSR
    printf("fd1 : %d\n", fd);
    if (fd < 0){ //ENOENT not exist
        fd = open("/backup/save/BlogMaker/code/test/aaPhoneList.txt", O_RDWR|O_CREAT);
        printf("fd2 : %d\n", fd);
        if (fd < 0 ){ //create
            printf("AndroidAuto phone list file creation error!!!");
            return false;
        }
        fileCreated = true;
    }
    struct stat finfo = {};//CodeSonar

    memset(&finfo, 0, sizeof(struct stat));
    retval = fstat(fd, &finfo);
    ftruncate(fd, mMMapSize);
    shBuffer =/*  (AAPhoneListData*) */mmap(nullptr, mMMapSize, PROT_READ|PROT_WRITE, MAP_SHARED, fd, 0);
    if(shBuffer != NULL)
    {
        *((char*)shBuffer+mMMapSize-1) = 0x11;
        ((AAPhoneListData*)shBuffer)->totalCount = 10;
        ((AAPhoneListData*)shBuffer)->currentPosition = 5;
        ((AAPhoneListData*)shBuffer)->mStatus =12;
        ((AAPhoneListData*)shBuffer)->vendorId = 15; //DealerMod
        memcpy(((AAPhoneListData*)shBuffer)->huBTMac, "hell0o\0", 6);
        memcpy(((AAPhoneListData*)shBuffer)->knownPhoneList, "hell0o\0", 6);
        memcpy(((AAPhoneListData*)shBuffer)->knownPhoneList+1, "hell1o\0", 6);
        strncpy(((AAPhoneListData*)shBuffer)->phoneMac,"-", 2);
    }
    // memcpy(shBuffer->huBTMac, "hell0o\0", 6);
    // if (fileCreated == true){
    //     shBuffer->totalCount = 0;
    //     shBuffer->currentPosition = 0;
    //     shBuffer->vendorId = 0;
    //     strncpy(shBuffer->phoneMac,"-", 2);
    // }
    msync(shBuffer, mMMapSize, MS_SYNC);

    close(fd);
    munmap(shBuffer, mMMapSize);
    shBuffer = NULL;

    fd = open("aaPhoneList.txt", O_RDWR|O_CREAT);

    if (fd < 0){ //ENOENT not exist
        fd = open("aaPhoneList.txt", O_RDWR|O_CREAT);
        if (fd < 0 ){ //create
            printf("2AndroidAuto phone list file creation error!!!");
            return false;
        }
    }
    finfo = {};//CodeSonar

    memset(&finfo, 0, sizeof(struct stat));
    retval = fstat(fd, &finfo);
    ftruncate(fd, mMMapSize);
    shBuffer = mmap(nullptr, mMMapSize, PROT_READ|PROT_WRITE, MAP_SHARED, fd, 0);
    printf("totalCount : %d \n", ((AAPhoneListData*)shBuffer)->totalCount);
    printf("currentPosition : %d \n", ((AAPhoneListData*)shBuffer)->currentPosition);
    printf("mStatus : %d \n", ((AAPhoneListData*)shBuffer)->mStatus);
    printf("vendorId : %d \n", ((AAPhoneListData*)shBuffer)->vendorId);
    printf("huBTMac : %s \n", ((AAPhoneListData*)shBuffer)->huBTMac);
    printf("knownPhoneList : %s \n", ((AAPhoneListData*)shBuffer)->knownPhoneList);
    printf("knownPhoneList : %s \n", ((AAPhoneListData*)shBuffer)->knownPhoneList+1);
    printf("phoneMac : %s \n", ((AAPhoneListData*)shBuffer)->phoneMac);
    printf("checkSum : %x \n", *((char*)shBuffer + mMMapSize-1));
    return 0;
}

int main()
{
    printf("---------------WRITE-----------------\n");
    // saveDevInfoFile(WIRELESS_DEV_LIST_FILE);
    printf("%d\n", mmMapOpen());
    printf("---------------READ-----------------\n");
    // loadDevicesFromFile();
    std::vector<std::string> file_names = {"aaPhoneList.mm","wireless_dev_list.dat","aaPhoneList"};
    
    for(auto file_name : file_names)
    {
        int typeIndex = file_name.find_last_of('.');
        std::cout << typeIndex <<"\n";
        if(typeIndex == -1) continue;
        if(file_name.substr(typeIndex+1) == "mm")
        {
            std::cout <<"mm file" << "\n";
        }
        else if(file_name.substr(typeIndex+1) == "dat")
        {
            std::cout <<"dat file" << "\n";
        }
    }
}
//     struct Data {
//         int num;
//         char name[100];
//     };

//     Data _data[2];
//     _data[1] = 10;
// }