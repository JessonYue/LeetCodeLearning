char * removeDuplicates(char * S){
    int write = 0;
    int read = 0;
    char top, ch;
    while(ch = S[read++]){
        if(0 == write){
            top = 0;
        }else{
            top = S[write-1];

        }
        if(ch == top){
            write--;
        }else{
            S[write] = ch;
            write++;
        }
    }
    S[write] = 0;
    return S;
}