#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct point
{
    ll x, y;
};

bool doIntersect(point a, point b, point c, point d)
{
    if ((c.y >= a.y && c.y <= b.y) || (c.y <= a.y && c.y >= b.y))
    {
        if ((a.x <= c.x && b.x >= d.x) || (a.x >= c.x && b.x <= d.x))
            return true;
    }

    return false;
}

int main()
{
    int testCases;
    cin >> testCases;

    while (testCases--)
    {
        int N, Q;
        cin >> N >> Q;

        struct point A[N + 5];
        for (int i = 1; i <= N; i++)
        {
            A[i].x = i;
            scanf("%lld", &A[i].y);
        }

        int x1, x2;
        ll y;

        while (Q--)
        {
            scanf("%d %d %lld", &x1, &x2, &y);

            struct point queryInit, queryEnd;

            queryInit.x = x1;
            queryInit.y = y;

            queryEnd.x = x2;
            queryEnd.y = y;

            ll count = 0;
            
            for (i=1 ; i < N; i++)
            {
                if ((A[i].x == queryEnd.x) && (A[i].y == queryEnd.y))
                    continue;
                
                if ((A[i + 1].x == queryInit.x) && (A[i + 1].y == queryInit.y))
                    continue;

                if((A[i].y > y && A[i+1].y > y) || (A[i].y < y && A[i+1].y < y))
                    continue;

                if((A[i].y > y && A[i+1].y > y) || (A[i].y < y && A[i+1].y < y))
                    continue;

                if (doIntersect(A[i], A[i + 1], queryInit, queryEnd))
                    count++;
            }

            printf("%lld\n", count);
        }
    }

    return 0;
}