#pragma once

#include <string>


class Course {
private:
	std::string courseName;
	std::string* students;
	int numberOfStudents;
	int capacity;

public:
	// Constructors
	Course(const std::string& courseName, int capacity);
	Course(const Course& course);

	// Destructor
	~Course();

	// Member functions
	std::string getCourseName() const;
	void addStudent(const std::string& name);
	void dropStudent(const std::string& name);
	std::string* getStudents() const;
	int getNumberOfStudents() const;
	void clear();
};
