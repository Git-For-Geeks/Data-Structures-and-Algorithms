class Solution {
public:
    int titleToNumber(string columnTitle) {
        long long int ii, col=0;
        for(ii=0; ii<columnTitle.length(); ii++) {
            col = 26*col + columnTitle[ii] - 'A' + 1;
        }
        return col;
    }
};