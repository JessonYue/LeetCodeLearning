char * toHex(int num){
   if (num == 0) return "0";
    char *ret;char nums[] ="0123456789abcdef";
    ret = (char *)(calloc(9,sizeof(char )));
    int i = 7, j = 8;
    do {
        int la= num & 0xf;
        ret[i--] = nums[la];
        num >>= 4;
        j--;
    } while (num != 0 && j > 0);
    return ret+i+1;


}