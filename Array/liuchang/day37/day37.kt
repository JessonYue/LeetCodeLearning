package net.study.kotlintest

/**
 * @author       刘畅
 * @createdate   2020/7/7
 * @describe
 */
class day37 {


    fun changeString(str: String): String {
        var chars: CharArray = str.toCharArray();
        var count = chars.size;
        var newString = CharArray(count);
        for (i in count - 1 downTo 0) {
            for (j in 0 until count) {
                if (newString[j] == '\u0000') {
                    newString[j] = chars[i];
                    break;
                }
            }
        }
        return String(newString);

    }

    fun main(args:Array<String>){
        System.out.println("====="+changeString("abcdef"))
    }
}