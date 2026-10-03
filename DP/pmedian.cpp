for(int h = 1; h <= k;++h){ //窮舉目前放了多少個區間
    for(int i = 1;i <= n;++i){ //第 h 個區間以 pi 為右界
        dp[h][i] = inf; //初始化
        for(int j = 1; j <= i; ++j){ //第 h 個區間的左界
            dp[h][i] = min(dp[h][i],dp[h-1][j-1] + d[j][i]);
        } 
    } 
}
cout << dp[k][n];