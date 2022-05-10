from cs50 import get_int

height = get_int("Height: ")

if height < 9 and height > 0:
    for i in range(height + 1):
        print(" " * (height - i), end="")
        print("#" * i, end="")
        print("  ", end="")
        print("#" * i)



