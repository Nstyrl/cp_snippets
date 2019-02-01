vector <int> kmp(string s) { // zwraca vector dlugosci prefikso-sufiksow, wynik indeksowany od 0
    vector <int> pref(s.size() + 1, -1);
    for(int i = 0, j = -1; i < s.size(); i++) {
        while(j >= 0 && s[j] != s[i]) j = pref[j];
        pref[i + 1] = ++j;
    }
    return vector<int>(pref.begin() + 1, pref.end());
}