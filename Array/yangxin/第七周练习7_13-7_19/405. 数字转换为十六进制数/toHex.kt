/**
 * 405. 数字转换为十六进制数
 * 给定一个整数，编写一个算法将这个数转换为十六进制数。对于负整数，我们通常使用 补码运算 方法。
 */
fun toHex(num: Int): String {
	var numTmp = num
	val map = "0123456789abcdef".toCharArray()
	var tmp: Int
	val sb = StringBuilder()
	while (numTmp != 0) {
		tmp = numTmp and 0xf
		sb.append(map[tmp])
		numTmp = numTmp ushr 4
	}

	if (sb.isEmpty()) {
		sb.append('0')
	}

	return sb.reverse().toString()
}