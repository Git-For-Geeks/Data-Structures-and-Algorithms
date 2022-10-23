public List<String> buildArray(int[] target, int n) {
    List<String> res = new ArrayList<>();
    int curr = 1;
        
    for(int i = 0; i < target.length; i++){
        res.add("Push");//have to push every time

        if(target[i] != curr){//means we have to pop
            res.add("Pop");
            i--;//also don't move to next element in the array
        }
        curr++;
    }
    return res;
}