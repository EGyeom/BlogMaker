#include <bits/stdc++.h>
int arr[26];
int main()
{
    std::string input = "aaaaaaaaaaaabcaaaaa";
    std::unordered_map<char,int> m = {};
    std::unordered_map<int,std::vector<char>> ans;
    if(input.empty()) printf("input is empty");
/* 
    int max = 1;
    for(auto c : input)
    {
        if(m.find(c) != m.end())
        {
            m[c]++;
            if(max < m[c]) max = m[c];
        } 
        else m[c] = 1;
    }

    for(int i =0; i < 26; i++)
    {
        auto iter = m.find('a' + i);
        if(iter == m.end()) continue;
        ans[iter->second].push_back(iter->first);
    }

    for(int i =0; i <= max; i++)
    {
        auto iter = ans.find(i);
        if(iter == ans.end()) continue;
        for(auto c : iter->second)
        {
            printf("%c : %d\n", c, i);
        }
    } */
    std::vector<std::pair<int,int>> v;
    
    for(auto c : input)
    {
        arr[c - 'a']++;
    }

    for(int i =0; i < 26; i++)
    {
        if(arr[i] == 0) continue;
        v.push_back({i,arr[i]});
    }

    int vSize = v.size();
    for(int i =0; i < vSize-1; i++)
    {
        int minIndex = i;
        for(int j =1; j < vSize; j++)
        {
            if(v[minIndex].second > v[j].second)
            {
                minIndex = j;
            }
        }
        if(i == minIndex) continue;
        // int first = v[i].first;
        // int second = v[i].second;
        // v[i].first = v[minIndex].first;
        // v[i].second = v[minIndex].second;
        // v[minIndex].first = first;
        // v[minIndex].second = second;
        std::swap(v[i], v[minIndex]);
    }
}