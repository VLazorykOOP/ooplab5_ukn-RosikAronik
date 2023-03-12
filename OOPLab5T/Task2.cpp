#include <iostream>
#include <string>

using namespace std;

class Room { // оголошення класу "Кімната"
protected:
    double area; // приватне поле, що зберігає площу кімнати

public:
    Room(double area = 0) : area(area) {} // конструктор класу "Кімната"

    double get_area() const { // метод доступу до поля area
        return area;
    }

    void set_area(double area) { // метод зміни значення поля area
        this->area = area;
    }
};

class OneBedroomApartment { // оголошення класу "Однокімнатна квартира"
protected:
    Room bedroom;
    double kitchen_area;
    int floor;

public:
    OneBedroomApartment(double bedroom_area = 0, double kitchen_area = 0, int floor = 1)
        : bedroom(bedroom_area), kitchen_area(kitchen_area), floor(floor) {}

    double get_bedroom_area() const { // метод доступу до спальні
        return bedroom.get_area();
    }

    void set_bedroom_area(double area) { //метод доступу для зміни значення спальні
        bedroom.set_area(area);
    }

    double get_kitchen_area() const { // метод доступу до площі кухні
        return kitchen_area;
    }

    void set_kitchen_area(double area) { // метод доступу для зміни значення площі кухні
        kitchen_area = area;
    }

    int get_floor() const { // метод доступу до поверху квартири
        return floor;
    }

    void set_floor(int floor) { // метод доступу для зміни значення поверху квартири
        this->floor = floor;
    }
};

class OneBedroomApartmentCity : public OneBedroomApartment { // оголошення похідного класу
private:
    string city_name; // приватне поле, що зберігає назву міста

public:
    OneBedroomApartmentCity(double bedroom_area = 0, double kitchen_area = 0, int floor = 1, string city_name = "") //приймає параметри та ініціалізує об'єкт базового класу OneBedroomApartment за допомогою списку ініціалізації і присвоює значення параметра city_name до поля city_name
        : OneBedroomApartment(bedroom_area, kitchen_area, floor), city_name(city_name) {}

    virtual ~OneBedroomApartmentCity() {} //деструктор класу

    void print() const {// вивід поілв
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