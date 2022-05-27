/*
一开始想用迪杰斯特拉，发现超出自己能力范围了，查答案用floyd更简单，这道题需要更加理解floyd算法
而不是单纯的背模板,所以本题是Floyd变种
本题求的是 a到b的最大噪声值最小的路径上，这个最大噪声值是多少，u know?
*/
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 110;

int n,m,q;
int g[N][N];
int dis[N][N];
int cnt = 1;

int main()
{
    
    while(cin >> n >> m >> q)
    {
        memset(g,0x3f,sizeof g);
        while(m--)
        {
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c);
            g[a][b] = min(g[a][b],c);
            g[b][a] = min(g[b][a],c);
        }

        for(int k = 1; k <= n; k ++ )
            for(int i = 1; i <= n; i ++ )
                for(int j = 1; j <= n; j ++ )
                    g[i][j] = min(g[i][j],max(g[i][k],g[k][j])); //最小的那个最大噪声值
        
        cout <<"Case #" << cnt++ <<endl;

        while(q--)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            if(g[a][b] == 0x3f3f3f3f) puts("no path");
            else printf("%d\n",g[a][b]);
        }
    }

    return 0;
}