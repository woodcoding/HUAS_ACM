import java.math.BigInteger;
import java.util.Scanner;

/**
 * Created by chen on 2017/4/21 0021.
 */
public class Main{
    static final int maxn = 65;
    static BigInteger dp[][][] = new BigInteger[maxn][maxn][maxn];

    private static void Inital(){
        for(int i=0;i<maxn;i++)for(int j=0;j<maxn;j++)for(int k=0;k<maxn;k++)dp[i][j][k]=BigInteger.ZERO;
        dp[1][0][0] = BigInteger.ONE;
        dp[1][1][0] = BigInteger.ONE;
        dp[1][1][1] = BigInteger.ONE;
        for(int i=2;i<=60;i++){
            for(int j=0;j<=60;j++){
                for(int k=0;k<=60;k++){
                    if(i-1>=j)dp[i][j][k]=dp[i][j][k].add(dp[i-1][j][k]);
                    if(j-1>=k)dp[i][j][k]=dp[i][j][k].add(dp[i][j-1][k]);
                    if(k-1>=0)dp[i][j][k]=dp[i][j][k].add(dp[i][j][k-1]);
                }
            }
        }
    }

    public static void main(String args[]){
        Inital();
        Scanner cin = new Scanner(System.in);
        int n;
        while (cin.hasNext()){
            n = cin.nextInt();
            System.out.println(dp[n][n][n]);
            System.out.println();
        }
    }
}