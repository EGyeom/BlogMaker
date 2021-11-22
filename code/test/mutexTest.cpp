#include <iostream>
#include <pthread.h>
#include <mutex>
#include <unistd.h>

class mutexChecker{
    public:
    static std::mutex m;
    static int size;
    static int getSize();
    static void* sizeUpdate(void *);
    static void* test(void* );
    pthread_t pthread[2];

    mutexChecker();
    ~mutexChecker();
};
int mutexChecker::size = 0;
std::mutex mutexChecker::m;
mutexChecker::mutexChecker()
{
    int result = 0;
    result = pthread_create(&pthread[0], NULL, sizeUpdate, (void*)this);

    result = pthread_create(&pthread[1], NULL, test, (void*)this);

    int status =0;

    pthread_join(pthread[0], (void**)&status);
    pthread_join(pthread[1], (void**)&status);
}

int mutexChecker::getSize()
{
    m.lock();
    // std::cout <<"get Size :" << size << "\n";
    m.unlock();
    return size;
}

void* mutexChecker::sizeUpdate(void *pthis)
{
    m.lock();
    // std::cout <<"sizeUpadte" << size << "\n";
    while(size <=30)
    {
        usleep(500000);
        // std::cout << size << "\n";
        size++;
    }
    m.unlock();
}

void* mutexChecker::test(void* pthis)
{
    while(1)
    {
        sleep(1);
        getSize();
    }
}


int main()
{
    mutexChecker * mutex_ = new mutexChecker();

}