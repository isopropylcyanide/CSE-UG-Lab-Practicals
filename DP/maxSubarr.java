import java.util.*;
import java.io.*;
import java.math.*;

class maxSubArr{
    // Print max contiguous and non contiguous sum
    static int getMaxNonCont(int []A){
        Arrays.sort(A);
        int sum = 0;

        if (A[A.length -1] <= 0)
            return A[A.length -1];

        for (int a : A){
            if (a > 0)
                sum += a;
        }
        return sum;
    }

    static int max(int a, int b){
        return a > b ? a : b;
    }

    static int getMaxContg(int A[]){
        // use Kadane's algorithm;
        int maxSum = A[0], currMax = A[0];
        for (int i = 1; i < A.length; i++){
            currMax = max(A[i], currMax + A[i]);
            maxSum = max(currMax, maxSum);
        }

        return maxSum;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int testCases = Integer.parseInt(br.readLine());
        while (testCases -- > 0){
            int N = Integer.parseInt(br.readLine());
            String s[] = br.readLine().split(" ");
            int A[] = new int[s.length];

            for (int i = 0; i < s.length; i++)
                A[i] = Integer.parseInt(s[i]);

            int maxContSum = getMaxContg(A);
            int maxNonContSum = getMaxNonCont(A);
            System.out.println(maxContSum + " " + maxNonContSum);
        }

    }

};
