class Solution {
public:
    int countLocalMaximums(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<vector<int>>> pref(
            201,
            vector<vector<int>>(n + 1, vector<int>(m + 1, 0))
        );

        for (int val = 0; val <= 200; val++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {

                    int add = (matrix[i][j] > val);

                    pref[val][i + 1][j + 1] =
                        pref[val][i][j + 1] +
                        pref[val][i + 1][j] -
                        pref[val][i][j] +
                        add;
                }
            }
        }

        auto query = [&](int val, int r1, int c1, int r2, int c2) {

            return pref[val][r2 + 1][c2 + 1]
                 - pref[val][r1][c2 + 1]
                 - pref[val][r2 + 1][c1]
                 + pref[val][r1][c1];
        };

        int ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                int x = matrix[i][j];

                if (x == 0) {
                    continue;
                }

                int r1 = max(0, i - x);
                int c1 = max(0, j - x);

                int r2 = min(n - 1, i + x);
                int c2 = min(m - 1, j + x);

                int cnt = query(x, r1, c1, r2, c2);

                vector<pair<int,int>> corners = {
                    {i - x, j - x},
                    {i - x, j + x},
                    {i + x, j - x},
                    {i + x, j + x}
                };

                for (auto &[r, c] : corners) {
                    if (r >= 0 && r < n && c >= 0 && c < m) {
                        if (matrix[r][c] > x) {
                            cnt--;
                        }
                    }
                }

                if (cnt == 0) {
                    ans++;
                }
            }
        }

        return ans;
    }
};
