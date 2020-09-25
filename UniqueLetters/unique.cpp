/*******************************************************************************
 * Name        : unique.cpp
 * Author      : Luke McEvoy
 * Date        : September 23, 2020
 * Description : Determining uniqueness of chars with int as bit vector.
 * Pledge      : I pledge my honor I have abided by the Stevens Honor System.
 ******************************************************************************/
#include <iostream>
#include <cctype>
#include <sstream>

using namespace std;

bool is_all_lowercase(const string &s) {
    // TODO: returns true if all characters in string are lowercase
    // letters in the English alphabet; false otherwise.
    int a = 97;
    int z = 122;
    for (long unsigned int i = 0; i < s.length(); i++) {
        int i_ascii = (int)s[i];
        if (!((a <= i_ascii) && (i_ascii <= z))) {
            return false;
        }
    }
    return true;
}

bool is_all_char(const string &s) {
    for (long unsigned int i = 0; i < s.length(); i++) {
        if (isdigit(s[i])) {
            return false;
        }
    }
    return true;
}

bool all_unique_letters(const string &s) {
    // TODO: returns true if all letters in string are unique, that is
    // no duplicates are found; false otherwise.
    // You may use only a single int for storage and work with bitwise
    // and bitshifting operators.
    // No credit will be given for other solutions.
    unsigned int bitwise_reference = 0;
    int a_ascii = 'a';
    int current_letter;

    for(char i : s) {
        current_letter = 1 << (i - a_ascii);
        if ((int(bitwise_reference & current_letter)) == current_letter) {
            return false;
        }
        bitwise_reference = bitwise_reference | current_letter;
    }
    return true;
}

void usage_error_message() {
    cerr << "Usage: ./unique <string>" << endl;
}

void input_error_message() {
    cerr << "Error: String must contain only lowercase letters." << endl;
}

int main(int argc, char * const argv[]) {
    // TODO: reads and parses command line arguments.
    // Calls other functions to produce correct output.

    string s;
    istringstream iss;

    if (argc != 2) { 
        usage_error_message();
        return 1;
    }

    iss.str(argv[1]);
    (iss >> s);

    if(!(is_all_lowercase(s))) {
        input_error_message();
        return 1;
    }

    if (!is_all_char(s)) {
        input_error_message();
        return 1;
    }

    if (all_unique_letters(s)) {
        cout << "All letters are unique." << endl;
        return 0;
    }

    cout << "Duplicate letters found." << endl;
    return 1;

}
