#include<iostream>
#include <map>
using namespace std;
class HttpRequest {
private:
    string url;
    string method;
    map<string, string> headers;
    map<string,string> queryParams;
    string body;
    int timeout; // in seconds

    // Private constructor - can only be accessed by the Builder
    HttpRequest() { }

    public:
    friend class HttpRequestStepBuilder;

    void execute() {
        cout << "Executing " << method << " request to " << url << endl;
        
        if (!queryParams.empty()) {
            cout << "Query Parameters:" << endl;
            for (const auto& param : queryParams) {
                cout << "  " << param.first << "=" << param.second << endl;
            }
        }

        cout << "Headers:" << endl;
        for (const auto& header : headers) {
            cout << "  " << header.first << ": " << header.second << endl;
        }
        
        if (!body.empty()) {
            cout << "Body: " << body << endl;
        }
        
        cout << "Timeout: " << timeout << " seconds" << endl;
        cout << "Request executed successfully!" << endl;
    }
};

class MethodStep;
class HeadersStep;
class OptionalStep;

class UrlSteps{
    public:
    virtual MethodStep& withUrl(string url) = 0;
};

class MethodStep{
    public:
    virtual HeadersStep& withMethod(string method) = 0;
};

class HeadersStep{
    public:
    virtual OptionalStep& withHeader(string key, string value) = 0;
};

class OptionalStep {
public:
    virtual ~OptionalStep() {}
    virtual OptionalStep& withBody(string body) = 0;
    virtual OptionalStep& withTimeout(int timeout) = 0;
    virtual HttpRequest build() = 0;
};

class HttpRequestStepBuilder: 
    public MethodStep,
    public HeadersStep,
    public OptionalStep,
    public UrlSteps{
    private:
    HttpRequest req;

    public:

    static UrlSteps& getBuilder() {
        return *(new HttpRequestStepBuilder());
    }

    MethodStep& withUrl(string url) override{
        req.url = url;
        return *this;
    }

    HeadersStep& withMethod(string method) override {
        req.url = method;
        return *this;
    }

    OptionalStep& withHeader(string key, string value) override{
        req.headers[key] = value;
        return *this;
    }

    OptionalStep& withBody(string body) override{
        req.body = body;
        return *this;
    }

    OptionalStep& withTimeout(int timeout) override{
        req.timeout = timeout;
        return *this;
    }

    HttpRequest build() override {
        return req;
    }

};


int main(){
    HttpRequest stepRequest = HttpRequestStepBuilder::getBuilder()
    .withUrl("https://api.example.com/products")
    .withMethod("POST")
    .withHeader("Content-Type", "application/json")
    .withBody("{\"product\": \"Laptop\", \"price\": 49999}")
    .withTimeout(45)
    .build();

    stepRequest.execute();
    return 0;
}