class Solution {
public:
  char posInfinite(string &s, int pos) {
    int n = (int) s.size();
    if (pos <= n) {
      return s[pos - 1];
    }
    vector<ll> len = {(ll)n};
    for (ll i = 1; len.back() < pos; i++) {
      len.push_back(2 * len.back() + i);
    }
    for (ll i = (ll) len.size() - 1; i >= 1; i--) {
      ll prev = len[i - 1];
      if (pos <= prev) {
        continue;
      }
      if (pos <= prev + i) {
        return '$';
      }
      pos = len[i] - pos + 1;
    }
    return s[pos - 1];
  }
};
