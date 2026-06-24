#include<iostream>
#include<vector>
using namespace std;

class ISubscriber {

};

class IChannel {
    public:
    virtual void subscribe(ISubscriber *subscriber) = 0;
    virtual void unSubscribe(ISubscriber *subscriber) = 0;
    virtual void notify() = 0;
    virtual void addVideo(string name) = 0;
    virtual string getLatestVideo(string name) = 0;
};

class Channel {

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
            subscriber->notify();
        }
    }

    void addVideo(string name) override {
        latestVideo = name;
        notify();
    }

    string getLatestVideo() override {
        return "Checkout our new video " + latestVideo;
    }
};

class Subscriber {
    string name;
    public:

    Subscriber(string name){
        this->name = name;
    }

    string notify(){
        
    }
}

int main(){

    IChannel *mrBeast = new Channel("Mr beast");
    IChannel *harry = new Channel("codewithharry");

    ISubscriber *sub1 = new Subscriber("kapil");

    mrBeast.subscribe(sub1);
    harry.subscribe(sub1);


    mrBeast.addVideo("video1 added");

    return 0;
}