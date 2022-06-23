class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int> umap;
        umap['I'] = 1;
        umap['V'] = 5;
        umap['X'] = 10;
        umap['L'] = 50;
        umap['C'] = 100;
        umap['D'] = 500;
        umap['M'] = 1000;
        
        int ans = 0;
        for(int i=0;i<s.length();i++){
            if(i+1<s.length() && (umap[s[i]] < umap[s[i+1]])){
                ans -= umap[s[i]];
            } else{
                ans += umap[s[i]];
            }
        }
        return ans;
    }
};