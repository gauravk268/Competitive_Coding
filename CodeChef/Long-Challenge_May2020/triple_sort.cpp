#include<bits/stdc++.h>
using namespace std;

#define ll long long

#define FoR(i, a) for(int i=0; i<a; i++)
#define FOR(i, a, b) for(int i=a; i<b; i++)
#define MEM(a, b, n) memset(a, b, sizeof(a[0])*n)

const int MOD = 1e9+7;
const int SIZE_INT = 16;


void solve()
{
    int N, K;
    cin>>N>>K;

    vector<int>a(N+1), b(N+1), c(N+1);
    
    for(int i=0; i<N; i++){
        cin>>a[i];
        b[i+1] = a[i];
        c[a[i]] = i+1;
    }

    int countTemp=0;
    bool flag = true;

    vector<int> all, pair;
    int count=0;

    for(int i=1; i<N+1; i++){

        if(b[i] != i){
            int num_a = i;
            int num_b = b[i];
            int num_c = b[num_b];

            if(num_a == num_c){
                if( (find(pair.begin(), pair.end(), num_a) == pair.end()) && (find(pair.begin(), pair.end(), num_c) == pair.end()) ){
                    count++;
                    pair.push_back(i);
                    pair.push_back(b[i]);
                }
                continue;
            }

            int value_a = b[num_a];
            int value_b = b[num_b];
            int value_c = b[num_c];

            b[num_a] = value_c;
            c[value_c] = num_a;

            b[num_b] = value_a;
            c[value_a] = num_b;

            b[num_c] = value_b;
            c[value_b] = num_c;

            all.push_back(num_a);
            all.push_back(num_b);
            all.push_back(num_c);

            countTemp++;

            if(countTemp>K){
                flag=false;
                break;
            }

            if(b[i] != i){
                i--;
            }
        }

    }


    if(count>0 && flag == true){
        if(count%2 == 1){
            flag = false;
        }
        else{
            int pairSize = pair.size();

            for(int j=0; j<pairSize; j+=4){
                int temp_a = pair[j];
                int temp_b = pair[j+1];
                int temp_c = pair[j+2];
                int temp_d = pair[j+3];

                all.push_back(temp_a);
                all.push_back(temp_c);
                all.push_back(temp_b);

                all.push_back(temp_c);
                all.push_back(temp_b);
                all.push_back(temp_d);

                countTemp+=2;

                if(countTemp>K){
                    flag = false;
                    break;
                }
            }
        }
    }

    if(flag == false){
        cout<<-1<<"\n";
    }
    else if(countTemp<=K){
        cout<<countTemp<<"\n";

        for(int i=0; i<all.size(); i+=3){
            cout<<all[i]<<" "<<all[i+1]<<" "<<all[i+2]<<"\n";
        }
    }
    else{
        cout<<-1<<"\n";
    }



    //         auto it_a = find(a.begin(), a.end(), b[i]);
    //         int dis_a = distance(a.begin(), it_a);
    //         auto it_b = find(a.begin(), a.end(), b[dis_a]);
    //         int dis_b = distance(a.begin(), it_b);

    //         if(i == dis_a || dis_a == dis_b || dis_b == i)
    //             continue;

    //         vector<int> tempVec;
    //         tempVec.push_back(i);
    //         tempVec.push_back(dis_a);
    //         tempVec.push_back(dis_b);
    //         sort(tempVec.begin(), tempVec.end());

    //         doubleVec.push_back(tempVec);

    //         if(i < dis_a && i < dis_b){     // i < dis_b < dis_a
    //             if(dis_a > dis_b){
    //                 int temp;
    //                 temp = a[dis_a];
    //                 a[dis_a] = a[dis_b];
    //                 a[dis_b] = a[i];
    //                 a[i] = temp;
    //             }

    //             else{       // i < dis_a < dis_b
    //                 int temp;
    //                 temp = a[dis_b];
    //                 a[dis_b] = a[dis_a];
    //                 a[dis_a] = a[i];
    //                 a[i] = temp;
    //             }
    //         }

    //         numDiff++;

    //         if(b[i] != a[i]){
    //             if(i < dis_a && i < dis_b){     // i < dis_b < dis_a
    //                 if(dis_a > dis_b){
    //                     int temp;
    //                     temp = a[dis_a];
    //                     a[dis_a] = a[dis_b];
    //                     a[dis_b] = a[i];
    //                     a[i] = temp;
    //                 }

    //                 else{       // i < dis_a < dis_b
    //                     int temp;
    //                     temp = a[dis_b];
    //                     a[dis_b] = a[dis_a];
    //                     a[dis_a] = a[i];
    //                     a[i] = temp;
    //                 }
    //             }
                
    //             vector<int> tempVec;
    //             tempVec.push_back(i);
    //             tempVec.push_back(dis_a);
    //             tempVec.push_back(dis_b);
    //             sort(tempVec.begin(), tempVec.end());

    //             doubleVec.push_back(tempVec);

    //             numDiff++;
    //         }
    //     }


}


int main()
{
    //two lines to speed-up
    cin.tie(0);
    ios::sync_with_stdio(false);

    // solve();

    int testCases;
    cin >> testCases;

    while (testCases--)
    {
        solve();
    }

    return 0;
}