//here original string will be changed like #s1#s2#s3....# (size = 2*n+1)
//vector p contains left or right side extended length. so, len = p[i] + 1 + p[i] (# incluced)

vector < int > ManacherAlgo(string &s){
    string t = "";
    for(int i = 0; i < s.size(); i++){
        t += '#';
        t += s[i];
    }
    t += '#';
    int n = t.size();
    vector < int > p(n);
    
    int l = 0, r = -1;
    for(int i = 0; i < n; i++){
        int k;
        if(i > r) k = 0;
        else k = min(p[l + r - i], r - i);
        while(i-k >= 0 && i+k < n && t[i-k] == t[i+k]) k++;
        if(t[i-k] != t[i+k]) k--;
        p[i] = k;
        if(i+k > r){
            l = i - k;
            r = i + k;
        }
    }
