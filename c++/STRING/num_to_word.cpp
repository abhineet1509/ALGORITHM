#include <bits/stdc++.h>
using namespace std;

class Converter {
public:
    // for number to words
    vector<string> below_20 = {"", "one", "two", "three", "four", "five", "six",
                               "seven", "eight", "nine", "ten", "eleven", "twelve",
                               "thirteen", "fourteen", "fifteen", "sixteen",
                               "seventeen", "eighteen", "nineteen"};
    vector<string> tens = {"", "", "twenty", "thirty", "forty", "fifty",
                           "sixty", "seventy", "eighty", "ninety"};

    // for words to number
    unordered_map<string, int> wordMap = {
        {"zero", 0}, {"one", 1}, {"two", 2}, {"three", 3}, {"four", 4},
        {"five", 5}, {"six", 6}, {"seven", 7}, {"eight", 8}, {"nine", 9},
        {"ten", 10}, {"eleven", 11}, {"twelve", 12}, {"thirteen", 13},
        {"fourteen", 14}, {"fifteen", 15}, {"sixteen", 16},
        {"seventeen", 17}, {"eighteen", 18}, {"nineteen", 19},
        {"twenty", 20}, {"thirty", 30}, {"forty", 40}, {"fifty", 50},
        {"sixty", 60}, {"seventy", 70}, {"eighty", 80}, {"ninety", 90},
        {"hundred", 100}, {"thousand", 1000}
    };

    // --- Number to Words ---
    string numberToWords(int num) {
        if (num == 0) return "zero";
        return helper(num);
    }

    // --- Words to Number ---
    int wordsToNumber(string s) {
        stringstream ss(s);
        string word;
        long long total = 0, current = 0;

        while (ss >> word) {
            if (wordMap[word] < 100)
                current += wordMap[word];
            else if (word == "hundred")
                current *= 100;
            else if (word == "thousand") {
                total += current * 1000;
                current = 0;
            }
        }
        total += current;
        return total;
    }

private:
    string helper(int num) {
        if (num < 20) return below_20[num];
        else if (num < 100) {
            string res = tens[num / 10];
            if (num % 10) res += " " + below_20[num % 10];
            return res;
        } else if (num < 1000) {
            string res = below_20[num / 100] + " hundred";
            if (num % 100) res += " " + helper(num % 100);
            return res;
        } else if (num < 1000000) {
            string res = helper(num / 1000) + " thousand";
            if (num % 1000) res += " " + helper(num % 1000);
            return res;
        } else {
            return "number too large";
        }
    }
};

int main() {
    Converter c;
    int choice;
    cout << "1. Number to Words\n2. Words to Number\nEnter choice: ";
    cin >> choice;
    cin.ignore();  // to clear newline from buffer

    if (choice == 1) {
        int num;
        cout << "Enter number: ";
        cin >> num;
        cout << c.numberToWords(num) << endl;
    } 
    else if (choice == 2) {
        string line;
        cout << "Enter words: ";
        getline(cin, line);
        cout << c.wordsToNumber(line) << endl;
    } 
    else {
        cout << "Invalid choice" << endl;
    }
    return 0;
}
