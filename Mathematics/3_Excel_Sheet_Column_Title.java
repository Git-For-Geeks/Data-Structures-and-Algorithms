package Mathematics;

import java.util.Scanner;

class Solution {
    
    public static String convertToTitle(int colNum) {
        StringBuilder colName = new StringBuilder();

        while (colNum > 0) {
            int rem = colNum % 26;
            if (rem == 0) {
                colName.append("Z");
                colNum = (colNum / 26) - 1;
            }
            else
            {
                colName.append((char)((rem - 1) + 'A'));
                colNum = colNum / 26;
            }
        }
        return(colName.reverse().toString());
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Col No. : ");
        int col=sc.nextInt();
        String title=convertToTitle(col);
        System.out.println("Col Name : "+title);
    }
}