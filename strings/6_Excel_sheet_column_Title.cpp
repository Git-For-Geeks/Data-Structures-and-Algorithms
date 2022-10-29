#define MAX 10
class Solution {
public:
    string convertToTitle(int columnNumber) {
       int n = columnNumber;
       char str[MAX]; 
       int i = 0; 
       while (n > 0) {
            int r = n % 26; // here r is remainder
            if (r == 0) {
                str[i++] = 'Z';
                n = (n / 26) - 1;
            }
            else {
                str[i++] = (r - 1) + 'A';
                n = n / 26;
            }
        }
        str[i] = '\0';
        reverse(str, str + strlen(str));
        // cout << str << endl;
 
    return str;
    }
};