// K-th Permutation Sequence

string kthPermutation(int n, int k) {
    vector<int> num;
    int fact = 1;  // find factorial upto n-1 numbers
    for (int i = 1; i < n; i++) {
        fact = fact * i;
        num.push_back(i);
    }
    num.push_back(n);
    string ans = "";
    k = k - 1;
    while (1) {
        ans = ans + to_string(num[k / fact]);  // find num for that pos
        num.erase(num.begin() + k / fact);     // erase num which is taken
        if (num.size() == 0) break;            // if all num taken then break
        k = k % fact;                          // new k
        fact = fact / num.size();              // new fact
    }
    return ans;
}