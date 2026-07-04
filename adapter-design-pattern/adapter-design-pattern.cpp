#include<iostream>
using namespace std;

class XmlDataProvider{
    public:
    string getXmlData(string &data){
        size_t sep = data.find(':');
        string name = data.substr(0, sep);
        string id   = data.substr(sep + 1);
        // Build an XML representation
        return "<user>"
               "<name>" + name + "</name>"
               "<id>"   + id   + "</id>"
               "</user>";
    }
};

class IReports{
    public:
    virtual string getJsonData(string &data) = 0;
};

class XmlDataProviderAdapter: public IReports{
    XmlDataProvider *xmlProvider;
    public:

    XmlDataProviderAdapter(XmlDataProvider *xmlProvider){
        this->xmlProvider = xmlProvider;
    }
    string getJsonData(string &data) override {
         string xml = xmlProvider->getXmlData(data);

        // 2. Naïvely parse out <name> and <id> values
        size_t startName = xml.find("<name>") + 6;
        size_t endName   = xml.find("</name>");
        string name      = xml.substr(startName, endName - startName);

        size_t startId = xml.find("<id>") + 4;
        size_t endId   = xml.find("</id>");
        string id      = xml.substr(startId, endId - startId);

        // 3. Build and return JSON
        return "{\"name\":\"" + name + "\", \"id\":" + id + "}";
    }
};

int main(){
    XmlDataProvider *xmlProv = new XmlDataProvider();
    IReports *report = new XmlDataProviderAdapter(xmlProv);

    // 3. Give it some raw data
    string rawData = "Alice:42";

     cout << "Processed JSON: "<<report->getJsonData(rawData)<<endl;
}