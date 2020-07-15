package net.study.kotlintest

/**
 * @author       刘畅
 * @createdate   2020/7/14
 * @describe
 */
class day44 {
    fun firstUniqChar(str: String): Int {
        var length = str.length;
//        printf("%d\n", length);
        var n = 0;
        var chars = str.toCharArray();
        while (chars[n] != null) {
            var index = n;
            for (i in 0 until length){
                if (chars[index] == chars[i] && i != index) {
                    break;
                } else if (i == (length - 1)) {
                    return n;
                }
            }
            index++;
            n++;
        }
        return -1;
    }

    fun main(args: Array<String>) {
        System.out.println("=====" + firstUniqChar("loveleetcode"));

    }
}