class Solution {
    public boolean backspaceCompare(String S, String T) {
        if ((S == null || S.length() == 0) && (T != null || T.length() != 0)) {
            return false;
        }
        if ((T == null || T.length() == 0) && (S != null || S.length() != 0)) {
            return false;
        }

        char s_array[] = S.toCharArray();
        char t_array[] = T.toCharArray();
        char s1[] = new char[S.length()];
        char t1[] = new char[T.length()];
        int s1_index = 0;
        int t1_index = 0;
        for (char c : s_array) {
            if (c == '#') {
                if (s1_index > 0) {
                    s1_index--;
                }
            } else {
                s1[s1_index++] = c;
            }
        }

        for (char c : t_array) {
            if (c == '#') {
                if (t1_index > 0) {
                    t1_index--;
                }
            } else {
                t1[t1_index++] = c;
            }
        }

        if (s1_index == t1_index) {
            while (s1_index > 0) {
                s1_index--;
                if (t1[s1_index] != s1[s1_index]) {
                    return false;
                }
            }
            return true;
        }
        return false;
    }
}