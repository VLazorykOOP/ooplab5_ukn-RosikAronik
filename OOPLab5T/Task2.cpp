#include <iostream>
#include <string>

using namespace std;

class Room { // ���������� ����� "ʳ�����"
protected:
    double area; // �������� ����, �� ������ ����� ������

public:
    Room(double area = 0) : area(area) {} // ����������� ����� "ʳ�����"

    double get_area() const { // ����� ������� �� ���� area
        return area;
    }

    void set_area(double area) { // ����� ���� �������� ���� area
        this->area = area;
    }
};

class OneBedroomApartment { // ���������� ����� "����������� ��������"
protected:
    Room bedroom;
    double kitchen_area;
    int floor;

public:
    OneBedroomApartment(double bedroom_area = 0, double kitchen_area = 0, int floor = 1)
        : bedroom(bedroom_area), kitchen_area(kitchen_area), floor(floor) {}

    double get_bedroom_area() const { // ����� ������� �� ������
        return bedroom.get_area();
    }

    void set_bedroom_area(double area) { //����� ������� ��� ���� �������� ������
        bedroom.set_area(area);
    }

    double get_kitchen_area() const { // ����� ������� �� ����� ����
        return kitchen_area;
    }

    void set_kitchen_area(double area) { // ����� ������� ��� ���� �������� ����� ����
        kitchen_area = area;
    }

    int get_floor() const { // ����� ������� �� ������� ��������
        return floor;
    }

    void set_floor(int floor) { // ����� ������� ��� ���� �������� ������� ��������
        this->floor = floor;
    }
};

class OneBedroomApartmentCity : public OneBedroomApartment { // ���������� ��������� �����
private:
    string city_name; // �������� ����, �� ������ ����� ����

public:
    OneBedroomApartmentCity(double bedroom_area = 0, double kitchen_area = 0, int floor = 1, string city_name = "") //������ ��������� �� �������� ��'��� �������� ����� OneBedroomApartment �� ��������� ������ ����������� � �������� �������� ��������� city_name �� ���� city_name
        : OneBedroomApartment(bedroom_area, kitchen_area, floor), city_name(city_name) {}

    virtual ~OneBedroomApartmentCity() {} //���������� �����

    void print() const {// ���� ����
        cout << "Bedroom Area: " << get_bedroom_area() << " sq.m." << endl;
        cout << "Kitchen Area: " << kitchen_area << " sq.m." << endl;
        cout << "Floor: " << floor << endl;
        cout << "City Name: " << city_name << endl;
    }
};

int Apartment() {
    OneBedroomApartmentCity apt1(50, 20, 5, "Kyiv");
    apt1.print();
    cout << endl;

    OneBedroomApartmentCity apt2(60, 15, 3, "Lviv");
    apt2.print();
    cout << endl;

    return 0;
}