#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

const int N = 10;
typedef pair<int,int> PII;
char map[N][N],res[N][N];
bool st[N][N];
PII Prev[N][N];
queue<PII> q;

void bfs()
{
    q.push({0,0});
    
    int dx[4] = {-1,1,0,0}, dy[4] = {0,0,-1,1};
    while(q.size())
    {   
        auto t = q.front();
        q.pop();

        for(int i = 0; i < 4; i ++ )
        {
            int x = t.first + dx[i],y = t.second + dy[i];
            if(x >= 0 && x < 8 && y >=0 && y < 8 && map[x][y] == 'O' && !st[x][y])
            {
                Prev[x][y] = t;
                q.push({x,y});
                st[x][y] = true;
            }
        }
    }

    res[0][0] = res[7][7] = ' ';
    auto t = Prev[7][7];
    while(t.first || t.second)
    {
        res[t.first][t.second] = ' ';
        t = Prev[t.first][t.second];
    }

}

int main()
{
    for(int i = 0 ; i < 8; i ++ )
        for(int j = 0; j < 8; j ++ )
        {
            cin >>map[i][j];
            res[i][j] = map[i][j];
        }
    bfs();
    for(int i = 0 ; i < 8; i ++ )
    {
        for(int j = 0; j < 8; j ++ )
            cout << res[i][j];
        cout << endl;
    }
    return 0;
}