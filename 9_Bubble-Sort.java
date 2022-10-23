class Main{
    public static void main(String[] args) {
        int arr[] = {6,3,8,9,4,2};
        int n = arr.length;
        bubble_sort(arr,n);
        System.out.print("{");
        for(int i : arr){
            System.out.print(" "+i);
        }
        System.out.print(" }");
    }
    public static void bubble_sort(int arr[], int n){
        int temp;
        for(int i=0;i<n-1;i++){
            
            for(int j=0;j<n-i-1;j++){
                
                if(arr[j]>arr[j+1]){
                    temp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = temp;
                }
                
            }
            
        }
        
    }
}