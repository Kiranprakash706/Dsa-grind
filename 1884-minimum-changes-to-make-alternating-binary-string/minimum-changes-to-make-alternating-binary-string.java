class Solution {
    public int minOperations(String s) {
        StringBuilder startsWithOne  = new StringBuilder();
        StringBuilder startsWithZero = new StringBuilder(); 

        for(int i=0;i<s.length();i++){
            if(i%2==0){
                startsWithOne.append('1');
                startsWithZero.append('0');
            }
            else{
                startsWithOne.append('0');
                startsWithZero.append('1');
            }
        }

        String one = startsWithOne.toString();
        String zero = startsWithZero.toString();
        int z = 0;
        int o = 0;

        for(int i=0;i<s.length();i++){
            if(s.charAt(i)!=one.charAt(i)) o++;
            if(s.charAt(i)!=zero.charAt(i))z++;
        }
        return o>z?z:o;
    }
}