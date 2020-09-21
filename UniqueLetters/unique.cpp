/*******************************************************************************
 * Name        : unique.cpp
 * Author      : 
 * Date        : 
 * Description : Determining uniqueness of chars with int as bit vector.
 * Pledge      :
 ******************************************************************************/
#include <iostream>
#include <cctype>


using namespace std;

bool is_all_lowercase(const string &s) {
    // TODO: returns true if all characters in string are lowercase
    // letters in the English alphabet; false otherwise.
    int a = 97;
    int z = 122;
    for (long unsigned int i = 0; i < s.length(); i++) {
        int i_ascii = (int)s[i];
        // cout << "i_ascii: " << i_ascii << endl;
        // cout << "(a <= i_ascii): " << a << ", " << i_ascii << ", bool: " << bool(a <= i_ascii) << endl;
        // cout << "(i_ascii <= z): " << i_ascii << ", " << z << ", bool: " << bool(i_ascii <= z) << endl;
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

    if (argc == 1) { 
        usage_error_message();
        return 1;
    }

    if (argc > 2) { 
        usage_error_message();
        return 1;
    }

    // if (!all_unique_letters) {
    //     input_error_message();
    // }

    if (!is_all_char(argv[1])) {
        input_error_message();
        return 1;
    }

    cout << is_all_lowercase(argv[1]) << endl;

    return 0;


}
