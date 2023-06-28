// House Robber 2

// same as maximumNonAdjacentSum just little trick used.

// space optimised
long long int maximumNonAdjacentSum(vector<long long int> &nums) {
    int n = nums.size();
    long long int prev = nums[0], prev2 = 0;
    for (int i = 1; i < n; i++) {
        long long int pick = nums[i];
        if (i > 1) {
            pick += prev2;
        }
        long long int nonPick = prev;
        long long int curi = max(pick, nonPick);
        prev2 = prev;
        prev = curi;
    }
    return prev;
}

long long int houseRobber(vector<int> &valueInHouse) {
    int n = valueInHouse.size();
    if (n == 1) return valueInHouse[0];
    vector<long long int> temp1, temp2;
    for (int i = 0; i < n; i++) {
        if (i != n - 1) temp1.push_back((long long int)valueInHouse[i]);
        if (i != 0) temp2.push_back((long long int)valueInHouse[i]);
    }
    return max(maximumNonAdjacentSum(temp1), maximumNonAdjacentSum(temp2));
}