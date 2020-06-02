class Solution {
    //自己写的，O(n^2)
    public int[] twoSum1(int[] numbers, int target) {
        for(int i=0;i<numbers.length;i++){
            for(int j=numbers.length-1;j>0;j--){
                if(numbers[i]+numbers[j]==target){
                    return new int[]{++i,++j};
                }
            }
        }
        return null;
    }



//答案，O(n)
    //利用最大最小之和，与 target 做比较，
    //如果sum>target，说明j得小一点，所以j--；
    //如果sum<target，说明i得大一点，所以i++
    public int[] twoSum(int[] numbers, int target) {
        if(numbers == null){
            return null;
        }
        int i = 0;
        int j = numbers.length-1;
        while(i<j){
             int sum = numbers[i]+numbers[j];
             if(sum<target){
                i++;
             }else if(sum>target){
                 j--;
             }else{
                return new int[]{i+1,j+1};
             } 
        }
        return null;
    }

}