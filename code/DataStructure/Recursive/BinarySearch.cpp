#include <cstdio>
#include <algorithm>

int BinarySearch(std::vector<int> arr, int key)
{

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

int BinarySearch(std::vector<int>& arr, int left, int right,int key)
{
    if(left > right) return -1;

    int middle = (left + right)/2;
    
    if(key == arr[middle])
    {
        return middle;
    }
    else if(key < arr[middle])
    {
        return BinarySearch(arr, left, middle-1, key);
    }
    else if(key > arr[middle])
    {
        return BinarySearch(arr, left+1, right, key);
    }

}

int main()
{
    std::vector<int> v = {3,5,9,7,10,2};
    std::sort(v.begin(), v.end());

    int key = 9;
    int left = 0;
    int right = v.size() -1 ;
    int index = BinarySearch(v,key);
    int indexbyReCursive = BinarySearch(v,left,right,key);

    if(index == -1)
    {
        printf("num : %d is not in array\n", key);
    }
    else printf("num : %d find ! index = %d\t indexbyReCursive = %d\n", key, index, indexbyReCursive);
}