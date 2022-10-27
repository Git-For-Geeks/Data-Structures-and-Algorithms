class Solution {
public:
    bool isValid(string &str){
        if(str.length()>3) return false;
        if(str.front()=='0' && str.length()>1) return false;
        int val = stoi(str);
        return val>=0 && val<=255;
    }
    
    void compute(string s,vector<string> &ans){
        for(int i=1 ; i<=3 ; i++)
        {
            string first = s.substr(0,i);
            if(isValid(first))
            {
                for(int j=1 ; j<=3 && i+j<s.size() ;j++)
                {
                    string second = s.substr(i,j);
                    if(isValid(second))
                    {
                        for(int k=1 ; k<=3 && i+j+k<s.size() ; k++)
                        {
                            string third=s.substr(i+j,k);
                            string fourth=s.substr(i+j+k);
                            if(isValid(third) && isValid(fourth))
                            {
                                ans.push_back(first+"."+second+"."+third+"."+fourth);
                            }
                        }
                    }
                }
            }
        }
    }
    
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        compute(s,ans);
        return ans;    
    }
};