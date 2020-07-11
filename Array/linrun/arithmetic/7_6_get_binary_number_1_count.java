/**
 * date:2020/7/7
 * description:
 * author:rlin
 */
class M7_7_GetBinaryNumber1Count {
    /**
     * 计算一个二进制数中有几个位是1
     */
    private int number_1_count(int target) {
        int count = 0;
        while (target != 0) {
            if ((target & 0x01) == 1) {
                count++;
            }
            target = target >>> 1;
        }
        return count;
    }
}
