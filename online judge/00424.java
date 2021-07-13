package test;

import java.math.BigInteger;
import java.util.Scanner;
import java.lang.String;

class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scan = new Scanner(System.in);
		
		BigInteger bi[] = new BigInteger[100];
		int i = 0;
		while(true){
			String temp = scan.nextLine();
			bi[i] = new BigInteger(temp);
			if (bi[i].equals(new BigInteger("0"))) break;
			i++;
		}
		
		BigInteger out = new BigInteger("0");
		for (int j = 0; j < i; j++)
			out = out.add(bi[j]);
		System.out.println(out);
		
		scan.close();
	}
}
