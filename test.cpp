#include<iostream>
#include<string>
using namespace std;
class User {
    private:
        string name;
    public:
        User(string name){
            this->name = name;
        }

        string getUserName(){
            return this->name;
        }

        virtual void displayUserName() {
            cout<<"my name is "<<this->name;
        }

};

class Student: public User{

    public:
    Student(string name) : User(name) {}
    void displayUserName() override {
        cout<<"student name is "<< getUserName();
    }
};

class Base {
public:
    virtual void show() {
        cout << "Base\n";
    }
};

class Derived : public Base {
    public:
    void show() override {
        cout<<"Derived\n";
    }
};

int main() {
    Base* ptr = new Derived();
    ptr->show();
    return 0;
}