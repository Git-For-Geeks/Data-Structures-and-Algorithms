class Solution{
    public:
    // You need to complete this function

    // avoid space at the starting of the string in "move disk....."
    long long toh(int N, int from, int to, int aux) {
        long long steps = 0;
        if(N>=1){
           steps = steps + toh(N-1,from, aux, to);   
           cout<<"move disk "<< N <<" from rod "<< from <<" to rod "<< to <<endl;
           steps++;
           steps = steps + toh(N-1, aux, to, from);
        }
        return steps;
    }

};