class Solution {
public:
    int candy(vector<int>& ratings) {
        int n=ratings.size();
        vector<int>L2R(n,1),R2L(n,1);
        // left to right chalo
        for(int i=1;i<n;i++)
        {
            if(ratings[i]>ratings[i-1])
            {
                L2R[i]=L2R[i-1]+1;
            }
        }
        // Right to left chalo 
        for(int i=n-2;i>=0;i--)
        {
            if(ratings[i]>ratings[i+1])
            {
                R2L[i]=R2L[i+1]+1;
                // one array se bhi kar sakte agar yahi pe maximum lele niche dekho
                // arr[i]=max(arr[i],arr[i+1]+1)  L2R bhi htana padega hume waha bhi arr[] use karna

            }
        }
        // take max of L2R[i] and R2L[i] and add two sum or agar ek arr[] hota to uska sum answer hota
        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=max(L2R[i],R2L[i]);
        }
        return sum;
    }
};


// or in O(1) space

class Solution {
public:
    int candy(vector<int>& ratings) {
     int n=ratings.size();
     int Totalcandy=n; // each person gives one candy
     int i=1;
     while(i<n)
     {
        if(ratings[i]==ratings[i-1])
        {
            i++;
            continue;
        }
        // for increasing slope(peak)
        int peak=0;
        while(ratings[i]>ratings[i-1])
        {
           peak++;
           Totalcandy+=peak;
           i++;
           if(i==n)
             return Totalcandy;
        }
        // for decreasing slop
        int dip=0;
        while(i<n && ratings[i]<ratings[i-1])
        {
            dip++;
            Totalcandy+=dip;
            i++;
        }
        // subtract extra dip or peak  which is min
        Totalcandy-=min(peak,dip);
     }
     return Totalcandy;
    }
};