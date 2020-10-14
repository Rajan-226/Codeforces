#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define pb push_back
#define nl cout<<"\n"
#define db(x) cout<<x<<" "
#define fi(a,b) for(int i=a;i<b;i++)
#define fj(a,b) for(int j=a;j<b;j++)
#define fk(a,b) for(int k=a;k<b;k++)
#define F first
#define S second
#define mxsize (int)1e6+5
ll fastexp(ll a,ll n,ll nod=LLONG_MAX){
    ll ans=1;
    while(n){
        if(n&1)
            ans=(ans*a)%nod;
        a=(a*a)%nod;
        n>>=1;
    }
    return ans;
}
ll check(vector<pair<int,int>>& v,int ind,bool ok){
    int n=v.size();
    vector<bool> vis(n,0);
    int i=ind;
    ll ans=v[ind].S;
    vis[ind]=1;
    while(i>=0&&i<=n-1){
        if(ok){
            if(!vis[i]){
                vis[i]=1;
                ans+=v[i].S;
                ok=0;
                continue;
            }
            i++;
        }
        else{
            if(!vis[i]){
                vis[i]=1;
                ans+=v[i].S;
                ok=1;
                continue;
            }
            i--;
        }
    }
    return ans;
}
void fun(){
    int n;
    cin>>n;
    ll ans=0;
    vector<pair<int,int>> v;
    fi(0,n){
        int a,b;
        cin>>a>>b;
        v.push_back({a,b});
    }
    sort(v.begin(),v.end());
    if(v[0].F>0){
        cout<<v[0].S<<"\n";
        return ;
    }
    if(v[n-1].F<0){
        cout<<v[n-1].S<<"\n";
        return; 
    }
    int ind;
    fi(0,n){
        if(v[i].F>0){
            ind=i;
            break;
        }
    }
    ans=max(ans,check(v,ind,0));
    ans=max(ans,check(v,ind-1,1));
    cout<<ans<<"\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(20);
    cout<<fixed;
    #ifndef ONLINE_JUDGE
        freopen("/ATOM/input.txt", "r", stdin);
        freopen("/ATOM/output.txt", "w", stdout);
    #endif
    int t=1;
    // cin>>t;
    while(t--){
        fun();
    }
}
