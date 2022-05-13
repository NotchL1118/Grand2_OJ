//这道贪心没搞懂，直接百度的
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 1010;
int n; 

int main()
{
    double max_b,ot_b; // max_battery 电池最大容量 和 other_total_battery 其他的电池之和
    while(cin >> n)
    {
        max_b = ot_b = 0.0;
        double battery[N];
        for(int i = 0; i < n; i ++ )
        {
            cin >> battery[i];
            if(max_b < battery[i])
                max_b = battery[i];
            ot_b += battery[i];
        }
        ot_b -= max_b;

        if(max_b > ot_b)
            printf("%.1f\n",ot_b);
        else
            printf("%.1f\n",(ot_b + max_b) / 2 );

    }
    
    return 0;
}