package net.study.kotlintest

/**
 * @author       刘畅
 * @createdate   2020/7/17
 * @describe
 */
class day47 {

    fun backspaceCompare(s: String, t: String): Boolean {
        var a = s.toCharArray();
        var b = t.toCharArray();
        var asb = StringBuffer();
        var bsb = StringBuffer();
        for (i in a.indices) {
            if (i + 1 < a.size && a[i + 1] == '#') {
                continue;
            } else if (a[i] == '#' && i < a.size) {
                continue;
            } else {
                asb.append(a[i]);
            }

        }
        for (j in b.indices) {
            if (j + 1 < b.size && b[j + 1] == '#') {
                continue;
            } else if (b[j] == '#') {
                continue;
            } else {
                bsb.append(b[j]);
            }
        }

        return asb.toString() == bsb.toString();
    }

    fun main(arg: Array<String>) {
        System.out.println("=====" + backspaceCompare("ab#c", "ad#c"));
    }
}