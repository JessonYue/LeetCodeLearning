/**

   默认为两组无序数组，第一步合并为datas
 * 归并排序，
 * 思路： 将两个各自有顺序的部分合并，从而生成一个新的有序的部分，从下到上依次归并（二叉树的后序遍历）
 *
 * 有点：重复数据效率高，适合链表
 * 缺点：空间占用大
 *
 */
 
public void mergeSort(int[] datas,int start,int end){
    if(start == end){
        return;
    }
 
 
    int mid = (end + start)/2;
    //分成两半，继续归并
    mergeSort(datas,start,mid);
    mergeSort(datas,mid+1,end);
 
    merge(datas,start,mid+1,end);
}
 
 
/**
 * 合并两个有序  中间切开的，左右两部分是排好的
 * @param arrays
 * @param left
 * @param mid
 * @param right
 */
public void merge(int[] arrays,int left,int mid,int right){
 
    //创建两个集合，承装左右部分
    int leftSize = mid - left;
    int rightSize = right - mid + 1;
 
    int[] leftArray = new int[leftSize];
    int[] rightArray = new int[rightSize];
 
 
    //给两个集合填充数据
    for(int i = left;i<mid;i++){
        leftArray[i - left] = arrays[i];//左侧数据填充
    }
    for(int i = mid;i<right+1;i++){
        rightArray[i - mid] = arrays[i];
    }
    //开始比较，然后合并  左右从零开始比较，谁小，谁放到新数组，然后移动指针
    int i = 0;//左侧
    int j = 0;//右侧
    int k = left;//原数组定位的指针， 从当前位置开始填充
    while (i < leftSize && j < rightSize){//两个指针都在范围内，说明可以继续比
        if(leftArray[i] < rightArray[j]){
            arrays[k] = leftArray[i];//拿到数组
            k++;//挪动合并数组指针
            i++;//挪动左侧数据指针
        }else{
            arrays[k] = rightArray[j];
            k++;
            j++;
        }
    }
    //当有一侧被比较完毕后，把剩下的一侧数组放到原先数组
    while(i < leftSize){
          arrays[k] = leftArray[i];
          i++;
          k++;
    }
    while(j < rightSize){
          arrays[k] = rightArray[j];
          j++;
          k++;
    }
}