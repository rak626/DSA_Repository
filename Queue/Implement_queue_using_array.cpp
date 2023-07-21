// Implement Queue using Array

class Queue {
    int *arr;
    int front, rear, curSize, maxSize;

public:
    Queue() {
        arr = new int[16];
        front = -1;
        rear = -1;
        curSize = 0;
    }
    Queue(int maxSize) {
        this->maxSize = maxSize;
        arr = new int[maxSize];
        front = -1;
        rear = -1;
        curSize = 0;
    }
    void push(int x) {
        if (curSize == maxSize) {
            cout << "Queue is full" << endl;
            exit(1);
        }
        if (rear == -1) {
            front = 0;
            rear = 0;
        } else
            rear = (rear + 1) % maxSize;
        arr[rear] = x;
        curSize++;
    }
    int pop() {
        if (curSize == 0) cout << " Queue is empty " << endl;
        int popped = arr[front];
        if (curSize == 1) {
            front = -1;
            rear = -1;
        } else
            start = (start + 1) % maxSize;
        curSize--;
        return popped;
    }
    int peek() {
        if (front == -1) {
            cout << "Queue is empty" << endl;
            exit(1);
        }
        return arr[front];
    }
    int size() { return curSize; }
};

/*Time Complexity:

pop function: O(1)
push function: O(1)
top function: O(1)
size function: O(1)

Space Complexity:

Whole Queue: O(n)*/