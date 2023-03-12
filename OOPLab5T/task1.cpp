#include <iostream>
#include <string>

using namespace std;

class Student {//���� �������� �� �� ���� ���� 
protected://������� �� ���� � ����� ������ ��������, ���� ����������
    string name;
    int course;
    int id;

public:
    Student(string name = "", int course = 0, int id = 0)//�����������, ���� �������� ����
        : name(name), course(course), id(id) {}

    virtual ~Student() {}//���������� ���������� �����=

    virtual void print() const {//���������� �����, �� �������� �������� ����
        cout << "Name: " << name << endl;
        cout << "Course: " << course << endl;
        cout << "ID: " << id << endl;
    }

    virtual void set_id(int id) {//���������� �����, �� ����� �������� id
        this->id = id;
    }
};

class GraduatingStudent : public Student {
private:
    string thesis_title;//�������� ����, �� ������ ���� �������� ������.

public:
    GraduatingStudent(string name = "", int course = 0, int id = 0, string thesis_title = "")//������ ��������� �� �������� ��'��� �������� ����� Student �� ��������� ������ ����������� � �������� �������� ��������� thesis_title �� ���� thesis_title
        : Student(name, course, id), thesis_title(thesis_title) {}

    GraduatingStudent(string name, int course, string thesis_title)
        : Student(name, course), thesis_title(thesis_title) {}

    virtual ~GraduatingStudent() {}//���������� ����������

    virtual void print() const {//������� ����� �������� ����� �� �������� ��������� ���������� ��� ���� �������� ������
        Student::print();
        cout << "Thesis Title: " << thesis_title << endl;
    }

    virtual void set_id(int id) override {//���� �� �������������� ����� set_id(), ���� ���������� �������� ���� id � ����������, ���� ��� ��������� � �������, ���� 1000.
        this->id = id + 1000;
    }

    void set_thesis_title(string title) {//����� ���������� �������� ���� thesis_title � ��������� ����������.
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