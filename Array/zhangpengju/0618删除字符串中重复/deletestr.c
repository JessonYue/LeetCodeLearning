
//参考力扣写的，双指针
char * removeDuplicates(char * S){
    int i=1,stackIndex=0;
    while(S[i]){
        if(S[i++]==S[stackIndex]){
            if(stackIndex) stackIndex--;
            else S[stackIndex]=0;        
        }
        else{
            if(S[stackIndex]) stackIndex++;
            S[stackIndex]=S[i-1];
        }
    }
    S[stackIndex+1]=0;
    return S;
}
