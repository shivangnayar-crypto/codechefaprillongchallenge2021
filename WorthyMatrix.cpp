#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll min(ll x,ll y){
    if(x<y){
        return x;
    }
    return y;
}
int main() {
    ll ttt;
    cin>>ttt;
    while(ttt-- !=0){
        ll n,m,kk;
        cin>>n>>m>>kk;
        double a[n+1][m+1];
        for(ll i=0;i<=n;i++){
            for(ll j=0;j<=m;j++){
                if(i==0 || j==0){
                   a[i][j]=0;
                }
                else{
                    cin>>a[i][j];
                }
            }
        }
        for(ll i=0;i<=n;i++){
            double pre=0;
            for(ll j=0;j<=m;j++){
                a[i][j]+=pre;
                pre=a[i][j];
            }
        }
        for(ll j=0;j<=m;j++){
            double pre=0;
            for(ll i=0;i<=n;i++){
                a[i][j]+=pre;
                pre=a[i][j];
            }
        }
        ll zz=min(n,m);
        ll ans=0;
        for(ll len=1;len<=zz;len++){
            for(ll i=len;i<=n;i++){
                for(ll j=len;j<=m;j++){
                    if((a[i][j]+a[i-len][j-len]-a[i][j-len]-a[i-len][j])/(len*len)>=kk){
                        ans++;
                    }
                }
            }
            
        }
        cout<<ans<<endl;
    }
}
