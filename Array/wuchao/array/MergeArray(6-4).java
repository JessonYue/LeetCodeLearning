class Solution {
    //双指针法，Copy 一份A的元素，然后逐个对比B的元素
    //较小的放回A中，直到遍历完其中一个数组，将剩下没遍历完的那个数组剩余的元素直接拷贝进A剩余的位置中
    public void merge(int[] A, int m, int[] B, int n) {
        int[] subA = Arrays.copyOfRange(A,0,m);
        int i=0;
        int j=0;
        int k=0;
        while(i<m&&j<n){
            if(subA[i]<B[j]){
                A[k++]=subA[i];
                i++;
            } else {
                A[k++]=B[j];
                j++;
            }
        }
        //subA中还有元素没遍历完，这些元素都比A中的大
        while(i<m){
            A[k++] = subA[i];
            i++;
        }
        //B中还有元素没遍历完，这些元素都比A中的大
        while(j<n){
            A[k++] = B[j];
            j++;
        }
    }

    //改进双指针法，直接从A和B的最大值开始比较，较大的一个放到A的尾部，这样就不用开辟新的数组了
    //直到遍历完其中一个数组，将剩下没遍历完的那个数组剩余的元素直接拷贝进A剩余的位置中
    public void merge(int[] A, int m, int[] B, int n) {
        int i=m-1;
        int j=n-1;
        int k=A.length-1;
        while(i>=0&&j>=0){
            if(A[i]>B[j]){
                A[k--]=A[i--];
            } else {
                A[k--]=B[j--];
            }
        }
        //A中还有元素没遍历完，这些元素都比已经拷贝过的元素小
        while(i>=0){
            A[k--] = A[i--];
        }
        //B中还有元素没遍历完，这些元素都比已经拷贝过的元素小
        while(j>=0){
            A[k--] = B[j--];
        }
    }
}
