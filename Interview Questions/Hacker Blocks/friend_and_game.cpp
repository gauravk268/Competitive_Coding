//?https://hack.codingblocks.com/app/contests/1783/1758/problem
#include<bits/stdc++.h>
using namespace std;

signed main() {
    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;

        set<int> st;
        for(int i = 1; i <= 9; i++) {
            st.insert(i);
        }

        vector<int> ans;
        int n = s.length();

        for(int i = 0; i < n; i++) {
            int num = s[i] - '0';
            // cout << num << endl;

            if(num % 2 == 0) {
                auto it = st.begin();
                ans.push_back(*it);
                st.erase(it);
                continue;
            } else {
                int j = i;
                int cnt = 0;
                while(j < n) {
                    int t = s[j] - '0';
                    if(t % 2) {
                        cnt++;
                    } else {
                        break;
                    }
                    j++;
                }
                auto it = st.begin();
                advance(it, cnt);
                int k = 0;
                while(k <= cnt) {
                    ans.push_back(*it);
                    it--;
                    k++;
                }
                k = 0;
                while(k <= cnt) {
                    st.erase(st.begin());
                    k++;
                }
                i = j;
            }
        }
        if(st.size() != 0) {
            ans.push_back(*st.begin());
        }

        for(int i : ans) {
            cout << i;
        }
        cout << endl;
       

    }
}