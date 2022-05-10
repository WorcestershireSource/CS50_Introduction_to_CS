from cs50 import get_int

card = get_int("What is card number? ")
str_card = str(card)

c_length = len(str_card)

two_digit = card / (10 ** (c_length - 2))

if two_digit < 50 or two_digit > 39:
    company = "VISA"
elif two_digit < 56 and two_digit > 50:
    company = "MASTERCARD"
elif two_digit == 34 or two_digit == 37:
    company = "AMEX"

luhn = 0

for i in range(0, c_length, 2):
    j = int(str_card[c_length - (i + 1)]
    luhn += int(j)
    print(luhn)

    z = int(j) * 2
    if z > 9:
        luhn += z - 10 + 10
    elif z < 10:
        luhn += z
    print(luhn)


if luhn % 10 == 0:
    print(company)
else:
    print("INVALID")

print(luhn)
print(company)




