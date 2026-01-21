def group_anagrams(words):
    mp = {}
    for w in words:
        key = ''.join(sorted(w))
        mp.setdefault(key, []).append(w)
    return list(mp.values())


words = input().split()
print(group_anagrams(words))
