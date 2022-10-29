import java.util.*;
public class Main
{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String s = sc.next();
		//Converting String to array of character
		char[] ch = s.toCharArray();
        List <String> sol = new ArrayList<>();
        
        for(char c = ch[0]; c<=ch[3]; c++){
            for(char r = ch[1]; r<=ch[4]; r++){
                //Adding to the sol list
                sol.add(""+ c + r);
            }
        }
        System.out.println(sol);
	}
}
