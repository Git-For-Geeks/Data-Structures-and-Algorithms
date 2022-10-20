class Solution
{
public:
    string intToRoman(int num)
    {

        // pre calculate the roman value

        vector<string> ones = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};

        vector<string> tens = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};

        vector<string> hundreds = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};

        vector<string> thousands = {"", "M", "MM", "MMM"};

        string res = "";

        // finding digit at thousands place

        res += thousands[num / 1000];

        // finding digit at hundreds place

        res += hundreds[(num % 1000) / 100];

        // finding digit at tens place

        res += tens[(num % 100) / 10];

        // finding digit at ones place

        res += ones[num % 10];

        return res;
        //*********************************************************************************
        //*********************************************************************************
        //                      Time Complexity :- O(Constant)
        //*********************************************************************************
        //*********************************************************************************
        //*********************************************************************************
        //*********************************************************************************
        //                      Space Complexity :- O(Constant
        //*********************************************************************************
        //*********************************************************************************
      
    }
};