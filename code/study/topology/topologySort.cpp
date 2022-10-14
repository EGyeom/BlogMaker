#include <iostream>
#include <queue>
#include <vector>
#include <stack>
using namespace std;

#define INPUTMAX 10

int input;
stack<int> st;
vector<int> isVisited(INPUTMAX,0);
vector<int> edgeInfo[INPUTMAX],inDegree(INPUTMAX,0);

void topologySort_bfs(vector<int> indegree)
{
	queue<int> q;
    
    for(int i = 1; i <= input; i++)
    {
    	if(inDegree[i] == 0)
        	q.push(i);
    }

	while(q.empty() == false)
    {   
    	int front = q.front();
        q.pop();
        cout << front << " ";
        for(int i = 0; i < edgeInfo[front].size(); i++)
        {
        	int edge = edgeInfo[front][i];
        	if(--inDegree[edge] == 0)
            	q.push(edge);
        }
    }
}

void dfs(int curr)
{
    isVisited[curr] = true;
    for(int& iter : edgeInfo[curr])
    {
        if(isVisited[iter] == false)
        {
            dfs(iter);
        }
    }
    st.push(curr);
}

void topologySort_dfs()
{    
    for(int i = 1; i <= input; i++)
    {
        if(isVisited[i] == false)
        {
            dfs(i);
        }
    }
}

int main()
{
    input = 6;
    edgeInfo[1].push_back(4);
    inDegree[4]++;
    edgeInfo[1].push_back(2);
    inDegree[2]++;
    
    edgeInfo[2].push_back(3);
    inDegree[3]++;
    
    edgeInfo[4].push_back(2);
    inDegree[2]++;
    edgeInfo[4].push_back(5);
    inDegree[5]++;
    edgeInfo[4].push_back(6);
    inDegree[6]++;
    
    edgeInfo[5].push_back(6);
    inDegree[6]++;
    
    vector<int> inde1 = inDegree;
    vector<int> inde2 = inDegree;

    topologySort_bfs(inde1);
    cout << "\n";
    topologySort_dfs();

    while(!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
}