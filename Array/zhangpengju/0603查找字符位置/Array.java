    @Test
    public void test(){

        String a = "abcdddg";
        String b = "dd";
        int i = strStr(a, b);
        System.out.println(i+"");
    }


    /**
     *
     * 主要思路，拿出needle 第一个开始对比，发现相同的则继续，否则，继续寻找haystack 中相同首字母位置
     * 查找needle 出现的位置 首次出现的位置
     * @param hayStack
     * @param needle
     */
    public int strStr(String hayStack,String needle){

        if(hayStack == null || needle == null){
            return -1;
        }


        //取出第一个位置needle
        char firstNeedle = needle.charAt(0);

        int hayStackIndex = 0;
        do{

            char firstHay = hayStack.charAt(hayStackIndex);
            if(firstNeedle == firstHay){
                int i;
                for(i = 1;i<needle.length();i++){

                    char needleChar = needle.charAt(i);
                    char hayChar = hayStack.charAt(hayStackIndex+i);
                    if(needleChar != hayChar){
                        break;
                    }
                }

                if(i>=needle.length()){//全部匹配
                    return hayStackIndex;
                }
            }

            hayStackIndex++;

        }while (hayStackIndex < hayStack.length());

        return 0;

    }