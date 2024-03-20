#include <iostream>
#include <limits>

using namespace std;

template <typename T>

class Queue
{
private:
    struct Node
    {
        T data;
        Node *next;

        Node(const T &data)
        {
            this->data = data;
            next = nullptr;
        }
    };

    Node *front, *rear;

public:
    Queue()
    {
        front = rear = nullptr;
    }

    void enqueue(const T &data)
    {
        Node *newNode = new Node(data);
        if (isEmpty())
        {
            front = rear = newNode;
        }
        else
        {
            rear->next = newNode;
            rear = newNode;
        }
    }

    T dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue empty!" << endl;
        }

        T data = front->data;
        Node *temp = front;
        front = front->next;
        delete temp;

        if (front == nullptr)
        {
            rear = nullptr;
        }

        return data;
    }

    bool isEmpty() const
    {
        return front == nullptr;
    }

    void printQueue() const
    {
        if (isEmpty())
        {
            cout << "Empty queue!" << endl;
            return;
        }

        Node *temp = front;
        cout << "Queue elements: ";
        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    T &operator[](int index)
    {
        if (isEmpty())
        {
            cout << "Queue empty!" << endl;
        }

        Node *temp = front;
        for (int i = 0; i < index; i++)
        {
            temp = temp->next;
        }

        return temp->data;
    }

    Queue &operator=(const Queue &other)
    {
        if (this != &other)
        {
            while (!isEmpty())
            {
                dequeue();
            }

            Node *temp = other.front;
            while (temp != nullptr)
            {
                enqueue(temp->data);
                temp = temp->next;
            }
        }

        return *this;
    }
    Queue<T> &operator+(const T &data)
    {
        enqueue(data);
        return *this;
    }

    Queue<T> &operator-()
    {
        dequeue();
        return *this;
    }
    ~Queue()
    {
        while (!isEmpty())
        {
            dequeue();
        }
    }
};
double getDoubleInput()
{
    double num;
    cout << "Enter integer value: ";
    while (!(cin >> num))
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. \n Please enter an integer: ";
    }

    return num;
}
int main()
{
    Queue<double> q, q1;

    int setter = 0;
    int answer = 0;
    do
    {
        cout << "--------------Overload playground--------------" << endl;
        cout << "(1)(+) Add element to queue." << endl;
        cout << "(2)(-) Delete element from queue." << endl;
        cout << "(3)(=) Copy current queue to buffer queue." << endl;
        cout << "(4) Check if queue is empty." << endl;
        cout << "(5) Print all queues." << endl;
        cout << "(6) Exit." << endl;
        cout << "Choice: ";
        cin >> setter;

        switch (setter)
        {
        case 1:
            double value;
            cout << "ADD to 1 or 2 ? ";
            cin >> answer;
            value = getDoubleInput();
            if (answer == 1)
            {
                q + value;
            }
            else if (answer == 2)
            {
                q1 + value;
            }

            break;
        case 2:
            cout << "DELETE from 1 or 2 ? ";
            cin >> answer;
            cout << "Queue after deleted element." << endl;
            if (answer == 1)
            {
                -q;
                q.printQueue();
            }
            else if (answer == 2)
            {
                -q1;
                q1.printQueue();
            }
            cin.clear();
            break;
        case 3:
            cout << "Copy (1 to 2) or (2 to 1)";
            cin >> answer;
            if (answer == 1)
            {
                q1 = q;
            }
            else if (answer == 2)
            {
                q = q1;
            }
            cin.clear();
            break;
        case 4:
            cout << "First queue(empty all ok):";
            q[0];
            cout << "Second queue(empty all ok):";
            q1[0];
            break;
        case 5:
            cout << "--Current queue--" << endl;
            q.printQueue();
            cout << "--Copied queue--" << endl;
            q1.printQueue();
            break;
        }

    } while (setter != 6);
}