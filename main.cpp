#include <iostream>

/*
1.
Реализовать классы с публичными свойствами: Student(fio, studVar, subGroup), Group(name)
Реализовать конструкторы по умолчанию, инициализации, копирования.
Составить коллекцию объектов класса Student в виде динамического массива students в классе Group.
Реализовать метод Group::addStudent(const Student &student) добавляющий студента в группу.
Имена классов, свойств и методов должны в точности соответствовать условию.

2.
Составить коллекцию Groups объектов класса Group в виде односвязного списка.
Реализовать метод Groups::addGroup(const Group &) добавляющий группу в коллекцию.
Реализовать метод Group *Groups::getGroup(const string &) находящий группу по подстроке названия.
Реализовать метод Student *Group::getStudent(const string &) находящий студента по подстроке ФИО.
*/

class Student
{
public:
    std::string fio;
    unsigned int studVar;
    unsigned int subGroup;

    Student()
    {
        fio = "";
        studVar = 0;
        subGroup = 0;
    };
    Student(std::string _fio, unsigned int _studVar, unsigned int _subGroup)
    {
        fio = _fio;
        studVar = _studVar;
        subGroup = _subGroup;
    }
    Student(const Student &_student)
    {
        fio = _student.fio;
        studVar = _student.studVar;
        subGroup = _student.subGroup;
    }
    ~Student() {};

    // friend std::ostream &operator<<(std::ostream &stream, Student student)
    // {
    //     stream << student.fio << " " << student.studVar << " " << student.subGroup << ", ";
    //     return stream;
    // }
};

// struct myList_item
// {
//     Student val;
//     myList_item *next;

//     myList_item(Student _val) : val(_val), next(nullptr) {}
// };

// struct myList
// {
//     myList_item *first;
//     myList_item *last;

//     myList() : first(nullptr), last(nullptr) {}

//     bool is_list_empty()
//     {
//         return first == nullptr;
//     }

//     void add_item(Student _val)
//     {
//         myList_item *curr = new myList_item(_val);
//         if (is_list_empty())
//         {
//             first = curr;
//             last = curr;
//             return;
//         }
//         last->next = curr;
//         last = curr;
//     }

// };

class Group
{
private:
    int students_amount = 0;

public:
    std::string name;
    Student *students;

    Group()
    {
        name = "";
        students = nullptr;
    };

    Group(std::string _name)
    {
        name = _name;
        students = nullptr;
    }

    Group(const Group &_group)
    {
        name = _group.name;
        //students = _group.students;
        students_amount = _group.students_amount;
        students = new Student[students_amount];
        for (int item = 0; item < students_amount; item++){
            students[item] = _group.students[item];
        }
    }

    // ~Group(){
    //     // delete[] students;
    //     students_amount = 0;
    // }

    void addStudent(const Student &student)
    {
        if (students_amount == 0)
        {
            students = new Student[students_amount+1];
            students[0]= student;
            students_amount += 1;
        }
        else{
            Student *new_students = new Student[students_amount+1];
            for(int item = 0; item <= students_amount; item++){
                new_students[item] = students[item];
            }
            delete [] students;
            students = new_students;
            delete [] new_students;
            students_amount += 1;
            students[students_amount - 1] = student;  

        }

    }
};

int main()
{

    Student student1("FIO", 1, 1);
    Student student2("FIO2", 2, 2);
    Student student3(student2);

    // std::cout << student1.fio << '\n';
    // std::cout << student2.fio << '\n';
    // std::cout << student3.fio << '\n';

    Group group1("BIV201");
    Group group2("BIV202");

    group1.addStudent(student1);
    group1.addStudent(student2);
    group2.addStudent(student2);
    Group group3(group1);

    std::cout << group1.name << '\n';
    std::cout << group1.students[0].fio << '\n';
    std::cout << group1.students[1].fio << '\n';
    std::cout << group2.name << '\n';
    std::cout << group2.students[0].fio << '\n';
    std::cout << group3.name << '\n';
    std::cout << group3.students[0].fio << '\n';
    std::cout << group3.students[1].fio << '\n';

    // std::cout << "\n\n\n";
    // group1.addStudent(student1);

    // std::cout << "\n\n\n";
    // group1.addStudent(student2);
    // std::cout << "\n\n\n";

    // group1.addStudent(student3);
    // std::cout << "\n\n\n";

    return 0;
}