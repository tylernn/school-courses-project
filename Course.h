/*
	OptiFlex Technologies Inc.
	
	Tran, Alvin
	Nguyen, Tyler
	
	Fall 2022
	CS A250 - C++ 2
	Project: CS Courses
*/

#ifndef COURSE_H
#define COURSE_H

#include <string>
#include <set>

class Course
{
public:

	// Constructors
	Course() : courseNumber(0), courseName("N/A"), courseUnits(0), prereqs() {}
	Course(int newCourseNumber, const std::string& newCourseName,
               int newCourseUnits, const std::set<int>& newPrereqs);

	// Accessor functions
	int getCourseNumber() const;
	const std::string& getCourseName() const;
	int getCourseUnits() const;
	const std::set<int>& getCoursePrereqs() const;
	const Course& getCourse() const;
	static std::string getPrefix();

	// Mutator functions
	void setCourseName(const std::string& newCourseName);
	void setCourseNumber(int newCourseNumber);
    	void setCourseUnits(int newCourseUnits);
    	void setPrereqs(const int prereqTransfer[], int prereqAmount);

	// Destructor
    	~Course() {}
private:
	int courseNumber;
	std::string courseName;	
	int courseUnits;	
	std::set<int> prereqs;
	static const std::string PREFIX;
};
#endif