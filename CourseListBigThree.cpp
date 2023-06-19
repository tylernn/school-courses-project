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
#include <string>
using namespace std;

// Copy constructor
CourseList::CourseList(const CourseList& courseCopy)
{
	if (courseCopy.count == 0)
	{
		first = last = new Node;
		count = 0;
		(*this).clearList();
	}
	else
	{
		first = new Node(courseCopy.first->getCourse(), nullptr);
		first->setNext(new Node(courseCopy.last->getCourse(), nullptr));
		count = courseCopy.count;
	}
}

// Definition overloaded assignment operator
CourseList& CourseList::operator=(const CourseList& courseAssign)
{
	if (&courseAssign == this)
	{
		cerr << "Attempted assignment to itself." << endl;
	}
	else
	{
		if (courseAssign.count == 0)
		{
			(*this).clearList();
		}
		else if (count == 0)
		{
			(*this).copyCallingObjIsEmpty(courseAssign);
		}
		else if (count == courseAssign.count)
		{
			(*this).copyObjectsSameLength(courseAssign);
		}
		else if (count > courseAssign.count)
		{
			(*this).copyCallingObjLonger(courseAssign);
		}
		else 
		{
			(*this).copyCallingObjShorter(courseAssign);
		}
	}
	return *this;
}

// Definition function copyCallingObjIsEmpty
void CourseList::copyCallingObjIsEmpty(const CourseList& emptyList)
{
	Node* currentEmpty = emptyList.first;

	while (currentEmpty != nullptr)
	{
		this->addCourse(currentEmpty->getCourse());
		currentEmpty = currentEmpty->getNext();
	}
}

// Definition function copyObjectsSameLength
void CourseList::copyObjectsSameLength(const CourseList& sameLenList)
{
	Node* currentSameLen = sameLenList.first;
	Node* current = first;

	while (current != nullptr)
	{
		current->setCourse(currentSameLen->getCourse());
		current = current->getNext();
		currentSameLen = currentSameLen->getNext();
	}
}

// Definition function copyCallingObjLonger
void CourseList::copyCallingObjLonger(const CourseList& shorterList)
{
	Node* currentShorter = shorterList.first;
	Node* current = first;

	while (currentShorter != nullptr)
	{
		current->setCourse(currentShorter->getCourse());
		if (currentShorter->getNext() != nullptr)
		{
			current = current->getNext();
		}
		currentShorter = currentShorter->getNext();
	}
	current->setNext(nullptr);
	current = current->getNext();
	delete current;
	current = nullptr;
}

// Definition function copyCallingObjShorter
void CourseList::copyCallingObjShorter(const CourseList& longerList)
{
	Node* currentLonger = longerList.first;
	Node* current = first;

	while (current->getNext() != nullptr)
	{
		current->setCourse(currentLonger->getCourse());
		current = current->getNext();
		currentLonger = currentLonger->getNext();
	}

	current->setCourse(currentLonger->getCourse());
	currentLonger = currentLonger->getNext();

	while (currentLonger != nullptr)
	{
		Node* newNode = new Node(currentLonger->getCourse(), nullptr);
		current->setNext(newNode);
		current = newNode;
		currentLonger = currentLonger->getNext();
	}
	count = longerList.count;
}

// Destructor
CourseList::~CourseList()
{
	if (count != 0) {
		clearList();
	}
}