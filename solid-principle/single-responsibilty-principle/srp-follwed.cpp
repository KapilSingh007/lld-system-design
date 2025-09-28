#include<iostream>
using namespace std;

class ShoppingCart {
    public:
    string productName;
    int price;

    ShoppingCart(string productName, int price){
        this->productName = productName;
        this->price = price;
    }
};


class CalculateCartValue{
    vector<ShoppingCart*> userCart;
    public:
    int cartValue=0;
    CalculateCartValue(vector<ShoppingCart*>  userCart){
        this->userCart= userCart;
    }

    void calulate(){   
        for(auto x:userCart){
        cartValue += x->price;
    }
}

};


class PrintCartValue{
    CalculateCartValue* userCartValue;

    public: 
    PrintCartValue(CalculateCartValue* userCartValue){
        this->userCartValue =  userCartValue;
    }

    void print(){
        cout<<"User Having cart value of "<<userCartValue->cartValue<<endl;
    }
};


int main(){
    ShoppingCart* cart1 = new ShoppingCart("HRX Backpack", 964);
    ShoppingCart* cart2 = new ShoppingCart("Roadester cargo", 754);
    ShoppingCart* cart3 = new ShoppingCart("Highlander cargo", 864);

    vector<ShoppingCart*> userCart = {cart1,cart2,cart3};

    CalculateCartValue* cartValue  =  new CalculateCartValue(userCart);
    cartValue->calulate();

    PrintCartValue* printValue = new PrintCartValue(cartValue);

    printValue->print();

    return 0;
}
