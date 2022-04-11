//两个二分，分别求出 <=x 的最大值 和 > x 的最小值 然后对比一下两个哪个离x最近就是答案
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

const int N = 1e5+10;

int n,m;
int a[N];

int main()
{
    cin >> n;
    for(int i = 0; i < n; i ++ )
        scanf("%d",&a[i]);
    cin >> m;
    while(m--)
    {
        int x;
        scanf("%d",&x);
        int l = 0, r = n-1;
        while(l < r)
        {
            int mid = (l + r + 1) >> 1;
            if(a[mid] <= x) l = mid;
            else r= mid - 1;
        }
        int t = l;
        r = n -1;
        while(l < r)
        {
            int mid = (l + r) >> 1;
            if(a[mid] > x) r = mid;
            else l = mid + 1;
        }
        if(fabs(a[t] - x) > fabs(a[l] - x) )cout << a[l] << endl;
        else cout << a[t] << endl;

    }

    return 0;
}