class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(),satisfaction.end());
        int ans=0;
        int res=0;
        int c=1;
        int sum=0,ind=-1;
        bool flag=true;
        for(int i=0;i<satisfaction.size();i++)
        {
            // cout<<satisfaction[i]<<" ";
            if(satisfaction[i]>=0)
            {
                ans+=(satisfaction[i]*(i-ind));
                sum+=satisfaction[i];
            }
            else
            {
                ind=i;
            }
        }
        cout<<ans<<"  ";
            if(ind==-1)return ans;
            res=ans;
            for(int i=ind;i>=0;i--)
            {
                ans+=sum;
                ans+=satisfaction[i];
                res=max(ans,res);
                // cout<<res<<"  ";
                sum=sum+satisfaction[i];
            }
        return res;
    }
};
