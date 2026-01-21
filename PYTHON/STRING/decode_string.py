def decode(s):
    stack = []
    curr = ""
    num = 0

    for ch in s:
        if ch.isdigit():
            num = num * 10 + int(ch)
        elif ch == '[':
            stack.append((curr, num))
            curr, num = "", 0
        elif ch == ']':
            prev, n = stack.pop()
            curr = prev + curr * n
        else:
            curr += ch

    return curr


s = input()
print(decode(s))
