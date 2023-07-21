// next smallest element

vector<int> nextSmallerElement(vector<int> &arr, int n) {
    stack<int> st;
    vector<int> nse(arr.size());
    for (int i = arr.size() - 1; i >= 0; i--) {
        while (!st.empty() and st.top() >= arr[i]) st.pop();
        if (st.empty())
            nse[i] = -1;
        else
            nse[i] = st.top();
        st.push(arr[i]);
    }
    return nse;
}