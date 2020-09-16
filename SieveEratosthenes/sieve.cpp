/*******************************************************************************
 * Name        : sieve.cpp
 * Author      : Luke McEvoy
 * Date        : September 15, 2020
 * Description : Sieve of Eratosthenes
 * Pledge      : I pledge my honor that I have abided by the Stevens Honor System.
 ******************************************************************************/
#include <cmath>
#include <iomanip>
#include <iostream>
#include <sstream>

using namespace std;

class PrimesSieve {
public:
    PrimesSieve(int limit);

    ~PrimesSieve() {
        delete [] is_prime_;
    }

    int num_primes() const {
        return num_primes_;
    }

    void display_primes() const;

private:
    // Instance variables
    bool * const is_prime_;
    const int limit_;
    int num_primes_, max_prime_;

    // Method declarations
    int count_num_primes() const;
    void sieve();
    static int num_digits(int num);
};

PrimesSieve::PrimesSieve(int limit) :
        is_prime_{new bool[limit + 1]}, limit_{limit} {
    sieve();
}

void PrimesSieve::display_primes() const {
    // TODO: write code to display the primes in the format specified in the
    // requirements document.

    const int max_prime_width = num_digits(max_prime_), primes_per_row = 80 / (max_prime_width + 1);
	int primes_on_current_line = 0;
    bool output_over_char_limit = false;

	if(limit_ > 99){
		for(int i = 2; i <= limit_; i++){
			if(is_prime_[i]){
				if(primes_on_current_line == primes_per_row){
					cout << endl << setw(max_prime_width) << i;
					primes_on_current_line = 0;
				} else {
					if(output_over_char_limit){
						cout << setw(max_prime_width + 1) << i;
					} else {
						cout << setw(max_prime_width) << i;
						output_over_char_limit = true;
					}
				}
				primes_on_current_line++;
			}
		}
	} else {
        for (int i = 2; i <= limit_; i++) {
            if (is_prime_[i]) { 
                cout << i;
                if (i != max_prime_) {
                    cout << " ";
                }
            }
        }
    }
}

int PrimesSieve::count_num_primes() const {
    // TODO: write code to count the number of primes found
    int prime_count = 0;
    for (int i = 0; i <= limit_; i++) {
        if (is_prime_[i]) { prime_count++; }
    }
    return prime_count;
}

void PrimesSieve::sieve() {
    // TODO: write sieve algorithm
    for (int i = 0; i <= limit_; i++) {
        if (i < 2) { is_prime_[i] = false; } else { is_prime_[i] = true; }
    }

    for (int i = 2; i <= floor(sqrt(limit_)); i++) {
        if (is_prime_[i]) {
            for (int j = i*i ; j <= limit_; j+= i) { is_prime_[j] = false; }
        }
    }

    int iterator_to_max = limit_;
    while(!(is_prime_[iterator_to_max])) { iterator_to_max--; }
    max_prime_ = iterator_to_max;

    num_primes_ = count_num_primes();
}

int PrimesSieve::num_digits(int num) {
    // TODO: write code to determine how many digits are in an integer
    // Hint: No strings are needed. Keep dividing by 10.
    int digits_count = 1;
    while(floor(num/10) != 0) {
        digits_count++;
        num = floor(num/10);
    }
    return digits_count;
}

int main() {
    cout << "**************************** " <<  "Sieve of Eratosthenes" <<
            " ****************************" << endl;
    cout << "Search for primes up to: ";
    string limit_str;
    cin >> limit_str;
    int limit;

    // Use stringstream for conversion. Don't forget to #include <sstream>
    istringstream iss(limit_str);

    // Check for error.
    if ( !(iss >> limit) ) {
        cerr << "Error: Input is not an integer." << endl;
        return 1;
    }
    if (limit < 2) {
        cerr << "Error: Input must be an integer >= 2." << endl;
        return 1;
    }

    PrimesSieve primes(limit);
    cout << endl << "Number of primes found: " << primes.num_primes() << endl;
    cout << "Primes up to " << limit_str << ":" << endl;
    primes.display_primes();
    return 0;
}