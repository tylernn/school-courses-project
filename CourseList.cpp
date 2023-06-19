/*
	OptiFlex Technologies Inc.

	Tran, Alvin
	Nguyen, Tyler

	Fall 2022
	CS A250 - C++ 2
	Project: CS Courses
*/

#include "CourseList.h"

#include <iostream>
using namespace std;

// Definition function addCourse
void CourseList::addCourse(const Course& newCourse)
{
	insertInOrder(new Node(newCourse, nullptr));
}

// Definition function addCourse
void CourseList::addCourse(int courseNumber, const string& courseName,
			   int courseUnits, const set<int>& prereqs)
{
	insertInOrder(new Node(Course(courseNumber, courseName, courseUnits,
				      prereqs), nullptr));
}

// Definition function getPrefix
std::string CourseList::getPrefix() const
{
	return Course::getPrefix();
}

// Definition function getNumberOfCourses
int CourseList::getNumberOfCourses() const
{
	return count;
}

// Definition function isEmpty
bool CourseList::isEmpty() const
{
	return (count == 0);
}

// Definition function searchCourse (courseNumber)
// Assume list is non-empty.
bool CourseList::searchCourse(int courseNum) const
{
	return (getCourseLocation(courseNum) != nullptr);
}

// Definition function searchCourse (courseNumber, courseName)
// Assume list is non-empty.
bool CourseList::searchCourse(int courseNum, string& courseName) const
{
	if (getCourseLocation(courseNum) != nullptr)
	{
		courseName = getCourseLocation(courseNum)->getCourse().getCourseName();
		return true;
	}
	else
	{
		return false;
	}
}

// Definition function searchCourse(courseNumber, course) 
// Assume list is non-empty.
bool CourseList::searchCourse(int courseNum, Course& course) const
{
	if (getCourseLocation(courseNum) != nullptr)
	{
		course = getCourseLocation(courseNum)->getCourse();
		return true;
	}
	else
	{
		return false;
	}
}

// Definition deleteCourse
// Assume list is non-empty.
// Assume course is in the list.
void CourseList::deleteCourse(int courseNumDelete)
{
	if (first->getCourse().getCourseNumber() == courseNumDelete)
	{
		Node* temp = first;
		first = first->getNext();
		delete temp;
		temp = nullptr;
		--count;
	}
	else
	{
		Node* trailCurrent = first;
		Node* current = first->getNext();

		while (current != nullptr)
		{
			if (current->getCourse().getCourseNumber() == courseNumDelete)
			{
				trailCurrent->setNext(current->getNext());
				delete current;
				current = nullptr;
				--count;
			}
			else
			{
				trailCurrent = trailCurrent->getNext();
				current = current->getNext();
			}
		}
	}
}

// Definition retrieveAllCourses
// Assume list is non-empty.
void CourseList::retrieveAllCourses(string& courses)
{
	Node* current = first;
	courses = "";

	while (current != nullptr)
	{
		courses += getPrefix() + to_string(current->getCourse()
				   .getCourseNumber()) + " - " + current->getCourse()
				   .getCourseName() + "\n";
		current = current->getNext();
	}
}

// Definition clearList
void CourseList::clearList()
{
	Node* temp = first;

	while (first != nullptr)
	{
		first = first->getNext();
		delete temp;
		temp = first;
	}
	last = nullptr;
	count = 0;
}

// Definition function getCourseLocation
Node* CourseList::getCourseLocation(int courseNumSearch) const
{
	Node* current = first;

	while (current != nullptr)
	{
		if (current->getCourse().getCourseNumber() == courseNumSearch)
		{
			return current;
		}
		else
		{
			current = current->getNext();
		}
	}
	return current;
}