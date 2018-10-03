import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner cin  = new Scanner(System.in);
		int t = cin.nextInt();
		for(int i=1;i<=t;i++){
	        BigDecimal b1;
	        BigDecimal b2 = new BigDecimal("1");
	        BigDecimal b3 = new BigDecimal("6");
	        BigDecimal b4 = new BigDecimal("6");
	        BigDecimal b5 = new BigDecimal("6");
	        b1=cin.nextBigDecimal();
	        b1=b1.add(b2);
	        b4 = b1.subtract(b2);
	        b5 = b1.add(b2);
	        b1 = b1.multiply(b4.multiply(b5));
	        b1 = b1.divide(b3);
	        b1 = b1.multiply(b1);
	        System.out.println(b1);
		}
		
		
	}

}
