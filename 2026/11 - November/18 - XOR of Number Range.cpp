class Solution {
public:
    int findXOR(int l, int r) {
        auto f = [&](int x) -> int {
            if (x % 4 == 1) {
                return 1;
            }
            if (x % 4 == 2) {
                return x + 1;
            }
            if (x % 4 == 3) {
                return 0;
            }
            if (x % 4 == 0) {
                return x;
            }
        };
        return f(r) ^ f(l - 1);
    }
};
