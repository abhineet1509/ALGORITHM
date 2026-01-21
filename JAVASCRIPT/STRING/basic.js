class StringOperations {

    reverseString(str) {
        let res = "";
        for (let i = str.length - 1; i >= 0; i--) {
            res += str[i];
        }
        return res;
    }

    isBinary(str) {
        for (let ch of str) {
            if (ch !== '0' && ch !== '1')
                return false;
        }
        return true;
    }

    toCamelCase(str) {
        let res = "";
        let makeUpper = false;

        for (let ch of str) {
            if (ch === ' ' || ch === '_' || ch === '-') {
                makeUpper = true;
            } else {
                if (makeUpper) {
                    res += ch.toUpperCase();
                    makeUpper = false;
                } else {
                    res += ch.toLowerCase();
                }
            }
        }
        return res;
    }

    isPalindrome(str) {
        let left = 0, right = str.length - 1;

        while (left < right) {
            if (str[left] !== str[right])
                return false;
            left++;
            right--;
        }
        return true;
    }

    isPangram(str) {
        let set = new Set();

        for (let ch of str.toLowerCase()) {
            if (ch >= 'a' && ch <= 'z') {
                set.add(ch);
            }
        }
        return set.size === 26;
    }
}

// -------- MAIN --------
let obj = new StringOperations();

let str1 = "hello";
let str2 = "101010";
let str3 = "hello world example";
let str4 = "madam";
let str5 = "The quick brown fox jumps over the lazy dog";

console.log("Reverse:", obj.reverseString(str1));
console.log("Is Binary:", obj.isBinary(str2));
console.log("Camel Case:", obj.toCamelCase(str3));
console.log("Is Palindrome:", obj.isPalindrome(str4));
console.log("Is Pangram:", obj.isPangram(str5));
