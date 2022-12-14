from cs50 import get_int

# Ask for input from the user
card = get_int("What is card number? ")
str_card = str(card)
c_length = len(str_card)
two_digit = int(card / (10 ** (c_length - 2)))

# Check what company the card is based on length and first two digits
company = "NULL"
if (two_digit < 50 and two_digit > 39) and (c_length == 13 or c_length == 16):
    company = "VISA"
elif (two_digit < 56 and two_digit > 50) and c_length == 16:
    company = "MASTERCARD"
elif (two_digit == 34 or two_digit == 37) and c_length == 15:
    company = "AMEX"

# Perform the luhn algorithm
luhn = 0
for i in range(1, c_length + 1, 2):
    if c_length - i > -1:
        luhn += int(str_card[c_length - i])
    if c_length - (i + 1) > -1:
        z = int(str_card[c_length - (i + 1)]) * 2
        if z > 9:
            luhn += (z - 10) + 1
        elif z < 10:
            luhn += z

# Check if luhn is divisible by 10 to check validity
# If valid, print the company name
if luhn % 10 == 0:
    print(company)
else:
    print("INVALID")