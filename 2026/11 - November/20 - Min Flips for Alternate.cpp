class Solution {
public:
    int minFlips(string &s) {
        int n = (int) s.size();
        int cnt1 = 0;
        int cnt2 = 0;
        for (int i = 0; i < n; i++) {
            char expected1 = (i & 1 ? '0' : '1');
            char expected2 = (i & 1 ? '1' : '0');
            if (s[i] != expected1) {
                cnt1++;
            }
            if (s[i] != expected2) {
                cnt2++;
            }
        }
        return min(cnt1, cnt2);
    }
};
