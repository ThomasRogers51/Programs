/* In this homework, you will implement a single linked list to store a list of students. Every student has an ID, a name, and a 
major. You will create 2 classes: Student and Classroom. Student class should have all above attributes and also a “next” pointer. 
     Student 
Type       Attribute 
String       ID 
String       name 
String       major 
Student*     next 
Classroom class should have a head node as an attribute to keep the list of the students. Also, following member functions should 
be implemented in this class: 
Classroom 
Type            Attribute 
Student*          head 
 
Return Type      Function  
                constructor 
void            addStudent(string id, string name, string major) 
void            removeStudent (string id) 
void            print() 
void            print(string id) 
Student         at(int index) 
int             getSize() 
bool            isEmpty() 
 
addStudent(…): Adds a new student to the list. The new student is placed based on the ALPHABETICAL ORDER of the names. You should
n’t add the student directly to the end or front of the list. The new student has to be inserted to the correct position. For 
example, if you have following three students: 
A new student, “David Taylor” will be placed in alphabetical order between the second and third student.  
removeStudent(…): This functions will remove a student using the given id number. If the given id number is not in the list, it 
will give an error. 
print(): Print all students in (alphabetical) order. id, name, and the major should be printed for each student. 
print(string id): Prints all information of a student for a given id 
at(int index): Returns the student at given index 
getSize(): returns the number of students in the list 
isEmpty(): returns true if list is empty, returns false otherwise. 
You will implement the Student and Classroom classes along with a main.cpp file. I expect you to have 3 files: Classroom.h, 
Classroom.cpp, and main.cpp. Student class definition will be in the Classroom.h file. 
main.cpp includes following operations in the main function.  
1. Add following students to the list using addStudent(string id, string name, string major) 
A25123 Izzie Cline Mathematics 
A23452 Bridget McCann Computer Science 
A45120 Isa Powell History 
A56009 Nick Miller Computer Science 
A65980 Alannah Wilks Literature 
A45018 Montana Gates Biology 
Amy Newman Bill Smith Emily Jordan
A86003 Janet Newman Nursing 
2. Print the list of the students in alphabetical order using Print() 
3. Remove Janet Newman from the list using removeStudent (string id) 
4. Print Janet Newman information (you should give error message since Janet Newman is already removed) 
5. Print the list of the students in alphabetical order using Print() 
Additional Resources: 
In addition, I have provided an integer single linked list C++ class to help you to study for linked lists. If you study that 
code, you can see the following functions: 
void pushBack(int newValue) 
void insertAt(int newValue,int index) 
int at(int index) 
int removeAt(int index) 
void print()   
This code is given you for a reference not to use it in this assignment. There are some functions in that class that you don’t 
need or there are some which requires some modifications.  
*/

#include "Classroom.h"

int main(void)
{
    Classroom room;
    
    room.addStudent("A25123", "Izzie Cline", "Mathematics");
    room.addStudent("A45018", "Montana Gates", "Biology");
    room.addStudent("A23452", "Bridget McCann", "Computer Science");
    room.addStudent("A56009", "Nick Miller", "Computer Science");
    room.addStudent("A86003", "Janet Newman", "Nursing");
    room.addStudent("A45120", "Isa Powell", "History");
    room.addStudent("A65980", "Izzie Cline", "Literature");
    
    room.print();

    cout << "\nRemove Janet Newman with ID: A86003" << endl;
    room.removeStudent("A86003");

    cout << "\nPrint Janet Newman with ID: A86003" << endl;

    room.print("A86003");

    room.print();
    return 0;
}
