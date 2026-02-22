class Solution {
public:

    //brute force approach
    //time complexity: O(logn)
    //space complexity: O(logn)

    //function to convert integer number to 'binary number'
    string toBinary(int num)
    {
        //to store 'binary' form of given integer(in reversed form)
        string str="";
        while(num)
        {
            //holding last bit in 'rem'
            int rem=num%2;
            //inserting it into 'str'
            str.push_back(rem+'0');
            //updating 'num'
            num=num/2;
        }
        //reversing the string representation(str) of 'binary' given number
        reverse(str.begin(),str.end());
        //returning binary repsentation of given integer(num)
        return str;
    }

    //given function
    int binaryGap(int n)
    {
        int ans = 0;
        //converting given number to 'binary string'
        string binaryNum = toBinary(n);

        //to store index of previous '1'
        int prevOcc=-1;
        for(int i=0;i<binaryNum.size();i++)
        {
            //checking if current bit is '1'
            if(binaryNum[i] == '1')
            {
                //if this is not 'first' 1, updating the gap
                if(prevOcc != -1)
                    ans=max(ans,i-prevOcc);

                //updating last seen of '1' index
                prevOcc=i;
            }
        }
        //returning maximum distance
        return ans;
    }
};