#include <iostream>
using namespace std;

int front = 0, back = -1;
int length = 10;
int *queue = new int[length];

void incQueue(int *&queue) {
    int tempArr[length];
    for (int i = 0; i <= back; i++) {
        tempArr[i] = queue[i];
    }
    length += 10;
    delete queue;
    queue = new int[length];
    for (int i = 0; i < length; i++) {
        queue[i] = NULL;
    }
    for (int i = 0; i <= back; i++) {
        queue[i] = tempArr[i];
    }
}

void enqueue(int x) {
    if (back == length - 1) {
        cout << "Extending queue array . . ." << endl;
        incQueue(queue);
        enqueue(x);
    } else {
        queue[++back] = x;
    }
}

void dequeue() {
    if (front == -1 || front > back) {
        cout << "Queue is empty";
        return;
    } else {
        cout << "Dequeued element is : " << queue[front] << endl;
        front++;
    }
}
int getSize() {
    // int counter = 0;
    // if (queue[length - 1] != NULL) {
    //     return length;
    // } else {
    //     for (int i = front; i <= back; i++) {
    //         counter++;
    //         continue;
    //     }
    // }
    return back - front + 1;
}

void printQueue() {
    if (front == -1 || front > back) {
        cout << "Queue is empty!" << endl;
        return;
    } else {
        int i;
        if (front > back) {
            for (i = front; i <= getSize(); i++) {
                cout << queue[i] << " ";
            }
            for (i = 0; i <= back; i++) {
                cout << queue[i] << " ";
            }
        } else {
            for (i = front; i <= back; i++)
                cout << queue[i] << " ";
        }
    }
    cout << endl;
}

int main() {
    int ch, value;
    cout << "1) Insert element to queue" << endl;
    cout << "2) Delete element from queue" << endl;
    cout << "3) Get the size of the queue" << endl;
    cout << "4) Display all the elements of queue" << endl;
    cout << "5) Exit" << endl;
    do {
        cout << "Enter your choice : " << endl;
        cin >> ch;
        switch (ch) {
            case 1:
                cout << "Enter the number you want to enqueue : ";
                cin >> value;
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                cout << "Size of the queue is : " << getSize() << endl;
                break;
            case 4:
                printQueue();
                break;
            case 5:
                delete queue;
                cout << "Exit" << endl;
                break;
            default:
                cout << "Invalid choice" << endl;
        }
    } while (ch != 5);
    return 0;
}
