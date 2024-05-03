int tr[N][2];
int sum[N];
int cnt = 1;
 
void add(int x, int t) {
    int p = 1;
    sum[p] += t;
    for (int i = 29; i >= 0; i--) {
        int d = x >> i & 1;
        if (!tr[p][d]) {
            tr[p][d] = ++cnt;
        }
        p = tr[p][d];
        sum[p] += t;
    }
}
 
int query(int x) {
    int ans = 0;
    int p = 1;
    for (int i = 29; i >= 0; i--) {
        int d = x >> i & 1;
        if (sum[tr[p][!d]]) {
            p = tr[p][!d];
            ans |= 1 << i;
        } else {
            p = tr[p][d];
        }
    }
    return ans;
}

void solve(){
	//add(x , t); for inserting t = 1, for erasing t = -1
	//query(x);
}
