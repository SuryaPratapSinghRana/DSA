// by linear traversal jab equal hojaye gi citaion[index] and n-index mtlb utne hi element exact usse upar h to wahi answer ajayega
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int index=0;
        int n=citations.size();
        while(index<n && n-index>citations[index])
        {
            index++;
        }
        return n-index;
    }
};

// by binary search

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n=citations.size();
        int l=0,r=n-1;
        while(l<=r)
        {
            int mid=l+(r-l)/2;
            if(citations[mid]==n-mid)
            {
                return n-mid;
            }
            else if(citations[mid]>n-mid)
            {
               r=mid-1;
            }
            else
            {
                l=mid+1;
            }
        }
        return n-l;  // ye isliye kyunki agar citation[mid]>n-mid h to mtlb right update karenge aur agar hume right mein nahi mila h-index to wo left wala hi tha
                    // example: 1 1 2 3 3 and 1 3 5 5 5 5
    }
};