class Solution {
public:
    int minimumLength(string s) {
        vector<int> vec(26, 0);
        int n = s.size();
        for (int i = 0; i < n; i++) {
            vec[s[i] - 'a']++;
        }
        int answer = 0;
        for (int i = 0; i < n; i++) {
            if (vec[s[i] - 'a'] > 2) {
                vec[s[i] - 'a'] -= 2;
            }
        }

        for (int i = 0; i < 26; i++) {
            answer += vec[i];
        }

        return answer;
    }
};