class Solution {
public:
   int maxDepth(string s) {
    int size = 0;      
    int currentDepth = 0; 

    for (char c : s) {
        if (c == '(') {
            currentDepth++;
            size = max(size, currentDepth); 
        } else if (c == ')') {
            if (currentDepth > 0) {
                currentDepth--; 
            }
        }
    }

    return size;
}
};