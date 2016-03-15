import java.util.*;
import java.io.*;
import java.math.*;

class fibMod{

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String input[] = br.readLine().split(" ");
        int A = Integer.parseInt(input[0]);
        int B = Integer.parseInt(input[1]);
        int N = Integer.parseInt(input[2]);

        BigInteger a = BigInteger.valueOf(A), b = BigInteger.valueOf(B);
        BigInteger sum = BigInteger.valueOf(0);
        for(int i = 3; i <= N; i++){
            BigInteger sum1 = b.multiply(b);
            sum = sum1.add(a);
            a = b;
            b = sum;
        }
        System.out.println(b);
    }

};
