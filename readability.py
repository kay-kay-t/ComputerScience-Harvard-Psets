from cs50 import get_string

text = get_string("Text:")

lettercount = 0
wordcount = 1
sentencecount = 0

# i - amount of symbols
for i in range(len(text)):
        
    if text[i].isalpha():
        lettercount += 1
    elif text[i] == ' ':
        wordcount += 1
    elif text[i] == '.' or text[i] == '!' or text[i] == '?':
        sentencecount += 1
       
# calculating the grade by formula
L = lettercount / wordcount * 100
S = sentencecount / wordcount * 100
grade = round(0.0588 * L - 0.296 * S - 15.8)
if grade > 16:
    print("Grade 16+")
elif grade > 1 and grade < 17:
    print(f"Grade {grade}")
else:
    print("Before Grade 1")