#include<iostream>
using namespace std;

class PaymentStrategy {
    public:
    virtual void pay () = 0;
};

class UpiPayment: public PaymentStrategy{
    public:

    void pay() override {
        cout<<"Payment is done using upi\n";
    }
};

class CcPayment: public PaymentStrategy{
    public:

    void pay() override {
        cout<<"Payment is done using credit card\n";
    }
};

class DcPayment: public PaymentStrategy{
    public:

    void pay() override {
        cout<<"Payment is done using debit card\n";
    }
};

class PaymentService {
    PaymentStrategy *strategy;
    public:
    PaymentService(PaymentStrategy *strategy){
        this->strategy = strategy;
    }

    void pay(){

        strategy->pay();
    }
};
int main(){

    PaymentService* payment = new PaymentService(new CcPayment());

    payment->pay();

    return 0;

}