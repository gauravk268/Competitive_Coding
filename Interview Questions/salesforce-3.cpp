#include<bits/stdc++.h>
using namespace std;

signed main() {
    string s;
    getline(cin, s);
    int n;
    cin >> n;

    stringstream ss(s);

    string word;
    int curr = n;
    string ans = "";
    bool flag = 0;
    while(ss >> word) {
        if(curr >= (int)word.length()) {
            ans += word;
            ans += " ";
            curr = curr - word.length() - 1;
        } else {
            ans += '\n';
            if(curr < word.length()) {
                flag = 1;
                break;
            }
            ans += word;
            ans += " ";
            curr = n - word.length() - 1;
        }
    }
    cout << ans << endl;
}