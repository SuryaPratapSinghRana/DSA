struct Item{
    int value;
    int weight;
};

class Solution {
  public:
    // Function to get the maximum total value in the knapsack.
    
    static bool cmp(pair<double,Item> a,pair<double,Item> b){
        return a.first>b.first;
    }
    double fractionalKnapsack(int w, Item arr[], int n) {
        // Your code here
        vector<pair<double,Item>> v;
        for(int i=0;i<n;i++)
        {
            double vbyw=arr[i].value*1.0/arr[i].weight;
            pair<double,Item> p=make_pair(vbyw,arr[i]);
            v.push_back(p);
        }
        sort(v.begin(),v.end(),cmp);
        double profit=0;
        for(int i=0;i<n;i++)
        {
            if(v[i].second.weight<w){
                profit=profit+v[i].second.value;
                w=w-v[i].second.weight;
            }
            else
            {
               profit=profit+v[i].first*w;
               w=0;
            }
        }
        return profit;
    }
};