#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 1e6 + 10;

int n,k;
int a[N],place[N];

int main()
{
    scanf("%d%d",&n,&k);
    int num = 0;
    for(int i = 1; i <= n; i ++ )
    {
        scanf("%d",&a[i]);
        if(a[i] == k)
            place[++num] = i;
    }

    int ans = 0;
    for(int i = num; i >= 1; i -- )
    {
        if(place[i] % 2 == 0 || place[i] == 1) ans++; //偶数位置
        else    //奇数位置
        {
            int origin = i; //原位置
            while(i >= 1 && place[i] %2 != 0)
            {
                if(place[i] == 1) break;
               i --; //找到原位置前第一个偶数位置
            }
            ans += origin - i + 1;
        }
    }
    cout << ans;
    return 0;
}