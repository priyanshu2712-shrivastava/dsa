class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        int i = 0;

        while (i < path.size()) {

            // Skip '/'
            if (path[i] == '/') {
                i++;
                continue;
            }

            // Extract one component
            string component = "";

            while (i < path.size() && path[i] != '/') {
                component += path[i];
                i++;
            }

            // Current directory
            if (component == ".") {
                continue;
            }

            // Parent directory
            else if (component == "..") {
                if (!st.empty()) {
                    st.pop();
                }
            }

            // Normal directory
            else {
                st.push(component);
            }
        }

        // Construct answer
        vector<string> temp;

        while (!st.empty()) {
            temp.push_back(st.top());
            st.pop();
        }

        reverse(temp.begin(), temp.end());

        string ans = "";

        for (auto& dir : temp) {
            ans += "/" + dir;
        }

        // Root
        if (ans.empty()) {
            return "/";
        }

        return ans;
    }
};