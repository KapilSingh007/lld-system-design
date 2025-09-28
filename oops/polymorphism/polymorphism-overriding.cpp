#include<iostream>
using namespace std;
class Animal{
    public:
    virtual void run() = 0;
};

class Rat:public Animal{
    void run(){
        cout<<"Rat runs very slowly"<<endl;
    }
};

class Cat:public Animal{
    void run(){
        cout<<"Cat runs faster than rat"<<endl;
    }
};

class Dog:public Animal{
    void run(){
        cout<<"Dog runs"<<endl;
    }
};


int main(){


    // Below code represent dynamic polymorphism(function overriding)
    Animal* rat = new Rat;
    Animal* cat = new Cat;
    Animal* dog = new Dog;

    rat->run();
    cat->run();
    dog->run();

    return 0;
}
