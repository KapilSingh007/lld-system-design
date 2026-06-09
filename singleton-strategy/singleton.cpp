#include<iostream>
using namespace std;

class SingletonClass {

    private:
    static SingletonClass *instance;
    SingletonClass(){}

    public:
    static SingletonClass *getClassInstance(){
        if(instance) {
            return instance;
        } else {
            instance = new SingletonClass();
            return instance;
        }
    }
};
SingletonClass* SingletonClass::instance = nullptr;

int main(){
    SingletonClass *instance1 = SingletonClass::getClassInstance();
    SingletonClass *instance2 = SingletonClass::getClassInstance();

    cout<<"is class instance is same: "<<(instance1 == instance2);
    return 0;
}