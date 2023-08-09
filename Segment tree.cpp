// In the name of Allah.
// We're nothing and you're everything.
// Ya MAALIK-UL-MULK!!!

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace std;
using namespace __gnu_pbds;

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
 
template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

#define ll long long
template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
struct custom_hash {
static uint64_t splitmix64(uint64_t x) {
    // http://xorshift.di.unimi.it/splitmix64.c
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
}
 
size_t operator()(uint64_t x) const {
    static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64(x + FIXED_RANDOM);
}
};
ll binpow(ll a,ll b,ll m){ll res=1;while(b>0){if(b&1)res=(res*a)%m;a=(a*a)%m;b/=2;}return res;}

#define pii   pair <int, int>
#define pll   pair <ll, ll>
#define vi    vector<int>
#define vl    vector<ll>
#define ump   unordered_map<ll,ll,custom_hash>
#define pqgi  priority_queue<int,vector<int>,greater<int>>
#define endl  '\n'
#define mk    make_pair
#define pb    push_back
#define ft    first
#define sd    second
#define TestCase    int TT; cin >> TT;for(int zz=1;zz<=TT;zz++)
#define FASTIO  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define all(a)   a.begin(),a.end()
#define f(i,a,b)  for(int i=a;i<b;i++)
#define rf(i,a,b)  for(int i=b-1;i>=a;i--)
#define rep(i,a,b)  for(int i=a;i<=b;i++)
#define rev(i,a,b)  for(int i=b;i>=a;i--)
#define fs(val,y)   fixed<<setprecision(y)<<val
const long long N = 2e5 + 5, M = 1e9 + 7, mod = 998244353, INF = 1e18, inf = INT_MAX;
int fx[] = {1, -1, 0, 0, 1, -1, 1, -1};
int fy[] = {0, 0, 1, -1, 1 , -1, -1, 1};


vi trees;

int segtree(int node, int l, int r, int L, int R, int v){ //update and query
	//change the code as needed
	if(L <= l && R >= r){
		if(v != -1) trees[node] = v; //update the index
		return trees[node];
	}
	if(R < l || r < L) return inf; //maybe needed to change
	
	int last = (l + r) / 2;
	int mn = min(segtree(node*2, l, last, L, R, v),segtree(node*2+1, last+1, r, L, R, v)); //maybe needed to change
	trees[node] = min(trees[node*2] , trees[node*2+1]); //this line is for update any value and maybe needed to change
	return mn;
}


void build_segtree(vi &a, int &n){ //build the segtree
	//change the code as needed
	while(__builtin_popcount(n) != 1){
	    a.pb(inf); //maybe needed to change
	    n++;
	}
	trees.resize(2*n);
    
	f(i,0,n) trees[i+n] = a[i];
	for(int i = n - 1; i >= 1; i--){
		trees[i] = min(trees[i*2] , trees[i*2+1]); //maybe needed to change
	}
}


int main()
{ 
    FASTIO
    TestCase{
    	//take input
    	int n,q;
    	cin >> n >> q;
    	vi a(n);
    	f(i,0,n) cin >> a[i];
    	
    	build_segtree(a , n); //be careful about value of n,,,maybe changed
    	
    	//query and update
    	while(q--){
    		int t;
    		cin >> t;
	    	if(t == 1){
	    		int k,u;
	    		cin >> k >> u;
	    		k--;
	    		segtree(1, 0, n-1, k, k, u); //update kth index by u
	    	}
	    	else{
	    		int a,b;
	    		cin >> a >> b;
	    		a--,b--;
	    		cout << segtree(1, 0, n-1, a, b, -1) << endl; //query in a given range
	    	}
    	}
    }
    return 0;
}
