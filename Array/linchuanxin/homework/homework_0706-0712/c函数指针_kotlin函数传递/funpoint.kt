package day39_0709


fun max(a:Int, b:Int):Int{
    var j:Int
    if(a > b)
        j = a
    else
        j = b;
    return j;
}


fun chooseMax(arg1: Int, arg3: (arg4: Int) -> Int):Int{
    return arg3.invoke(arg1)
}


fun fromArg(arg:String){
    print(arg+"\n")
}

fun operateArgMethod(arg1:String,arg2:(arg:String)->Unit){
  arg2.invoke(arg1)
}

fun sayHello() {
    print("say hello from sayHello Method\n")
}


fun operateMethod(say:()->Unit){
    say()
}

fun main() {

    operateMethod { sayHello() }
    val h = sayHello()
    operateMethod { h }

    operateArgMethod("niu bi", {it-> fromArg("ni")})

    print(chooseMax(1, {it-> max(110,16)}))

}