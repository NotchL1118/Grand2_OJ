#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int M=3e5+10;
int t,n,m,k,ans;
int f[M],a[M],b[M];
int getf(int x){
    if(f[x]==x) return  x;
    return f[x]=getf(f[x]);
}
int main(){
    cin>>t;
    k=0;
    while(t--){
        cin>>n>>m;
        for(int i=1;i<=n;i++){
            f[i]=i;
            a[i]=0;//记录边，起始边个数为零。
            b[i]=1;//记录点，原始本身就为一个点。
        }
        for(int i=1;i<=m;i++){
            int t1,t2;
            scanf("%d%d",&t1,&t2);
            int u=getf(t1);
            int v=getf(t2);
            if(u==v) a[u]++; //本来就在一个集合里了，所以b数组不需要+1
            else {
                f[v]=u;
                a[u]+=a[v]+1;//因为最终怕判断的根节点判组群，所以记录边和点只需要在根节点上即可。
                b[u]+=b[v];
            }
        }
        ans=0;
        for(int i=1;i<=n;i++){
            if(i==f[i]&&a[i]-b[i]>0)
             ans+=a[i]-b[i];
        }
        printf("Case #%d: %d\n",++k,ans);
    }
     return 0;
}
