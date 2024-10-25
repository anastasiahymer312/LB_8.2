#include <iostream>
#include <string>
#include <sstream>
#include <limits>

using namespace std;

string removeBrackets(const string& str) {
    stringstream ss(str);
    string result;
    char c;
    int depth = 0; 

    
    while (ss.get(c)) {
        if (c == '(') {
            depth++; 
        }
        else if (c == ')') {
            depth--; 
        }
        else if (depth == 0) {
            result += c; 
        }
    }
    return result; 
}

size_t minLengthOfDigits(const string& str) {
    size_t minLength = numeric_limits<size_t>::max(); 
    size_t len = 0;
    size_t start = 0;

    while ((start = str.find_first_of("0123456789", start)) != string::npos) {
        size_t finish = str.find_first_not_of("0123456789", start);
        if (finish == string::npos) {
            finish = str.length();
        }
        len = finish - start;

        if (len < minLength) {
            minLength = len;
        }
        start = finish + 1; 
    }

    return minLength == numeric_limits<size_t>::max() ? 0 : minLength;
}

int main() {
    string str;
    cout << "Enter string:" << endl;
    getline(cin, str);

    // Видалення дужок та виведення результату
    string modifiedStr = removeBrackets(str);
    cout << "String without brackets: " << modifiedStr << endl;

    // Підрахунок найменшої кількості цифр
    size_t minLength = minLengthOfDigits(modifiedStr);
    cout << "Length of min groups of digits: " << minLength << endl;

    return 0;
}
