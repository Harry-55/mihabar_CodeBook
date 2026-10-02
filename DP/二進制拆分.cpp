//目前物品最多拿 k 個
int s = 0;
vector<pair<int,int>> A;//A是儲存所有捆
for(int r = 1; r * 2 <= k; r *= 2){//TLE的話先算k最大拿幾個
    s += r;
    A.push_back({r*c[i],r*v[i]});//r個一綑
}
A.push_back({(k-s)*c[i],(k-s)*v[i]});//最後一捆