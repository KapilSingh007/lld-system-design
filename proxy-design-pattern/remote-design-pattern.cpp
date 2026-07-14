#include<iostream>
using namespace std;
class IDataFetch{
    public:
    virtual void fetch() = 0;

};
class RealDataService: public IDataFetch{
    
    string imagePath;
    public:
    RealDataService(){
        cout << "[RealDataService] Initialized (simulating remote setup)\n";
    }

    void fetch() override {
        cout<<"[RealDataService] Data from server";
    }
};
class ProxyDataService: public IDataFetch{
    IDataFetch* data;

    public:
    ProxyDataService(){
        data = new RealDataService();
    }
    void fetch() override {
        data->fetch();
    }

};

int main(){

    IDataFetch* dataService  = new ProxyDataService();
    dataService->fetch();
}