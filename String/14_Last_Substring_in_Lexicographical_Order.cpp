class Solution {
public:
    string lastSubstring(string s) {
         int n =s.length();
        int MaxIndex=n-1;
        int i=n-2;
        while(i>=0)
        {
            if(s[i]>s[MaxIndex])
                MaxIndex=i;
            else if(s[i]==s[MaxIndex])
            {
                int j=1;
                while((MaxIndex+j)<n && s[i+j]==s[MaxIndex+j] && (i+j)!=MaxIndex) j++;
                
                if(s[i+j]>=s[MaxIndex+j] || (MaxIndex+j)>=n)
                    MaxIndex=i;
            }
            i--;
        }
        return s.substr(MaxIndex);
    }
    
};
