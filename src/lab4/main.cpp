#include <iostream>
#include <string>
#include <stdexcept>
#include <regex>

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
    House(const string a, int f, int cor, int s, int year) : floors(f), countOfRooms(cor), square(s), yearOfConstruction(year)
    {
    }

    ~House()
    {
        cout << "Destructor House = " << address << endl;
    }

    virtual void Show()
    {
        cout << "--------------------------" << endl;
        cout << "address = " << address << endl;
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

class RussianLetterException : public std::exception
{
public:
    const char *what() const throw()
    {
        return "Russian letter found in the string!";
    }
};

static bool hasRussianCharacters(const std::string &input)
{
    regex russianRegex("[А-Яа-я]");
    return regex_search(input, russianRegex);
}

int main()
{

    int choice;
    string address;
    int floors, rooms, square, year;
    bool pool, basement, garden;

    while (true)
    {
        cout << "Choose house type:" << endl;
        cout << "1. Default house" << endl;
        cout << "2. Villa" << endl;
        cout << "3. Mansion" << endl;
        cout << "4. Exit" << endl;
        cout << "Input: ";
        cin >> choice;

        if (cin.fail())
        {
            cout << "Invalid input. Try again" << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }

        switch (choice)
        {
        case 1:
            try
            {
                cout << "Enter address(20 chars max): ";
                cin >> address;
                if (hasRussianCharacters(address))
                {
                    throw RussianLetterException();
                }
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
                cout << "Enter year of building: ";
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
            catch (const RussianLetterException &e)
            {
                cout << "Exception caught: " << e.what() << endl;
            }
            catch (...)
            {
                cout << "Unknow error" << endl;
            }
            break;
        case 2:
            try
            {
                cout << "Enter address(20 chars max): ";
                cin >> address;
                if (hasRussianCharacters(address))
                {
                    throw RussianLetterException();
                }
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
                cout << "Enter year of building: ";
                cin >> year;
                if (year < 2000)
                {
                    throw invalid_argument("Invalid input for year (must be at least 1)");
                }
                cout << "Do you want swimming pool (1 - yeah, 0 - NO): ";
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
            catch (const RussianLetterException &e)
            {
                cout << "Exception caught: " << e.what() << endl;
            }
            catch (...)
            {
                cout << "Unknow error" << endl;
            }
            break;
        case 3:
            try
            {
                cout << "Enter address (20 chars max): ";
                cin >> address;
                if (hasRussianCharacters(address))
                {
                    throw RussianLetterException();
                }
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
                cout << "Enter year of building: ";
                cin >> year;
                if (year < 2000)
                {
                    throw invalid_argument("Invalid input for year (must be at least 1)");
                }
                cout << "Do you want swimming pool (1 - yeah, 0 - NO): ";
                cin >> basement;
                cout << "Do you want basement (1 - yeah, 0 - NO): ";
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
            catch (const RussianLetterException &e)
            {
                cout << "Exception caught: " << e.what() << endl;
            }
            catch (...)
            {
                cout << "Unknow error" << endl;
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
