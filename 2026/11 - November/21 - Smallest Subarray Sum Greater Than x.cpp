class Solution {
public:
    int smallestSubWithSum(vector<int>& arr, int x) {
        int n = (int) arr.size();
        int l = 0;
        int sum = 0;
        int len = INT_MAX;
        for (int r = 0; r < n; r++) {
            sum += arr[r];
            while (sum > x) {
                sum -= arr[l];
                len = min(len, r - l + 1);
                l++;
            }
        }
        return len == INT_MAX ? 0 : len;
    }
};
