package DataStructure;

import java.util.*;

public class Main {
    public static void main(String[] args) {
        HashMap<Object, Object> objectObjectHashMap = new HashMap<>(1 << 31);
//        objectObjectHashMap.put("1","1");
//        objectObjectHashMap.put("2","1");
//        objectObjectHashMap.put("3","1");
//        objectObjectHashMap.put("4","1");
//        objectObjectHashMap.put("5","1");
//        objectObjectHashMap.put("6","1");
//        objectObjectHashMap.put("7","1");
//        objectObjectHashMap.put("8","1");
        Collections.synchronizedMap(objectObjectHashMap);
        BST<Integer> bst = new BST<>();
        bst.add(10);
        bst.add(6);
        bst.add(16);
        bst.add(12);
        bst.add(18);
//        int n = 1000;
//        Random random = new Random();
//        for (int i = 0; i < n; i++) {
//            bst.add(random.nextInt(10000));
//        }
//
//        ArrayList<Integer> nums = new ArrayList<>();
//
//        while (!bst.isEmpty()) {
//            nums.add(bst.removeMin());
//        }
//        System.out.println(nums);
//        for (int i = 1; i < nums.size(); i++) {
//            if (nums.get(i -1 ) > nums.get(i)){
//                throw new RuntimeException("BST REMOVE minimum ERROR!");
//            }
//        }
//        System.out.println("REMOVE MINIMUM COMPLETE!");
        System.out.println(bst.floor(13));
        System.out.println(bst.size());

    }
}
