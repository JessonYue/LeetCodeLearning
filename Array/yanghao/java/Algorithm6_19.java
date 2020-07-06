package jdbc.mvc.interfaces;

public class Algorithm6_19 {
	public String removeDuplicates(String S) {
	    StringBuilder res = new StringBuilder();
	    int size = 0;
	    for (int i = 0; i < S.length(); i++) {
	        if(size != 0 && res.charAt(size-1) == S.charAt(i))
	            res.deleteCharAt(--size);
	        else{
	            res.append(S.charAt(i));
	            size++;
	        }
	    }
	    return res.toString();
	}

}
