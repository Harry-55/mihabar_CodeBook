while(s < n){
        // ans = 0, s = 1
        int k = (s - ans - 1) / (m - 1) + 1; 
        if(s + k > n) k = n - s;
        s += k;
        ans = (ans + k * m) % s;
}// n ¤j m ¤p