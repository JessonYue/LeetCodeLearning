package bit_operation

class BItOperation {
    fun hasAlternatingBits(n: Int): Boolean {
        var N = n
        N = N.xor(N.ushr(1))
        return N.and(N + 1) == 0
    }
}