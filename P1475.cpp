/*
    题中的小游戏都是1分钟内完成的，所以不需要考虑时间的影响，用贪心
    1.肯定先完成罚款多的任务，所以用罚款从大到小排序
    2.排完序了，肯定罚款多的能在规定时间前完成最好，所以可以倒序开始看，把任务插在规定时序之前，用个数组维护完成了没有
*/
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 510;
struct Match
{
    int t,v;
}match[N];

bool cmp(const Match &a, const Match &b) 
{
    return a.v > b.v;
}

int m,n;
bool used[N];

int main()
{
    cin >> m >> n;
    for(int i = 1; i <= n; i ++ )
        scanf("%d",&match[i].t);
    for(int i = 1; i <= n; i ++ )
        scanf("%d",&match[i].v);

    sort(match+1,match +1 + n, cmp);

    for(int i = 1; i <= n; i ++ )
    {
        for(int j = match[i].t; j >= 1; j --) //j >= 1因为j是各个游戏的规定时间，是从1开始的
        {
            if(!used[j])
            {
                used[j] = true;
                match[i].v = 0; //这件事做了，罚款为0
                break;
            }
        }

    }
    for(int i = 1; i <= n; i ++ )
    {
        m -= match[i].v;
    }
    cout << m << endl;
    return 0;
}