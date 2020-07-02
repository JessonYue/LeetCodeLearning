package staudy

class Algorithm6_18 {

    fun removeDuplicates(S:String):String{
        val res = StringBuffer()
        var size = 0;
        for (i in 1..S.length){
            if (size != 0 && res[size - 1] == S[i]){
                res.deleteCharAt(--size)
            }else{
                res.append(S[i])
                size++
            }
        }
        return res.toString()
    }
}