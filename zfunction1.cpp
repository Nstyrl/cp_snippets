vector <int> ZFunction(string s) { // 0 indexed, corner case [0] = 0
    vector<int> result(s.size());
    for(int i = 1, j = 1, best = 1; i < s.size(); i++) {
        if(i + result[i - best] >= j) {
            while(j < i || s[j] == s[j - i]) j++;
            result[i] = j - i;
            best = i;
        } else {
            result[i] = result[i - best];
        }
    }
    return result;
}