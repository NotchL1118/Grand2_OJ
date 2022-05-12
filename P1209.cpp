//滑雪
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 110;

int n,m;
int h[N][N];
int f[N][N];

int dx[4] = {-1,0,1,0},dy[4] = {0,1,0,-1};
int dp(int i, int j)
{
    if(f[i][j] != -1) return f[i][j];

    f[i][j] = 1;
    for(int k = 0; k < 4; k ++ )
    {
        int x = i + dx[k], y = j + dy[k];
        if(x >= 1 && x <= n && y >=1 && y <= m && h[x][y] < h[i][j])
            f[i][j] = max(f[i][j],dp(x,y) + 1);
    }
    return f[i][j];
}
int main()
{
    cin >> n >> m;
    for(int i = 1; i <= n;  i++ )
        for(int j = 1; j <= m; j ++ )
            cin >> h[i][j];

    memset(f, -1, sizeof f);
    
    int res = -1;
    for(int i = 1; i <=n ; i ++ )
        for(int j = 1; j <= m; j ++ )
            res = max(res,dp(i,j));

    cout << res;
    return 0;
}