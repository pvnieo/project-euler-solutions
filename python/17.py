
num_in_word = ["zero", "one", "two", "three", "four", "five", "six", "seven", "eight",
               "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen",
               "sixteen", "seventeen", "eighteen", "nineteen", "twenty"]
dic_num = {}
for i in range(21):
    dic_num[i] = num_in_word[i]

dic_num[30] = "thirty"
dic_num[40] = "forty"
dic_num[50] = "fifty"
dic_num[60] = "sixty"
dic_num[70] = "seventy"
dic_num[80] = "eighty"
dic_num[90] = "ninety"
dic_num[100] = "hundred"
dic_num[1000] = "thousand"
dic_num[" "] = "and"


def less_than_100_converter(num):
    d = num // 10
    u = num - d*10
    if d <= 1:
        return dic_num[num]
    elif u == 0:
        return dic_num[num]
    else:
        return dic_num[d*10] + dic_num[u]


def between_100_999_converter(num):
    c = num // 100
    d = (num - 100 * c) // 10
    u = num - 100 * c - 10 * d
    if (d*10 + u) == 0:
        return dic_num[c]+dic_num[100]
    else:
        return dic_num[c]+dic_num[100] + dic_num[" "] + less_than_100_converter(d*10 + u)


def num_to_letter_converter(num):
    m = num // 1000
    c = (num - 1000*m) // 100
    d = (num - 1000*m - 100 * c) // 10
    u = num - 1000*m - 100 * c - 10 * d
    num_letter = ''
    if m != 0:
        return "onethousand"
    elif c == 0:
        num_letter += less_than_100_converter(num)
    else:
        num_letter += between_100_999_converter(num)

    return num_letter


s = ""
for i in range(1, 1001):
    s += num_to_letter_converter(i)

print(len(s))
