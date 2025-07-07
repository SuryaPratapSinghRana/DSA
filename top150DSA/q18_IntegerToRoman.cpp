// Approach 1 one divide wali sidha digits mille gi oos place pe
// T.C O(1)
class Solution {
public:
    string intToRoman(int num) {
        string ones[] = {"","I","II","III","IV","V","VI","VII","VIII","IX"};
        string tens[] = {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
        string hrns[] = {"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
        string ths[]={"","M","MM","MMM"};
        
        return ths[num/1000] + hrns[(num%1000)/100] + tens[(num%100)/10] + ones[num%10];
    }
};

// Approach 2 subraction wali
// T.c 0(n)

class Solution {
public:
    string intToRoman(int num) {
      vector<string>str={"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"};
      vector<int>arr={1,4,5,9,10,40,50,90,100,400,500,900,1000};
      int n=arr.size();
      string ans="";
      for(int i=n-1;i>=0;i--)
      {
        while(arr[i]<=num)
        {
            ans.append(str[i]);
            num-=arr[i];
        }
      }
      return ans;
    }
};                    

