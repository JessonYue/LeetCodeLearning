package day28



fun numOfSubarrays(arr: IntArray, k: Int, threshold: Int): Int {
    var standSum = k * threshold
    var sum = 0
    var count=0

    for (i in 0..k-1){
        sum += arr[i];
    }

    if (sum >= standSum)
        count = 1;

    for (j in k..arr.size-1){
        sum -= arr[j-k]
        sum += arr[j]
        if(sum >= standSum)
            count++
    }
    return count;
}


fun main() {
    var arr: IntArray = intArrayOf(1,1,1,1,1)
    print(numOfSubarrays(arr,1,0))
}