#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

const int N = 10010;

int n;
int g[N];
int res;
int main()
{
	cin >> n;
	
	for(int i = 0; i < n; i ++ )
		cin >> g[N];
	
	for(int i = 0; i < n; i ++ ) 
	{
		int minv = 1e9, maxv = -1e9;
		for(int j = i; j < n; j ++ )
		{
			minv = min(minv,g[j]);
			maxv = max(maxv,g[j]);
			if(maxv - minv == j - i)
			{
				cout << minv << ' ' << maxv <<endl;
				res++;
			} 
		}		
	}
	cout << res;
	return 0;
}