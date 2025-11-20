class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](auto& a, auto& b) {
            if(a[1]==b[1]) return a[0]>b[0];
            return a[1]<b[1];
        });

        vector<int> st;

        for(auto& interval : intervals) {
            auto start = interval[0], end = interval[1];

            auto lower = lower_bound(st.begin(), st.end(), start), 
                upper = upper_bound(st.begin(), st.end(), end);
            auto distance = upper-lower; 

            if(distance==0) {
                st.push_back(end-1);
                st.push_back(end);
            } else if(distance==1) {
                st.push_back(end);
            }
        }

        return st.size();
    }
};