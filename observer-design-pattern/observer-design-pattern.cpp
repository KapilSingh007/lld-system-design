#include<iostream>
#include<vector>
using namespace std;

class ISubscriber {
    public:
    virtual void notify(string videoInfo) = 0;
};

class IChannel {
    public:
    virtual void subscribe(ISubscriber *subscriber) = 0;
    virtual void unSubscribe(ISubscriber *subscriber) = 0;
    virtual void notify() = 0;
    virtual void addVideo(string name) = 0;
};

class Channel: public IChannel {

    vector<ISubscriber*> subscribers;
    string name;
    string latestVideo;
    public:
    Channel(string name){
        this->name = name;
    }

    void subscribe(ISubscriber *subscriber) override {
        subscribers.push_back(subscriber);
    }
    void unSubscribe(ISubscriber *subscriber) override {
        auto index = find(subscribers.begin(),subscribers.end(),subscriber);
        subscribers.erase(index);
    }

    void notify() override {
        for(auto subscriber: subscribers){
            subscriber->notify(latestVideo);
        }
    }

    void addVideo(string name) override {
        latestVideo = name;
        notify();
    }
};

class Subscriber: public ISubscriber {
    string name;
    public:

    Subscriber(string name){
        this->name = name;
    }

    void notify(string videoInfo) override {
        cout<< "Checkout our new video " + videoInfo<<endl;
    }
};

int main(){

    IChannel *mrBeast = new Channel("Mr beast");
    IChannel *harry = new Channel("codewithharry");

    ISubscriber *sub1 = new Subscriber("kapil");

    mrBeast->subscribe(sub1);
    harry->subscribe(sub1);


    mrBeast->addVideo("video1 added");

    return 0;
}