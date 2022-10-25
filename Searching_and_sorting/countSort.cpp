 string countSort(string arr)
    {
        //we have 26 characters from a to z so storing them
vector<int>count(26,0);
int z = arr.size();
for(int i=0;i<z;i++)
{   //converting char to num and storing in count array
    //increment count at that particular position
    count[arr[i]-'a']++; //eg. 'c' - 'a' = 2
}

for(int i=1;i<26;i++)
//keeping the count at first index intact
//and incrementing count at next index using previous index
count[i]+=count[i-1];

//declare an empty string 
string s(arr.length(), ' ');

for(int i=0;i<z;i++){
    //pre-decrement 
    //put count value in j index
    int j = --count[arr[i]-'a'];
    //put character in string s
    s[j] = arr[i];
}
return s;

    } 
        
   
};