/*
服了这sb题目了，最小生成树的应用，思路不难，虽然我第一时间没想到hhh，恶心的是进制转化
*/
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
typedef pair<int, int>  PII;
typedef long long ll;
const int N = 5010;

int T;
int n;
bool st[N];
int x[N],y[N];
ll g[N][N],dist[N];

void prim()
{
    memset(dist,0x3f,sizeof dist);
    memset(st,0,sizeof st);

    ll res = 0;
    for(int i = 0; i < n; i ++ )
    {
        int t = -1;
        for(int j = 0; j < n; j ++ )
            if(!st[j] && (t == -1 || dist[j] < dist[t]))
                t = j;
        
        st[t] = true;
        if(i) res = max(res,dist[t]); //不是第一次

        for(int j = 0; j < n; j ++ )
            dist[j] = min(dist[j],g[t][j]);
    }
    printf("%lld\n",res);
}

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(int i = 0; i < n; i ++ )
        {
            scanf("%d%d",&x[i],&y[i]);
        }

        memset(g,0x3f,sizeof(g));
        for(int i = 0; i < n; i ++ )
            for(int j = i+1; j < n; j ++ )
            {
                ll d1 = x[i] - x[j];
                ll d2 = y[i] - y[j];
                ll c = d1*d1 + d2*d2;
                g[i][j] = g[j][i] = c; //推荐用这个方式


                //g[i][j] = g[j][i]  = (ll)(x[i] - x[j])*(x[i] - x[j]) + (ll)(y[i] - y[j])*(y[i] - y[j]);
                //用这个方式一定要加两个ll来强制类型转化，不然(y[i] - y[j])*(y[i] - y[j])，两个int相乘就爆int了;血的教训，有些步骤不能省
            }
        prim();
    }

    return 0;
}