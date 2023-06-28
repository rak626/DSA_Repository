// Implement Queue using Stacks

// O(1) amortised. ( amortised means almost close to O(1) but not actually O(1)
class MyQueue {
public:
    stack<int> stack1, stack2;
    MyQueue() {}

    void push(int x) { stack1.push(x); }

    int pop() {
        if (stack2.empty()) {
            while (!stack1.empty()) {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        int popped = stack2.top();
        stack2.pop();
        return popped;
    }

    int peek() {
        if (stack2.empty()) {
            while (!stack1.empty()) {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        return stack2.top();
    }

    bool empty() {
        if (stack1.empty() and stack2.empty()) return true;
        return false;
    }
};