#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

class House
{
protected:
    string address;
    int floors;
    int countOfRooms;
    int square;
    int yearOfConstruction;

public:
    House(const string a, int f, int cor, int s, int year) : floors(f), countOfRooms(cor), square(s), yearOfConstruction(year) {
        if (a.size() > 20) {
            throw invalid_argument("Address exceeds 20 characters");
        }
        address = a;
    }

    ~House()
    {
        cout << "Destructor House = " << address << endl;
    }

    virtual void Show()
    {
        cout << "--------------------------" << endl;
        cout << "ADDRESS = " << address << endl;
        cout << "FLOOR = " << floors << endl;
        cout << "COUNT OF ROOMS = " << countOfRooms << endl;
        cout << "SQUARE = " << square << endl;
    }

    string getAddress() const {
        return address;
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
        cout << "Destructor Villa = " << address << endl;
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
        cout << "Destructor Mansion = " << address << endl;
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
 
    int choice;
    string address;
    int floors, rooms, square, year;
    bool pool, basement, garden;

    while (true) {
        cout << "Choose type of build:" << endl;
        cout << "1. Default house" << endl;
        cout << "2. Villa" << endl;
        cout << "3. Mansion" << endl;
        cout << "4. Exit" << endl;
        cout << "Your choice: ";
        cin >> choice;

        if (cin.fail()) {
            cout << "INput error. Try again." << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }

        switch (choice) {
        case 1:
            try {
                cout << "Enter address (20 symbol limit): ";
                cin >> address;
                if (address.size() > 20) {
                    throw invalid_argument("Address exceeds 20 characters");
                }
                cout << "Enter number of floors: ";
                cin >> floors;
                if (floors < 1) {
                    throw invalid_argument("Invalid input for floors (must be at least 1)");
                }
                cout << "Enter number of rooms: ";
                cin >> rooms;
                if (rooms < 1) {
                    throw invalid_argument("Invalid input for rooms (must be at least 1)");
                }
                cout << "Enter square: ";
                cin >> square;
                if (square < 1) {
                    throw invalid_argument("Invalid input for square (must be at least 1)");
                }
                cout << "Enter year of building: ";
                cin >> year;
                if (year < 2000) {
                    throw invalid_argument("Invalid input for year (must be at least 1)");
                }
                House house = House(address, floors, rooms, square, year);
                house.Show();
            }
            catch (const invalid_argument& e) {
                cout << "Error: " << e.what() << endl;
                cin.clear();
                cin.ignore(10000, '\n');
            }
            break;
        case 2:
            try {
                cout << "Enter address (20 symbol limit): ";
                cin >> address;
                if (address.size() > 20) {
                    throw invalid_argument("Address exceeds 20 characters");
                }
                cout << "Enter number of floors: ";
                cin >> floors;
                if (floors < 1) {
                    throw invalid_argument("Invalid input for floors (must be at least 1)");
                }
                cout << "Enter number of rooms: ";
                cin >> rooms;
                if (rooms < 1) {
                    throw invalid_argument("Invalid input for rooms (must be at least 1)");
                }
                cout << "Enter square: ";
                cin >> square;
                if (square < 1) {
                    throw invalid_argument("Invalid input for square (must be at least 1)");
                }
                cout << "Enter year of building: ";
                cin >> year;
                if (year < 2000) {
                    throw invalid_argument("Invalid input for year (must be at least 1)");
                }
                cout << "Do you have swimming pool (1 - yes, 0 - no): ";
                cin >> pool;
                Villa villa = Villa(address, floors, rooms, square, year, pool);
                villa.Show();
            }
            catch (const invalid_argument& e) {
                cout << "Error: " << e.what() << endl;
           
           
                cin.clear();
                cin.ignore(10000, '\n');
            }
            break;
        case 3:
            try {
                cout << "Enter address(20 symbols limit): ";
                cin >> address;
                if (address.size() > 20) {
                    throw invalid_argument("Address exceeds 20 characters");
                }
                cout << "Enter number of floors: ";
                cin >> floors;
                if (floors < 1) {
                    throw invalid_argument("Invalid input for floors (must be at least 1)");
                }
                cout << "Enter number of rooms: ";
                cin >> rooms;
                if (rooms < 1) {
                    throw invalid_argument("Invalid input for rooms (must be at least 1)");
                }
                cout << "Enter square: ";
                cin >> square;
                if (square < 1) {
                    throw invalid_argument("Invalid input for square (must be at least 1)");
                }
                cout << "Enter year of building: ";
                cin >> year;
                if (year < 2000) {
                    throw invalid_argument("Invalid input for year (must be at least 1)");
                }
                cout << "Do you have basement (1 - yes, 0 - no): ";
                cin >> basement;
                cout << "Do you have garden (1 - yes, 0 - no): ";
                cin >> garden;
                Mansion mansion = Mansion(address, floors, rooms, square, year, basement, garden);
                mansion.Show();
            }
            catch (const invalid_argument& e) {
                cout << "Error: " << e.what() << endl;
                cin.clear();
                cin.ignore(10000, '\n');
            }
            break;
        case 4:
            return 0;
        default:
            cout << "Invalid choice. Try again." << endl;
        }
    }

    return 0;
}
