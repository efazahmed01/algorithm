#include<bits/stdc++.h>
using namespace std;

class Edge
{
    public:
        int a,b,c;
        Edge(int a,int b,int c)
        {
            this->a = a;
            this->b = b;
            this->c = c;
        }
};

int dis[105];
vector<Edge> edge_list;
int n,e;

void bellman_ford()
{
    for(int i = 0 ; i < n-1 ; i++)
    {
        for(auto i: edge_list)
        {
            int x,y,z;
            x = i.a;
            y = i.b;
            z = i.c;

            if(dis[x] != INT_MAX && dis[x] + z < dis[y])
            {
                dis[y] = dis[x] + z;
            }
        }
    }
}

int main()
{
    cin >> n >> e;
    for(int i = 0; i < n; i++)
    {
        dis[i] = INT_MAX;
    }
    while(e--)
    {
        int a,b,c;
        cin >> a >> b >> c;
        edge_list.push_back(Edge(a,b,c));
    }
    dis[0] = 0;
    bellman_ford();
    
    for(int i = 0; i < n; i++)
    {
        cout << i << "->" << dis[i] << endl;
    }
}
