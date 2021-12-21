#include <iostream>

class Student
{
public:
    std::string fio;
    unsigned int studVar;
    unsigned int subGroup;

    Student();
    Student(std::string _fio, unsigned int _studVar, unsigned int _subGroup)
    {
        fio = _fio;
        studVar = _studVar;
        subGroup = _subGroup;
    }
    Student(Student &_student)
    {
        fio = _student.fio;
        studVar = _student.studVar;
        subGroup = _student.subGroup;
    }
};

struct myList_item
{
    Student val;
    myList_item *next;

    myList_item(Student _val) : val(_val), next(nullptr) {}
};

struct myList
{
    myList_item *first;
    myList_item *last;

    myList() : first(nullptr), last(nullptr) {}

    bool is_list_empty()
    {
        return first == nullptr;
    }

    void add_item(Student _val)
    {
        myList_item *curr = new myList_item(_val);
        if (is_list_empty())
        {
            first = curr;
            last = curr;
            return;
        }
        last->next = curr;
        last = curr;
    }
};

class Group
{
public:
    std::string name;
    myList students;

    Group();

    Group(std::string _name)
    {
        name = _name;
    }

    Group(Group &_group)
    {
        name = _group.name;
        students = _group.students;
    }

    void addStudent(Student student)
    {
        students.add_item(student);
    }
};

int main()
{

    Student student1("FIO", 3, 1);
    Student student2("FIO2", 2, 2);

    Group group1("BIV201");

    group1.addStudent(student1);
    group1.addStudent(student2);

    return 0;
}