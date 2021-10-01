#include<bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> PBDS;

// For duplicate insertion change 'int' to pair type and assign second value as unique value

int main() {
    PBDS St;
    // insertion takes (logn)
    St.insert(1);
    St.insert(3);
    St.insert(4);
    St.insert(10);
    St.insert(15);

    // Kth Largest element at till now (logn)

    for(int i = 0; i < St.size(); i++) {
        cout << i << " " << *St.find_by_order(i) << endl;
    }
    // Strictly smaller than given key
    cout << St.order_of_key(5) << endl;
}
