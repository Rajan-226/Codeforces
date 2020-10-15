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
//shift o is not working
map<pair<string,string>,int> mp;
bool check(string& a,string& b){
	if(mp[{a,b}]){
		if(mp[{a,b}]==-1)	return 0;
		return 1;
	}
	int n=a.size();
	if(n==0){
		mp[{a,b}]=-1;
		return 0;
	}
	if(a==b)
		return mp[{a,b}]=1;
	if(n%2){
		mp[{a,b}]=-1;
		return 0;
	}
	string halfa=a.substr(0,n/2);
	string shalfa=a.substr(n/2);
	string halfb=b.substr(0,n/2);
	string shalfb=b.substr(n/2);
	if(check(halfa,halfb)&&check(shalfa,shalfb))	return mp[{a,b}]=1;
	if(check(halfb,shalfa)&&check(halfa,shalfb))	return mp[{a,b}]=1;
	mp[{a,b}]=-1;
	return 0;
}
bool fun(){
	string a,b;	
	cin>>a>>b;
	return check(a,b);
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
		if(fun())	cout<<"YES\n";
		else		cout<<"NO\n";
	}
}
