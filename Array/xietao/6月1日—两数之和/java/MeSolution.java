public class MeSolution {
    public int[] twoSum(int[] numbers, int target) {

        for(int index = 0; index < numbers.length-1; index++){
            for(int i = 1; i < numbers.length; i++){
                if(numbers[index] + numbers[i] == target){
                    if(index == i){
                        continue;
                    }
                    return new int[]{++index,++i};
                }

            }
        }
        return new int[]{0,0};
    }
}
