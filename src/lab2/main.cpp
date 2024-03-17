#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        next = nullptr;
    }
};

class Queue
{
public:
    Node *front;
    Node *rear;

    Queue()
    {
        front = rear = nullptr;
    }

    void enqueue(int data)
    {
        Node *newNode = new Node(data);
        if (rear == nullptr)
        {
            front = rear = newNode;
        }
        else
        {
            rear->next = newNode;
            rear = newNode;
        }
    }

    void dequeue()
    {
        if (front == nullptr)
        {
            cout << "Empty query!" << endl;
            return;
        }
        else if (front == rear)
        {
            front = rear = nullptr;
        }
        else
        {
            Node *temp = front;
            front = front->next;
            delete temp;
        }
    }

    Queue operator+(const Queue &other)
    {
        Queue newQueue;
        Node *temp1 = this->front;
        Node *temp2 = other.front;

        while (temp1 != nullptr && temp2 != nullptr)
        {
            newQueue.enqueue(temp1->data + temp2->data);
            temp1 = temp1->next;
            temp2 = temp2->next;
        }

        return newQueue;
    }

    Queue operator-(const Queue &other)
    {
        Queue newQueue;
        Node *temp1 = this->front;
        Node *temp2 = other.front;

        while (temp1 != nullptr && temp2 != nullptr)
        {
            newQueue.enqueue(temp1->data - temp2->data);
            temp1 = temp1->next;
            temp2 = temp2->next;
        }

        return newQueue;
    }
    Queue operator=(const Queue &other)
    {
        while (front != nullptr)
        {
            dequeue();
        }

        Node *temp = other.front;
        while (temp != nullptr)
        {
            enqueue(temp->data);
            temp = temp->next;
        }

        return *this;
    }

    void print()
    {
        Node *temp = front;
        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main()
{
    Queue q1, q2, q4, q5, q7, q8;
    q1.enqueue(1);
    q1.enqueue(2);
    q2.enqueue(3);
    q2.enqueue(4);

    q4.enqueue(7);
    q4.enqueue(8);
    q5.enqueue(3);
    q5.enqueue(4);

    q7.enqueue(1);
    q7.enqueue(2);
    q8.enqueue(3);
    q8.enqueue(4);

    Queue q3 = q1 + q2;
    Queue q6 = q4 - q5;

    cout << "Operator overload(+)" << endl;
    cout << "Elements of q1: ";
    q1.print();
    cout << "Elements of q2: ";
    q2.print();
    cout << "Result: ";
    q3.print();

    cout << "\nOperator overload(-)" << endl;
    cout << "Elements of q4: ";
    q4.print();
    cout << "Elements of q5: ";
    q5.print();
    cout << "Result: ";
    q6.print();

    cout << "\nOperator overload(=)" << endl;
    cout << "Elements of q7: ";
    q7.print();
    cout << "Elements of q8: ";
    q8.print();
    q7 = q8;
    cout << "Result: ";
    q7.print();

    return 0;
}
