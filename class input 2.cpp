
#include<iostream>
using namespace std;

class students {
public:
    string name;
    string course;
    int age;
    double grade;

    students(string name,string course, int age, double grade) {
        this->name = name;
        this->course = course;
        this->age = age;
        this->grade = grade;
    }
};

int main() {
    students student1("Rain","BSE", 18, 74.5);

    cout << "Predefined Student:" << endl;
    cout << student1.name << endl;
    cout << student1.age << endl;
    cout << student1.grade << endl;

    string newName;
    string newCourse;
    int newAge;
    double newGrade;

    cout << "\nEnter details for your new student:" << endl;
    cout << "Name: ";
    getline(cin, newName);
    cout << "Course: ";
    getline(cin, newCourse);
    cout << "Age: ";
    cin >> newAge;
    cout << "Grade: ";
    cin >> newGrade;

    students newStudent(newName, newCourse,newAge, newGrade);

    cout << "\nYour new student:" << endl;
    cout << newStudent.name << endl;
    cout<< newStudent.course <<endl;
    cout << newStudent.age << endl;
    cout << newStudent.grade << endl;

    return 0;
}