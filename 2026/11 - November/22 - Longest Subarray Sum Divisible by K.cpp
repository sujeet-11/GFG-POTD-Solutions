class Solution {
public:
    int longestSubarrayDivK(vector<int>& arr, int k) {
        int n = (int) arr.size();
        int ans = 0;
        unordered_map<int, int> mp;
        mp[0] = -1;
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            sum += arr[i];
            int rem = ((sum % k) + k) % k;
            if (mp.count(rem)) {
                ans = max(ans, i - mp[rem]);
            } else {
                mp[rem] = i;
            }
        }
        return ans;
    }
};
