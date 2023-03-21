class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans=0,c=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]!=0)
            {
                ans+=(c*(c+1))/2; // we can get number of subarray by this formula
                c=0;
            }
            else c++;
        }
        ans+=(c*(c+1))/2; //this is for last subarray 
        return ans;
    }
};
