// Problem 638.cpp : This file contains the 'main' function. Program execution begins and ends there.
/*Given a string of words delimited by spaces, reverse the words in string. For example, given "hello world here", return "here world hello"

Follow-up: given a mutable string representation, can you perform this operation in-place?*/

#include <iostream>
#include <string>

using namespace std;

void reverseChars(string& sentence, int start, int end) {
    while (start < end) {
        char temp = sentence[start];
        sentence[start] = sentence[end];
        sentence[end] = temp;
        end--;
        start++;
    }
}

void reverseSentence(string& sentence) {
    int start = 0;
    int end = sentence.length() - 1;
    reverseChars(sentence, start, end);
}

void reverseWords(string& sentence) {
    int start = 0;
    int end;
    for (int i = 0; i < sentence.length(); i++) {
        if (sentence[i] == ' ') {
            end = i - 1;
            reverseChars(sentence, start, end);
            start = i + 1;
        } 
    }
    end = sentence.length() - 1;
    reverseChars(sentence, start, end);
}

int main()
{
    string sentence = "";
    while (1) {
        string sentence;
        cout << "Enter sentence: ";
        getline(cin, sentence);
        if (sentence == "exit") {
            break;
        }
        reverseSentence(sentence);
        reverseWords(sentence);
        cout << "Reversed words: " << sentence << endl;
    }

}
