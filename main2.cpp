#include <iostream>
using namespace std;

class Student {
public:
    Student();
    Student(string newFio, int newStudVar, int newSubGroup);
    Student(const Student &student);
    ~Student() {}
    
    string fio;
    int subGroup;
    int studVar;
};

Student::Student() {
    fio = "";
    subGroup = 0;
    studVar = 0;
}

Student::Student(string newFio, int newStudVar, int newSubGroup) {
    fio = newFio;
    subGroup =  newSubGroup;
    studVar = newStudVar;
}

Student::Student(const Student &student) {
    fio = student.fio;
    studVar = student.studVar;
    subGroup = student.subGroup;
}

class Group {
public:
    Group();
    Group(string newName);
    Group(const Group &students);
    void addStudent(const Student &student);

    string name;
    int length;
    Student *students;
};

Group::Group(string newName)  {
    name = newName;
    length = 0;
    students = nullptr;
}

Group::Group() {
    name = "";
    length = 0;
    students = nullptr;
}

Group::Group(const Group &newStudents) {
    name = newStudents.name;
    length = newStudents.length;
    this->students = new Student[length];
        for (int i =0; i< length;i++) {
            this->students[i] = Student(newStudents.students[i]);
        }
}

void Group::addStudent(const Student &student) {
    if(!length) {
        length += 1;
        students = new Student[length];
        students[length - 1] = Student(student);
    } else {
        Student *newArray = new Student[length + 1];
        for (int i = 0; i <= this->length; i++) {
            newArray[i] = this->students[i];
        }
        delete[] this->students;
        this->students = newArray;
        this->students[length] = Student(student);
        length++;
    }
}
