// Implement Stack using Queues

// using 2 queue

class MyStack {
public:
  queue<int> queue1, queue2;
  MyStack() {}

  void push(int x) {
    queue1.push(x);
    while (!queue2.empty()) {
      queue1.push(queue2.front());
      queue2.pop();
    }
    swap(queue1, queue2);
  }

  int pop() {
    int popped = queue2.front();
    queue2.pop();
    return popped;
  }

  int top() { return queue2.front(); }

  bool empty() { return queue2.empty(); }
};

// using one queue only

class MyStack {
public:
  queue<int> q;
  MyStack() {}

  void push(int x) {
    int size = q.size();
    q.push(x);
    while (size--) {
      q.push(q.front());
      q.pop();
    }
  }

  int pop() {
    int popped = q.front();
    q.pop();
    return popped;
  }

  int top() { return q.front(); }

  bool empty() { return q.empty(); }
};

// Time Complexity: O(N)

// Space Complexity: O(N)
