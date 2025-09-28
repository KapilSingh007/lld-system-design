#include<iostream> 
using namespace std;

class Person {

    string name;
    int age;

    public:
    Person(string name, int age){
        this->name = name;
        this->age = age;
    }

    void detail(int age){
        this->age = age;
        cout<<"Person age changed to "<<age<<endl;
    }

    void detail(int age, string name){
        this->name = name;
        this->age = age;
        cout<<"Person name changed to "<<name<<" and age to "<<age<<endl;
    }

    void detail(){
        cout<<"Person name is "<<name<<" and age is "<<age<<endl;
    }

};
int main(){
    Person* p = new Person("kapil",24);
    p->detail();
    p->detail(25);
    p->detail(25,"kapil");
    return 0;
}