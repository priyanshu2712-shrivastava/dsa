class Solution {
public:
    bool rotateString(string s, string goal) {
    if (s.length() != goal.length()) return false;
    string double1= s + s;
    return double1.find(goal) != string::npos;
}

};