//抄的，数据结构以后要好好学
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,a,b) for(ll i=a;i<=b;i++)
#define per(i,a,b) for(ll i=a;i>=b;i--)
const ll MAXN = 1e5+5;
struct node{
    ll l,r,val;
}a[MAXN<<2];
struct query{
    ll p,x;
}q[MAXN];
ll b[MAXN];
void build(ll rt,ll l,ll r){
    a[rt].l=l,a[rt].r=r,a[rt].val=0;
    if(l==r)return ;
    ll mid=(l+r)>>1;
    build(rt<<1,l,mid);
    build(rt<<1|1,mid+1,r);
}
void update(ll rt,ll x,ll val){
    if(a[rt].l==a[rt].r&&a[rt].l==x){
        a[rt].val+=val;
        return;
    }
    ll mid=(a[rt].l+a[rt].r)>>1;
    if(x<=mid)update(rt<<1,x,val);
    else update(rt<<1|1,x,val);
    a[rt].val=a[rt<<1].val+a[rt<<1|1].val;
}
ll query(ll rt,ll l,ll r){
    if(a[rt].l>=l&&a[rt].r<=r)return a[rt].val;
    ll mid=(a[rt].l+a[rt].r)>>1,ans=0;
    if(l<=mid)ans+=query(rt<<1,l,r);
    if(r>mid)ans+=query(rt<<1|1,l,r);
    return ans;
}
ll query1(ll rt,ll x){
    if(a[rt].l==a[rt].r)return a[rt].l;
    if(x<=a[rt<<1].val)return query1(rt<<1,x);
    else return query1(rt<<1|1,x-a[rt<<1].val);
}
int main(){
    ll n;
    scanf("%lld",&n);
    build(1,1,1e5);
    ll num=0;
    rep(i,1,n){
        scanf("%lld%lld",&q[i].p,&q[i].x);
        if(q[i].p==4)continue;
        b[++num]=q[i].x;
    }
    sort(b+1,b+num+1);
    num=unique(b+1,b+num+1)-b-1;
    rep(i,1,n){
        ll x;
        if(q[i].p!=4)x=lower_bound(b+1,b+num+1,q[i].x)-b;
        else x=q[i].x;
        if(q[i].p==1){
            update(1,x,1);
        }
        if(q[i].p==2){
            update(1,x,-1);
        }
        if(q[i].p==3){
            ll ans=query(1,1,x-1)+1;
            printf("%lld\n",ans);
        }
        if(q[i].p==4){
            ll ans=query1(1,x);
            printf("%lld\n",b[ans]);
        }
        if(q[i].p==5){
            ll pos=query(1,1,x-1);
            ll ans=query1(1,pos);
            printf("%lld\n",b[ans]);
        }
        if(q[i].p==6){
            ll pos=query(1,1,x);
            ll ans=query1(1,pos+1);
            printf("%lld\n",b[ans]);
        }
    }
    return 0;
}