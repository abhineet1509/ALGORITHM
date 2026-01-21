
def is_palindrome_array(arr):
    return arr == arr[::-1]


n = int(input("Enter size of array: "))
arr = list(map(int, input("Enter elements: ").split()))

print("Palindrome" if is_palindrome_array(arr) else "Not Palindrome")

def is_palindrome_string(s):
    return s == s[::-1]


s = input("Enter a string: ")
print("Palindrome" if is_palindrome_string(s) else "Not Palindrome")

def is_palindrome_number(n):
    original = n
    rev = 0

    while n > 0:
        rev = rev * 10 + n % 10
        n //= 10

    return original == rev


num = int(input("Enter a number: "))
print("Palindrome" if is_palindrome_number(num) else "Not Palindrome")
