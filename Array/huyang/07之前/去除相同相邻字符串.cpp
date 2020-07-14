class Solution {
public:
    string removeDuplicates(string S) {
        if( S.length() <= 1 ){
            return S;
        }
        int j = 1;
        while(j<S.length() ){

            if(j==0 || S[j-1] != S[j]){
                j++;
            }else if(S[j-1] == S[j]){
               S.erase(j-1,2);
               j--;
            }


            if(S.length() <= 1 ){
                return S;
            }
        }

        return S;
    }
};