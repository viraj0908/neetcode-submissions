class Solution {

    vector<vector<int>> dp;
    string s, p;

    bool f(int i, int j){

        if(j == p.size())
            return i == s.size();

        if(dp[i][j] != -1)
            return dp[i][j];

        bool firstMatch =
            (i < s.size() &&
            (s[i] == p[j] || p[j] == '.'));

        if(j+1 < p.size() && p[j+1] == '*'){

            return dp[i][j] =
                (
                    f(i, j+2) ||
                    (firstMatch && f(i+1, j))
                );
        }

        return dp[i][j] =
            firstMatch && f(i+1, j+1);
    }

public:

    bool isMatch(string s1, string s2) {

        s = s1;
        p = s2;

        dp.resize(
            s.size()+1,
            vector<int>(p.size()+1, -1)
        );

        return f(0,0);
    }
};