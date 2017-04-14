C = [[0 for i in range(105)] for i in range(105)]
for i in range(0, 102):
    C[i][0]=1
    for j in range(1, i+1):
        C[i][j] = C[i-1][j] + C[i-1][j-1]

def gcd(a, b):
    if b == 0:
        return a
    return gcd(b, a % b)


while True:
    try:
        m, n, l = map(int, raw_input().split())
        if l > m:
            print('mukyu~')
        else:
            dp = [[0 for i in range(105)] for i in range(105)]
            dp[0][0] = 1
            for i in range(1, n+1):
                for j in range(1, m+1):
                    for k in range(0, min(j+1, l)):
                        dp[i][j] += dp[i-1][j-k]*C[m-(j-k)][k]
            tot = n ** m
            use = 0
            for i in range(1, n+1):
                use += dp[i][m]
            use = tot - use
            g = gcd(tot, use)
            print str(use/g)+'/'+str(tot/g)
    except:
        break