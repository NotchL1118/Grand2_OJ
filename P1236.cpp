//夺取宝藏
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 1010;

int g[N][N];
int f[N][N];
int n,m;
int dx[2] = {-1,0}, dy[2] = {0,-1};
int main()
{
    while(cin >> n >> m)
    {
        for(int i = 1; i <= n ; i ++ )
            for(int j = 1; j <= m; j ++ )
            {
                cin >> g[i][j];
                for(int k = 0; k < 2; k ++ )
                {
                    int x = i + dx[k], y = j + dy[k];
                    if(x >= 1 && x <= n && y >=1 & y <= m)
                        f[i][j] = max(f[i][j],f[x][y] + g[i][j]);
                }
            }
        cout << f[n][m] << endl;
        memset(g,0,sizeof g);
        memset(f,0,sizeof f);
    }

    return 0;
}