package com.ryujin.algorithm

fun main() {
    var o = Object()
    var a = o;
    o = Object()
    print(a==o)
}