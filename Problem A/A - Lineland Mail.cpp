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
void fun(){
    int n;
    cin>>n;
    ll a[n+2];
    fi(1,n+1){
        cin>>a[i];
    }
    a[0]=a[1];
    a[n+1]=a[n];
    fi(1,n+1){
        ll mn,mx;
        if(i==1){
            mn=abs(a[i+1]-a[i]);
            mx=abs(a[n]-a[i]);
        }
        else if(i==n){
            mn=abs(a[n]-a[n-1]);
            mx=abs(a[n]-a[0]);
        }
        else{
            cout<<min(abs(a[i]-a[i-1]),abs(a[i]-a[i+1]))<<" "<<max(abs(a[i]-a[n+1]),abs(a[i]-a[0]))<<"\n";
            continue;
        }
        cout<<mn<<" "<<mx<<"\n";
    }
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
