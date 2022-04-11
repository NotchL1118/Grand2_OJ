#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 50,M = 20010;

int m,n;//容量 和 多少个物体
int v[N],w[N];
int f[M];

int main()
{
    while(cin >> m >> n)
    {
        for(int i = 1; i <= n ; i ++ )  cin >> v[i] >> w[i];

        for(int i = 1; i <= n; i ++ )
            for(int j = m; j >= v[i]; j -- )
             f[j] = max(f[j], f[ m - v[i]] + w[i]);
        cout << f[m] << endl;
        
        memset(v,0,sizeof v);
        memset(w,0,sizeof w);
        memset(f,0,sizeof f);
    }


    return 0;
}