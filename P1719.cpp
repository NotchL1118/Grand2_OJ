/*
  抄的，一开始看错题了，然后浪费了1小时，没思路了
　贪心做法，记录下每个指定值到自己前面的那个2的次方的距离，若在2的次方位置上，则可以直接删除，就是操作次数加1。
  不在2的次方上的话，有2种情况
      第一种，已经进行删除的操作数，大于删除该数所需的操作数，直接操作数加1即可，也就是直接删掉。怎么理解这种情况呢，我们可以这样想，当前面删除时，后面的数会向前移，
  因为要删除的操作数，大于删除该数所需的操作数，那么正好当该数移动到2的次方位置上时，我们对它进行删除。
      第二种情况，已经进行删除的操作数，小于删除该数所需的操作数。我们取这个数所需的操作数。这个可以这样理解，当前面的数删除完成时，这个数已经快到能被删除的地方，
  那么再加上几次操作即可把这个数也删掉，这两次操作的数量加起来也就是要删除的这个数的操作数。
*/
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
const int N = 1e6 + 10;

int n,k,j;
int dis[N];
int result;

//求n与前面一个离n最近的2的次方数的距离
int distance(int n)   
{
    for(int i = 0; i < n; i ++ )
        if(pow(2,i) == n)
            return 0;
        else if(pow(2,i) > n)
            return n - pow(2,i-1) + 1;  //result ++ 操作的是最后一步，所以这里要加1
}

int main()
{
    cin >> n >> k;
    int t;
    for(int i = 1; i <= n; i++)
    {
        cin >> t;
        if( t == k ) 
            dis[j++] = distance(i);
    }

    // //输出dis数组
    // for(int i = 0; i < j; i++)
    //     cout << dis[i] << " ";
    // cout<< endl;

    for(int i = 0; i < j; i ++ )
         if(dis[i] == 0 || result > dis[i])
            result++;
        else
            result = max(result,dis[i]);

    cout << result << endl;

    return 0;
}