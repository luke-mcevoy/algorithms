/*
 * max.cpp
 *
 *  Created on: Sep 2, 2020
 *      Author: Luke McEvoy
 */

#include <iostream>
#include <sstream>

using namespace std;

int max(int m, int n) {
    return (m > n) ? m : n;
}

int main(int argc, char *argv[]) {
    int m, n;
    istringstream iss;

    if (argc != 3) {
        cerr << "Usage: " << argv[1] << " <integer m> <integer n>" << endl;
        return 1;
    }
    iss.str(argv[1]);
    if ( !(iss >> m) ) {
        cerr << "error: The first argument is not a valid integer." << endl;
        return 1;
    }

    iss.clear();
    iss.str(argv[2]);
    if ( !(iss >> n) ) {
        cerr << "error: The first argument is not a valid integer." << endl;
        return 1;
    }


    return 0;
}


