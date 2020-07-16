#include <bits/stdc++.h>
using namespace std;

class date
{
public:
    int month;
    long long int year;
};

int isLeap(long long int year)
{
    if ((year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0)))
        return 1;
    return 0;
}

int dayofweek(int m, int y)
{
    static int t[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
    y -= m < 3;
    return (y + y / 4 - y / 100 + y / 400 + t[m - 1] + 1) % 7;
}

int dayMonth(int month, long long int year)
{
    if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
        return 31;
    if(month == 4 || month == 6 || month == 9 || month == 11)
        return 30;
    if(month == 2){
        if (isLeap(year))
            return 29;
        else
            return 28;
    }
}

int dateCheck(date New, date temp)
{
    if (New.year > temp.year)
        return 1;
    else if (temp.month <= New.month)
        return 1;
    return 0;
}

int main()
{
    int testCases;
    cin >> testCases;

    while (testCases--)
    {
        int count = 0;
        date  dateNew, dateTemp;
        cin >> dateTemp.month >> dateTemp.year >> dateNew.month >> dateNew.year;

        while (dateCheck(dateNew, dateTemp))
        { 
              
            if (dateTemp.month == 2)
            {
                int dateMonth = dayMonth(dateTemp.month, dateTemp.year);
                int day = dayofweek(dateTemp.month, dateTemp.year);
                if ((day == 0 && dateMonth == 28) || (day == 6))
                    count++;
            }

            if(dateTemp.month == dateNew.month && dateTemp.year == dateNew.year)
                break;

            dateTemp.month++;
            if( dateTemp.month == 13 ){
                dateTemp.month = 1;
                dateTemp.year++;
            }

            while(dateTemp.month != 2 && dateTemp.month != dateNew.month){
                dateTemp.month++;
                if( dateTemp.month == 13 ){
                    dateTemp.month = 1;
                    dateTemp.year++;
                }
            }
        }
        
        cout << count << endl;
    }

    return 0;
}