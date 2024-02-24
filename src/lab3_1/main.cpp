#include <iostream> 
using namespace std; 
 
class Document 
{ 
public: 
    string type;      // a 
    string fullName;  // b 
    string docNumber; // c 
    int validity;     // срок действия (d) 
 
public: 
    Document(const string a, string b, string c, int d) : type(a), fullName(b), docNumber(c), validity(d) {} 
 
    ~Document() 
    { 
        cout << "Destructor Document = " << type << endl; 
    } 
 
    virtual void Show() 
    { 
 
        cout << "-------------------" << endl; 
        cout << "Type of document: " << type << endl; 
        cout << "Name: " << fullName << endl; 
        cout << "Document number: " << docNumber << endl; 
        cout << "Document validity: " << validity << endl; 
    } 
    void Show1(){
        Show();
    }
}; 
 
class Passport : virtual public Document 
{ 
public: 
    string typePassport; // t 
 
public: 
    Passport(const string a, string b, string c, int d, string t) : Document(a, b, c, d), typePassport(t) {} 
 
    ~Passport() 
    { 
         cout << "Destructor Passport = " << type << endl; 
    } 
    
 
    void Show() override 
    { 
        Document::Show();
        cout << "Type of passport = " << typePassport << endl; 
    } 
}; 
 
class Lulus : virtual public Document // lulus - пропуск 
{ 
public: 
    string where; // w 
 
public: 
    Lulus(const string a, string b, string c, int d, string w) : Document(a, b, c, d), where(w) {} 
 
    ~Lulus() 
    { 
        cout << "Destructor Lulus = " << type << endl; 
    } 

 
    void Show() override 
    { 
        Document::Show();
        cout << "Lulus for = " << where << endl; 
    } 
}; 
 
class Certificate : virtual public Document 
{ 
protected: 
    string what; // h 
 
public: 
    Certificate(const string a, string b, string c, int d, string h) : Document(a, b, c, d), what(h) {} 
 
    ~Certificate() 
    { 
        cout << "Destructor certificate = " << type << endl; 
    } 

    void Show() override 
    { 
        Document::Show();
        cout << "Certificate of = " << what << endl; 
    } 
}; 
 
int main() 
{ 
    Passport passport = Passport("Passport", "Ivan Ivanov Ivanjvich", "AB566566", 7, "interior"); 
    Lulus lulus = Lulus("Lulus", "Petrov Petr Petrovich", "568974", 4, "university"); 
    Certificate certificate = Certificate("Certificate", "Leonovets Darya Victorovna", "54781", 10, "Auto"); 
 
    passport.Show1(); 
    lulus.Show1(); 
    certificate.Show1(); 
}