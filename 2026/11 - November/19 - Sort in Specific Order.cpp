class Solution {
public:
    void sortIt(vector<int>& arr) {
        sort(arr.begin(), arr.end(), [](int a, int b) {
            if ((a & 1) != (b & 1)) {
                return (a & 1) > (b & 1);
            }
            if (a & 1) {
                return a > b;
            }
            return a < b;
        });
    }
};
