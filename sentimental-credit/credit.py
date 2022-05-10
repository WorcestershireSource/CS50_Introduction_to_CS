from cs50 import get_int

card = get_int("What is card number? ")
str_card = str(card)

c_length = len(str_card)

two_digit = int(card / (10 ** (c_length - 2)))

if two_digit < 50 or two_digit > 39 and (c_length == 13 or c_length == 16):
    company = "VISA"
elif two_digit < 56 and two_digit > 50 and c_length == 16:
    company = "MASTERCARD"
elif two_digit == 34 or two_digit == 37 and c_length == 15:
    company = "AMEX"


luhn = 0

for i in range(0, c_length + 1, 2):
    luhn += int(str_card[c_length - (i + 1)])
    print(str(i) + " digit luhn is " + str(luhn))
    if c_length - (i + 2) > -1:
        z = int(str_card[c_length - (i + 2)]) * 2
        print(str(z))
        if z > 9:
            luhn += (z - 10) + 1
        elif z < 10:
            luhn += z
        print(str(i + 1) + " digit luhn is " + str(luhn))

print(str_card[0])

if luhn % 10 == 0:
    print(company)
else:
    print("INVALID")






