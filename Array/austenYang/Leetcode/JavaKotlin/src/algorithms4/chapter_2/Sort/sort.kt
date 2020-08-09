package algorithms4.chapter_2.Sort

fun selectSort(array: IntArray) {
    for (i in array.indices) {
        var minIndex = i
        for (j in i until array.size) {
            if (array[minIndex] > array[j]) {
                minIndex = j
            }
        }
        swap(array, i, minIndex)
    }
}

/**
 * 1. 将第一待排序序列第一个元素看做一个有序序列，把第二个元素到最后一个元素当成是未排序序列。
 * 2. 从头到尾依次扫描未排序序列，将扫描到的每个元素插入有序序列的适当位置。
 */
fun insertSort(array: IntArray) {
    for (i in 1 until array.size) {
        var j = i
        while (j > 0 && array[j] < array[j - 1]) {
            val temp = array[j - 1]
            array[j - 1] = array[j]
            array[j] = temp
            j--
        }
    }
}

fun mergeSort(array: IntArray) {
    mergeSortInner(array, 0, array.size - 1)
}

private fun mergeSortInner(array: IntArray, lo: Int, hi: Int) {
    if (lo >= hi) return
    val mid = lo + (hi - lo) / 2
    mergeSortInner(array, lo, mid)
    mergeSortInner(array, mid + 1, hi)
    merge(array, lo, mid, hi)
}

private fun merge(array: IntArray, lo: Int, mid: Int, hi: Int) {
    var i = lo
    var j = mid + 1
    val temp = array.copyOf()
    for (k in lo..hi) {
        when {
            i > mid -> array[k] = temp[j++]
            j > hi -> array[k] = temp[i++]
            temp[i] < temp[j] -> array[k] = temp[i++]
            else -> array[k] = temp[j++]
        }
    }
}


fun quickSort(intArray: IntArray) {
    quickSortInner(intArray, 0, intArray.size - 1)
}

private fun quickSortInner(intArray: IntArray, lo: Int, hi: Int) {
    if (lo >= hi) return
    val j = partition(intArray, lo, hi)
    quickSortInner(intArray, lo, j - 1)
    quickSortInner(intArray, j + 1, hi)
}

private fun partition(intArray: IntArray, lo: Int, hi: Int): Int {
    var i = lo
    var j = hi + 1
    val v = intArray[lo]
    while (true) {
        while (intArray[++i] < v) if (i == hi) break
        while (intArray[--j] > v) if (j == lo) break
        if (i >= j) break
        swap(intArray, i, j)
    }
    swap(intArray, lo, j)
    return j
}

private fun swap(intArray: IntArray, i: Int, j: Int) {
    val temp = intArray[i]
    intArray[i] = intArray[j]
    intArray[j] = temp
}


fun main() {
    val arrays = intArrayOf(1, 3, 2, 1)
    insertSort(arrays)

    mergeSort(arrays)
    quickSort(arrays)
    selectSort(arrays)
    arrays.forEach(::println)
}