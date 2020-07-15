#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"

const int MOD = 1e9 + 7;
const int SIZE_INT = 16;

void solve()
{
    int n;
    cin >> n;

    vector<ll> a, b, values;

    ll temp, cost = 0;
    cin >> temp;

    a.push_back(temp);
    values.push_back(temp);

    for (int i = 0; i < n - 1; i++)
    {
        cin >> temp;
        a.push_back(temp);

        auto it = find(values.begin(), values.end(), temp);
        if (it == values.end())
        {
            values.push_back(temp);
        }
        else
        {
            values.erase(it);
        }
    }

    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        b.push_back(temp);

        auto it = find(values.begin(), values.end(), temp);
        if (it == values.end())
        {
            values.push_back(temp);
        }
        else
        {
            auto pos = it - values.begin();
            values.erase(it);
        }
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    if (a == b)
    {
        cost = 0;
    }
    else if (values.empty())
    {
        for (int i = 0; i < n; i++)
        {
            if (a[i] != b[i])
            {
                if (a[i] > b[i])
                {
                    ll temp = a[i];
                    a[i] = b[i + 1];
                    b[i + 1] = temp;
                }
                else
                {
                    ll temp = b[i];
                    b[i] = a[i + 1];
                    a[i + 1] = temp;
                }

                cost++;
                i++;
            }
        }
    }
    else
    {
        cost = -1;
        values.clear();
    }

    a.clear();
    b.clear();

    cout << cost << endl;
}

void solve2()
{
    int n;
    cin >> n;

    vector<ll> a, b, values;

    ll temp, costA = 0, costB = 0;

    cin >> temp;
    a.push_back(temp);
    values.push_back(temp);

    for (int i = 0; i < n - 1; i++)
    {
        cin >> temp;

        if (find(a.begin(), a.end(), temp) == a.end())
        {
            a.push_back(temp);
        }
        else if (find(b.begin(), b.end(), temp) == b.end())
        {
            b.push_back(temp);
            costA++;
        }

        auto it = find(values.begin(), values.end(), temp);
        if (it == values.end())
        {
            values.push_back(temp);
        }
        else
        {
            values.erase(it);
        }
    }

    for (int i = 0; i < n; i++)
    {
        cin >> temp;

        if (find(b.begin(), b.end(), temp) == b.end())
        {
            b.push_back(temp);
        }
        else if (find(a.begin(), a.end(), temp) == a.end())
        {
            a.push_back(temp);
            costB++;
        }

        auto it = find(values.begin(), values.end(), temp);
        if (it == values.end())
        {
            values.push_back(temp);
        }
        else
        {
            values.erase(it);
        }
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    if (values.empty())
    {
        if (costA > costB)
        {
            cout << costA << endl;
        }
        else
        {
            cout << costB << endl;
        }
    }
    else
    {
        cout << "-1" << endl;
    }

    a.clear();
    b.clear();
    values.clear();
}

void solve1()
{
    int n;
    cin >> n;

    vector<int> seqA(n), seqB(n);
    int minValue = MOD;
    set<int> values;
    unordered_map<int, int> countTotal, count1, count2;

    for (auto &i : seqA)
    {
        cin >> i;

        minValue = min(minValue, i);
        values.insert(i);
        countTotal[i]++;
        count1[i]++;
    }

    for (auto &i : seqB)
    {
        cin >> i;

        minValue = min(minValue, i);
        values.insert(i);
        countTotal[i]++;
        count2[i]++;
    }

    sort(seqA.begin(), seqA.end());
    sort(seqB.begin(), seqB.end());

    if (seqA == seqB)
    {
        cout << "0" << endl;
        return;
    }

    for (auto i : values)
    {
        if (countTotal[i] % 2 == 1)
        {
            cout << "-1" << endl;
            return;
        }
    }

    vector<int> array1, array2;

    for (auto i : values)
    {
        int countFirst = 0, countSecond = 0;

        if (count1.find(i) != count1.end())
            countFirst = count1[i];
        if (count2.find(i) != count2.end())
            countSecond = count2[i];

        if (countFirst > countSecond)
        {
            int difference = countFirst - countSecond;
            if (difference % 2 == 1)
            {
                cout << "-1" << endl;
                return;
            }
            for (int j = 0; j < difference; j = j + 2)
            {
                array1.push_back(i);
            }
        }
        else if (countSecond > countFirst)
        {
            int difference = countSecond - countFirst;
            if (difference % 2 == 1)
            {
                cout << "-1" << endl;
                return;
            }
            for (int j = 0; j < difference; j = j + 2)
            {
                array2.push_back(i);
                array1.push_back(i);
            }
        }
    }

    if (array1.size() != 2 * array2.size())
    {
        cout << "-1" << endl;
        return;
    }

    sort(array1.begin(), array1.end());

    int minTwice = 2 * minValue;
    int result = 0;
    int k = 0;
    int l = array1.size();

    while (k < l)
    {
        result = result + min(array1[k], minTwice);
        k++;
        l--;
    }

    cout << result << endl;
}

int main()
{
    //a line to speed-up
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int testCases = 1;
    cin >> testCases; //remove it if only 1 testcase
    while (testCases--)
    {
        solve1();
    }

    return 0;
}