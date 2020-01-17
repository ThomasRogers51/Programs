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