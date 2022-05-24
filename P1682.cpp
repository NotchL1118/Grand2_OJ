#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 2010;

int n,m;
int g[N][N];
int dist[N];
bool st[N];

int prim()
{
    int ans = -1e9;
    memset(dist,0x3f,sizeof dist);

    for(int i = 0 ; i < n; i ++ )
    {
        int t = -1;
        for(int j = 1; j <= n; j ++ )
            if(!st[j] &&( t == -1 || dist[t] > dist[j]))
                t = j;

        if(i) ans = max(ans,dist[t]);
        st[t] = true;

        for(int j = 1; j <= n; j ++ ) dist[j] = min(dist[j], g[t][j]);

    }
    return ans;
}

int main()
{
    cin >> n >> m;
    memset(g,0x3f,sizeof g);

    for(int i = 0; i < m; i ++ )
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        g[a][b] = g[b][a] = min(g[a][b],c);
    }

    int res = prim();
    cout << res << endl;
    return 0;

}