/*
一开始想到了图论，后来查到原题，是并查集和组合运算问题
一个集合代表一个稳定的药材
Cn0 + Cn1 + Cn2 + ......+ Cnn = 2^n (n个集合)
组合数公式，再减去一个什么都取，答案为 2^n -1
*/
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 1e6 + 10;
const int mod = 998244353;

int pre[N];
int n;

int find(int n)
{
    if(pre[n] != n) pre[n] = find(pre[n]);
    return pre[n]; 
}

int pow(int n)
{
    int ans = 1,base = 2;
    for(int i = 1;i <= n; i ++ )
    {
        ans = (ans * base) % mod;
    }
    return ans;
}
int main()
{
    cin >> n;
    for(int i = 1; i <= n; i ++ ) pre[i] = i;

    for(int i = 1; i <= n; i ++ )
    {
        int t;
        cin >> t;
        pre[i] = find(pre[t]); //集合合并
    }

    int cnt = 0;
    for(int i = 1; i <= n; i ++ )
        if(pre[i] == i) cnt ++;

    cout << pow(cnt)-1;
    
    return 0;
}