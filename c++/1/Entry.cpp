/*
Author : @wuan
Link :
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pi pair<ll, ll>
#define fi first
#define se second
#define endl '\n'
class Vehicle
{
private:
    string brand;
    int year;

public:
    Vehicle()
    {
        this->brand = "Unknown";
        this->year = 0;
    }
    Vehicle(string brand, int year)
    {
        this->brand = brand;
        this->year = year;
    }
    string getBrand()
    {
        return this->brand;
    }
    int getYear()
    {
        return this->year;
    }
    void setBrand(string brand)
    {
        this->brand = brand;
    }
    void setYear(int year)
    {
        this->year = year;
    }
    virtual void displayInfo()
    {
        cout << "Brand: " << this->brand << endl;
        cout << "Year: " << this->year << endl;
    }
};
class Car : public Vehicle
{
private:
    string model;

public:
    Car() : Vehicle("Unknown", 0), model("Unknown") {}
    Car(string brand, int year, string model) : Vehicle(brand, year), model(model) {}
    void displayInfo() override
    {
        Vehicle::displayInfo();
        cout << "Model: " << model;
    }
};
class Bike : public Vehicle
{
private:
    int engineCapacity;

public:
    Bike() : Vehicle("Unknown", 0), engineCapacity(0) {}
    Bike(string brand, int year, int engineCapacity) : Vehicle(brand, year), engineCapacity(engineCapacity) {}
    void displayInfo() override
    {
        Vehicle::displayInfo();
        cout << "EngineCapacity: " << engineCapacity;
    }
};
int main()
{

    Car c1 = Car();
    Car c2 = Car("Toyota", 2022, "Camry");

    Bike b1 = Bike();
    Bike b2 = Bike("Honda", 2021, 150);

    c1.displayInfo();
    cout << endl;
    c2.displayInfo();
    cout << endl;

    b1.displayInfo();
    cout << endl;

    b2.displayInfo();
    cout << endl;
    return 0;
}