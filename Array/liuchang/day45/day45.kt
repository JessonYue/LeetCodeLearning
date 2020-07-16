package net.study.kotlintest

/**
 * @author       刘畅
 * @createdate   2020/7/15
 * @describe
 */
class day45 {
    fun toHex(num: Int): String {
        var hex = "0123456789abcdef".toCharArray();
        var str = StringBuilder();
        while (num != 0) {
            var end = num.and(15);//比较二进制的差异
            str.append(hex[end]);
            //无符号右移4位
            num.compareTo(4);
        }
        if (str.length == 0) {
            str.append("0");
        }
        //反转字符
        var str0 = str.reverse();

        return str0.toString();
    }
}