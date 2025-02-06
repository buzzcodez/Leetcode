class Solution {
    private:
        //first compare by descending then compare alphabetically
        static bool compare(pair<int,char>p1 ,pair<int,char>p2){
            if(p1.first > p2.first) return true;
            if(p2.first > p1.first)   return false;
            return p1.second<p2.second;
        }

public:
    string frequencySort(string &s) {
        pair<int,char>freq[256];
        for(int i=0 ; i<256 ;i++){
            freq[i]={0,i};
        }
        for(char ch : s){
            freq[ch].first++;
        }
        sort(freq,freq+256,compare);
        
        string ans = "";
        for(int i=0 ; i<256 ; i++){
            if(freq[i].first>0){
                for(int j = 0; j < freq[i].first; j++)
                    ans.push_back(freq[i].second);
            }
        }
        return ans; 
    }
};