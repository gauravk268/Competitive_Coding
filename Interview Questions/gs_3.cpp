#include<bits/stdc++.h>
using namespace std;
#define int long long
#define mod 1000000007

// M - Number of Chips
// N - Number of Robots
// time - 

int alignProcess(int M, int N, int *time, int *comp) {
    int ans = 0;

    int end[N][M];
    end[0][0] = (time[0] * comp[0]) % mod;

    for(int i = 1; i < M; i++) {
        end[0][i] = (end[0][i - 1] + time[i] * comp[0]) % mod;
    }

    for(int i = 1; i < N; i++) {
        end[i][0] = (time[0] * comp[i]) % mod;
        for(int j = 1; j < M; j++) {
            end[i][j] = (end[i][j - 1] + time[j] * comp[i]) % mod;
        }
    }

    for(int i = 1; i < N; i++) {
        int tmp = 0;
        for(int j = 0; j < M; j++) {
            int start = end[i][j] - time[j] * comp[i];

            if(tmp < end[i - 1][j] - start) {
                tmp = end[i - 1][j] - start;
            }
            if(tmp > 0)
                ans += tmp;
        }
    }
    return ans + end[N - 1][M - 1];
}

signed main() {
    int N, M;
    cin >> N >> M;
    int time[M];
    int comp[N];
    for(int i = 0; i < M; i++) {
        cin >> time[i];
    }
    for(int i = 0; i < N; i++) {
        cin >> comp[i];
    }

    cout << alignProcess(M, N, time, comp) << endl;
}