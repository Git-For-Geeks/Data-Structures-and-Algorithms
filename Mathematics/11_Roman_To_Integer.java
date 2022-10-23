package Mathematics;

import java.util.*;

public class Main {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter Roman numeral: ");
        String s = sc.next();
        int ans = 0, num = 0;
        for (int i = s.length()-1; i >= 0; i--) {
            //It will seprate charater from string 
            switch(s.charAt(i)) {
                case 'I': num = 1; break;
                case 'V': num = 5; break;
                case 'X': num = 10; break;
                case 'L': num = 50; break;
                case 'C': num = 100; break;
                case 'D': num = 500; break;
                case 'M': num = 1000; break;
            }
            if ( 4* num < ans){
                //It is for the instances where subtraction is used (for 4, 9, 40, 90, 400, 900)
                ans -= num;
            }
            else {
                ans += num;
            }
        }
        System.out.println("Integer = "+ ans);
    }
}
