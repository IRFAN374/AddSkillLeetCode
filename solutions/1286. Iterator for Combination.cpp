class CombinationIterator {
public:
    vector<string> ans;
    int index = 0;
     string out="";
    int len;
    CombinationIterator(string characters, int combinationLength) {
       len=combinationLength;
       helper(characters,0);
    }
    
    string next() {
        return ans[index++];
    }
    
    bool hasNext() {
        return index < ans.size() ? true : false;
    }
    
    void helper(string str,int start){
        if(out.size()==len){
            ans.push_back(out);
            return ;
        }
        for(int i=start;i<str.size();i++){
            out.push_back(str[i]);
            helper(str,i+1);
            out.pop_back();
        }
    }
};
​
/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
