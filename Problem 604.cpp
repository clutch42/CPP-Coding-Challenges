// Problem 604.cpp : This file contains the 'main' function. Program execution begins and ends there.
/*Soundex is an algorithm used to categorize phonetically, such that two names that sound alike but are spelled differently have the same representation.

Soundex maps every name to a string consisting of one letter and three numbers, like M460.

One version of the algorithm is as follows:

Remove consecutive consonants with the same sound (for example, change ck -> c).
Keep the first letter. The remaining steps only apply to the rest of the string.
Remove all vowels, including y, w, and h.
Replace all consonants with the following digits:
b, f, p, v → 1
c, g, j, k, q, s, x, z → 2
d, t → 3
l → 4
m, n → 5
r → 6
If you don't have three numbers yet, append zeros until you do. Keep the first three numbers.
Using this scheme, Jackson and Jaxen both map to J250.

Implement Soundex.*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct LetterToInt {
    vector<char> letters;
    int num;
    LetterToInt(vector<char> l, int n): letters(l), num(n) {}
};

struct ListOfConversions {
    vector<LetterToInt> list;
    ListOfConversions(vector<LetterToInt> l) : list(l) {}
};

string removeConsecutive(string word, const ListOfConversions& soundex) {
    int index = 0;
    while (index < word.length()-1) {
        char letter1 = word[index];
        int letter1Val = 0;
        char letter2 = word[index + 1];
        int letter2Val = 0;
        for (auto s : soundex.list) {
            for (auto l : s.letters) {
                if (letter1 == l) {
                    letter1Val = s.num;
                }
                if (letter2 == l) {
                    letter2Val = s.num;
                }
            }
        }
        if (letter1Val == letter2Val && letter1Val > 0) {
            word = word.erase(index + 1, 1);
            index = 0;
        }
        else {
            index++;
        }
    }
    return word;
}

string removeVowels(string word) {
    vector<char> vowels = { 'a', 'e', 'i', 'o', 'u', 'y', 'w', 'h' };
    int index = 1;
    while (index < word.length()) {
        for (auto v : vowels) {
            if (word[index] == v) {
                word = word.erase(index, 1);
                index = 0;
                break;
            }
        }
        index++;
    }
    return word;
}

string replaceConsonants(string word, const ListOfConversions& soundex) {
    for (int i = 1; i < word.length(); i++) {
        for (auto s : soundex.list) {
            for (auto l : s.letters) {
                if (word[i] == l) {
                    word[i] = '0' + s.num;
                }
            }
        }
    }
    return word;
}

string checkLength(string word) {
    if (word.length() < 4) {
        while (word.length() < 4) {
            word += '0';
        }
    }
    else if (word.length() > 4) {
        word = word.substr(0, 4);
    }
    
    return word;
}

int main()
{
    ListOfConversions soundex = ListOfConversions({
        LetterToInt({'b', 'f', 'p', 'v', 'B', 'F', 'P', 'V'}, 1),
        LetterToInt({'c', 'g', 'j', 'k', 'q', 's', 'x', 'z', 'C', 'G', 'J', 'K', 'Q', 'S', 'X', 'Z'}, 2),
        LetterToInt({'d', 't', 'D', 'T'}, 3),
        LetterToInt({'l', 'L'}, 4),
        LetterToInt({'m', 'n', 'M', 'N'}, 5),
        LetterToInt({'r', 'R'}, 6)
    });

    for (const auto& conversion : soundex.list) {
        cout << "Letters: ";
        for (const auto& letter : conversion.letters) {
            cout << letter << " ";
        }
        cout <<  "\tNumber: " << conversion.num << endl;
    }
    while (1) {
        string input;
        string transform;
        getline(cin, input);
        transform = removeConsecutive(input, soundex);
        cout << transform << endl;
        transform = removeVowels(transform);
        cout << transform << endl;
        transform = replaceConsonants(transform, soundex);
        cout << transform << endl;
        transform = checkLength(transform);
        cout << transform << endl;
    }
}
