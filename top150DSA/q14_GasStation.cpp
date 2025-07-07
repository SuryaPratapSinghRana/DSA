class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
        int fuel=0,totaldiff=0,index=0;
        for(int i=0;i<n;i++)
        {
            int diff=gas[i]-cost[i];
            totaldiff+=diff;  // ye chahe to alag se for loop lga ke karglo total gas -total cost agar negative h phir hum niche return krdenge -1 ya jaise yaha humne kiya E gas[i]- E cost[i] 
            fuel+=diff;
            if(fuel<0)
            {
               index=i+1;
               fuel=0;
            }
        }

        if(totaldiff<0)
        {
            return -1;

        }
        else
        {
            return index;  // matlab anwer exist kar raha h agar totaldiff >=0 hai to answer hmara wahi h jaha se hume negative value nahi milli
        }
    }
};