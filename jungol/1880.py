key = input()
str_ = input().split()
for word in str_:
    for w in word:
        print(key[ord(w)-97] if w.islower() else key[ord(w)-65].upper(), end='')
    print(' ', end='')
