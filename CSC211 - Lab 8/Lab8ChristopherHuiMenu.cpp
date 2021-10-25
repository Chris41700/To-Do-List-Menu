#include "Lab8ChristopherHuiMenu.h"

void getData(Task* pList, int& num) {
	ifstream inFile;

	inFile.open("tasks.txt"); //Opens input file

	if (!inFile) {	//Check to see if tasks file is open
		cout << "Error opening the file" << endl;
		exit(1);
	}

	while (!inFile.eof()) {	//Iterate through the file until the end
		inFile >> pList->name >> pList->dueMonth >> pList->dueDay >> pList->dueYear >> pList->priority;	//Reads the task's name, due month, day, year, and priority
		pList++;	//Increment pList pointer
		num++;	//Iterates to the next task
	}

	inFile.close();	//Closes the file
}

void viewTasks(Task* pList, int size) {
	string result = "not completed";	//By default, tasks are set to not complete

	do {
		if (size == 0) {	//Checks to see if there are any tasks to view
			cout << "There is not any tasks to view." << endl;
			return;
		}
	} while (size == 0);

	for (int i = 0; i < size; i++) {	//Outputting task statements
		cout << "\n-------Task " << i + 1 << "-----------" << endl;
		cout << "Name: " << pList->name << endl;
		cout << "Due date: " << pList->dueDay << '/' << pList->dueMonth << '/' << pList->dueYear << endl;
		cout << "Priority: " << pList->priority << endl;

		if (pList->isComplete)	//Outputs complete if bool is set to true for a task
			result = "completed";
		else
			result = "not completed";

		cout << "Status: " << result << endl;

		pList++;
	}
}

void removeTasks(Task* pList, int& size) {
	int currentTask;	//The task the user wants to remove

	do {
		if (size == 0) {	//Checks to see if there is any tasks in the array 
			cout << "There are no tasks to remove." << endl;
			return;
		}
	} while (size == 0);

	cout << "Which task would you like to remove? ";	//Prompts the user to enter a task number to remove
	cin >> currentTask;

	currentTask -= 1;	//Decreases the current task by 1 since in the array it is one less than what they input

	(pList + currentTask)->isComplete = false;	//Will set the current task completion as false 

	do {
		if (currentTask < 0 || currentTask >= size) {	//Checks to see if current task entered by user is valid in the array
			cout << "Invalid task" << endl;
			return;
		}
	} while (currentTask < 0 || currentTask >= size);

	size--;	//Decrement the size of the array

	for (int i = currentTask; i < size; i++)	//Shifts the array by one element to the left starting at the current task
		pList[i] = pList[i + 1];

	pList--;	//Decrement pList
}

void addTasks(Task* pList, int& size) {
	if (size < 10) {	//If the array is not full, the add task statement runs
		cout << "What is the task's name? (Use underscore instead of spaces) ";
		cin >> (pList + size)->name;

		do {	//Will keep running until user enters a valid month, day, and year
			cout << "What is the due date? (Month/Day/Year separate by spaces) ";
			cin >> (pList + size)->dueMonth >> (pList + size)->dueDay >> (pList + size)->dueYear;

			//Checks to see if the month, day, and year is a valid input
			if (!(1 <= (pList + size)->dueMonth && (pList + size)->dueMonth <= 12) || !(1 <= (pList + size)->dueDay && (pList + size)->dueDay <= validMonth(pList + size)) || !(1000 <= (pList + size)->dueYear && (pList + size)->dueYear <= 9999)) {
				cout << "Invalid input" << endl;
			}
		} while (!(1 <= (pList + size)->dueMonth && (pList + size)->dueMonth <= 12) || !(1 <= (pList + size)->dueDay && (pList + size)->dueDay <= validMonth(pList + size)) || !(1000 <= (pList + size)->dueYear && (pList + size)->dueYear <= 9999));

		do {	//Will keep running until user enters a valid priority number
			cout << "What is the priority? (1-3) ";
			cin >> (pList + size)->priority;

			if (!(1 <= (pList + size)->priority && (pList + size)->priority <= 3)) {
				cout << "Invalid input" << endl;
			}
		} while (!(1 <= (pList + size)->priority && (pList + size)->priority <= 3));
		pList++;
		size++;	//The array size will increment
	}
	else {	//Runs if the array is full
		cout << "There no more space in the list." << endl;
	}
}

void completeTask(Task* pList, int size) {
	int currentTask;

	do {
		if (size == 0) {	//Checks to see if there is any tasks in the array 
			cout << "There is no tasks to update." << endl;
			return;
		}
	} while (size == 0);

	cout << "What task do you want to update? ";	//Prompts the user to enter a task to update
	cin >> currentTask;

	currentTask -= 1;	//Decreases the current task by 1 since in the array it is one less than what they input

	do {
		if (currentTask < 0 || currentTask >= size) {	//Checks to see if current task entered by user is valid in the array
			cout << "Invalid task" << endl;
			break;
		}
	} while (currentTask < 0 || currentTask >= size);

	(pList + currentTask)->isComplete = true;	//Set the current task to true
}

void taskSummary(Task* pList, int& size) {
	double tasksCompleted = 0;	//The amount of tasks completed is set to 0

	do {
		if (size == 0) {	//Checks to see if there is any tasks in the array 
			cout << "There is no tasks to view summary." << endl;
			return;
		}
	} while (size == 0);

	for (int i = 0; i < size; i++) {	//Iterate through the array
		if ((pList + i)->isComplete == true) {	//If a task is set to true, tasksCompleted is incremented
			tasksCompleted++;
		}
	}

	cout << "Summary of To-Do List" << endl;
	cout << "Total number of tasks\t" << size << endl;
	cout << "Percentage completed\t" << setprecision(2) << fixed << (tasksCompleted / size) * 100 << '%' << endl;
}

int validMonth(Task* pList) {
	//Switch statement to return the number of days depending on the month
	switch (pList->dueMonth) {
	case 1:
		return 31;
		break;
	case 2:
		//Leap year condition
		if ((pList->dueYear % 400 == 0) || (pList->dueYear % 4 == 0 && pList->dueYear % 100 != 0)) {
			return 29;
			break;
		}
		else {
			return 28;
			break;
		}
	case 3:
		return 31;
		break;
	case 4:
		return 30;
		break;
	case 5:
		return 31;
		break;
	case 6:
		return 30;
		break;
	case 7:
		return 31;
		break;
	case 8:
		return 31;
		break;
	case 9:
		return 30;
		break;
	case 10:
		return 31;
		break;
	case 11:
		return 30;
		break;
	case 12:
		return 31;
		break;
	}
}