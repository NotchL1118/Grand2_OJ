#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int N = 2*1e6 + 10;


int n,q;
ll s[N];

int main()
{
    scanf("%d%d",&n,&q);
    for(int i = 1; i <= n; i ++ )
    {
        cin >> s[i];
        s[i] += s[i-1];
    }
    while(q--)
    {
        ll t;
        cin >> t;

        int l = 1, r = n;
        while(l < r)
        {
            int mid = (l+r)>>1;
            if(s[mid] >= t) r = mid;
            else l = mid + 1;
        }
        printf("%d ",l); //看清题目，输出一行，操了
    }
    
    return 0;
}