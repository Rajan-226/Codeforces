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

void fun(){
	int n,k;
	cin>>n>>k;
	ll a[n*k];
	fi(0,n*k)	cin>>a[i];
	ll ans=0;
	int md=ceil(1.0*n/2);
	if(n%2)	md--;

	int c=md;
	int d=k;
	for(int i=n*k-1;i>=0;i--){
		if(d==0)	break;
		if(c==0){
			ans+=a[i];
			c=md;
			d--;
			continue;
		}
		c--;
		if(d==0)	break;
	}
	cout<<ans<<"\n";
}
// ceil n/2
// 2 4 16 18 21 27 36 53 82 91 92 95
//         r        r          r
// 92+82+36
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
	cin>>t;
	while(t--){
		fun();
	}
}
