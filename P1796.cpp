//dfs没什么好说的
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int n,m;
int res = 0;

void dfs(int x,int y)
{
    if(x > n || y > m) return ;
    if(x == n && y == m)
    {
        res ++;
        return ;
    }

    dfs(x+2,y+1);

    dfs(x+1,y+2);

}

int main()
{
    cin >> n >> m;
    dfs(1,1);
    cout << res;
    return 0;
}