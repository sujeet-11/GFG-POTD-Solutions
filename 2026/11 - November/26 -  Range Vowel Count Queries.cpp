class Solution {
public:
  vector<int> countVowels(string &s, vector<vector<int>> &queries) {
    int n = (int) s.size();
    vector<int> pref(n, 0);
    auto check = [&](char c) -> bool {
      return (c == 'a' || c == 'e' || c == 'i' || c == 'u' || c == 'o');
    };
    pref[0] = check(s[0]);
    for (int i = 1; i < n; i++) {
      if (check(s[i])) {
        pref[i] = 1 + pref[i - 1];
      } else {
        pref[i] = pref[i - 1];
      }
    }
    int q = (int)queries.size();
    vector<int> ans(q);
    for (int i = 0; i < q; i++) {
      int l = queries[i][0];
      int r = queries[i][1];
      ans[i] = pref[r];
      if (l - 1 >= 0) {
        ans[i] -= pref[l - 1];
      }
    }
    return ans;
  }
};
