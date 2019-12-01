class Solution {
//find possiple string length(1 to N)
//for each length find possible solution
//for each length find palindromic string
public:
    
    bool isPalin(string a){
        
        bool isPalin = true;
        for (int i=0;i<a.size();i++){
            int j = a.size()-1-i;
            if (a[i] != a[j]){
                isPalin = false;
                break;
            }
            
        }
        return isPalin;
    }
    
    string longestPalindrome(string s) {
        bool istrue = false;
        string ans = "";
        bool break_inner = false;
        // differnt string length
        for (int i=s.size();i>=1;i--) //i=3
        {
            int length = i;//length = 3
            if (break_inner)
                break;
            //for each length find whole solutions
            for (int j=0;j<s.size();j++){//j=0
                string tmp = "";
                // check range
                if (j+length -1 <= s.size()-1){ //0+2 <=4
                  
                    string tmp = s.substr(j,length);
                    istrue = isPalin(tmp);//tmp=bab
                    if (istrue){//false
                        ans = tmp;
                        break_inner = true;
                        break;
                    }
                 }
                 else
                    break;
            }    
        }
    return ans;
    }
};