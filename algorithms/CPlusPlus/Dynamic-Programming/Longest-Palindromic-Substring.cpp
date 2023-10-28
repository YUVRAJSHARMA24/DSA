class Solution {
public:
    int dp[1001][1001];
    bool solve(string &s, int i, int j)
    {
        if(i >= j)
            return 1;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        if(s[i] == s[j])
            return dp[i][j] = solve(s, i+1, j-1);
        
        return dp[i][j] = 0;
    }
    
    string longestPalindrome(string s) {
        int n = s.size();
        memset(dp, -1, sizeof(dp));
        int maxi = INT_MIN;
        int start = 0;
        
        for(int i = 0; i<n; i++)
        {
            for(int j = i; j<n; j++)
            {
                if(solve(s, i, j) == true)
                {
                    if(j - i + 1 > maxi)
                    {
                        maxi = j - i + 1;
                        start = i;
                    }
                }
            }
        }
        
        return s.substr(start, maxi);
    }
};
