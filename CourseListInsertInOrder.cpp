/*
	OptiFlex Technologies Inc.

	Tran, Alvin
	Nguyen, Tyler

	Fall 2022
	CS A250 - C++ 2
	Project: CS Courses
*/

#include "CourseList.h"

// Definition function insertInOrder
// Assume there are no duplicates.
void CourseList::insertInOrder(Node* insert) 
{
    if (first == nullptr) 
    {
        first = last = insert;
    }
    else 
    {
        int insertNum = insert->getCourse().getCourseNumber();
        if (insertNum < first->getCourse().getCourseNumber())
        {
            insert->setNext(first);
            first = insert;
        }
        else if (insertNum > last->getCourse().getCourseNumber())
        {
            last->setNext(insert);
            insert->setNext(nullptr);
            last = insert;
        }
        else 
        {
            Node* trailCurrent = first;
            Node* current = first->getNext();

            while (current != nullptr) 
            {
                int trailValue = trailCurrent->getCourse()
                                        .getCourseNumber();
                int currentNum = current->getCourse().getCourseNumber();
                if (insertNum > trailValue && insertNum < currentNum)
                {
                    trailCurrent->setNext(insert);
                    insert->setNext(current);
                }
                trailCurrent = trailCurrent->getNext();
                current = current->getNext();
            }
        }
    }
    ++count;
}