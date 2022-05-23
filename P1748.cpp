//空间换时间
#include <iostream>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;
const int N = 2010;

int T;
int n;
int A[N],B[N],C[N],D[N];
map<int,int> result; //自带索引


int main()
{
    cin >> T;
    while(T--)
    {
        int sum = 0,cnt = 0;
        cin >> n;
        for(int i = 0; i < n; i ++ )
            scanf("%d%d%d%d",A+i,B+i,C+i,D+i);

        for(int i = 0; i < n; i ++ )
            for(int j = 0; j < n; j ++ )
            {
                sum = A[i] + B[j];
                result[sum] ++ ;
            }

        for(int i = 0; i < n; i ++ )
            for(int j = 0; j < n; j ++ )
            {
                sum = C[i] + D[j];
                    cnt += result[-sum];
            }
        cout << cnt << endl;
        result.erase(result.begin(),result.end()); //或者reslut.clear();
    }

    return 0;
}