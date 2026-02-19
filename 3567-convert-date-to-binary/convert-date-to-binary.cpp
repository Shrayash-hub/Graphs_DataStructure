class Solution {
public:
    string convertDateToBinary(string date) {
        auto bin = [](int x) {
            string s = bitset<16>(x).to_string();
            return s.substr(s.find('1'));
        };
        return bin(stoi(date.substr(0,4))) + "-" +
               bin(stoi(date.substr(5,2))) + "-" +
               bin(stoi(date.substr(8,2)));
    }
};