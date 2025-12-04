#include <iostream>
#include <string>
#include <cctype>    // for isalpha, toupper, etc.
#include <cstring>   // for C-style functions
using namespace std;

int main() {
    string s = "helloWorld123!";
    string s2 = "HELLO";

    cout << "===== LENGTH & CAPACITY =====\n";
    cout << "size(): " << s.size() << endl;
    cout << "capacity(): " << s.capacity() << endl;
    cout << "empty(): " << s.empty() << endl;
    s.resize(8);
    cout << "resize(8): " << s << endl;
    s.clear();
    cout << "clear(): " << s << " (length=" << s.length() << ")\n\n";

    s = "helloWorld123!";
    cout << "===== ELEMENT ACCESS =====\n";
    cout << "s[0]: " << s[0] << endl;
    cout << "at(2): " << s.at(2) << endl;
    cout << "front(): " << s.front() << endl;
    cout << "back(): " << s.back() << endl << endl;

    cout << "===== MODIFIERS =====\n";
    s.append("ABC");
    cout << "append('ABC'): " << s << endl;
    s.push_back('x');
    cout << "push_back('x'): " << s << endl;
    s.pop_back();
    cout << "pop_back(): " << s << endl;
    s.insert(5, "123");
    cout << "insert(5,'123'): " << s << endl;
    s.erase(5,3);
    cout << "erase(5,3): " << s << endl;
    s.replace(0,5,"HELLO");
    cout << "replace(0,5,'HELLO'): " << s << endl;
    s.swap(s2);
    cout << "swap(s2): s=" << s << ", s2=" << s2 << endl;
    s += " world";
    cout << "operator+= : " << s << endl << endl;

    cout << "===== SEARCHING =====\n";
    s = "hellotherehello";
    cout << "find('lo'): " << s.find("lo") << endl;
    cout << "rfind('lo'): " << s.rfind("lo") << endl;
    cout << "find_first_of('aeiou'): " << s.find_first_of("aeiou") << endl;
    cout << "find_last_of('aeiou'): " << s.find_last_of("aeiou") << endl;
    cout << "find_first_not_of('he'): " << s.find_first_not_of("he") << endl;
    cout << "find_last_not_of('lo'): " << s.find_last_not_of("lo") << endl << endl;

    cout << "===== SUBSTRING & COPY =====\n";
    cout << "substr(1,4): " << s.substr(1,4) << endl;
    char arr[10];
    s.copy(arr,5,0); arr[5]='\0';
    cout << "copy(5,0): " << arr << endl << endl;

    cout << "===== COMPARISON =====\n";
    string a = "abc", b = "abd";
    cout << "compare(a,b): " << a.compare(b) << endl;
    cout << "(a<b): " << (a<b) << endl << endl;

    cout << "===== CONVERSIONS =====\n";
    string num = "123";
    cout << "stoi('123'): " << stoi(num) << endl;
    cout << "stof('3.14'): " << stof("3.14") << endl;
    cout << "to_string(42): " << to_string(42) << endl << endl;

    cout << "===== INPUT/OUTPUT =====\n";
    cout << "Enter a string with spaces: ";
    string line;
    getline(cin, line);
    cout << "You entered: " << line << endl << endl;

    cout << "===== CHARACTER FUNCTIONS =====\n";
    char ch1 = 'A', ch2 = 'b', ch3 = '9', ch4 = ' ';
    cout << "isalpha('A'): " << isalpha(ch1) << endl;
    cout << "isdigit('9'): " << isdigit(ch3) << endl;
    cout << "isalnum('A'): " << isalnum(ch1) << endl;
    cout << "islower('b'): " << islower(ch2) << endl;
    cout << "isupper('A'): " << isupper(ch1) << endl;
    cout << "tolower('A'): " << (char)tolower(ch1) << endl;
    cout << "toupper('b'): " << (char)toupper(ch2) << endl;
    cout << "isspace(' '): " << isspace(ch4) << endl;
    cout << "ispunct('!'): " << ispunct('!') << endl;
    cout << "isxdigit('F'): " << isxdigit('F') << endl;
    cout << "iscntrl('\\n'): " << iscntrl('\n') << endl;
    cout << "isprint('A'): " << isprint('A') << endl;
    cout << "isgraph('!'): " << isgraph('!') << endl;
    cout << "isblank('\\t'): " << isblank('\t') << endl;
    cout << "isascii('A'): " << isascii('A') << endl;

    return 0;
}
