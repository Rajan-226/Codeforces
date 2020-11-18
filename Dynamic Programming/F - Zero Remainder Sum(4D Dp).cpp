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

#define vvl vector<vector<ll>>
#define vl vector<ll>
#define pl pair<ll,ll>
#define ppl pair<ll,pair<ll,ll>>
#define mxsize (int)1e6+5
ll dp[75][75][75][75];
ll a[75][75];
int n,m,k;
ll help(int x,int y,int cnt,int rem){
    
    if(dp[x][y][cnt][rem]!=INT_MIN)    return dp[x][y][cnt][rem];
    if(x==n){ 
        ll ans=-1e9;
        if(rem==0)  ans=0;
        return dp[x][y][cnt][rem]=ans;
    }

    if(y==m)    return dp[x][y][cnt][rem]=help(x+1,0,0,rem);

    ll ans=help(x,y+1,cnt,rem);
    if(cnt<m/2) 
        ans=max(ans,a[x][y]+help(x,y+1,cnt+1,(a[x][y]+rem)%k));
    
    return dp[x][y][cnt][rem]=ans;
}   
void fun(){
    cin>>n>>m>>k;
    fi(0,n) fj(0,m) cin>>a[i][j];
    fi(0,n+1){
        fj(0,m+1){
            for(int tt=0;tt<=m;tt++){
                for(int t=0;t<=k;t++){
                    dp[i][j][tt][t]=INT_MIN;
                }
            }
        }
    }
    cout<<help(0,0,0,0)<<"\n";
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
