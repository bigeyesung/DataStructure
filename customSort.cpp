class Solution {
//corner case:
//empty array
//two or more strings have same frequency

//sudo code
//traverse the arr, and count string frequency (save it in a list)
//sort freq in decreasing order
//get the kmost freq string (freq-> string)
struct Newtype{
    string name;
    int fre;
};

struct myclass {
  bool operator() ( Newtype a, Newtype b) {
    if (a.fre > b.fre)
        return true;

    else if (a.fre == b.fre) {
        return a.name.compare(b.name) < 0;
    }

    else return false;
  } 
} myobject;    
    
   
    
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string,int>table;
        vector<Newtype>vec;
        vector<string>ans;
        for (int i=0;i<words.size();i++){
            if (table.find(words[i]) == table.end())
                table[words[i]] = 1;
            else
                table[words[i]] += 1;
        }
                
        //sort the newtype in decresing order
        for(auto t:table){
            
            Newtype tmp;
            tmp.name = t.first;//key
            tmp.fre = t.second;//value
            vec.push_back(tmp);
        }
        sort(vec.begin(),vec.end(),myobject);
        for(int i=0;i<k;i++){
            string str = vec[i].name;
            ans.push_back(str);
        }        
    return ans;    
    }
};