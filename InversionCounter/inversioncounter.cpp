/*******************************************************************************
 * Name        : inversioncounter.cpp
 * Author      : Luke McEvoy
 * Version     : 1.0
 * Date        : October 29, 2020
 * Description : Counts the number of inversions in an array.
 * Pledge      : I pledge my honor I have abided by the Stevens Honor System.
 ******************************************************************************/
#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>
#include <cstdio>
#include <cctype>
#include <cstring>

using namespace std;

// Function prototype.
static long mergesort(int array[], int scratch[], int low, int high);

/**
 * Counts the number of inversions in an array in theta(n^2) time.
 */
long count_inversions_slow(int array[], int length) {
    long counter = 0;
    for (int i = 0; i < length - 1; i++) {
        for (int j = 1 + i; j < length; j++) {
            if (array[i] > array[j]) {
                counter = counter + 1;
            }
        }
    }
    return counter;
}

/**
 * Counts the number of inversions in an array in theta(n lg n) time.
 */
long count_inversions_fast(int array[], int length) {
    int* scratch = new int[length];
    return mergesort(array, scratch, 0, length-1);
}

static long mergesort(int array[], int scratch[], int low, int high) {
    long number = 0;

    if (low < high) {
    	int mid = low + (high - low) / 2;
    	number = number + mergesort(array, scratch, low, mid);
    	number = number + mergesort(array, scratch, mid+1, high);
    	int L = low;
    	int H = mid + 1;
    	for (int i = low; i <= high; i++) {
    		if (L <= mid && (H > high || array[L] <= array[H]) ) {
    			scratch[i] = array[L];
    			L = L + 1;
    		} else {
    			scratch[i] = array[H];
                number = number + (mid - L) + 1;
                H = H + 1;
            }
        }
        for (int j = low; j <= high; j++) {
          array[j] = scratch[j];
      }
  }
  return number;
}

int main(int argc, char *argv[]) {
    // TODO: parse command-line argument
    istringstream var;
    string answer;
    if (argc > 1) {
        if (argc == 2) {
            var.str(argv[1]);
            var >> answer;
            if ( answer.compare("slow") != 0) {
                cerr << "Error: Unrecognized option '" << answer << "'."  << endl;
                return 1;
            }
        } else {
            cerr << "Usage: ./inversioncounter [slow]" << endl;
            return 1;
        }
    }

    cout << "Enter sequence of integers, each followed by a space: " << flush;

    istringstream iss;
    int value, index = 0;
    vector<int> values;
    string str;
    str.reserve(11);
    char c;
    while (true) {
        c = getchar();
        const bool eoln = c == '\r' || c == '\n';
        if (isspace(c) || eoln) {
            if (str.length() > 0) {
                iss.str(str);
                if (iss >> value) {
                    values.push_back(value);
                } else {
                    cerr << "Error: Non-integer value '" << str
                    << "' received at index " << index << "." << endl;
                    return 1;
                }
                iss.clear();
                ++index;
            }
            if (eoln) {
                break;
            }
            str.clear();
        } else {
            str += c;
        }
    }

    if (values.size() == 0) {
        cerr << "Error: Sequence of integers not received." << endl;
        return 1;
    }

    int* array = new int[(int)values.size()];
    for (int i = 0; i < (int)values.size(); i++) {
        array[i] = values[i];
    }
    if (argc == 1) {
        cout << "Number of inversions: "
        << count_inversions_fast(array, values.size()) << endl;
    }
    else if (answer == "slow") {
        cout << "Number of inversions: " << count_inversions_slow(array, values.size()) << endl;
    }

    delete [] array;
    return 0;
}
