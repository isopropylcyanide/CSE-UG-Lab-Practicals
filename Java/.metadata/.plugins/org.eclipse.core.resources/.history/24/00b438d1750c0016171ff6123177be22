public class Average {
  
 public static void main(String[] args) {
  int [] A = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  partitionEqualAvg(A);
 }
  
 public static void partitionEqualAvg(int [] A) {
  int n = A.length;
  int S = sumOfArray(A);
  double avg = S/(double)n;
  int subsetLen = n/2;
   
  /*
   * T[k][i][j] is 1 
   * k : size of subset
   * i : last element considered
   * j : sum wanted
   * 
   * if we there exists some subset of size k 
   * using the set of elements {1,2,...,i} that sum to j. 
   * 
   * T[k][i][j] = T[k-1][i-1][j-item_i] || T[k][i-1][j] 
   * 
   */
  boolean [][][] T = new boolean[subsetLen+1][n+1][S+1];
   
  for (int i=0; i<=n; i++) {
   T[0][i][0] = true;
  }
   
  for (int k=1; k<=subsetLen; k++) {
   for (int i=1; i<n; i++) {
    for (int j=1; j<=S; j++) {
     if (A[i] <= j) {
      T[k][i][j] = T[k-1][i-1][j-A[i]];
     }
     T[k][i][j] = T[k][i][j] || T[k][i-1][j];
     if (T[k][i][j]) {
      double tempAvg = (double)j/(double)k;
      if (Math.abs((tempAvg - avg)) <= 0.00001 ) {
       System.out.println("Partition 1: " + j + " " + k);
       System.out.println("Partition 1: " + (S-j) + " " + (n-k));
       return ;
      }
     }
    }
   }
  }
  System.out.println("No partition with equal average possible!");
 }
  
 public static int sumOfArray(int [] A) {
  int len = A.length;
  int sum = 0;
  for (int i=0; i<len; i++) {
   sum += A[i];
  }
  return sum;
 }
}