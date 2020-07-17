public class day47 {

    public static boolean backspaceCompare(String s, String t) {
        char a[] = s.toCharArray();
        char b[] = t.toCharArray();
        StringBuffer asb = new StringBuffer();
        StringBuffer bsb = new StringBuffer();
        for (int i = 0; i < a.length; i++) {
            if (i + 1 < a.length&&a[i + 1] == '#') {
                continue;
            } else if (a[i] == '#' && i < a.length) {
                continue;
            } else {
                asb.append(a[i]);
            }

        }
        for (int j = 0; j < b.length; j++) {
            if (j + 1 < b.length&&b[j + 1] == '#' ) {
                continue;
            } else if (b[j] == '#' ) {
                continue;
            } else {
                bsb.append(b[j]);
            }
        }

        return asb.toString().equals(bsb.toString());
    }

    public static void main(String[] args) {
        System.out.println(backspaceCompare("ab#c", "ad#c"));
    }

}
