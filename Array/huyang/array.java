class Solution {
    public int[] twoSum(int[] nums, int target) {
        Map<Integer, Integer> map = new HashMap<>();
        int[] sum = new int [2];
        for(int i = 0 ; i < nums.length ; i ++ ){

            int res = target - nums[i];


            if(map.containsKey(res)){
              int index =   map.get(res);
              sum[0] = index;
              sum[1] = i;
              return sum;
            }

            map.put(nums[i], i );


        }
        return sum;

    }
}