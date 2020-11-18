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
int a[105][105];

vector<vector<int>> ans;

int n,m;
void help(vector<int> v){
	for(int i=0;i<v.size();i+=2){
		a[v[i]][v[i+1]]^=1;
	}
}
void anotherhelp(){
	int x=n-2,y=m-2;
	vector<int> temp;

	int c=0;
	fi(x,n){
		fj(y,m){
			temp.push_back(i);temp.push_back(j);
			if(a[i][j]==1)	c++;
		}
	}
	if(c==0)	return ;
	
	// db(c);nl;
	vector<int> v;
	if(c==4){
		ans.push_back({x,y,x+1,y,x,y+1});
		help(ans.back());
		c=1;
	}
	if(c==1){
		fi(x,n){
			fj(y,m){
				if(a[i][j]==1){
					v.push_back(i);
					v.push_back(j);
				}
			}
		}
		int ch=2;
		for(int i=0;i<temp.size();i+=2){
			if(temp[i]==v[0])	continue;
			ch--;
			v.push_back(temp[i]);
			v.push_back(temp[i+1]);

			if(ch==0)	break;
		}
		help(v);
		ans.push_back(v);
		v.clear();
		c=2;
	}
	if(c==2){
		bool ok=1;
		fi(x,n){
			fj(y,m){
				if(a[i][j]==0){
					v.push_back(i);
					v.push_back(j);
				}
				if(ok&&a[i][j]==1){
					v.push_back(i);v.push_back(j);
					ok=0;
				}
			}
		}
		ans.push_back(v);
		help(ans.back());
		c=3;
	}
	v.clear();
	if(c==3){
		fi(x,n){
			fj(y,m){
				if(a[i][j]==1){
					v.push_back(i);
					v.push_back(j);
				}
			}
		}	
		ans.push_back(v);
		help(ans.back());
	}
}
void fun(){
	cin>>n>>m;
	string s[n];
	fi(0,n)	cin>>s[i];
	fi(0,n){
		fj(0,m){
			if(s[i][j]=='0')	a[i][j]=0;
			else 		a[i][j]=1;
		}
	}
	for(int i=0;i<n;i++){
		if(i==n-1)	break;
		for(int j=0;j<m;j++){
			if(i==n-2&&j==m-2)	break;
			if(i==n-2){
				vector<int> v;
				if(a[i][j]==1){
					v.push_back(i);	v.push_back(j);
				}
				if(a[i+1][j]==1){
					v.push_back(i+1);	v.push_back(j);
				}
				if(v.empty())	continue;
				if(v.size()==2){
					v.push_back(i+1);v.push_back(j+1);
				}
				if(v.size()==4){
					v.push_back(i);v.push_back(j+1);
				}
				help(v);
				ans.push_back(v);
				continue;
			}
			if(a[i][j]==0)	continue;
			if(j==0)	ans.push_back({i,j,i+1,j,i,j+1});
			else		ans.push_back({i,j,i+1,j,i+1,j-1});
			help(ans.back());
		}
	}
	anotherhelp();
	// fi(0,n){
	// 	fj(0,m)	db(a[i][j]);nl;
	// }
	// nl;
	cout<<ans.size()<<"\n";
	for(auto& v:ans){
		for(auto j:v){
			cout<<j+1<<" ";
		}nl;
	}
	ans.clear();	
}
// 1 1
// 0 0

// 1 0
// 1 1

// 0 0
// 0 0




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
