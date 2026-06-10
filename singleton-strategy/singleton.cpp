#include <iostream>

class SingletonClass {
private:
    SingletonClass() {
        std::cout << "SingletonClass created\n";
    }

    // Prevent copyingƒ
    SingletonClass(const SingletonClass&) = delete;
    SingletonClass& operator=(const SingletonClass&) = delete;

public:
    static SingletonClass& getInstance() {
        static SingletonClass instance;  // Created once, thread-safe since C++11
        return instance;
    }

    void showMessage() {
        std::cout << "Hello from SingletonClass\n";
    }
};

int main() {
    SingletonClass& s1 = SingletonClass::getInstance();
    SingletonClass& s2 = SingletonClass::getInstance();

    s1.showMessage();

    std::cout << (&s1 == &s2) << std::endl; // 1 (true)

    return 0;
}