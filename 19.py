
days = ["MON", "TUE", "WEN", "THU", "FRI", "SAT", "SUN"]
months = [(0, "January"), (1, "February"), (2, "March"), (3, "April"),
          (4, "May"), (5, "June"), (6, "July"), (7, "August"),
          (8, "September"), (9, "October"), (10, "November"), (11, "December")]

def num_feb(year):
    if year % 100 == 0 and year % 400 != 0:
        return 28
    elif year % 100 == 0 and year % 400 == 0:
        return 29
    elif year % 4 == 0:
        return 29
    else: return 28

def next_first_month(year, month, day):
    if month in [0, 2, 4, 6, 7, 9, 11]:
        return days[(days.index(day) + 3) % 7]
    elif month in [3, 5, 8, 10]:
        return days[(days.index(day) + 2) % 7]
    else:
        if num_feb(year) == 28:
            return days[(days.index(day)) % 7]
        else:
            return days[(days.index(day) + 1) % 7]

def first_sundays_in_year(f_day, year):
    s = 0 if f_day != "SUN" else 1
    for month in range(12):
        f_day = next_first_month(year, month, f_day)
        if f_day == "SUN":
            s += 1
    if f_day == "SUN":
        s -= 1 
    return (s, f_day)

f_day_1901 = first_sundays_in_year("MON", 1900)[1]

def count_sundays(beg, end, f_day):
    s = 0
    for year in range(beg, end +1):
        tmp = first_sundays_in_year(f_day, year)
        s += tmp[0]
        f_day = tmp[1]
    return (s, f_day)

print(count_sundays(1901, 2000, f_day_1901)[0])
