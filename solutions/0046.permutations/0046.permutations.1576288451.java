class Solution {
    public List<List<Integer>> permute(int[] nums) {
        List<List<Integer>> res = new ArrayList<>();
        List<Integer> current = new ArrayList<Integer>();
        for (int n : nums) {
            current.add(n);
        }
        backtrack(current, 0, res);
        return res;
    }
    
    void backtrack(List<Integer> current, int k, List<List<Integer>> res) {
        if (k == current.size()) {
            res.add(new ArrayList<Integer>(current));
        }
        for (int i = k; i < current.size(); i++) {
            Collections.swap(current, k, i);
            backtrack(current, k+1, res);
            Collections.swap(current, k, i);
        }
    }
    
    void swap(List<Integer> current, int i, int j) {
        int temp = current.get(i);
        current.set(i, current.get(j));
        current.set(j, temp);
    }
}
