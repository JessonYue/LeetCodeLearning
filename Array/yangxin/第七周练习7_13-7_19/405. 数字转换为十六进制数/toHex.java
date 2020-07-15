 /**
 * 405. 数字转换为十六进制数
 * 给定一个整数，编写一个算法将这个数转换为十六进制数。对于负整数，我们通常使用 补码运算 方法。
 */
public String toHex(int num) {
	char map[] = "0123456789abcdef".toCharArray();
	StringBuilder sb = new StringBuilder();
	int tmp;
	while (num != 0) {
		tmp = num & 0xf;
		sb.append(map[tmp]);
		num >>>= 4;
	}

	if (sb.length() == 0) {
		sb.append('0');
	}
	return sb.reverse().toString();
}