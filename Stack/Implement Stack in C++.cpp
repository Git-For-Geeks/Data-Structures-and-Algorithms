
// we will run a loop from i = 1 to target.size and maintain a variable j ,if we found i equal to target[j] then we will perform push operation and increment j
// else we will perform both operation that is push and pop and keep j as it is.

class Solution {
public:
vector buildArray(vector& target, int n) {i
vector <string>s;  // string of vector which will store our final answers
int j=0;  // variable to access target element and to maintain a track of cuurent number
for(int i=1;i<=n && j<target.size();i++)   // loop 
{
if(i==target[j]){    // matching condtion 
s.push_back("Push");
j++;     
}
else{
s.push_back("Push");   
s.push_back("Pop");
}
}
return s;    // returning answer string
}
};
