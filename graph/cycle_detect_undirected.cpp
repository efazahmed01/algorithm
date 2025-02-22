#include<bits/stdc++.h>
using namespace std;


bool vis[1005];
int parent[1005];
vector<int> ad_list[1005];
bool cycle;

void bfs(int i)
{
    queue<int> q;
    q.push(i);
    vis[i] = true;

    while(!q.empty())
    {
        int p = q.front();
        q.pop();
        for(auto child: ad_list[p])
        {
            if(vis[child] && parent[p]!=child)
                cycle = true;
            if(!vis[child])
            {
                q.push(child);
                parent[child] = p;
                vis[child] = true;
            }
        }
    }
}

void dfs(int i)
{
    vis[i] = true;
    for(auto it: ad_list[i])
    {
        if(vis[it] && parent[i] != it)
            cycle = true;
        if(!vis[it])
        {
            parent[it] = i;
            dfs(it);
        }     
    }
}

int main()
{
    int n,e;
    cin >> n >> e;
    memset(vis, false, sizeof(vis));
    memset(parent, -1, sizeof(parent));
    cycle = false;
    while(e--)
    {
        int x,y;
        cin >> x >> y;
        ad_list[x].push_back(y);
        ad_list[y].push_back(x);
    }
    for(int i = 0; i < n; i++)
    {
        if(!vis[i])
            bfs(i);
                  
    }
    if(cycle)
        cout << "Cycle\n";  
    else
    cout << "No Cycle\n";  
}
