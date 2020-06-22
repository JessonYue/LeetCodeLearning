/**
 *给出由小写字母组成的字符串 S，重复项删除操作会选择两个相邻且相同的字母，并删除它们。
 *
 * 在 S 上反复执行重复项删除操作，直到无法继续删除。
 *
 * 在完成所有重复项删除操作后返回最终的字符串。答案保证唯一。
 *
 * 来源：力扣（LeetCode）
 * 链接：https://leetcode-cn.com/problems/remove-all-adjacent-duplicates-in-string
 * 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
 char * removeDuplicates(char * S){
     int readIndex = 0;
     int writeIndex = -1;
     char ch;
     while(ch = S[readIndex++]){
         if(writeIndex <0){
             writeIndex = 0;
             S[0] = ch;
         }else{
             if(ch == S[writeIndex]){
                 writeIndex --;
             }else{
                 S[++writeIndex] = ch;
             }
         }
     }
     S[++writeIndex] = 0;
     return S;
 }
