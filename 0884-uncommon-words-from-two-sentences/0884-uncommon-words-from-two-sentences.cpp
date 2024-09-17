class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        string s = s1 + " " + s2;
        stringstream str(s);

        cout << s1.max_size();

        unordered_map<string, int> mpp;
        string temp;
        while (str >> temp) {
            mpp[temp]++;
        }

        vector<string> ans;
        for (auto& val : mpp) {
            if (val.second == 1) {
                ans.push_back(val.first);
            }
        }

        return ans;
    }
};