#include<iostream>
#define SIZE 5
using namespace std;
class Queue {
    private:
    int items[SIZE], front, rear;
    public:
    Queue() {
        front = -1;
        rear = -1;
    }

    bool isFull() {
        if((front == 0 && rear == SIZE - 1) || rear + 1 == front) {
            return true;
        }
        return false;
    }

    bool isEmpty() {
        if(front == -1) {
            return true;
        }
        return false;
    }

    void enqueue(int value) {
        if(isFull()) {
            cout<<"\nQueue is Full";
        } else {
            if(front == -1) front = 0;
            rear = (rear + 1) % SIZE;
            items[rear] = value;
        }
    }

    void dequeue() {
        if(isEmpty()) {
            cout<<"\nQueue is Empty";
        } else {
            if(front == rear) {
                front = -1;
                rear = -1;
            } else {
                front = (front + 1) % SIZE;

            }
        }
    }

    void display() {
        if(isEmpty()) {
            cout<<"\nQueue is Empty";
        } else if (front <= rear) {
            cout<<"\nElements in Queue\n";
            for(int i=front; i<=rear; i++)
             cout<<items[i]<<" ";
        } else if (front > rear) {
            cout<<"\nElements in Queue\n";
            for(int i = front; i < SIZE; i++) 
             cout<<items[i]<<" ";
            for(int i = 0; i<=rear; i++)
             cout<<items[i]<<" ";
        }
    }
};
int main() {
    Queue q;
    q.dequeue();
    q.enqueue(12);
    q.enqueue(54);
    q.enqueue(13);
    q.enqueue(98);
    q.enqueue(76);
    q.enqueue(83);
    q.dequeue();
    q.enqueue(83);
    q.dequeue();
    q.display();
    return 0;
}