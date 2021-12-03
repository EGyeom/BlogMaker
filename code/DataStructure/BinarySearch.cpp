#include <cstdio>
#include <algorithm>

int BinarySearch(std::vector<int> arr, int key)
{
    std::sort(arr.begin(), arr.end());

    int left = 0;
    int right = arr.size();

    while(left <= right)
    {
        int middle = (left+right)/2;
        if(arr[middle] < key)
        {
            left = middle +1;
        }
        else if(arr[middle] > key)
        {
            right = middle -1;
        }
        else
        {
            return middle;
        }
    }
    return -1;
}

int main()
{
    std::vector<int> v = {3,5,9,7,10,2};

    int key = 9;

    int index = BinarySearch(v,key);

    if(index == -1)
    {
        printf("num : %d is not in array\n", key);
    }
    else printf("num : %d find ! index = %d\n", key, index);
}