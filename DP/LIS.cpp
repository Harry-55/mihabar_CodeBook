vector<int> dp;
for(int i = 0; i < n;++i){
    auto it = lower_bound(all(dp),A[i]) - dp.begin();
    if(it == dp.size()){
        dp.push_back(A[i]);
    }else{
        dp[it] = A[i];
    }
}
cout << dp.size() << '\n';