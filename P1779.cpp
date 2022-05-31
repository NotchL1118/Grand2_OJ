//线性DP
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 1e5+10;

int n,m;
int p[N],x[N],f[N]; //f[i]表示到第i个弹簧最远能到哪里
int res;

int main()
{
    scanf("%d%d",&n,&m);

    for(int i=0;i<n;i++)
        scanf("%d%d",&p[i],&x[i]);

    if(p[0] > 0)
        res += p[0];
    f[0] = p[0] + x[0]; //第一个跳板能到的最远距离

    for(int i = 0; i < n; i ++ )
    {
        if(f[i] < p[i+1])
        {
            res += p[i+1] - f[i];
            f[i+1] = p[i+1] + x[i+1];
        }
        else
        {
            if(f[i] < p[i+1] + x[i+1])
            {
                f[i+1] = p[i+1] + x[i+1];
            }
            else
            {
                f[i+1] = f[i];
            }
        }
    }
    if(f[n-1] < m)
        res += m - f[n-1];

    cout << res << endl;
    return 0;
}