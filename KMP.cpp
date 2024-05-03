// finding string s as a substring in string t
vector < int > prefix_function(string &s){
    int n = s.size();
    vector < int > ps(n);
    for(int i = 1; i < n; i++){
        int j = ps[i-1];
        while(j > 0 && s[j] != s[i]) j = ps[j-1];
        if(s[i] == s[j]) j++;
        ps[i] = j;
    }
    return ps;
}

void solve(){
    string s, t;
    cin >> s >> t;
    vector < int > ps = prefix_function(s);
    int i = 0, j = 0, pos = -1;
    while(i < (int)t.size()){
        if(t[i] == s[j]) i++, j++;
        else if(j) j = ps[j-1];
        else i++;
        if(j == s.size()){ 
            pos = i - (int)s.size();
            break;
        }
    }
    cout << pos << endl;
}
