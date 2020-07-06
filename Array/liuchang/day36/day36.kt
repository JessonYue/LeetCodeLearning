package net.study.kotlintest

/**
 * @author       刘畅
 * @createdate   2020/7/7
 * @describe
 */
class day36 {

    fun count4One(num: Int): Int {
        var tmp = 0;
        var count = 0;
        var number = num;
        while (number != 0) {
            tmp = (number.and(1))
            if (tmp == 1)
                count++;
            number = number.shr(1) ;
        }
        return count;
    }

    fun main(args:Array<String>){

        System.out.println("=====" + count4One(15));
    }
}