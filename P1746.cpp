//模板二分，没啥好说的
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 100010;
int n,m;
int f[N];

int main()
{
    cin >> n >> m;
    for(int i = 0; i < n; i ++ )
    {
        scanf("%d",&f[i]);
    }
    while(m--)
    {
        int x;
        cin >> x;
        int l = 0, r = n -1;
        while(l < r)
        {
            int mid = (l + r + 1) >> 1;
            if(f[mid] <= x) l = mid;
            else r = mid - 1;
        }
        if(f[l] <= x)
            cout << f[l] << endl;
        else cout << -1 << endl;
    }
    return 0;
}