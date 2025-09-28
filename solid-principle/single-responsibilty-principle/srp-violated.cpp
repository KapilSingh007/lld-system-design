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

class UserShopping{

    int cartValue =0;
    vector<ShoppingCart*> userCart;

    public: 
    UserShopping(vector<ShoppingCart*> userCart){
        this->userCart = userCart;
    }

    void calulateUserCartValue(){
        for(auto x:userCart){
            cartValue += x->price;
        }
    }

    void printCartValue(){
        cout<<"User Having cart value of "<<cartValue<<endl;
    }

    void scheduleUserOrder(){
        cout<<"Scheduling user order ... ";
       
        cout<<"order scheduled"<<endl;

    }
};

int main(){
    ShoppingCart* cart1 = new ShoppingCart("HRX Backpack", 964);
    ShoppingCart* cart2 = new ShoppingCart("Roadester cargo", 754);
    ShoppingCart* cart3 = new ShoppingCart("Highlander cargo", 864);

    vector<ShoppingCart*> userCart = {cart1,cart2,cart3};

    // for(auto x:userCart){
    //     cout<<x->productName<< " "<<x->price<<endl;
    // }

    UserShopping* user = new UserShopping(userCart);

    user->calulateUserCartValue();
    user->printCartValue();
    user->scheduleUserOrder();

    return 0;

}