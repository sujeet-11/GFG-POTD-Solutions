class Solution {
public:
    bool findPattern(string& s) {
        int n = (int) s.size();
        int i = 0;
        while (i < n) {
            if (s[i] != 'x') {
                return false;
            }
            int cnt = 0;
            while (i < n && s[i] == 'x') {
                cnt++;
                i++;
            }
            while (i < n && s[i] == 'y') {
                cnt--;
                i++;
            }
            if (cnt != 0) {
                return false;
            }
        }
        return true;
    }
};
