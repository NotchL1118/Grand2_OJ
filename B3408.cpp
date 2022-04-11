#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

const int N = 100010;
typedef pair<int,int> PII;

int n, m, s, T;
int h[N],e[N],ne[N],w[N],idx;
int dist[N];
bool st[N];

void add(int a, int b, int c)
{
    e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx++;
}

void dijkstra()
{
    memset(dist,0x3f,sizeof dist);
    dist[s] = 0;
    priority_queue<PII,vector<PII>,greater<PII>> heap; //小根堆，PII根据first排序，所以一定要距离在前，不然就会出错
    heap.push({0,s});

    while(heap.size())
    {
        auto t = heap.top();
        heap.pop();

        int ver = t.second;
        int distance = t.first;

        if(st[ver]) continue;
        st[ver] = true;

        for(int i = h[ver]; i != -1; i = ne[i])
        {
            int j = e[i];
            if(dist[j] > distance + w[i])
            {
                dist[j] = distance + w[i]; 
                heap.push({dist[j],j});
            }
        }
    }
    cout << dist[T];

}
int main()
{
    cin >> n >> m >> s >> T;

    memset(h,-1, sizeof h);

    for(int i = 0; i < m; i ++ )
    {
        int a, b , c;
        cin >> a >> b >> c;
        add(a,b,c);
        add(b,a,c);
    }

    dijkstra();
    
    return 0;
}