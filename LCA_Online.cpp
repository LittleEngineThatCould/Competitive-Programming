class tree
{
    private:
        int dis[MAXN];
        int dp[MAXN][mL];
    public:
        tree()
        {
            this->add_vertex(1,1);
        }
        void add_vertex(int a, int b)
        {
            dp[b][0] = a;
            dis[b] = (b == a ? 0 : dis[a] + 1);
            REP(i, 1, mL)
            {
                dp[b][i] = dp[dp[b][i-1]][i-1];
            }
        }
        int lca(int a, int b)
        {
            for(int i = mL-1; i >= 0; i--)
            {
                if(dis[dp[a][i]] >= dis[b])
                {
                    a = dp[a][i];
                }
                else if(dis[dp[b][i]] >= dis[a])
                {
                    b = dp[b][i];
                }
            }

            if(a == b) return a;

            for(int i = mL - 1; i >= 0; i--)
            {
                if (dp[a][i] != dp[b][i])
                {
                    a = dp[a][i];
                    b = dp[b][i];
                }
            }
            return dp[a][0];
        }
};
