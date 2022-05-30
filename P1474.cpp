//这吊题会爆int而且是多组输入
#include<bits/stdc++.h>
using namespace std;
 
vector<long long int> v;
 
int main()
{
    int n;
    while(cin >> n)
    {
        v.clear();
        for(int i = 0;i < n;i ++)
        {
            long long int x;
            cin >> x;
            v.push_back(x);
        }
        while(v.size() > 1){
            sort(v.begin(),v.end());
            long long int temp1 = v.front();

            v.erase(v.begin());
            long long int temp2 = v.front();

            v.erase(v.begin());
            v.push_back(temp1*temp2 + 1);
        }
        cout << v.front() << endl;
    }
}