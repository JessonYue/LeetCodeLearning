
  public String toHex(int num){//十六进制转化

        Stack<String>  sta = new Stack<>();

        String[] map = {"0","1","2","3","4","5","6","7","8","9","a","b","c","d","e","f"};
        String hex = "";

        int value = num;

        while(value > 0){
            int i = value / 16;
            sta.push(map[value % 16]);
            value = i;
        }

        while(!sta.empty()){
            hex += sta.pop();
        }


        return hex;
    }

   //采用位移
    public String moveIndex(int num){

        String[] map = {"0","1","2","3","4","5","6","7","8","9","a","b","c","d","e","f"};
        StringBuffer buffer = new StringBuffer();

        //通过位移

        while(num > 0){
            int i = num & 15;
            buffer.append(map[i]);
            num = num >>> 4;
        }




        return buffer.reverse().toString();
    }