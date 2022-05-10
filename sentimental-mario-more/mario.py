from cs50 import get_int

while True:
    height = get_int("Height: ")
    if height < 8:
        break

for i in range(height):
    print(" " * (height - i), end="")
    print("#" * i, end="")
    print("  ", end="")
    print("#" * i)



