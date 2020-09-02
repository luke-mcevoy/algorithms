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

using namespace std;

double sqrt(double num, double epsilon) {
	if (num < 0) return numeric_limits<double>::quiet_NaN();
	if (num == 0 || num == 1) return num;
	int last_guess;
	int next_guess;
	while( abs(last_guess-next_guess) <= epsilon ) {
		next_guess = (last_guess + num/last_guess) / 2;
	}
	return next_guess;
}

int main(int argc, char *argv[]) {
	if (argc < 2) {
		cerr << "Usage: " << argv[0] << " <toRoot> <epsilon>" << endl;
	}
	if (argc == 2) {
		int epsilon = 1e-7;
	}
	return 0;
}
