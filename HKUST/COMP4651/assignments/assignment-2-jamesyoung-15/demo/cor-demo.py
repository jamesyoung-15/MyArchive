import re
from collections import Counter
from pandas import DataFrame

path_to_input_text = "cor-demo-sample.txt" # Replace this by your testing input data.

def drop_empty_item(words):
    return [word for word in words if word != '']

def sort_dict_by_keys(d, reverse=True):
    keys = list(d.keys())
    keys.sort(reverse=reverse)
    return [(key,d[key]) for key in keys]

# Step 1: Tokenize the input text.
paragraph = ""
lines = []

with open(path_to_input_text, "r", encoding='unicode_escape') as f:
    for line in f.readlines():
        lines.append(drop_empty_item(re.sub("[^a-zA-Z]", " ", line).split(" ")))
        paragraph += line

paragraph = re.sub("[^a-zA-Z]", " ", paragraph)

words = paragraph.split(" ")
words = drop_empty_item(words)
word_pairs = []

# Step 2: Count the frequency for each word in the text (you should complete this in your first-pass MapReduce).
ctr=Counter(words)
ctr = sort_dict_by_keys(ctr, False)
single_key_freq = {}
for tmp in ctr:
    word = tmp[0]
    cnt = tmp[1]
    single_key_freq[word] = float(cnt)

# Step 3: Count the frequency for each word pairs in the text (you should complete this in your second-pass MapReduce).
for line in lines:
    ctr = Counter(line)
    ctr = sort_dict_by_keys(ctr, False)
    words = [y[0] for y in ctr]
    for id1 in range(len(words)):
        for id2 in range(id1+1, len(words)):
            word_pairs.append(words[id1]+"/"+words[id2])

# Step 4: Calculate the COR(A, B) for each word pairs in the text (you should complete this in your second-pass MapReduce).
ctr=Counter(word_pairs)
df = DataFrame(columns=['word1', 'word2', 'COR'])
for pair in ctr:
    cnt = ctr[pair]
    pair_freq = float(cnt)
    words = pair.split("/")
    COR = pair_freq / (single_key_freq[words[0]] * single_key_freq[words[1]])
    df.loc[len(df.index)] = [words[0], words[1], COR]
df = df.sort_values(by = ['word1', 'word2'], ascending = (True, True))
df.to_csv("result.csv", index=False, header=False, sep ='\t')
