package thread;

class answerSolution{
    public int climbStairs(int n) {
        return child(0,n);
    }

    public int child(int start, int end){
        if(start > end){
            return 0;
        }
        if(start == end){
            return 1;
        }
        return child(start + 1,end) + child(start + 2, end);
    }
}
