// structure with operator overloading (sorting)
struct tupple{
	int l,r,idx;
	bool operator<(const tupple &x) const{
		return (l == x.l ? r <= x.r : l < l.r);
	}
};

// dp ... all possible sum (here N = maximum possible total sum + constant;)
        vi dp(N);
    	dp[0] = 1;
    	for(int i = 1; i <= n; i++){
    		for(int j = N - 1; j >= 0; j--){
    			if(dp[j]) dp[j + s[i]] = 1;
    		}
    	}
     
// by using bitset
        bitset < N > dp;
    	dp[0] = 1;
    	for(int i = 1; i <= n; i++){
    		dp |= dp << s[i];
    	}

     
//bitset pass by reference
bool is_ok(bitset< N > &dp){
	....
}
// make zero all the bits of a bitset
   dp.reset();

//bitmasking (all possible way 2^n)
    	int k = a.size();
    	for(int i = 0; i < (1 << k); i++){        // from 0 to 2^k - 1 where k is the size of the array
            for(int mask = 0; mask < k; mask++){  // 0 indexing array
                if(i & (1 << mask)){
                	//operation as i need
                }
            }
        }

// unique all funciton
// i) total unique elements:
    int e = unique(all(a)) - a.begin();
// ii) erase duplicate and make all elements unique
    a.erase(unique(all(a)),a.end());

//dp with bitmask
        //int ans = 0;
	for(int mask = 0; mask < (1 << n); mask++){
		for(int j = 0; j < n; j++){
			if(mask >> j & 1){
				for(int i = 0; i < n; i++){
					if(mask >> i & 1) dp[j][mask] = max(dp[j][mask], dp[i][mask ^ (1 << j)] + a[j] + cond[i][j]);
				}
			}
			//if(__builtin_popcountll(mask) == m) ans = max(ans, dp[j][mask]);
		}
	}
