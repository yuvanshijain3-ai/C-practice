#include <iostream>
using namespace std;

class Queue {
private:
    int queue[5];
    int front;
    int rear;
    int size;

public:
    Queue()
    {
        size = 5;
        front = -1;
        rear = -1;
    }

    void enqueue(int value)
    {
        if (rear == size - 1)
        {
            cout << "\nQueue Overflow! Queue is full.\n";
            return;
        }

        if (front == -1)
        {
            front = 0;
        }

        rear++;
        queue[rear] = value;

        cout << "\nElement inserted successfully.\n";
    }

    void dequeue()
    {
        if (front == -1)
        {
            cout << "\nQueue Underflow! Queue is empty.\n";
            return;
        }

        cout << "\nElement deleted: " << queue[front] << endl;

        front++;

        if (front > rear)
        {
            front = rear = -1;
        }
    }

    void display()
    {
        if (front == -1)
        {
            cout << "\nQueue is empty.\n";
            return;
        }

        cout << "\nQueue Elements: ";

        for (int i = front; i <= rear; i++)
        {
            cout << queue[i] << " ";
        }

        cout << endl;
    }
};

int main()
{
    Queue q;
    int choice, value;

    do
    {
        cout << "\n1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Display" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                cout << "Enter element: ";
                cin >> value;
                q.enqueue(value);
                break;

            case 2:
                q.dequeue();
                break;

            case 3:
                q.display();
                break;

            case 4:
                cout << "\nExiting program...\n";
                break;

            default:
                cout << "\nInvalid choice!\n";
        }

    } while (choice != 4);

    return 0;
}