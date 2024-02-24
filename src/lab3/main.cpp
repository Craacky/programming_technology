#include <iostream>
#include <string>

using namespace std;

class House
{
protected:
    string adress;
    int floors;
    int countOfRooms;
    int square;
    int yearOfConstruction;

public:
    House(const string a, int f, int cor, int s, int year) : adress(a), floors(f), countOfRooms(cor), square(s), yearOfConstruction(year) {}

    ~House()
    {
        cout << "Destructor House = " << adress << endl;
    }

    virtual void Show()
    {
        cout << "--------------------------" << endl;
        cout << "ADRESS = " << adress << endl;
        cout << "FLOOR = " << floors << endl;
        cout << "COUNT OF ROOMS = " << countOfRooms << endl;
        cout << "SQUARE = " << square << endl;
    }
};

class Villa : virtual public House
{
protected:
    bool pool;

public:
    Villa(const string a, int f, int cor, int s, int year, bool p) : House(a, f, cor, s, year), pool(p) {}

    ~Villa()
    {
        cout << "Destructor Villa = " << adress << endl;
    }

    void Show() override
    {
        House::Show();
        cout << "POOL = " << pool << endl;
    }
};

class Mansion : virtual public House
{
protected:
    bool basement;
    bool garden;

public:
    Mansion(const string a, int f, int cor, int s, int year, bool ba, bool ga) : House(a, f, cor, s, year), basement(ba), garden(ga) {}

    ~Mansion()
    {
        cout << "Destructor Mansion = " << adress << endl;
    }

    void Show() override
    {
        House::Show();
        cout << "BASEMENT = " << basement << endl;
        cout << "GARDEN = " << garden << endl;
        cout << "--------------------------" << endl;
    }
};

int main()
{
    House house("Leopard", 3, 8, 180, 2004);
    Villa villa("Miami", 5, 23, 180, 1998, true);
    Mansion mansion("Pushkina", 8, 56, 1245, 2012, true, true);

    house.Show();
    villa.Show();
    mansion.Show();
}