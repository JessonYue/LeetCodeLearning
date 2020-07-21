var var_a: Int = 10;
var arrayListThree = arrayOf(2, 'a', 3, false, 9)


fun sum(a: Int, b: Int): Int {
    return a + b
}

fun test(a: Int, b: (num1: Int, num2: Int) -> Int): Int {
    return b.invoke(a, a)
}

fun funp(var_1: Int, var_2: Int, var_5: (var_3: Int, var_4: Int) -> Int): Int{
    return var_5.invoke(var_1,var_2);
}


fun main(args: Array<String>) {

//    val testStr = "a"
//    val sum = testStr.sumBy { it.toInt() + 100 }
//    println(sum)


//    var var_2 = funp(10, 40, { num1, num2 ->
//        sum(num1,num2)
//    })

    var var_2  = funp(10,20){ i: Int, i1: Int ->
        sum(10,20)
    }

    println(var_2)





}



fun basis(num: Int): Int {

    return num + var_a;
}
