import java.io.*;
import java.util.*;
import java.math.*;
public class Main {
    public static void main(String args[]) {
        Scanner in = new Scanner(System.in);
        int T=in.nextInt();
        while(T-->0) {
            BigInteger tmp = in.nextBigInteger();
            BigInteger a=BigInteger.ONE;
            for(int i=1;;i++){
//              System.out.println("fuck"+a);
                a=a.multiply(BigInteger.valueOf(2));
                if(a.compareTo(tmp)==1) {
                    //a.divide(tmp1);
//                  System.out.printf("test\n");
                    System.out.println(a.divide(BigInteger.valueOf(2)));
                    break;
                }
            }
        }
    }
 }