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
ll INV(ll x, ll m){x %= m;return binpow(x , m - 2, m);}

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
#define FOR(i,a,b)  for(int i=a;i<b;i++)
#define FORN(i,a,b)  for(int i=b-1;i>=a;i--)
#define rep(i,a,b)  for(int i=a;i<=b;i++)
#define rev(i,a,b)  for(int i=b;i>=a;i--)
#define fs(val,y)   fixed<<setprecision(y)<<val
const long long N = 2e5 + 5, M = 1e9 + 7, mod = 998244353, INF = 1e18, inf = INT_MAX;
int fx[] = {1, -1, 0, 0, 1, -1, 1, -1};
int fy[] = {0, 0, 1, -1, 1 , -1, -1, 1};

int main()
{ 
    FASTIO
    TestCase{
    	
    }
    return 0;
}
