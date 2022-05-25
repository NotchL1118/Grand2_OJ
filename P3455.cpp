/*
朴素迪杰斯特拉算法是O(n^2)的
本题稠密图，用邻接矩阵画图，遍历所有点，边X2，然后迪杰斯特拉一次，去最大值，最后减一下没有改变时候的值，就是答案
时间复杂度是O(n^4);不会爆
*/

#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int N = 300;

int n,m;
int dist[N];
int g[N][N];

int dijkstra()
{
    bool st[N] = {false};
    memset(dist,0x3f,sizeof dist);
    dist[1] = 0;

    for(int i = 0; i < n; i ++ )
    {
        int t = -1;

        for(int j = 1; j <= n; j ++ )
            if(!st[j] &&(t == -1 ||dist[t] > dist[j]))
                    t = j;

        st[t] = true;

        for(int j = 1; j <= n; j ++ )
            dist[j] = min(dist[j], dist[t] + g[t][j]);
        if(t == n) break;

    }

    return dist[n];
}

int main()
{
    cin >> n >> m;

    memset(g,0x3f,sizeof g);

    while(m--)
    {
        int a,b,c;
        cin >> a >> b >>c;
        g[a][b] = g[b][a] = min(g[a][b],c);

    }
    int ans = dijkstra();

    int tmp = -1e9;
    for(int i = 1; i <= n ; i ++ )
        for(int j = 1; j < i; j ++ )
        {
            if(g[i][j] != 0x3f3f3f3f)
            {
                int t = g[i][j];
                g[i][j] = g[j][i] = 2 * t;
                tmp = max(tmp,dijkstra());
                g[i][j] = g[j][i] = t;
            }
        }

    cout << tmp - ans << endl;
    return 0;
}