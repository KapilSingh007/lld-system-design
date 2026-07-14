#include<iostream>
using namespace std;
struct Request{
    bool user;
    struct Body{
        bool email;
    } body;
};
class IHandler{
    public:
    virtual void setNext(IHandler* nextHandler) = 0;
    virtual void handle(Request request) = 0;
};
class BaseHandler: public IHandler{
    protected:
    IHandler* nextHandler;
    public:

    void setNext(IHandler* nextHandler) override {
        this->nextHandler = nextHandler;
    }

    void handle(Request request) override{
        nextHandler->handle(request);
    }

};

class AuthHandler: public BaseHandler{
    public:

    // void setNext(IHandler* nextHandler) override {
    //     this->nextHandler = nextHandler;
    // }

    void handle(Request request) override{
        if(!request.user){
            cout<<"Authorization fail"<<endl;
            return ;
        }
        cout<<"User authorized"<<endl;
        nextHandler->handle(request);
    }

};

class EmailVerifyHandler: public BaseHandler{
    public:

    // void setNext(IHandler* nextHandler) override {
    //     this->nextHandler = nextHandler;
    // }

    void handle(Request request) override{
        if(!request.body.email){
            cout<<"Email is missing"<<endl;
            return;
        }
        cout<<"User verified"<<endl;
        nextHandler->handle(request);
    }

};

class OrderHandler: public BaseHandler{
    public:

    void handle(Request request) override{
        cout<<"order Placed"<<endl;
        return;
    }

};
int main(){
    Request req;
    req.user = true;
    req.body.email="kapil@gmail.com";

    IHandler* authService = new AuthHandler();
    IHandler* emailVerifyService = new EmailVerifyHandler();
    IHandler* orderService = new OrderHandler();
    authService->setNext(emailVerifyService);
    emailVerifyService->setNext(orderService);

    authService->handle(req);
    return 0;

}