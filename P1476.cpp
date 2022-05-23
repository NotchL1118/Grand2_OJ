//https://www.luogu.com.cn/blog/lzf-is-your-father/solution-p1248 抄的，思路还没理解全，此题还需再看
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int N = 1010;

int n,ans[N],t[N],a[N],b[N];

struct Node
{
    int minv,wan;
}mintime[N];

bool cmp(Node A,Node B)
{
    return A.minv < B.minv;
}

int main()
{
    while(cin >> n)
    {
        for(int i = 1; i <= n; i ++ )
        {
            mintime[i].wan = i;
            cin >> a[i];
            mintime->minv = a[i];
        }

        for(int i = 1; i <= n; i ++ )
        {
            cin >> b[i];
            mintime[i].minv = min(a[i],b[i]);
        }
        sort(mintime + 1, mintime + 1 + n,cmp);

        int p = 0, q = n + 1;
        for(int i = 1; i <= n; i ++ )
            if(mintime[i].minv == a[mintime[i].wan])
                ans[++p] = mintime[i].wan;
            else
                ans[--q] = mintime[i].wan;

        for(int i = 1; i <= n; i ++ )
            t[i] = t[i-1] + a[ans[i]];//A车间单独工作的情况
        
        int sum = t[1] + b[ans[1]];
        for(int i = 2; i <= n; i ++ )
            sum = max(t[i],sum) + b[ans[i]];

        cout << sum << endl;
        memset(ans,0,sizeof ans);
        memset(a,0,sizeof a);
        memset(b,0,sizeof b);
        memset(t,0,sizeof t);

    }

    return 0;
}