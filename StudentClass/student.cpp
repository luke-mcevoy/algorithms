/*
 * student.cpp
 *
 *  Created on: Sep 9, 2020
 *      Author: Luke McEvoy
 */
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

class Student {
public:
	Student(string first, string last, float gpa, int id) :
		first_{first}, last_{last}, gpa_{gpa}, id_{id} {}

	string full_name() const {
		return first_ + " " + last_;
	}

	int id() const {
		return id_;
	}

	float gpa() const {
		return gpa_;
	}

	void print_info() const {
		cout << full_name() << ", GPA: " << gpa()
				<< ", ID: " << id() << endl;
	}

private:
	string first_;
	string last_;
	float gpa_;
	int id_;
};

vector<Student> find_failing_students(const vector<Student> &students) {
	vector<Student> failing_students;
	for (const auto &student : students) {
		if (student.gpa() < 1) {
			failing_students.push_back(student);
		}
	}
	return failing_students;
}

void print_students(const vector<Student> &students) {
	for (auto it = students.cbegin(); it != students.cend(); ++it) {
		it->print_info();
	}
}

int main() {
	string first_name, last_name;
	float gpa;
	int id;
	char repeat;
	vector<Student> students;

	do {
		cout << "Enter student's first name: ";
		cin >> first_name;
		cout << "Enter student's last name: ";
		cin >> last_name;
		gpa = -1;
		while (gpa < 0 || gpa > 4) {
			cout << "Enter student's GPA (0.0-4.0): ";
			cin >> gpa;
		}
		cout << "Enter student's ID: ";
		cin >> id;
		students.push_back(Student(first_name, last_name, gpa, id));
		cout << "Add another student to database (Y/N)? ";
		cin >> repeat;
	} while (repeat == 'Y' || repeat == 'y');

	cout << endl << "All students: " << endl;
	print_students(students);

	cout << endl << "Failing students:";
	vector<Student> failing_students = find_failing_students(students);

	if (failing_students.size() == 0) {
		cout << " None" << endl;
	} else {
		cout << endl;
		for (auto it = failing_students.cbegin(); it != failing_students.cend(); ++it) {
			it->print_info();
		}
	}
	// TODO
	// Print a space and the word 'None' on the same line if no students are failing.
	// Otherwise, print each failign student on a seperate line.

	return 0;








}

