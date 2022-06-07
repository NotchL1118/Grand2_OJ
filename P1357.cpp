//简单的拓扑排序
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
const int N = 1010;

int n,m;
int h[N],e[N],ne[N],idx;
int rd[N];//入度
int cd[N];//出度
int f[N];

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}


int topsort()
{
    int ans = -1e9;
    queue<int> q;
    for(int i = 1; i <= n; i ++ )
        if(!rd[i] && cd[i])
        {
            q.push(i);
            f[i] = 1;
        }

    while(q.size())
    {
        int t = q.front();q.pop();
        if(!cd[t]) ans = max(ans,f[t]);
        for(int i = h[t]; i != -1; i = ne[i])
        {
            int j = e[i];
            f[j] = f[t] + 1;
            rd[j] --;
            if(!rd[j]) q.push(j);
        }
    }
    return ans;
}

int main()
{
    while(cin >> n >> m)
    {
        memset(h,-1,sizeof h);
        while(m--)
        {
            int a,b;
            cin >> a >> b;
            add(a,b);
            rd[b]++,cd[a]++;
        } 
        cout << topsort() << endl;
        memset(e,0,sizeof e);
        memset(ne,0,sizeof ne);
        memset(rd,0,sizeof rd);
        memset(cd,0,sizeof cd);
        idx = 0;
    }
    return 0;
}