from cs50 import get_string

input = get_string("Text: ")

# Count words sentences and letters in string
word_list = input.split()
num_words = len(word_list)
num_letters = sum(c.isalpha() for c in input)
num_sentences = input.count('.' or '?' or '!')

# Calculate averages and readability index score
av_letters = (num_letters / num_words) * 100
av_words = (num_sentences / num_words) * 100
index = round((0.0588 * av_letters) - (0.296 * av_words) - 15.8)

if index < 1:
    print("Before Grade 1")
elif index > 1 and 

