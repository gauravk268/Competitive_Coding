//?https://hack.codingblocks.com/app/contests/1783/1738/problem
#include <bits/stdc++.h>
using namespace std;

bool canConvert(string s, string t) {
    if(s.length() != t.length())
        return false;
    if(s == t)
        return true;

    map<char, char> mp;

    for(int i = 0; i < t.length(); i++) {
        if(s[i] == t[i])
            continue;
        if(mp.find(s[i]) == mp.end()) {
            mp[s[i]] = t[i];
        } else if(mp[s[i]] != t[i]) {
            return false;
        }
    }
    set<char> st;

    for(auto c : t) { 
        st.insert(c);
    }

    return st.size() < 26;
}

signed main() {
    string s, t;
    cin >> s >> t;

    if(canConvert(s, t)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}