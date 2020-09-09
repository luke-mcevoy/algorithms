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
	cout << "Compiled" << endl;
	return 0;
}

