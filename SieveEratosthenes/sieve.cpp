/*******************************************************************************
 * Name        : sieve.cpp
 * Author      :
 * Date        :
 * Description : Sieve of Eratosthenes
 * Pledge      :
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
        if (i < 2) { is_prime_[i] = true; } else { is_prime_[i] = false; }
    }

    for (int i = 0; i <= floor(sqrt(limit_)); i++) {
        if (is_prime_[i]) {
            for(int j = pow(i,2); j <= limit_; j++) { is_prime_[i] = false; }
        }
    }

    int iterator_to_max = limit_;
    while(!(is_prime_[iterator_to_max])) { iterator_to_max--; }
    max_prime_ = iterator_to_max;
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

    // TODO: write code that uses your class to produce the desired output.
    return 0;
}
