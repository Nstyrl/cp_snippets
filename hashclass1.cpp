class Hash {
    int n; int mod; int prime;
    vector <int> hash;
    vector <int> pows;
public:
    Hash() = default;
    template <class T> // first argument can be string or vector (and maybe something else too)
    Hash(T s, int mod = 1e9+7, int prime = 257) { // mod = 1e9+7, prime = 257 for strings
        n = s.size(), this->mod = mod, this->prime = prime;
        pows.assign(n + 1, 1); hash.assign(n + 1, 0);
        for(int i = 1; i <= n; i++) pows[i] = (pows[i - 1] * 1LL * prime) % mod;
        for(int i = 1; i <= n; i++) hash[i] = (hash[i - 1] * 1LL * prime + s[i - 1]) % mod;
    }
    int getHash(int l, int r) { // 0 indexed just like string s
        assert(0 <= l);assert(l <= r);assert(r < n);
        return ((hash[r + 1] - hash[l] * 1LL * pows[r - l + 1]) % mod + mod) % mod;
    }
};