class Solution {
public:
    
    string reformat(string s) {
        int digits{};
        int chars{};
        
        // count digits and spaces
        for (auto ch : s)
        {
            if (ch >= 'a' && ch <= 'z') ++chars;
            else ++digits;
        }
        
        // If counts and digits differ by one they cannot be arranged as per req.
        if (abs(chars- digits) > 1) return "";
        
		// May be a better way to represent this..??
        string answer(s.size(), ' ');
        // If chars are more then first digit should be a char and digits between them
        int charIndex = chars >  digits ? 0 : 1, digitIndex = !charIndex;
         for (auto ch : s)
        {
            if (ch >= 'a' && ch <= 'z') 
            {
                answer[charIndex] = ch;
                charIndex += 2;
            }
            else
            {
                 answer[digitIndex] = ch;
                digitIndex += 2;
            }
        }
        
        return answer;
    }
    
};
