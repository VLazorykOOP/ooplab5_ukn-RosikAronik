#include <iostream>
#include <string>

using namespace std;

class Student {//клас студента та всі його поля 
protected://доступу не буду з інших частин програми, окрім спадкоємців
    string name;
    int course;
    int id;

public:
    Student(string name = "", int course = 0, int id = 0)//конструктор, який ініціалізує поля
        : name(name), course(course), id(id) {}

    virtual ~Student() {}//віртуальний деструктор класу=

    virtual void print() const {//віртуальний метод, що виводить значення полів
        cout << "Name: " << name << endl;
        cout << "Course: " << course << endl;
        cout << "ID: " << id << endl;
    }

    virtual void set_id(int id) {//віртуальний метод, що змінює значення id
        this->id = id;
    }
};

class GraduatingStudent : public Student {
private:
    string thesis_title;//приватне поле, що містить тему дипломної роботи.

public:
    GraduatingStudent(string name = "", int course = 0, int id = 0, string thesis_title = "")//приймає параметри та ініціалізує об'єкт базового класу Student за допомогою списку ініціалізації і присвоює значення параметра thesis_title до поля thesis_title
        : Student(name, course, id), thesis_title(thesis_title) {}

    GraduatingStudent(string name, int course, string thesis_title)
        : Student(name, course), thesis_title(thesis_title) {}

    virtual ~GraduatingStudent() {}//віртуальний деструктор

    virtual void print() const {//викликає метод базового класу та виводить додаткову інформацію про тему дипломної роботи
        Student::print();
        cout << "Thesis Title: " << thesis_title << endl;
    }

    virtual void set_id(int id) override {//Клас має перевизначений метод set_id(), який встановлює значення поля id з параметром, який був переданий у функцію, плюс 1000.
        this->id = id + 1000;
    }

    void set_thesis_title(string title) {//метод встановлює значення поля thesis_title з переданим параметром.
        this->thesis_title = title;
    }
};

int main() {
    Student s1("Andronik Rostislav", 2, 12345);
    s1.print();
    cout << endl;

    GraduatingStudent gs1("Arhiluk Elvira", 5, 54321, "Usage of network");
    gs1.print();
    cout << endl;

    GraduatingStudent gs2("Fedorishin Andriy", 4, "Genetic Engineering");
    gs2.set_id(67890);
    gs2.set_thesis_title("Climate Change on Agriculture");
    gs2.print();
    cout << endl;

    return 0;
}