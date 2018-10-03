import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner cin  = new Scanner(System.in);
		while(cin.hasNext()){
			BigInteger a = new BigInteger("1");
			BigInteger b = new BigInteger("1");
			BigInteger t = new BigInteger("1");
			int n = cin.nextInt();
			if(n==-1)break;
			if(n==1 || n==2){
				System.out.println("Hour "+n+": "+1+" cow(s) affected");
				continue;
			}
			for(int i=3;i<=n;i++){
				t = a;
				a = a.add(b);
				b = t;
			}
			System.out.println("Hour "+n+": "+a+" cow(s) affected");
		}
		
		
	}

}
