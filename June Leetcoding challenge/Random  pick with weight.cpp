class Solution {

    private double calls;
    private int[] count;
    private double totalWeight;
    private Random rand;
    private int[] w;
    
    public Solution(int[] w) {
        count = new int[w.length];
        calls = 0;
        rand = new Random();
        this.w = w;
        for (int i : w) totalWeight += (double)i;
    }
    
    public int pickIndex() {
        calls++;
        int next = rand.nextInt(w.length);
        
        while (count[next] / calls > w[next] / totalWeight) {
            next = rand.nextInt(w.length);
        }
        
        count[next]++;
        return next;
    }
}

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(w);
 * int param_1 = obj.pickIndex();
 */
