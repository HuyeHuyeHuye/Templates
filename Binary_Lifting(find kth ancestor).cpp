int n, LOG;
vector < vector < int > > adj;
vector < vector < int > > up;
vector < int > depth;

void dfs(int v, int par, int d){
    depth[v] = d;
    up[v][0] = par;
    for(int i = 1; i <= LOG; i++){
        up[v][i] = up[up[v][i-1]][i-1];
    }
    for(auto &child : adj[v]){
        if(child ^ par){
            dfs(child, v, d+1);
        }
    }
}

int get_kth(int v, int k){
    if(depth[v] < k) return -1;
    for(int i = 0; i <= LOG; i++){
        if(k & (1 << i)){
            v = up[v][i];
        }
    }
    return v;
}

void preprocess(int root){
    depth.resize(n+1);
    LOG = ceil(log2(n+1));
    up.assign(n+1, vector < int > (LOG+1));
    dfs(root, root, 0);
}
void solve(){
    cin >> n;
    adj.resize(n+1, vector < int > ());
    for(int i = 2; i <= n; i++){
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    preprocess(1);
}
