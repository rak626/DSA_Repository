// sort a stack

void getSortedStack(stack<int> &stack, int target) {
    if (stack.empty()) {
        stack.push(target);
        return;
    }
    int curVal = stack.top();
    if (curVal > target) {
        stack.pop();
        getSortedStack(stack, target);
        stack.push(curVal);
    } else {
        stack.push(target);
        return;
    }
}

void sortStack(stack<int> &stack) {
    if (stack.empty()) return;
    int val = stack.top();
    stack.pop();
    sortStack(stack);
    getSortedStack(stack, val);
}