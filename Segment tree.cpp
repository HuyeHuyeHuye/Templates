vector < int > trees;

int segtree(int node, int l, int r, int L, int R, int v){ //update and query
    //change the code as needed
    if(L <= l && R >= r){
        if(v != -1) trees[node] = v; //update the index
        return trees[node];
    }
    if(R < l || r < L) return inf; //maybe needed to change
    
    int mid = (l + r) / 2;
    int mn = min(segtree(node*2, l, mid, L, R, v),segtree(node*2+1, mid+1, r, L, R, v)); //maybe needed to change
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
    
    for(int i = 0; i < n; i++) trees[i+n] = a[i];
    for(int i = n - 1; i >= 1; i--){
        trees[i] = min(trees[i*2] , trees[i*2+1]); //maybe needed to change
    }
}


void solve(){
    //build_segtree(a , sz);
    //segtree(1, 0, sz-1, k, k, u); ...update kth index by u
    //segtree(1, 0, sz-1, a, b, -1); ...query in a given range
}
