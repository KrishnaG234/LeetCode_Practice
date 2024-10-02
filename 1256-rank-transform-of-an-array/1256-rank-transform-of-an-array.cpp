class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        map<int, vector<int>> rankArr;

        for (int i = 0; i < arr.size(); i++) {
            rankArr[arr[i]].push_back(i);
        }

        int rank = 1;
        for (auto& pair : rankArr) {
            for (int i : pair.second) {
                arr[i] = rank;
            }
            rank++;
        }
        
        return arr;
    }
};