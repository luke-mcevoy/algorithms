/*******************************************************************************
 * Name    : sqrt.cpp
 * Author  : Luke McEvoy
 * Version : 1.0
 * Date    : September 2, 2020
 * Description : Computes square root using Netwon's method.
 * Pledge : I pledge my honor that I have abided by the Stevens Honor System.
 ******************************************************************************/
#include <iomanip>
#include <limits>
#include <iostream>
#include <unistd.h>

using namespace std;

double sqrt(double num, double epsilon) {

	if (num == 0 || num == 1) return num;

	double last_guess = num;
	double next_guess = ( last_guess + num/last_guess) / 2;
//	cout << setprecision(8) << next_guess;

//	cout << "Testing sqrt: last_guess " << last_guess << ", next_guess "<< next_guess << endl;
//	cout << "Testing abs: " << bool(abs(last_guess-next_guess) >= epsilon) << endl;
//	cout << "Testing epsilon: " << epsilon << endl;

	while( abs(last_guess-next_guess) >= epsilon ) {
		last_guess = next_guess;
		next_guess = (last_guess + num/last_guess) / 2;
	}

	return next_guess;

}

int main(int argc, char *argv[]) {
	double value, epsilon;
	istringstream iss;

	if (argc < 2 || argc > 3) {
		cerr << "Usage: " << argv[0] << " <value> [epsilon]" << endl;
		return 1;
	}

	if (argc == 2) {
		iss.str(argv[1]);
		if ( !(iss >> value) ) {
			cerr << "Error: Value argument must be a double." << endl;
			return 1;
		}
		iss.clear();
		epsilon = 1e-7;
	}

	if (argc == 3) {
		iss.str(argv[1]);
		if ( !(iss >> value) ) {
			cerr << "Error: Value argument must be a double." << endl;
			return 1;
		}
		iss.clear();

		iss.str(argv[2]);
		if ( !(iss >> epsilon) ) {
			cerr << "Error: Epsilon argument must be a positive double." << endl;
			return 1;
		}
		iss.clear();
	}

	if (value < 0) {
		cout << numeric_limits<double>::quiet_NaN() << endl;
		return 1;
	}

	if (epsilon <= 0) {
		cout << "Error: Epsilon argument must be a positive double." << endl;
		return 1;
	}

	cout << fixed << setprecision(8) << sqrt(value, epsilon) << endl;
	return 0;
}
