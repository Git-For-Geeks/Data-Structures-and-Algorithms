package Mathematics;

class Solution {
    
    public String convertToTitle(int colNum) {
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
}