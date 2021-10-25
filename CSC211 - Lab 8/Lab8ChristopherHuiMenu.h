#pragma once
#ifndef LAB8CHRISTOPHERHUIMENU_H
#define LAB8CHRISTOPHERHUIMENU_H

#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>
#include <fstream>

using namespace std;

struct Task {	//Structure of Task
	string name;
	int dueDay;
	int dueMonth;
	int dueYear;
	bool isComplete = false;
	int priority;
};

enum Actions { stop, view, removed, add, complete, summary };	//enum of Actions

void getData(Task*, int&);		//Function prototypes
void viewTasks(Task*, int);
void addTasks(Task*, int&);
void removeTasks(Task*, int&);
void completeTask(Task*, int);
void taskSummary(Task*, int&);
int validMonth(Task*);

#endif

