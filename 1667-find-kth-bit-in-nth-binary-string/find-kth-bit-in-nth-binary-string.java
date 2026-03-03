class Solution {

    public char findKthBit(int n, int k) {
		if(n==1) return '0';
		int mid = 1<<(n-1);  //2^(n-1)
		if(k==mid) return '1';

		if(k<mid){
			//exact kth bit S(n-1);
			return findKthBit(n-1, k);
		} else {
			//kth of ~reversed(S(n-1))
            int mirroredBit = (1<<n) - k; //2^n - k
            char ch = findKthBit(n-1, mirroredBit);
			return ch == '0' ? '1' : '0'; 
		}
    }
}