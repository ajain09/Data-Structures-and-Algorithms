//https://www.geeksforgeeks.org/?p=146957
//Given a string of size n, write functions to perform the following operations on a string-

// Left (Or anticlockwise) rotate the given string by d elements (where d <= n)
// Right (Or clockwise) rotate the given string by d elements (where d <= n).

import java.io.*;

class GFG {
	public static void main (String[] args) {
		String str1 = "GeeksforGeeks";
        System.out.println(leftrot(str1, 2));
 
        String str2 = "GeeksforGeeks";
        System.out.println(rightrot(str2, 2));
	}
	
	public static String leftrot(String s, int d){
	    String s1= s.substring(0,d);
	    String s2=s.substring(d);
	    return s2+s1;
	}
	
	public static String rightrot(String s, int d){
	    int n = s.length();
	    String s1 = s.substring(n-d,n); //last d letters
	    String s2 = s.substring(0,n-d); // first n-d letters
	    return s1+s2;
	}
}
