#include<iostream>
#include<string.h>
using namespace std;

int main(){
	
	int t;       // t test cases
	cin>>t;
	while(t--)
	{
		string Arr;       // input array
		cin>>Arr;
		long top=0,count=0,tempCount=0;
		for(long long i=0;i<Arr.size();i++)
		{
			if(Arr.at(i)=='<')  //if '<' symbol is encountered push on to the stack . 
				top++;
			else
			{
				top--;         //if '>' symbol is encountered	pop off the stack .
				if(top<0)
					break;
				tempCount++;
				if(top==0)
				{
					count=tempCount;  //keep count and store count in tmpCount.
				}	
			}
		}	
		cout<<count*2<<endl;    //print the count 2 times so that it inclues both opening and closing brackets. 
	}
	
return 0;
}