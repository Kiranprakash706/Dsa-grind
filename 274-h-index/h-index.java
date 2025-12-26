class Solution {
    public int hIndex(int[] citations) {
        if(citations.length == 1) return citations[0] > 0 ? 1 : 0;
        int max = Integer.MIN_VALUE;
        for(int cit : citations) max = Math.max(max,cit);
        int[] hVals = new int[max+1];

        for(int cit : citations){
            hVals[cit]++;
        }

        if(hVals[hVals.length - 1] >= hVals.length - 1) return hVals.length - 1;
        for(int i = hVals.length - 2; i >= 0 ; i--){
            hVals[i] += hVals[i+1];
            if(hVals[i] >= i) return i;
        }

        return 0;
    }
}
