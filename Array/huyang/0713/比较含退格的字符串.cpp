比较含退格的字符串
给定 S 和 T 两个字符串，当它们分别被输入到空白的文本编辑器后，判断二者是否相等，并返回结果。 # 代表退格字符。

注意：如果对空文本输入退格字符，文本继续为空。

//思路：从头开始遍历，如果不是#就拼到string,是#就去掉最后一个字符，生成结果比较

class Solution {
public:
    string getString(string S){
        //储存结果
        string l;
        //参数的长度
        int len = S.length();
        //记录字母的个数
        int count = 0;
        //遍历参数
        for(int i = 0; i < len; i++){
            //把参数中的字母都放到储存结果中
            if(S[i] != '#'){
                l += S[i];
                //记录字母个数
                count ++;
            }
            else{
                //判断有没有足够的字母去消除
                if(count != 0){
                    l.erase(l.end()-1);
                    count--;
                }
            }
        }
        return l;
    }
    bool backspaceCompare(string S, string T) {
        return getString(S) == getString(T);
    }
};

