#include<iostream>
using namespace std;
class PdfDocument{
    string data;
    string password;
    public:
    PdfDocument(string data, string password){
        this->data = data;
        this->password = password;
    }

    bool verifyPassword(string password){
        return this->password == password;
    }
};

class IPdfRenderer {
    public:
    virtual void renderPdf(PdfDocument* pdf, string password) = 0;
};
class PdfRenderService: public IPdfRenderer {
    public:
    void renderPdf(PdfDocument* pdf, string password) override {
        if(pdf->verifyPassword(password)){
            cout<<"your pdf unlocked"<<endl;
        }else{
            cout<<"password is incorrect"<<endl;
        }
    }
};

class ProxyPdfRenderService: public IPdfRenderer{
    IPdfRenderer* pdfRenderService;
    public:
    ProxyPdfRenderService(){
        pdfRenderService = new PdfRenderService();
    }
    void renderPdf(PdfDocument* pdf, string password) override {
        pdfRenderService->renderPdf(pdf,password);
    }
};


int main(){
    PdfDocument* pdf1  = new PdfDocument("data1","secret1");
    PdfDocument* pdf2  = new PdfDocument("data2","secret2");

    IPdfRenderer* pdfRenderService = new ProxyPdfRenderService();

    pdfRenderService->renderPdf(pdf1,"secret1");
    pdfRenderService->renderPdf(pdf1,"secret3");

}