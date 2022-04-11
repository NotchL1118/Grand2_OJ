#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

const int N = 10;
typedef pair<int,int> PII;
int map[N][N],res;
bool row[N],col[N],dg[N],udg[N];
bool col1[N],dg1[N],udg1[N];
vector<PII> p;
void dfs(int u)
{
    if(u == 8)
    {
        res++;
        return;
    }
    if(row[u])
    {
        dfs(u+1);
        return;
    }
    for(int j = 0; j < 8; j++ )
    {
        if(!row[u] && !col[j] && !dg[j-u+8] && !udg[j+u] && !col1[j] && !dg1[j-u+8] && !udg[j+u] )
        {
            col[j] = dg[j-u+8] = udg[j+u] = true;
            dfs(u+1);
            col[j] = dg[j-u+8] = udg[j+u] = false;
        }
    }

}

int main()
{
    for(int i = 0; i < 8; i ++)
        for(int j = 0; j < 8; j++ )
        {
            cin >> map[i][j];
            if(map[i][j] == 1)
            {
                row[i] = true;
                col[j] = col1[j] = true;
                dg[j-i+8] = dg1[j-i+8] = true;
                udg[j+i] = udg1[j+i] = true;
            }
        }

    dfs(0);
    cout << res;
    return 0;
}