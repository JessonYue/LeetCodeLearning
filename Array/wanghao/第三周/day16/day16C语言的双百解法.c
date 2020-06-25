bool isValid(char * s){
    if(*s == 0) return true;    
    int len = strlen(s);
    if(len & 1) return false;   
    len >> 1;                 
    char stack[len];
    int top = -1;
    for(int i=0; i<len; ++i){
        if(s[i] == '(' || s[i] == '[' || s[i] == '{')
            stack[++top] = s[i];
        else if(top == -1)
            return false;       
        else if(s[i] == stack[top]+1 || s[i] == stack[top]+2)
            stack[top--] = 0;  
        else
            return false;      
    }
    return top == -1;          
}