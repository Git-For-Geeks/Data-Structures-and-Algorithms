package Strings;

import java.util.ArrayList;
import java.util.List;

import static java.lang.Math.abs;

class Solution {
    public static List<String> strList = new ArrayList<>();
    public static int k;
    // str : Stores input string
    // n : Length of str.
    // curr : Stores current permutation
    // index : Index in current permutation, curr
    static void currRec(String str, int n, int index,String curr) { //current Reccursion
        // base case
        if (index == n) {
            return;
        }
        if (curr != null && !curr.trim().isEmpty()) {
            addList:
            {
                if (curr.length() > 1) {
                    int diff;
                    for (int z = 1; z < curr.length(); z++) {
                        diff = abs(curr.charAt(z) - curr.charAt(z - 1));
                        if (diff > k) {
                            break addList;
                        }
                    }
                    strList.add(curr);
                }
            }
        }
        for (int i = index + 1; i < n; i++) {
            curr += str.charAt(i);
            currRec(str, n, i, curr);

            // backtracking
            curr = curr.substring(0, curr.length() - 1);
        }
    }

    public static void main(String[] args) {
        String str = "pvjcci"; //enter the string here
        k=4; // enter the diff here
        currRec(str, str.length(), -1, "");
        System.out.println("Possible ideal subsequences : "+strList);
        int len=0;
        for(String slen:strList){
            if(slen.length()>len){
                len=slen.length();
            }
        }
        System.out.println("Tbe longest possible subsequence possible length : "+len);
    }
}