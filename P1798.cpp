#include <iostream>
#include <algorithm>
using namespace std;
#define N 202
int a[N], gap[N];
bool compare(int a, int b)
{
  return a > b;
}
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    if (m >= n)
    {
        cout << n << endl;
        return 0;
    }
    sort(a, a + n);
    int s = a[n - 1] - a[0] + 1;
    for (int i = 0; i < n - 1; i++)
        gap[i] = a[i + 1] - a[i] - 1;
    sort(gap, gap + n - 1, compare);
    int i = 1;
    while (i < m)
    {
        s -= gap[i - 1];
        i++;
    }
    cout << s << endl;
}