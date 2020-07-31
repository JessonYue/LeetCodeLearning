import java.util.LinkedHashMap;
import java.util.Map;

public class Solution_146<K, V> extends LinkedHashMap<Integer, Integer> {
    private int capacity;

    public Solution_146(int capacity) {
        super(capacity, 0.75f, true);
        this.capacity = capacity;
    }

    public int get(int key) {
        return getOrDefault(key, -1);
    }

    public void put(int key, int value) {
        super.put(key, value);
    }

    @Override
    protected boolean removeEldestEntry(Map.Entry<Integer, Integer> eldest) {
        return size() > capacity;
    }

    public static void main(String[] args) {
        Solution_146<Integer, Integer> linked = new Solution_146<>(3);
        linked.put(5, 5);
        linked.put(1, 1);
        linked.put(2, 2);
        System.out.println("key2----->" + linked.get(2));
        linked.put(3, 3);
        System.out.println("key3----->" + linked.get(3));
        System.out.println("key2----->" + linked.get(2));
        System.out.println("key1----->" + linked.get(1));
        System.out.println("key5----->" + linked.get(5));
    }
}
