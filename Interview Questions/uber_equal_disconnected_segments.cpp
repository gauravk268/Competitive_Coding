#include<bits/stdc++.h>
using namespace std;

/*
    ?PROBLEM - Equal Disconnected Segments
    DESCRIPTION - 
        Given N intervals we need to make each interval equal and disjoint.
        !NOTE - We can only shrink the interval i.e modified interval must be less than or equal to its actual size
        return the max size of interval is possible

        For EG: 
            intervals = [(1, 4), (2, 6), (8, 12)]
            Output : 2.5
            Explanation : (1,4) - (1, 3.5)
                          (2, 6) - (3.5, 6)
                          (8, 12) - (8, 10.5)

*/

bool isValid(vector<pair<double, double>> &intervals, double x) {
    double y;

    for(int i = 0; i < intervals.size(); i++) {
        if(i == 0) {
            if(intervals[i].first + x <= intervals[i].second) {
                y = intervals[i].first + x;
            } else {
                return false;
            }
        } else {
            if(y < intervals[i].first) {
                y = intervals[i].first;
            }
            if(y + x <= intervals[i].second) {
                y = y + x;
            } else {
                return false;
            }
        }
    }
    return true;
}

double equalDisconnectSegments(vector<vector<int>> &segments) {
    vector<pair<double, double>> intervals;

    for(auto segment : segments) {
        intervals.push_back({segment[0], segment[1]});
    }

    sort(intervals.begin(), intervals.end());

    double mn = INT_MAX;

    for(auto interval : intervals) {
        mn = min(mn, interval.second - interval.first);
    }

    double low = 0;
    double high = mn;
    double ans = mn;
    double precision = 0.0000001;
    while(high - low > precision) {
        double mid = low + (high - low) / 2;
        // cout << mid << endl;

        if(isValid(intervals, mid)) {
            ans = mid;
            low = mid;
        } else {
            high = mid;
        }
    }
    return ans;
}

signed main() {
    int n;
    cin >> n;
    vector<vector<int>> segments(n, vector<int>(2, 0));
    // cout << segments.size() << endl;

    for(int i = 0; i < n; i++) {
        cin >> segments[i][0] >> segments[i][1];
    }

    cout << equalDisconnectSegments(segments) << endl;
}