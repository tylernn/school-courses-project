#include "Interface.h"

#include <iostream>
using namespace std;

void displayMenu()
{
	cout << "**************************************************************\n"
		<< "                          MAIN MENU\n"
		<< "**************************************************************\n";
	cout << "\nSelect one of the following:\n\n"
		<< "    1: Search course\n"
		<< "    2: Add course\n"
		<< "    3: Delete course\n"
		<< "    4: Display all courses\n"
		<< "    5: (your choice)\n"
		<< "    6: To exit\n";
}


void processChoice(CourseList& courseList)
{
	// Write your code in here...
	bool userContinue = true;
	bool userExit = false;
	string userInput;


	do
	{
		// If the user does not enter a choice between 1-6
		cin >> userInput;
		if (userInput != "1" && userInput != "2" && userInput != "3" &&
			userInput != "4" && userInput != "5" && userInput != "6")
		{
			while (userInput != "1" && userInput != "2" && userInput != "3" &&
				userInput != "4" && userInput != "5" && userInput != "6")
			{
				cout << "Please pick a correct selection." << endl;
				userInput = "";
				cin >> userInput;
			}
		}
		// If the user has entered a choice between 1-6
		if (userInput == "1")
		{
			cout << "Please provide the course number to search : " << endl;
			int courseNumber = 0;
			cin >> courseNumber;

			if (courseList.searchCourse(courseNumber))
			{
				Course temp;
				courseList.searchCourse(courseNumber, temp);

				cout << temp.getCourseName() << temp.getCourseUnits() << temp.getPrefix();
			}
		}
		else if (userInput == "2")
		{
			cout << "Please contact the Curriculum Committee to start the"
				<< " process of adding a course." << endl;
		}
		else if (userInput == "3")
		{
			cout << "Please provide the course number to delete: " << endl;

			int courseNumber = 0;
			cin >> courseNumber;

			if (courseList.searchCourse(courseNumber))
			{
				cout << "Are you sure you want to delete the course, " << courseNumber << "?" << endl
					<< "Please enter \'Y\' to confirm deletion." << endl
					<< "Please enter \'N\' to exit action." << endl;

				string userYNInput;
				cin >> userYNInput;

				if (userYNInput == "Y")
				{
					courseList.deleteCourse(courseNumber);
					
					cout << "The course has been deleted." << endl;
				}
				else if (userYNInput == "N")
				{
					cout << "The course was not deleted." << endl;
				}
			}
			else
			{
				cerr << "The entered courseNumber cannot be found." << endl;
			}
		}
		else if (userInput == "4")
		{
			string allCourses;
			courseList.retrieveAllCourses(allCourses);
			cout << allCourses << endl;
		}
		else if (userInput == "5")
		{
			cout << "Please enter the course number: ";
			int findCourseNum = 0;
			cin >> findCourseNum;
			if (courseList.searchCourse(findCourseNum))
			{
				Course findTest;
				courseList.searchCourse(findCourseNum, findTest);
				cout << "The prerequisite courses for "
					<< findTest.getCourseName() << " is: ";
				for (auto prereqsElem : findTest.getCoursePrereqs())
				{
					cout << findTest.getPrefix() << prereqsElem << ". ";
				}
				cout << endl;
			}
			else
			{
				cerr << "The entered course number cannot be found. " << endl;
			}
		}
		else
		{
			userExit = true;
			cout << "Thank you for using OptiFlex Technologies Inc. "
				<< "software for your courses. Have a nice day." << endl;
		}
		// This code runs as long as the user does not enter 6 (exits program)
		if (!userExit)
		{
			cout << "If you would like to make another selection from the Main Menu," << endl
				<< "Please enter \'Y\' to continue." << endl
				<< "Please enter \'N\' to exit." << endl;
			string userYNInput;
			cin >> userYNInput;
			if (userYNInput == "Y")
			{
				userInput = "";
				userContinue = true;
				cout << endl;
				displayMenu();


			}
			else
			{
				userContinue = false;
				cout << "Thank you for using OptiFlex Technologies Inc. "
					<< "software for your courses. Have a nice day." << endl;
			}
		}
	} while (userContinue && !userExit);
}