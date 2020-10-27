import itertools

def shuffle(s,t):
    string = s+t
    for i in itertools.permutations(string):
        print(''.join(i))

word = input("palavra1 \n")
word2 = input("palavra2: \n")
shuffle(word,word2)