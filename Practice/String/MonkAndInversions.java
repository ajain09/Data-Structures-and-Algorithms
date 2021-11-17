// https://www.hackerearth.com/problem/algorithm/monk-and-inversions-arrays-strings-e5aaa427/

import java.io.*;
import java.util.*;
import java.lang.*;
 
class TestClass {
  
   public static void main(String args[] ) throws Exception {
 
       Scanner sc = new Scanner(System.in);
       int t = sc.nextInt();
       while (t>0){
           t--;
           int n = sc.nextInt();
           int[][] m = new int[n][n];
           int[][] arr =  new int[n][n];
           for (int i = 0; i < n; i++){
               for (int j = 0; j < n; j++){
                   m[i][j] = sc.nextInt();
               }
           }
           int count = 0;
           for (int i = 0; i < n; i++){
               for (int j = 0; j < n; j++){
                   for (int p = i; p < n; p++){
                       for (int q = j; q < n; q++){
                           if(m[i][j]>m[p][q]){
                               count++;
                           }
                       }
                   }
               }
           }
           System.out.println(count);
       }
   }
}
