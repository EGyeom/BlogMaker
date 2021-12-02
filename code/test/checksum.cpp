#include <iostream>
#include <cstdio>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

#define _WIRELESS_DEVICE_INFO_H_

#define WLD_DEVICE_LIST_MAX  (10 + 1)
#define WLD_DEVICE_ID_LEN    (18)
#define WLD_DEVICE_NAME_LEN  (32*3+2) //BMS_MAX_DEV_NAME_LEN  ((32 * 3) + 2)//32 unicode char + terminator //ischo 20181019,utf-8 3byte
#define WLD_BT_ADDRESS_LEN   (18)
#define WLD_MAC_ADDRESS_LEN  (18)

#define WIRELESS_DEV_LIST_FILE "/backup/save/BlogMaker/code/test/wireless_dev_list.dat"

//current WLDeviceInfo Version
#define WLD_INFO_VERSION_MAJOR 1
#define WLD_INFO_VERSION_MINOR 0

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
void saveDevInfoFile()
{
    int32_t fd;
    fd = open(WIRELESS_DEV_LIST_FILE,O_RDWR|O_CREAT, S_IRGRP|S_IWUSR);
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
    int tempCheckSum = 0;
    printf("%d\n", sizeof(WLDeviceInfo));
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
            tempCheckSum += (int)*(ptr+j);
        }
        if(i == WLD_DEVICE_LIST_MAX -1)
        {
            mWPDevList.WLDevices[WLD_DEVICE_LIST_MAX -1].WLDInfo.WLDType = (WLDeviceType)tempCheckSum;
        }
        write(fd, &(mWPDevList.WLDevices[i].WLDInfo), sizeof(WLDeviceInfo));
        printf("\n");
    }

    // ptr = "hello1";
    // for(int i =0; i < sizeof("hello1"); i++)
    // {
    //     printf("%d ", *(ptr+i));
    // }
    
    printf("tempCheckSum : %d\n", mWPDevList.WLDevices[WLD_DEVICE_LIST_MAX -1].WLDInfo.WLDType);
    close(fd);
    system("sync");
}

void loadDevicesFromFile()
{
    int mWLDInfoListMaxSize = sizeof(WLDeviceInfo) * WLD_DEVICE_LIST_MAX;
    if(access(WIRELESS_DEV_LIST_FILE,0) != 0) //check file exist or not
    {
        saveDevInfoFile();//for create file
        return;
    }

    size_t oldsize = sizeof(V_0_0_WLDeviceInfo)*WLD_DEVICE_LIST_MAX;
    struct stat st = {};
    stat(WIRELESS_DEV_LIST_FILE, &st);
    size_t filesize = st.st_size;
    
    int32_t fd = open(WIRELESS_DEV_LIST_FILE,O_RDONLY);
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
    printf("checksum = %d \t\t readvalue = %d \n", tempCheckSum, buff[WLD_DEVICE_LIST_MAX -1].WLDType);
    close(fd);

    if(buff[WLD_DEVICE_LIST_MAX -1].WLDType == tempCheckSum)
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


int main()
{
    printf("---------------WRITE-----------------\n");
    saveDevInfoFile();

    printf("---------------READ-----------------\n");
    loadDevicesFromFile();
}