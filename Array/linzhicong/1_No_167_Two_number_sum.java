class Solution {
    public int[] twoSum(int[] numbers, int target) {
        if(numbers == null || numbers.length <= 0) return new int[0];
        // return baoSearch(numbers, target);
        // return mapSearch(numbers, target);
        return doublePointSearch(numbers, target);
    }

    // 前后双指针，利用有序特性
    int[] doublePointSearch(int[] numbers, int target) {
        int start = 0, end = numbers.length - 1;
        while(start < end) {
            if (numbers[start] + numbers[end] == target) {
                return new int[]{start+1, end+1};
            } else if(numbers[start] + numbers[end] > target) {
                end--;
            } else {
                start++;
            }
        }
        return new int[]{};
    }

    // 使用map
    int[] mapSearch(int[] numbers, int target) {
        HashMap<Integer, Integer> map = new HashMap();
        for(int i = 0; i < numbers.length; i++) {
            if (map.get(numbers[i]) != null) {
                return new int[]{map.get(numbers[i]), i+1};
            } else {
                map.put(target - numbers[i], i+1);
            }
        }
        return new int[]{};
    }

    // 暴力解法
    int[] baoSearch(int[] numbers, int target) {
        int[] result = new int[2];
        for(int i = 0; i < numbers.length && numbers[i] <= target; i++) {
            for(int j = i+1; j < numbers.length; j++) {
                if(numbers[i] + numbers[j] == target) {
                    result[0] = i+1;
                    result[1] = j+1;
                    return result;
                } else if(numbers[i] + numbers[j] > target) {
                    break;
                }
            }
        }
        return result;
    }

}