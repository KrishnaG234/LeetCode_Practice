class Solution {
    vector<string> numbers = {"999", "888", "777", "666", "555",
                              "444", "333", "222", "111", "000"};

    bool contains(string number, string num) {
        for (int i = 0; i <= num.size() - 3; i++) {
            if (num[i] == number[0] && num[i + 1] == number[1] &&
                num[i + 2] == number[2]) {
                return true;
            }
        }
        return false;
    }

public:
    string largestGoodInteger(string num) {
        for (auto& number : numbers) {
            if (contains(number, num)) {
                return number;
            }
        }
        return "";
    }
};