#include <iostream>
#include <string>
#include <stdexcept>

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
    House(const string a, int f, int cor, int s, int year) : floors(f), countOfRooms(cor), square(s), yearOfConstruction(year){}

    ~House(){}

    virtual void Show()
    {
        cout << "--------------------------" << endl;
        cout << "ADRESS = " << adress << endl;
        cout << "FLOOR = " << floors << endl;
        cout << "COUNT OF ROOMS = " << countOfRooms << endl;
        cout << "SQUARE = " << square << endl;
    }

    string getAdress() const
    {
        return adress;
    }
};

class Villa : virtual public House
{
protected:
    bool pool;

public:
    Villa(const string a, int f, int cor, int s, int year, bool p) : House(a, f, cor, s, year), pool(p) {}

    ~Villa(){}

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

    ~Mansion(){}

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
    int choice;
    string address;
    int floors, rooms, square, year;
    bool pool, basement, garden;

    while (true)
    {
        cout << "Pick your type:" << endl;
        cout << "1. House" << endl;
        cout << "2. Villa" << endl;
        cout << "3. Mansion" << endl;
        cout << "4. exit" << endl;
        cout << "choose option: ";
        cin >> choice;

        if (cin.fail())
        {
            cout << "Error input. try again." << endl;
            cin.clear();
            cin.ignore(10000, '\n'); // clear buffer
            continue;
        }

        switch (choice)
        {
        case 1:
            try
            {
                cout << "Enter adress (no more than 20 symbols): ";
                cin >> address;
                if (address.size() > 20)
                {
                    throw invalid_argument("Address exceeds 20 characters");
                }
                cout << "Enter value of floors: ";
                cin >> floors;
                if (floors < 1)
                {
                    throw invalid_argument("Invalid input for floors (must be at least 1)");
                }
                cout << "Enter value of rooms: ";
                cin >> rooms;
                if (rooms < 1)
                {
                    throw invalid_argument("Invalid input for rooms (must be at least 1)");
                }
                cout << "Enter square: ";
                cin >> square;
                if (square < 1)
                {
                    throw invalid_argument("Invalid input for square (must be at least 1)");
                }
                cout << "Enter year of creation: ";
                cin >> year;
                if (year < 2000)
                {
                    throw invalid_argument("Invalid input for year (must be at least 1)");
                }
                House house = House(address, floors, rooms, square, year);
                house.Show();
            }
            catch (const invalid_argument &e)
            {
                cout << "Error: " << e.what() << endl;
                cin.clear();
                cin.ignore(10000, '\n');
            }
            break;
        case 2:
            try
            
            {
                cout << "Enter adress (no more than 20 symbols): ";
                cin >> address;
                if (address.size() > 20)
                {
                    throw invalid_argument("Address exceeds 20 characters");
                }
                cout << "Enter value of floors: ";
                cin >> floors;
                if (floors < 1)
                {
                    throw invalid_argument("Invalid input for floors (must be at least 1)");
                }
                cout << "Enter value of rooms: ";
                cin >> rooms;
                if (rooms < 1)
                {
                    throw invalid_argument("Invalid input for rooms (must be at least 1)");
                }
                cout << "Enter square: ";
                cin >> square;
                if (square < 1)
                {
                    throw invalid_argument("Invalid input for square (must be at least 1)");
                }
                cout << "Enter year of creation: ";
                cin >> year;
                if (year < 2000)
                {
                    throw invalid_argument("Invalid input for year (must be at least 1)");
                }
                cout << "Do you want swimming pool (1 - yeah, 0 - no): ";
                cin >> pool;
                Villa villa = Villa(address, floors, rooms, square, year, pool);
                villa.Show();
            }
            catch (const invalid_argument &e)
            {
                cout << "Error: " << e.what() << endl;
                cin.clear();
                cin.ignore(10000, '\n');
            }
            break;
        case 3:
            try
            {
                cout << "Enter adrees(no more than 20 symbols): ";
                cin >> address;
                if (address.size() > 20)
                {
                    throw invalid_argument("Address exceeds 20 characters");
                }
                cout << "Enter value of floors: ";
                cin >> floors;
                if (floors < 1)
                {
                    throw invalid_argument("Invalid input for floors (must be at least 1)");
                }
                cout << "Enter value of rooms: ";
                cin >> rooms;
                if (rooms < 1)
                {
                    throw invalid_argument("Invalid input for rooms (must be at least 1)");
                }
                cout << "Enter square: ";
                cin >> square;
                if (square < 1)
                {
                    throw invalid_argument("Invalid input for square (must be at least 1)");
                }
                cout << "Enter year of creation: ";
                cin >> year;
                if (year < 2000)
                {
                    throw invalid_argument("Invalid input for year (must be at least 1)");
                }
                cout << "Do you want basement (1 - yeah, 0 - no): ";
                cin >> basement;
                if(basement != 1 || basement !=0){
                    throw invalid_argument("Invalid input you have only 1 and 0 option");
                }
                cout << "Do you want garden (1 - yaeh, 0 - no): ";
                cin >> garden;
                Mansion mansion = Mansion(address, floors, rooms, square, year, basement, garden);
                mansion.Show();
            }
            catch (const invalid_argument &e)
            {
                cout << "Error: " << e.what() << endl;
                cin.clear();
                cin.ignore(10000, '\n');
            }
            break;
        case 4:
            return 0;
        default:
            cout << "Bag choice. Try again." << endl;
        }
    }

    return 0;
}
