package algorithms4.chapter_1;

public class FixedCapacityStackOfStrings {
    private String[] arrays;
    private int N;

    public FixedCapacityStackOfStrings(int cap) {
        arrays = new String[cap];
    }

    void push(String item) {
        arrays[N++] = item;
    }

    String pop() {
        if (!isEmpty()) {
            throw new UnsupportedOperationException("is Empty!");
        }
        return arrays[--N];
    }

    boolean isEmpty() {
        return N == 0;
    }

    int size() {
        return N;
    }
}
