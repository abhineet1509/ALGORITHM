def valid_parentheses(s):
    stack = []
    mp = {')': '(', ']': '[', '}': '{'}

    for ch in s:
        if ch in mp.values():
            stack.append(ch)
        else:
            if not stack or stack.pop() != mp[ch]:
                return False
    return not stack


s = input()
print(valid_parentheses(s))
