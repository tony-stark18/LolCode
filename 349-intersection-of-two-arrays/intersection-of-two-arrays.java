class Solution {
    public int[] intersection(int[] nums1, int[] nums2) {
        Arrays.sort(nums1);
        Arrays.sort(nums2);
        int n1 = nums1.length;
        int n2 = nums2.length;
        List<Integer> ls = new ArrayList<>();
        int i = 0;
        int j = 0;
        while (i < n1 && j < n2) {
            if (nums1[i] == nums2[j]) {
                if (ls.isEmpty() || nums1[i] != ls.get(ls.size() - 1)) {
                    ls.add(nums1[i]);
                }
                i++;
                j++;
            } else if (nums1[i] > nums2[j]) {
                j++;
            } else {
                i++;
            }
        }
        int[] arr = new int[ls.size()];
        for (i = 0; i < ls.size(); i++) {
            arr[i] = ls.get(i);
        }
        return arr;
    }
}
