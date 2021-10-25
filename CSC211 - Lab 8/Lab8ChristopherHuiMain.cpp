#include "Lab8ChristopherHuiMenu.h"

int main() {
	const int MAX_SIZE = 10;	//Maximum size of the array
	Task tasks[MAX_SIZE];	//struct task array
	int numOfTasks = 0;		//Number of task is set to 0 before reading from file
	int action;		//enum 
	Task* pList;	//Pointer pList

	pList = tasks;	//Assigns pointer pList to the array of tasks

	getData(pList, numOfTasks);	//Reads from a file

	cout << "-------All tasks has been added.-------\n";	//Task Menu

	do {
		cout << "\nMenu:" << endl;
		cout << "0 - exit" << endl;
		cout << "1 - view tasks" << endl;
		cout << "2 - remove a task" << endl;
		cout << "3 - add a tasks" << endl;
		cout << "4 - mark task as completed" << endl;
		cout << "5 - task summary" << endl;
		cout << "What would you like to do next? Enter a number: ";
		cin >> action;
		cout << endl;

		switch (action) {	//Menu choices
		case stop:	//Ends the program
			cout << "Thank you for choosing Anderson Inc. Hope to see you soon!" << endl;
			break;
		case view:	//View all tasks
			viewTasks(pList, numOfTasks);
			break;
		case removed:	//Removes a task
			removeTasks(pList, numOfTasks);
			break;
		case add:	//Adds a task
			addTasks(pList, numOfTasks);
			break;
		case complete:	//Set a task to complete
			completeTask(pList, numOfTasks);
			break;
		case summary:	//Overall task's summary
			taskSummary(pList, numOfTasks);
			break;
		}
	} while (action != stop);
	return 0;
}

/*
-------All tasks has been added.-------

Menu:
0 - exit
1 - view tasks
2 - remove a task
3 - add a tasks
4 - mark task as completed
5 - task summary
What would you like to do next? Enter a number: 3

What is the task's name? (Use underscore instead of spaces) hello_world
What is the due date? (Month/Day/Year separate by spaces) 2 29 2000
What is the priority? (1-3) 2

Menu:
0 - exit
1 - view tasks
2 - remove a task
3 - add a tasks
4 - mark task as completed
5 - task summary
What would you like to do next? Enter a number: 1


-------Task 1-----------
Name: Learn_basic_Python
Due date: 12/12/2021
Priority: 3
Status: not completed

-------Task 2-----------
Name: Implement_a_snake_game
Due date: 1/4/2021
Priority: 1
Status: not completed

-------Task 3-----------
Name: Clean_up_my_room
Due date: 10/1/2021
Priority: 2
Status: not completed

-------Task 4-----------
Name: Build_my_resume
Due date: 12/12/2021
Priority: 3
Status: not completed

-------Task 5-----------
Name: Study_for_the_exam
Due date: 5/3/2021
Priority: 1
Status: not completed

-------Task 6-----------
Name: Learn_how_to_juggle
Due date: 6/5/2022
Priority: 3
Status: not completed

-------Task 7-----------
Name: Create_a_website_using_React
Due date: 7/12/2021
Priority: 2
Status: not completed

-------Task 8-----------
Name: Have_a_tea_and_self-reflect
Due date: 1/3/2021
Priority: 2
Status: not completed

-------Task 9-----------
Name: hello_world
Due date: 29/2/2000
Priority: 2
Status: not completed

Menu:
0 - exit
1 - view tasks
2 - remove a task
3 - add a tasks
4 - mark task as completed
5 - task summary
What would you like to do next? Enter a number: 2

Which task would you like to remove? 1

Menu:
0 - exit
1 - view tasks
2 - remove a task
3 - add a tasks
4 - mark task as completed
5 - task summary
What would you like to do next? Enter a number: 4

What task do you want to update? 8

Menu:
0 - exit
1 - view tasks
2 - remove a task
3 - add a tasks
4 - mark task as completed
5 - task summary
What would you like to do next? Enter a number: 1


-------Task 1-----------
Name: Implement_a_snake_game
Due date: 1/4/2021
Priority: 1
Status: not completed

-------Task 2-----------
Name: Clean_up_my_room
Due date: 10/1/2021
Priority: 2
Status: not completed

-------Task 3-----------
Name: Build_my_resume
Due date: 12/12/2021
Priority: 3
Status: not completed

-------Task 4-----------
Name: Study_for_the_exam
Due date: 5/3/2021
Priority: 1
Status: not completed

-------Task 5-----------
Name: Learn_how_to_juggle
Due date: 6/5/2022
Priority: 3
Status: not completed

-------Task 6-----------
Name: Create_a_website_using_React
Due date: 7/12/2021
Priority: 2
Status: not completed

-------Task 7-----------
Name: Have_a_tea_and_self-reflect
Due date: 1/3/2021
Priority: 2
Status: not completed

-------Task 8-----------
Name: hello_world
Due date: 29/2/2000
Priority: 2
Status: completed

Menu:
0 - exit
1 - view tasks
2 - remove a task
3 - add a tasks
4 - mark task as completed
5 - task summary
What would you like to do next? Enter a number: 5

Summary of To-Do List
Total number of tasks   8
Percentage completed    12.50%

Menu:
0 - exit
1 - view tasks
2 - remove a task
3 - add a tasks
4 - mark task as completed
5 - task summary
What would you like to do next? Enter a number: 0

Thank you for choosing Anderson Inc. Hope to see you soon!
*/