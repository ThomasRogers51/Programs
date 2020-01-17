#include "Classroom.h";

Classroom::Classroom()
{

    head = NULL;

}

void Classroom::addStudent(string id, string name, string major)

{

    Student* student = new Student();

    student->id = id;
    student->name = name;
    student->major = major;
   
    if (head == NULL)
        {
        
            head = student;
            return;
        
        }
    
    Student* cur = head;
    Student* pre = NULL;
    
    while (cur != NULL && cur->name.compare(student->name) < 0)
    
    {
      
        pre = cur;
        cur = cur->next;
    
    }
    
    if (pre == NULL)
    
    {
        student->next = head;
        head = student;
    
    }
    
    else
    
    {
    
        if (cur == NULL)
        
        {
        
            pre->next = student;
        
        }
        
        else
        
        {
        
            student->next = cur;
            pre->next = student;
        
        }
    }
}

void Classroom::removeStudent(string id)

{

    Student* cur = head;
    Student* pre = NULL;
    bool found = false;
    while (cur)

    {

        if (cur->id.compare(id) == 0)

        {
            found = true;
            break;

        }

        pre = cur;
        cur = cur->next;

    }

    if (found)

    {

        if (pre == NULL)

        {

            head = head->next;
            free(cur);

        }

        else

        {

            pre->next = cur->next;
            free(cur);

        }
    }

    else

    {


        cout << "\n Given ID: " << id << " is not found in class list" << endl;

    }
}

void Classroom::print(string id)

{

    bool found = false;
    Student* temp = head;
    while (temp)

    {

        if (temp->id.compare(id) == 0)

        {

            cout << "\n" << temp->id << " , " << temp->name << " , " << temp->major << endl;
            found = true;
            break;

        }

        temp = temp->next;

    }

    if (found == false)

    {

        cout << "\nGiven ID: " << id << " is not found in class list" << endl;

    }
}

void Classroom::print()

{

    Student* temp = head;
    while (temp != NULL)

    {

        cout << "\nID:    " << temp->id << "\nName:  " << temp->name << "\nMajor: " << temp->major << endl;
        temp = temp->next;

    }
}

Student Classroom::at(int index)

{
    Student* temp = head;
    while (temp && index != 0)
    
    {
    
        index--;
        temp = temp->next;
    
    }

    if (index == 0)
    
    {
    
        return *temp;
    
    }
    
    else
    
    {
    
        Student student;
        student.id = "-";
        return student;
    
    }
}

int Classroom::getSize()

{

    Student* temp = head;
    int size = 0;
    while (temp)

    {

        size++;
        temp = temp->next;

    }

    return size;

}

bool Classroom::isEmpty()

{

    return head == NULL;

}