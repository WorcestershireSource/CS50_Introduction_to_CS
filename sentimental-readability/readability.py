from cs50 import get_string
import sys

input = get_string("Text: ")

# Count words sentences and letters in string
word_list = input.split()
num_words = len(word_list)
num_letters = sum(c.isalpha() for c in input)
num_sentences = input.count('.') + input.count('?') + input.count('!')

# Calculate averages and readability index score
av_letters = (num_letters / num_words) * 100
av_words = (num_sentences / num_words) * 100
index = round((0.0588 * av_letters) - (0.296 * av_words) - 15.8)

if index < 1:
    print("Before Grade 1")
elif index > 1 and index < 16:
    print("Grade " + str(index))
elif index > 15:
    print("Grade 16 +")
else:
    sys.exit(1)

print("words: " + str(num_words))
print("letters: " + str(num_letters))
print("sentences: " + str(num_sentences))
