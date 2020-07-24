bool backspaceCompare(char * S, char * T){
int l1=moveSpace(S,strlen(S));
int l2=moveSpace(T,strlen(T));
if(l1!=l2){
    return false;
}
for(int i=0;i<l1;i++){
    if(S[i]!=T[i]){
        return false;
    }
}
return true;
}
int moveSpace(char* str,int leng){
    int j=0;
    for(int i=0;i<leng;i++){
        if(!(str[i]=='#')){
            str[j++]=str[i];
        } else
        {
            // str[i] == '#'
            if(j>0)
            {
                j--;
            }
        }

    }
    return j;
}