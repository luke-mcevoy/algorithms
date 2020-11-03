/*******************************************************************************
 * Name    : waterjugpuzzle.cpp
 * Author  : Luke McEvoy
 * Version : 1.0
 * Date    : October 19, 2020
 * Description : Waterjug sequence
 * Pledge : I pledge my honor that I have abided by the Stevens Honor System.
 ******************************************************************************/
#include <iostream>
#include <sstream>

using namespace std;

// Struct to represent state of water in the jugs
struct State {
    int a, b, c;
    string directions;
    State *parent;

    State(int _a, int _b, int _c, string _directions) :
        a{_a}, b{_b}, c{_c}, directions{_directions}, parent{nullptr} { }

    // String representation of state in tuple form
    string to_string() {
        ostringstream oss;
        oss << "(" << a << ", " << b << ", " << c << ")";
        return oss.str();
    }
};


int main(int argc, char** argv) {

    int jug_input[6];
    string jugKey[3] = {"A", "B", "C"};

    if (argc != 7){
		cerr << "Usage: ./waterjugpuzzle <cap A> <cap B> <cap C> <goal A> <goal B> <goal C>";
		return 1;
	}

	for (int i = 1; i < argc; i++) {
		istringstream iss(argv[i]);
		iss >> jug_input[i];
		bool capacity_to_goal = (i <= 3 && jug_input[i] <= 0);
		
		if (!iss || jug_input[i] < 0 || capacity_to_goal) {
			if (i <= 3) {
				cerr << "Error: Invalid capacity '" << argv[i] << "' for jug " << jugKey[(i-1)%3] << ".";
                iss.clear();
                return 1;
            }
            cerr << "Error: Invalid goal '" << argv[i] << "' for jug " << jugKey[(i-1)%3] << ".";
            iss.clear();
            return 1;
		}
        iss.clear();
	}

	int capacity = 0;
	for (int i = 1; i <= 3; i++) {
		capacity += jug_input[i + 3];
		if (jug_input[i] < jug_input[i + 3]) {
			cerr << "Error: Goal cannot exceed capacity of jug " << jugKey[(i-1)%3] << ".";
			return false;
		}
	}

	if (capacity != jug_input[3]) {
		cerr << "Error: Total gallons in goal state must be equal to the capacity of jug C.";
		return 1;
	}
    cout << "No solution.";
	return 0;
}