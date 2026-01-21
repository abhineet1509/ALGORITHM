def longest_common_prefix(words):
    if not words:
        return ""
    prefix = words[0]

    for w in words[1:]:
        while not w.startswith(prefix):
            prefix = prefix[:-1]
    return prefix


words = input().split()
print(longest_common_prefix(words))
