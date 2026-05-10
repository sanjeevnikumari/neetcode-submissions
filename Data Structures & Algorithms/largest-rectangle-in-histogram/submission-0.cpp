class Solution {
public:
    // Next Smaller Element to Left (using stack)
    vector<int> nextSmallerLeft(vector<int>& heights) {
        int n = heights.size();
        vector<int> nsl(n);
        stack<int> st;  // stores indices

        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            nsl[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return nsl;
    }

    // Next Smaller Element to Right (using stack)
    vector<int> nextSmallerRight(vector<int>& heights) {
        int n = heights.size();
        vector<int> nsr(n);
        stack<int> st;  // stores indices

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            nsr[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return nsr;
    }

    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> nsl = nextSmallerLeft(heights);
        vector<int> nsr = nextSmallerRight(heights);

        int maxArea = 0;
        for (int i = 0; i < n; i++) {
            int width = nsr[i] - nsl[i] - 1;
            int area = heights[i] * width;
            maxArea = max(maxArea, area);
        }
        return maxArea;
    }
};