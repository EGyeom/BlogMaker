/* #include <iostream>
#include <cstdio>

class CarPlayConstants
{
public:
	static const int CARPLAY_SCREEN_WIDTH		= 800;
	static const int CARPLAY_SCREEN_HEIGHT		= 480;

	static const int VERSION_MAXLEN 			= 100;
	static const int ID_MAXLEN 					= 100;
	static const int NAME_MAXLEN 				= 100;
	static const int MODEL_MAXLEN 				= 50;
	static const int MANUFACTURE_MAXLEN			= 50;
	static const int SERIAL_MAXLEN				= 50;
	static const int BT_MACADDR_MAXLEN 			= 50;
	static const int UUID_MAXLEN				= 100;			// If need to change this value, check connectivity-handler-library header. Same value is exist in ch-lib header.
	static const int iPHONE_NAME_MAXLEN			= 255;			// If need to change this value, check connectivity-handler-library header. Same value is exist in ch-lib header.
	static const int iPHONE_LISTMAX				= 100;			// If need to change this value, check connectivity-handler-library header. Same value is exist in ch-lib header.
	static const int DEALERMODE_TEXTLEN			= 200;			// If need to change this value, check connectivity-handler-library header. Same value is exist in ch-lib header.

	class Call
	{
		public :

		static const int MULTICALL_NUM_MAX	= 5;
		static const int ABANDON_WAIT_MS	= 120;

		enum BtCall
		{
			BTCALL_NONE,
			BTCALL_CONTROLLER,
			BTCALL_2NDPHONE,
		};


		static const int REMOTEID_MAXLEN		= 256;
		static const int DISPLAYNAME_MAXLEN		= 256;
	};
};

typedef char PhoneDeviceID[CarPlayConstants::UUID_MAXLEN];

typedef struct _CallInfo
{
	char			callUUID[CarPlayConstants::Call::DISPLAYNAME_MAXLEN];
	char			diaplayName[CarPlayConstants::Call::DISPLAYNAME_MAXLEN];
	char			callNumber[CarPlayConstants::Call::DISPLAYNAME_MAXLEN];
	long long		timestamp;
	int			callStatus;
	int			conferenced;

} CallInfoDB;

typedef struct _PhoneListDataMap
{

	int			knownPhoneListCount; // 4
	PhoneDeviceID	knownPhoneList[CarPlayConstants::iPHONE_LISTMAX]; // 10000
	bool			noNeedPopup[CarPlayConstants::iPHONE_LISTMAX]; // 100
	char			connDevice_phoneModel[CarPlayConstants::DEALERMODE_TEXTLEN]; // 200
	char			connDevice_osBuildVer[CarPlayConstants::DEALERMODE_TEXTLEN]; // 200
    bool    		isMultiCall; // 1
	// CallInfoDB		callInfos[CarPlayConstants::Call::MULTICALL_NUM_MAX]; //784 * 5 = 3920
	char			cpConnectedPhoneBTAddr[6]; // 6 -> 8
	char			wireConnectedPhone[CarPlayConstants::UUID_MAXLEN];////AUDD20V-53481 // 100
	bool			disableBT;  // 1
	bool			cpStarted; // 3

} PhoneListDataMap;


int main()
{
    printf("%d\n", sizeof(CallInfoDB));
    printf("%d\n", sizeof(PhoneListDataMap));
} */


#include <iostream>
#include <map>
#include <string.h>
#include <cstdio>

using namespace std;
#define ALOG(...) fprintf(stderr,"[%s] :\t",__func__), fprintf(stderr, __VA_ARGS__), fprintf(stderr, "\n");

template<class Ret, class Arg>
class Functor{
public:

	Ret operator()(Arg arg)
	{
		cout << arg << "\n";
		return Ret();
	}
};
const char * func3(const char* arg)
{
	printf("func 2 %s\n %x\t %x\n", arg, *arg, arg);
	const char* pass = arg;
	return pass;
}

const char * func2(const char* arg)
{
	printf("func 2 %s\n %x\t %x\n", arg, *arg, arg);
	const char* pass = arg;
	return func3(pass);
}

const char * func1(const char* arg)
{
	printf("func 1 %s\n %x\t %x\n", arg, *arg, arg);
	const char* pass = arg;
	return func2(pass);
}

int getMaxStringPosition(const uint8_t* unicodeString, int maxLength)
{
    int ret = maxLength;
    int maxLastPoistion = maxLength -4 -1;//unicode(-4),last(-1)

    for(int i = 0; i < maxLastPoistion; i++)
    {
        uint8_t c = unicodeString[i];
        if      (c<=127) {i+=0;}
        else if ((c & 0xE0) == 0xC0) {i+=1;}
        else if ((c & 0xF0) == 0xE0) {i+=2;}
        else if ((c & 0xF8) == 0xF0) {i+=3;}
        else {
            ret = i;
            break;
            }
        ret = i+1;
    }

    // ALOGV("%s :  maxLength:%d, strlen:%d \n",__FUNCTION__,maxLength, ret);

    return ret;
}

int IntRetuen(uint32_t num)
{
	return num;
}

int main()
{
/* 	// Functor<void,string> f;
	// f("Hello");
	// Functor<void,string>()("Hello");

	// map<int,int> m;
	// for(int i =0; i < 10; i++)
	// {
	// 	m.insert({i, i*10});
	// }

	// for(int i =0; i < 10; i++)
	// {
	// 	printf("%d : %d\n", i, m[i]);
	// }
	const char* input = "hello world";
	// void * test = (void*)const_cast<char *>(input);
	// char str[20];
	// string testStr = input;
	// strncpy(str,input,20);
	// // printf("%s\n", (char*)test);
	// printf("%s\n",str);
	// printf("%s 123\n", testStr.c_str());
	// ALOG("%s : [%s]", str ,__FUNCTION__);
	printf("main %s\n %x\t %x\n", input, *input, input);
	const char *ret = func1(input);

	printf("main ret : %s\n %x\t %x\n", ret, *ret, ret); */

/* 	std::string input = "ῨῩῪΎῬ῭΅`ῲῳῴῶῷῸΌῺΏῼ´῾";
	char buff[256];
	memset(buff, 0 , 256);
	for(uint8_t i =0; i < input.size(); i++)
	{
		printf("%x\n", input[i]);
	}
	printf("\n");

	int len = getMaxStringPosition((const uint8_t*)input.c_str(),input.size());

	memcpy(buff, input.c_str(), (len > input.size()) ? input.size() : len);

	for(uint8_t i =0; i < strlen(buff); i++)
	{
		printf("%x\n", buff[i]);
	}
	printf("\n");

 */
	uint32_t num = 1002;
	int32_t ret = IntRetuen(num);
	// printf("%d\n", ret);
	ALOG("Hello world");
}
