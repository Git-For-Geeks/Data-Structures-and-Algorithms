class Solution:
    def convertToTitle(self, columnNumber: int) -> str:
        title = "" #Creating an empty string to concate the title
        while columnNumber:
            columnNumber = columnNumber - 1 #As alphabets start from 0 we decrease the count by 1
            title = chr(columnNumber%26+65) + title #We get the number and covert it into the required character and concate
            columnNumber = columnNumber//26 #We floor the number to get remaining alphabets
        return title # At last we return the title