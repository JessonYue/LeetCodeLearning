
public class ExampleUnitTest {
    @Test
    public void addition_isCorrect() {
        int[] numbers = {-1,2, 7, 11, 15};

        try {
            array167(numbers, 14);
        } catch (Exception e) {
            e.printStackTrace();
        }

    }

    /**
     2020.06.1
     167. 两数之和 II - 输入有序数组
     给定一个已按照升序排列 的有序数组，找到两个数使得它们相加之和等于目标数。

     函数应该返回这两个下标值 index1 和 index2，其中 index1 必须小于 index2。

     说明:

     返回的下标值（index1 和 index2）不是从零开始的。
     你可以假设每个输入只对应唯一的答案，而且你不可以重复使用相同的元素。
     示例:

     输入: numbers = [2, 7, 11, 15], target = 9
     输出: [1,2]
     解释: 2 与 7 之和等于目标数 9 。因此 index1 = 1, index2 = 2 。
     */

    //缩减搜索空间的角度思考这个解法  可替代 双重循环
    public int[] twoSumDoublePointer(int[] numbers, int target) {

        int[] result = new int[2];
        int length = numbers.length;
        int i = 0, j=length-1;
        int sum;
        while (i<j){
            sum = numbers[i]+numbers[j];
            if (target==sum){
                result[0] = i+1;
                result[1] = j+1;
                break;
            }else if (target>sum){
                i++;
            }else if (target<sum){
                j--;
            }
        }

        return result;
    }

    public int[] twoSum(int[] numbers, int target) {

        int[] result = new int[2];
        int length = numbers.length;
        for (int i = 0; i < length; i++) {
            for (int j = i+1; j <length ; j++) {
                if (numbers[i]!=numbers[j] && target==numbers[i]+numbers[j]){
                    result[0] = i+1;
                    result[1] = j+1;
                }
            }
        }

        return result;
    }


    public void array167(int[] arr, int target) throws Exception {
        int arrLength = arr.length;
        if (target >= arr[arrLength - 1] && arr[0]>0) throw new Exception("输入的 target 大于数组中最大数");
        if (target < arr[0]) throw new Exception("输入的 target 小于数组中最小数");
        for (int i = 0; i < arrLength; i++) {
            for (int j = i + 1; j < arrLength && target == arr[i]+arr[j]; j++) {
                System.out.println("[" + (i + 1) + "," + (j + 1) + "]");
            }
        }
        System.out.println("没有找合适的两个数");
    }


}
