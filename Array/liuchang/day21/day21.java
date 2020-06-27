public class day21 {

    public static void main(String[] args) {
        int data[] ={5, 4, 0, 3, 1, 6, 2};
        System.out.println("====="+arrayNesting(data,7));
    }


    public static int arrayNesting(int nums[],int numSize){

        int numData = 0;
        int data[]= new int[numSize];
        int dataCount = 0;
        for (int i = 0; i < numSize; ++i) {
            data[dataCount] = nums[numData];
            numData = nums[numData];
            if (data[0] == numData && dataCount > 1) {
                break;
            }
            dataCount++;

        }
        return dataCount;

    }
}
