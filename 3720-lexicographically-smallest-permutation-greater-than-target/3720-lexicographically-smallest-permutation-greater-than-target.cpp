class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        vector<int> cnt(26,0);
        bool greaterfound = false;
        for(char ch: s){
            cnt[ch-'a']++;
        }
        int n = target.size();
        string ans;
        for(int i=0;i<n; i++){
            for(int j=target[i]-'a'; j<26; j++){
                if(cnt[j]>0){
                    cnt[j]--;
                    ans.push_back('a'+j);
                    if(isPossible(ans,target, cnt)){
                        if(j>(target[i]-'a')){
                             greaterfound = true;
                            cout<<greaterfound<<endl;
                        }
                        break;
                    }
                    else{
                        cnt[j]++;
                        ans.pop_back();
                    } 
                }
            }
            if(greaterfound) break;
        }
        if(greaterfound)
        for(int i=0; i<26; i++){
            while(cnt[i]>0){
                ans.push_back('a'+i);
                cnt[i]--;
            }
        }
        return ans;

    }
    bool isPossible(string ans,string &target, vector<int> cnt){
        for(int i=25; i>=0; i--){
            while(cnt[i]>0){
                ans.push_back('a'+i);
                cnt[i]--;
            }
        }
        return ans>target;
    }
};