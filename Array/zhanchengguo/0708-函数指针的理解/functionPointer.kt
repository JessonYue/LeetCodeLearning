package com.test.ktapplication


fun main() {
    action1(3) {
        print("action1 is call\n")
    }

    action2(3) {
        it == 3
    }

}

fun action1(a: Int, callback: () -> Unit) {
    callback()
    print("input value is ${a}\n")
}

fun action2(a: Int, callback: (a: Int) -> Boolean) {
    if (callback(a)) {
        print("callback is true\n")
    } else {
        print("callback is false\n")
    }
}