class Solution {
public:
    int uniquePaths(int m, int n) {
        
        int dp[m][n];
        memset(dp,0,sizeof(dp));
        
        dp[m-1][n-1] = 1;
        
        for(int i=m-1; i>=0; i--)
        {
            for(int j=n-1; j>=0; j--)
            {
                if(j-1>=0)
                    dp[i][j-1]+=dp[i][j];
                if(i-1>=0)
                    dp[i-1][j]+=dp[i][j];
            }
        }
        
        return dp[0][0];
    }
};
