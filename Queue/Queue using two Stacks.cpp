//Function to push an element in queue by using 2 stacks.
void StackQueue :: push(int x)
{
    
    s1.push(x);
}

//here s1 denotes to stack1 and s2 denotes to stack2 
//Function to pop an element from queue by using 2 stacks.
int StackQueue :: pop()
{
    if(s1.empty())                     //stack1 empty
    {
        return -1;
    }
    else
    {
        while(!s1.empty())             // stack1 is not empty, pop of the stack and push ont to the stack2
        {
            int data = s1.top();
            s1.pop();
            s2.push(data);
        }
        int ans = s2.top();           //store the top of stack in ans 
        s2.pop();
        while(!s2.empty())
        {
            int data2 = s2.top();
            s2.pop();
            s1.push(data2);
        }
        return ans;
    }
   
}

