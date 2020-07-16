
public int firstUniqChar(String s) {
        HashMap<Character,Integer>  mapCount = new HashMap<>();
        
        //确定好每个元素个数
        for(int i = 0;i<s.length();i++){
            char c = s.charAt(i);
            Integer integer = mapCount.get(c);
            if(integer == null){
                mapCount.put(c,1);
            }else {
                integer++;
                mapCount.put(c,integer);
            }
        }
        
        //开始找唯一
       
        for(int i = 0;i<s.length();i++){
            Integer integer = mapCount.get(s.charAt(i));
            if(integer == 1){
                return i;
            }
        }
        
        return -1;


    }