from cs50 import get_int

card = get_int("What is card number?")

c_length = len(card)

two_digit = card / (10 ** (c_length - 2))

if two_digit < 50 or two_digit > 39)
    company = 