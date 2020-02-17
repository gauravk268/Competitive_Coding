#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int timeCode(int temp)
{
    switch (temp)
    {
    case 12:
        return 0;
    case 3:
        return 1;
    case 6:
        return 2;
    case 9:
        return 3;
    }
}

int main()
{
    int testCase;
    cin >> testCase;

    long long int dayProfit = 0;

    while (testCase--)
    {
        long long int value = -401, numRequest;

        cin >> numRequest;

        if (numRequest != 0)
        {
            int i, j, k, l, temp2, movie, timeMovie;
            char temp1;

            int A[4]{0}, B[4]{0}, C[4]{0}, D[4]{0};
            long long int profit[96]{0};

            while (numRequest--)
            {
                cin >> temp1 >> temp2;

                timeMovie = timeCode(temp2);

                switch (temp1)
                {
                case 'A':
                    A[timeMovie]++;
                    break;
                case 'B':
                    B[timeMovie]++;
                    break;
                case 'C':
                    C[timeMovie]++;
                    break;
                case 'D':
                    D[timeMovie]++;
                    break;
                }
            }

            //int valueA[4]{0}, valueB[4]{0}, valueC[4]{0}, valueD[4]{0};

            //int value1 = 0, value2 = 0, value3 = 0, value4 = 0;
            int m = 0;

            for (i = 0; i < 4; i++)
            {
                for (j = 0; j < 4; j++)
                {
                    for (k = 0; k < 4; k++)
                    {
                        for (l = 0; l < 4; l++)
                        {
                            if ((i != j) && (i != k) && (i != l) && (j != k) && (j != l) && (k != l))
                            {

                                int temp[4]{0};
                                temp[0] = A[i];
                                temp[1] = B[j];
                                temp[2] = C[k];
                                temp[3] = D[l];

                                sort(temp, temp + 4);

                                if (temp[3] == 0)
                                {
                                    profit[m++] = -400;
                                }
                                else
                                {
                                    if (temp[2] == 0)
                                    {
                                        int valueProfit = temp[3] * 100 - 300;
                                        profit[m++] = valueProfit;
                                    }
                                    else
                                    {
                                        if (temp[1] == 0)
                                        {
                                            int valueProfit = temp[3] * 100 + temp[2] * 75 - 200;
                                            profit[m++] = valueProfit;
                                        }
                                        else
                                        {
                                            if (temp[0] == 0)
                                            {
                                                int valueProfit = temp[3] * 100 + temp[2] * 75 + temp[1] * 50 - 100;
                                                profit[m++] = valueProfit;
                                            }
                                            else
                                            {
                                                int valueProfit = temp[3] * 100 + temp[2] * 75 + temp[1] * 50 + temp[0] * 25;
                                                profit[m++] = valueProfit;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }

            sort(profit, profit + m, greater<int>());
            value = profit[0];
        }

        else
            value = -400;

        cout << value << "\n";
        dayProfit += value;
    }

    cout << dayProfit << endl;

    return 0;
}

/*


                                if (A[i] == 0)
                                {
                                    valueA[0] = valueA[1] = valueA[2] = valueA[3] = -100;
                                }
                                else
                                {
                                    valueA[0] = A[i] * 100;
                                    valueA[1] = A[i] * 75;
                                    valueA[2] = A[i] * 50;
                                    valueA[3] = A[i] * 25;
                                }

                                if (B[j] == 0)
                                {
                                    valueB[0] = valueB[1] = valueB[2] = valueB[3] = -100;
                                }
                                else
                                {
                                    valueB[0] = B[j] * 75;
                                    valueB[1] = B[j] * 50;
                                    valueB[2] = B[j] * 25;
                                    valueB[3] = B[j] * 100;
                                }

                                if (C[k] == 0)
                                {
                                    valueC[0] = valueC[1] = valueC[2] = valueC[3] = -100;
                                }
                                else
                                {
                                    valueC[0] = C[k] * 50;
                                    valueC[1] = C[k] * 25;
                                    valueC[2] = C[k] * 100;
                                    valueC[3] = C[k] * 75;
                                }

                                if (D[l] == 0)
                                {
                                    valueD[0] = valueD[1] = valueD[2] = valueD[3] = -100;
                                }
                                else
                                {
                                    valueD[0] = D[l] * 25;
                                    valueD[1] = D[l] * 100;
                                    valueD[2] = D[l] * 75;
                                    valueD[3] = D[l] * 50;
                                }

                                value1 = valueA[0] + valueB[0] + valueC[0] + valueD[0];
                                profit[m++] = value1;

                                value2 = valueA[1] + valueB[1] + valueC[1] + valueD[1];
                                profit[m++] = value2;

                                value3 = valueA[2] + valueB[2] + valueC[2] + valueD[2];
                                profit[m++] = value3;

                                value4 = valueA[3] + valueB[3] + valueC[3] + valueD[3];
                                profit[m++] = value4;
*/