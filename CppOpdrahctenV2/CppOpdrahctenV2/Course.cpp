#include "Course.h"

#include <iostream>
#include <string>


Course::Course(const std::string& courseName, int capacity) {
	numberOfStudents = 0;
	this->courseName = courseName;
	this->capacity = capacity;
	students = new std::string[capacity];
}

Course::Course(const Course& course) {
	numberOfStudents = course.numberOfStudents;
	this->courseName = course.courseName;
	this->capacity = course.capacity;
	this->students = new std::string[this->capacity];
	for (int i = 0; i < this->numberOfStudents; i++) {
		this->students[i] = course.students[i];
	}
}

Course::~Course() {
	delete[] students;
}

std::string Course::getCourseName() const {
	return courseName;
}

void Course::addStudent(const std::string& name) {
	if (numberOfStudents >= capacity) {
		// Increase array size
		int newCapacity = capacity * 2;
		std::string* newStudents = new std::string[newCapacity];
		for (int i = 0; i < numberOfStudents; i++) {
			newStudents[i] = students[i];
		}
		delete[] students;
		students = newStudents;
		capacity = newCapacity;
	}
	students[numberOfStudents] = name;
	numberOfStudents++;
}

void Course::dropStudent(const std::string& name) {
	int index = -1;
	for (int i = 0; i < numberOfStudents; i++) {
		if (students[i] == name) {
			index = i;
			break;
		}
	}

	if (index != -1) {
		// Shift the remaining elements to fill the gap
		for (int i = index; i < numberOfStudents - 1; i++) {
			students[i] = students[i + 1];
		}
		numberOfStudents--;
	}
}

std::string* Course::getStudents() const {
	return students;
}

int Course::getNumberOfStudents() const {
	return numberOfStudents;
}

void Course::clear() {
	delete[] students;
	students = new std::string[capacity];
	numberOfStudents = 0;
}