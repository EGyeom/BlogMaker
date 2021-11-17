#include <iostream>
#include <vector>
#include <map>

void Solution(int target, std::vector<int> v)
{
    std::map<int,int> m;

    for(int i =0; i < v.size(); i++)
    {
        int temp = target - v[i];

        auto iter = m.find(temp);
        if(iter != m.end())
        {
            std::cout << iter->second << "," << i << "\n";
            return;
        }

        m.insert({v[i],i});
    }
}

int main()
{
    int target_num = 8;
    std::vector<int> v = {11,3,6,13,5};
    Solution(target_num,v);
}