/*******************************************************************************
 * Name        : stairclimber.cpp
 * Author      : Luke McEvoy
 * Date        : October 2, 2020
 * Description : Lists the number of ways to climb n stairs.
 * Pledge      : I pledge my honor that I have abided by the Stevens Honor System.
 ******************************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iomanip>
#include <cmath>

using namespace std;

vector<vector<int>> get_ways(int num_stairs) {

    // TODO: Return a vector of vectors of ints representing
    // the different combinations of ways to climb num_stairs
    // stairs, moving up either 1, 2, or 3 stairs at a time.
    vector<vector<int>> ways;
    if (num_stairs <= 0) {
        ways.push_back(vector<int>());
    } else {
        for (int i = 1; i <= 3; i++) {
            if (num_stairs >= i) {
                vector<vector<int>> result = get_ways(num_stairs - i);
                for (auto &sub_vector : result) {
                    sub_vector.insert(sub_vector.begin(), i);
                }
                ways.insert(ways.end(), result.begin(), result.end());
            }
        }
    }
    return ways;

}

int num_digits(int num) {
    int digits_count = 1;
    while (floor(num/10) != 0) {
        digits_count++;
        num = floor(num/10);
    }
    return digits_count;
}

void display_ways(const vector<vector<int>> &ways) {
    // TODO: Display the ways to climb stairs by iterating over
    // the vector of vectors and printing each combination.
    // const int max_prime_width = num_digits();
    // const int primes_per_row = 80 / (max_prime_width + 1);
    int line_count = 1;
    for (auto &sub_vector : ways) {
        if ((line_count < 10) && (ways.size() > 10)) {
            cout << " " << right << line_count++ << ". [";
        } else {
            cout << right << line_count++ << ". [";
        }
        for (long unsigned int i = 0; i < sub_vector.size()-1; i++) {
            cout << sub_vector[i] << ", ";
        } 
        cout << sub_vector[sub_vector.size()-1] << "]" << endl;
    }
    
}

int main(int argc, char * const argv[]) {
    int num_stairs;
    istringstream iss;

    // Case 1: No input arguments
    // Case 2: Too many input arguments
    if (argc != 2) {
        cerr << "Usage: ./stairclimber <number of stairs>" << endl;
        return 1;
    }

    // Case 3: Bad input type
    // Case 4: Bad input range
    iss.str(argv[1]);
    if ( !(iss >> num_stairs) || (num_stairs <= 0)) {
        cerr << "Error: Number of stairs must be a positive integer." << endl;
        return 1;
    }
    iss.clear();

    vector<vector<int>> ways = get_ways(num_stairs);
    long unsigned int counter = ways.size();
    if (num_stairs == 1) {
        cout << "1 way to climb 1 stair." << endl;
    } else {
        cout << counter << " ways to climb " << num_stairs << " stairs." << endl; 
    }
    display_ways(ways);
    return 0;
}

