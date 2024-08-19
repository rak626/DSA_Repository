// Implement Stack using Array

class Stack {
    int capacity;
    int *arr;
    int top;

public:
    Stack() {
        capacity = 1000;
        arr = new int[capacity];
        top = -1;
    }
    void push(int x) {
        top++;
        arr[top] = x;
    }
    int pop() {
        int res = arr[top];
        top--;
        return res;
    }
    int Top() { return top; }
    int size() { return top + 1; }
};

// Tc - O(n)
// Sc - O(n)