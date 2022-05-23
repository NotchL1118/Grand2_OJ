/*
很明显的贪心，一开始想法想简单了，用齐威王的马去二分找田忌第一个更快的马
如果田忌最大的马大于国王，那么就胜场++；
如果田忌最大的马小于国王，那么就一定会输，所以用田忌最小的马输给国王最大的马；
如果田忌最大的马等于国王，那么就比较最小的马；
    1、如果田忌最小的马大于国王，那么胜场++；
    2、如果田忌最小的马小于国王，那么就输给国王；
    3、如果田忌最小的马等于国王，就用田忌最小的马对国王最大的马，如果国王最大的马大，那么财产要减200；

用指针指
*/
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 1000010;

int n;
int tj[N],king[N],res;

int main()
{
    cin >> n;
    int rt = 1,rk = 1; //右指针，指慢马
    int lt = n, lk = n; //左指针，指快马
    for(int i = 1; i <= n; i ++ )
        cin >> tj[i];
    for(int i = 1; i <= n; i ++ )
        cin >> king[i];
    sort(tj+1,tj+n+1);
    sort(king+1,king+n+1);
    for(int i = 0; i < n; i ++ )
    {
        if(tj[lt] > king[lk]) //如果田忌快马大于王快马，就比赛+200
        {
            res += 200;
            lt--;
            lk--;
        }
        else if(tj[rt] > king[rk]) //田忌快马不必王快马快，比一下最慢的马，如果田最慢马更快，就两个最慢马比赛，+200
        {
                res += 200;
                rt++;
                rk++;
        }
        else if(tj[rt] < king[lk]) //如果田忌最慢马比王最慢马慢，那就田忌最慢马和王最快马比赛，-200;
        {
            res -= 200;
            rt ++;
            lk --;
        }
                                    //不需要再特判了，其他情况是平均，输赢都一样
    }
    cout << res;
    return 0;
}