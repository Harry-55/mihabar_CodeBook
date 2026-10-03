for(int i = 0;i < n; ++i)
    for (int s = 0; s < (1<<n) ; ++s)
        if (s & (1 << i))
            F[s] += F[s ^ (1 << i)];
//窮舉子集合
for(int s = mask; s ; s = (s-1)&mask;)