//说是背包问题，实际上是贪心问题，性价比最高的先选
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 110;
struct Coin
{
    int m;
    int v;
    double aver;

    bool operator >(Coin const & W) const
    {
        return aver > W.aver;
    }
}coin[N];

int n,m;

int main()
{
    cin >> n >> m;
    for(int i = 0 ; i < n; i ++ )
    {
        int mm,v;
        cin >> mm >> v;
        coin[i].m = mm;
        coin[i].v = v;
        coin[i].aver = 1.0 * v / mm;
    }

    sort(coin,coin + n,greater<Coin>());

    double ans = 0.0; //答案用double
    for(int i = 0; i < n; i ++ )
    {
        auto t = coin[i];
        if(m >= t.m)
        {
            m -= t.m;
            ans += (double)t.v;
        }
        else
        {
            ans += (double)m * t.aver;
            break;
        }
    }

    printf("%.2f",ans);
    return 0;
}