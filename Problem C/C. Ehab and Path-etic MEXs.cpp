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
vector<int> adj[mxsize];    //adjacency list
bool vis[mxsize];   //vis array for node transversal
map<pair<int,int>,int> mp;
int num=1;
void dfs(int node,int par){
    vis[node]=1;
	if(adj[node].size()==1&&mp[{min(adj[node][0],node),max(node,adj[node][0])}]==0){
		mp[{min(adj[node][0],node),max(node,adj[node][0])}]=num;
		num++;
	}
    for(auto child:adj[node]){
		if(node==par)	continue;
        if(vis[child]==0){
            dfs(child,node);
        }
    }
}
void fun(){
	int n;
	cin>>n;
	vector<pair<int,int>> v;
	fi(0,n-1){
		int x,y;
        cin>>x>>y;
		v.push_back({x,y});
        adj[x].pb(y);
        adj[y].pb(x);
	}
	dfs(1,-1);
	fi(0,n-1){
		if(mp[{min(v[i].F,v[i].S),max(v[i].F,v[i].S)}])
			cout<<mp[{min(v[i].F,v[i].S),max(v[i].F,v[i].S)}]-1<<"\n";
		else{
			cout<<num-1<<"\n";
			num++;
		}
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
