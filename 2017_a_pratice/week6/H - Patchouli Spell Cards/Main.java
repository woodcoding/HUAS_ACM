package a2017.practice.week5;

import java.math.BigInteger;
import java.util.Scanner;

/**
 * Created by chen on 2017/4/13 0013.
 */
public class Main {
    static final int maxn = 105;
    static BigInteger C[][] = new BigInteger[maxn][maxn];
    static BigInteger dp[][] = new BigInteger[maxn][maxn];
    static BigInteger N[] = new BigInteger[maxn];

    private static void Fac(BigInteger X[]) {
        X[0] = BigInteger.ONE;
        for (int i = 1; i < X.length; i++) {
            X[i] = X[i - 1].multiply(BigInteger.valueOf(i));
        }
    }

    private static void Comb(BigInteger X[][]) {
        for (int i = 0; i < maxn; i++) {
            for (int j = 0; j <= i; j++) {
                X[i][j] = N[i].divide(N[j]).divide(N[i - j]);
            }
        }
    }

    public static void main(String args[]) {
        Fac(N);
        Comb(C);
        int n, m, l;
        Scanner cin = new Scanner(System.in);
        while (cin.hasNext()) {
            m = cin.nextInt();
            n = cin.nextInt();
            l = cin.nextInt();
            if (l > m) {
                System.out.println("mukyu~");
                continue;
            }
            for (int i = 0; i < maxn; i++) {
                for (int j = 0; j < maxn; j++) {
                    dp[i][j] = BigInteger.ZERO;
                }
            }
            dp[0][0] = BigInteger.ONE;
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= m; j++) {
                    for (int k = 0; k <= Math.min(j, l - 1); k++) {
                        dp[i][j] = dp[i][j].add(dp[i - 1][j - k].multiply(C[m - (j - k)][k]));
                    }
                }
            }
            BigInteger all = BigInteger.valueOf(n).pow(m);
            BigInteger use = BigInteger.ZERO;
            for (int i = 1; i <= n; i++) {
                use = use.add(dp[i][m]);
            }
            use = all.subtract(use);
            BigInteger g = all.gcd(use);
            System.out.println(use.divide(g) + "/" + all.divide(g));
        }
    }
}
