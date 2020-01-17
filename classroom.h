#ifndef __CLASSROOM_H
#define __CLASSROOM_H
#include<iostream>
#include<cstdlib>

using namespace std;

class Student

{

	public:
		string id;
		string name;
		string major;
		Student* next;

};


class Classroom

{

	private:
		Student* head;
	public:
		Classroom();
	void addStudent(string id, string name, string major);
	void removeStudent(string id);
	void print();
	void print(string id);
		Student at(int index);
	int getSize();
	bool isEmpty();

};
#endif