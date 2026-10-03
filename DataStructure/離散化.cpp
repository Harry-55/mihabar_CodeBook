vi tmp(arr);
sort(all(tmp));
tmp.erase(unique(all(tmp)), tmp.end());
for(int i = 0 ; i < n ; i++) arr[i] = lower_bound(all(tmp), arr[i]) - tmp.begin();