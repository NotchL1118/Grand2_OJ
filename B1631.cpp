//牛牛派对，floyd会爆内存，只能用单源汇最短路，然后算一下每个点到x的最短距离和x到每个点的最短距离
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

const int N = 1010,M = 1e5 +10;
typedef pair<int,int> PII;

int n,m,x;
int h[N],e[M],w[M],ne[M],idx;
int res = -1;
int dist[N];


void add(int a, int b, int c)
{
    e[idx] = b, w[idx] = c,ne[idx] = h[a], h[a] = idx++;
}

int dijkstra(int start, int end)
{
    bool st[N] = {false};
    priority_queue<PII,vector<PII>,greater<PII>> heap;

    memset(dist,0x3f,sizeof dist);
    dist[start] = 0;
    heap.push({0,start});

    while(heap.size())
    {   
        auto t = heap.top();
        heap.pop();

        int ver = t.second,distance = t.first;

        if(st[ver]) continue;
        st[ver] = true;

        for(int i = h[ver]; i != -1; i = ne[i])
        {
            int j = e[i];
            if(dist[ver]+ w[i] < dist[j])
            {
                dist[j] = dist[ver] + w[i]; //NMD，w[i]不能记错,调试了半小时
                heap.push({dist[j],j});
            }
        }
    }
    return dist[end];
}
int main()
{
    cin >> n >> m >> x;
    memset(h,-1,sizeof h);
    for(int i = 0; i < m; i ++ )
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        add(a,b,c);
    }

    for(int i = 1; i <= n; i ++ )
    {
        if(i == x) continue;
        int tmp = dijkstra(i,x) + dijkstra(x,i);
        res = max(res,tmp);
    }
    
    cout << res << endl;
    return 0;
}