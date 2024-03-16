const int LOG = 20;
vector < int > adj[N];
int depth[N];
int up[N][LOG];

// for 1st call, par = root that means pass same value for v and par
void dfs(int v, int par, int d){
    depth[v] = d;
    up[v][0] = par;
    for(int i = 1; i < LOG; i++){
        up[v][i] = up[up[v][i-1]][i-1];
    }
    for(auto &child : adj[v]){
        if(child ^ par){
            dfs(child, v, d+1);
        }
    }
}

// this function return kth ancestor of vertex v
int get_kth(int v, int k){
    if(depth[v] < k) return -1;
    for(int i = 0; i < LOG; i++){
        if(k & (1 << i)){
            v = up[v][i];
        }
    }
    return v;
}

// this function return lowest common ancestor of x & y nodes
int get_lca(int x, int y){
    if(depth[x] < depth[y]) swap(x,y);
    //get same depth
    int k = depth[x] - depth[y];
    for(int j = LOG-1; j >= 0; j--){
        if(k & (1 << j)){
            x = up[x][j];
        }
    }
    //if y was ancestor of x
    if(x == y) return x;
    //move both x & y with power two
    for(int j = LOG-1; j >= 0; j--){
        if(up[x][j] != up[y][j]){
            x = up[x][j];
            y = up[y][j];
        }
    }
    return up[x][0];
}
