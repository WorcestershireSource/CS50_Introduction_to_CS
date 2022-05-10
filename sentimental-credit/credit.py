from cs50 import get_int

card = get_int("What is card number? ")

c_length = len(str(card))

two_digit = card / (10 ** (c_length - 2))

if two_digit < 50 or two_digit > 39:
    company = "VISA"
elif two_digit < 56 and two_digit > 50:
    company = "MASTERCARD"
elif two_digit == 34 or two_digit == 37:
    company = "AMEX"

luhn = 0

for i in range(17):
    if i % 2 == 0 and (((card % 10) * 2) > 9):
        luhn += (((card % 10) * 2) % 10) + ((((card % 10) * 2) / 10) % 10)
    elif (i % 2 > 0):
        luhn += (card % 10)
    else:
        luhn += (card % 10) * 2
    card = int(card / 10)


if luhn % 10 == 0:
    print(company)
else:
    print("INVALID")

print(luhn)
print(company)




