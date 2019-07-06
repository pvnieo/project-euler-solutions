#include <iostream>

#include <vector>

using namespace std;

vector<string> days {"MON", "TUE", "WEN", "THU", "FRI", "SAT", "SUN"};

int num_feb(int year){
    if (year % 100 == 0 && year % 400 != 0)
    {
        return 28;
    } else if (year % 100 == 0 && year % 400 == 0)
    {
        return 29;
    } else if (year % 4 == 0)
    {
        return 29;
    } else
    {
        return 28;
    } 
}

int find(vector<int> vec, int i){
    for (int j = 0; j < vec.size(); j++){
        if (i == vec[j])
            return j;
    }
    return -1;
}

int find(vector<string> vec, string key){
    for (int j = 0; j < vec.size(); j++){
        if (key == vec[j])
            return j;
    }
    return -1;
}


string next_first_month(int year, int month, string day){
    vector<int> months_1 {0, 2, 4, 6, 7, 9, 11};
    vector<int> months_2 {3, 5, 8, 10};

    if (find(months_1, month) != -1)
        return days[(find(days, day) + 3) % 7];
    else if (find(months_2, month) != -1)
        return days[(find(days, day) + 2) % 7];
    else {
        if (num_feb(year) == 28)
            return days[(find(days, day)) % 7];
        else
            return days[(find(days, day) + 1) % 7];
    }
}

struct sum_day
{
    int _sum;
    string f_day;
};

sum_day first_sundays_in_year(string f_day, int year){
    int s {0};
    if (f_day == "SUN")
        s = 1;
    for (int m = 0; m < 12; m++)
    {
        f_day = next_first_month(year, m, f_day);
        if (f_day == "SUN")
            s++;
    }
    if (f_day == "SUN")
        s--;

    struct sum_day to_return {s, f_day};
    return to_return;   
}


sum_day count_sundays(int beg, int end, string f_day){
    int s {0};
    for (int year = beg; year < end+1; year++)
    {
        struct sum_day tmp {};
        tmp = first_sundays_in_year(f_day, year);
        s += tmp._sum;
        f_day = tmp.f_day;
    }

    struct sum_day to_return {s, f_day};
    return to_return;   
}


int main() {
    struct sum_day tmp = first_sundays_in_year("MON", 1900);
    string f_day_1901 = tmp.f_day;
    tmp = count_sundays(1901, 2000, f_day_1901);

    cout << tmp._sum << endl;

    return 0;
}