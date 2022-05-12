import csv
import sys


def main():

    # Check for command-line usage
    if len(sys.argv) != 3:
            sys.exit("Usage: dna.py FILENAME FILENAME")

    people = []
    # Read database file into a variable
    with open(sys.argv[1], "r") as file:
        reader = csv.DictReader(file)
        for row in reader:
            people.append(row)

    # Read DNA sequence file into a variable
    with open(sys.argv[2], "r") as file2:
        reader = csv.reader(file2)
        for row in reader:
            sequence = row[0]


    # Find longest match of each STR in DNA sequence
    dna = []
    for key in people[0]:
        if key != "name":
            tmp = {"dna": key, "count": 0}
            dna.append(tmp)

    x = len(dna)

    for i in range(x):
        dna[i]["count"] = longest_match(sequence, dna[i]["dna"])

    # Check database for matching profiles
    num = len(people)
    count = 0
    for i in range(num):
        for j in range(x):
            if dna[j]["count"] == people[i][dna[j]["dna"]]:
                count += 1

    if count == x:
        print(people[i]["name"])
        return
    else:
        print("No match")

    return


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()
