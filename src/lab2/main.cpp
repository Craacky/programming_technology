#include <iostream>

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
            exit(1);
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

    T &operator[](int index)
    {
        if (isEmpty())
        {
            cout << "Queue empty!" << endl;
            exit(1);
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

    Queue<T> &operator-(const T &data)
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

int main()
{
    Queue<int> q;

    q + 10;
    q + 20;
    q + 30;

    cout << "First element: " << q[0] << endl;
    cout << "Second element: " << q[1] << endl;
    cout << "Third element: " << q[2] << endl;

    q - 10;
    q - 20;

    cout << "First element after dequeue: " << q[0] << endl;

    q - 30;

    cout << "Queue empty? " << (q.isEmpty() ? "Yes" : "No") << endl;
}