/*
	OptiFlex Technologies Inc.

	Tran, Alvin
	Nguyen, Tyler

	Fall 2022
	CS A250 - C++ 2
	Project: CS Courses
*/

#ifndef COURSELIST_H
#define COURSELIST_H

#include "Course.h"

#include <string>
#include <set>

class Node
{
public:
	Node() : course(), next(nullptr) {}
	Node(const Course& newCourse, Node* newNext)
		: course(newCourse), next(newNext) {}
	Course getCourse() const { return course; }
	Node* getNext() const { return next; }
	void setCourse(const Course& newCourse) { course = newCourse; }
	void setNext(Node* newNext) { next = newNext; }
	~Node() {}
private:
	Course course;
	Node* next;
};

class CourseList
{
public:
	// Default constructor
	CourseList() : first(nullptr), last(nullptr), count(0) {}

	// Functions addCourse
	void addCourse(const Course& newCourse);
	void addCourse(int courseNumber, const std::string& courseName,
		int courseUnits, const std::set<int>& prereqs);

	// Accessor functions
	std::string getPrefix() const;
	int getNumberOfCourses() const;

	// Boolean functions
	bool isEmpty() const;
	bool searchCourse(int courseNum) const;
	bool searchCourse(int courseNum, std::string& courseName) const;
	bool searchCourse(int courseNum, Course& course) const;

	// Function deleteCourse
	void deleteCourse(int courseNumDelete);

	// Function retrieveAllCourses
	void retrieveAllCourses(std::string& courses);

	// Function clearList
	void clearList();

	/********************* THE BIG THREE *********************/

	// Copy constructor	
	CourseList(const CourseList& courseCopy);

	// Overloaded assignment operator
	CourseList& operator=(const CourseList& courseAssign);

	// Destructor
	~CourseList();

private:
	// Function getCourseLocation
	virtual Node* getCourseLocation(int courseNumSearch) const;

	// Function insertInOrder
	void insertInOrder(Node* insert);

	// Helper functions for overloaded assignment operator
	void copyCallingObjIsEmpty(const CourseList& emptyList);
	void copyObjectsSameLength(const CourseList& sameLenList);
	void copyCallingObjLonger(const CourseList& shorterList);
	void copyCallingObjShorter(const CourseList& longerList);

	Node* first;
	Node* last;
	int count;
};

#endif