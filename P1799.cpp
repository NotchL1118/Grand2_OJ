//学会用multiset,可以在O(logN)的时间复杂度内查找最小值，首位就是最小值，末尾最大值
#include <iostream>
#include <cstring>
#include <algorithm>
#include <set>
using namespace std;
typedef long long ll;
const int N =1e6+10;
struct Chocklate
{
    ll chang;
    ll kuan;
    friend bool operator< (const Chocklate& n1, const Chocklate& n2)
    {
        return n1.kuan < n2.kuan;
    }
};

int n,m;
Chocklate cookie[N];
int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m;
    multiset<Chocklate> s;
    for(int i = 0; i < n; i ++ )
    {
        ll a,b;
        cin >> a >> b;
        cookie[i].chang = max(a,b);
        cookie[i].kuan = min(a,b);
        s.insert(cookie[i]);
    } 
    ll ans = 0;
    while(m--)
    {
        auto it = s.end();
        it --;
        ll c = it->chang;
        ll k = it->kuan;
        ans += k*k;
        c -=k;
        s.erase(it);
        Chocklate t;
        t.chang = max(c,k);
        t.kuan = min(c,k);
        s.insert(t);
    }
    cout << ans;
    return 0;
}