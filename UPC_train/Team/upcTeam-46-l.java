import java.math.BigInteger;
import java.util.Scanner;
 
public class Main {
    public static void main(String[] args) {
        // TODO Auto-generated method stub
        Scanner in = new Scanner(System.in);
        BigInteger a[]=new BigInteger[1000005];
        a[1]=BigInteger.valueOf(3);
        a[2]=BigInteger.valueOf(20);
        a[3]=BigInteger.valueOf(119);
        for(int i=4;i<=10004;i++) {
            a[i]=a[i-1].multiply(BigInteger.valueOf(6)).subtract((a[i-2].subtract(BigInteger.valueOf(2))));
        }
        int T;
        T=in.nextInt();
        for(int kk=1;kk<=T;kk++) {
            BigInteger c ;
            c=in.nextBigInteger();
            for(int i=1;i<=1000005;i++) {
                if(c.compareTo(a[i]) < 0) {
                    System.out.println(a[i]);
                    break;
                }
            }
        }
    }
}