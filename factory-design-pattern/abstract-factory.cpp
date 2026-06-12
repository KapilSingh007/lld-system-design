#include<iostream>
using namespace std;

class Car {
    public:
    virtual void assemble() = 0;
};

class CarSpecification {
    public:
    virtual void display() = 0;
};

class Sedan : public Car {
    public:
    void assemble() {
        cout<<"sedan car got assebled";
    }
};

class SedanSpecification: public CarSpecification {
    public:
    void display() override {
        cout<<"sedan card specification";
    }
};

class Hatchback : public Car {
    public:
    void assemble() {
        cout<<"sedan car got assebled";
    }
};

class HatchbackSpecification: public CarSpecification {
    public:
    void display() override {
        cout<<"sedan card specification";
    }
};

class CarFactory {

    public:
    virtual Car *createCar() = 0;

    virtual CarSpecification *createSpecification() = 0;
    
};

class NorthAmericaFactory: public CarFactory {

    public:
    Car *createCar() override {
        return new Sedan();
    }

    CarSpecification *createSpecification() override{
        return new SedanSpecification();
    }
};

class EuropeFactory: public CarFactory {
    
    public:
    Car *createCar() override {
        return new Hatchback();
    }

    CarSpecification *createSpecification() override{
        return new HatchbackSpecification();
    }
};


int main() {

    CarFactory *northAmericaFactory = new NorthAmericaFactory();
    Car *northAmericaCar = northAmericaFactory->createCar();
    CarSpecification *northAmericaCarSpec = northAmericaFactory->createSpecification();

    northAmericaCar->assemble();
    northAmericaCarSpec->display();

    return 0;
}