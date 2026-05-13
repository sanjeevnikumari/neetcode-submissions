class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

        unordered_set<string> st(wordList.begin(), wordList.end());

        if(st.find(endWord) == st.end())
            return 0;

        queue<pair<string,int>> q;
        q.push({beginWord, 1});

        unordered_set<string> vis;
        vis.insert(beginWord);

        while(!q.empty()) {

            auto [word, steps] = q.front();
            q.pop();

            if(word == endWord)
                return steps;

            for(int i = 0; i < word.size(); i++) {

                char original = word[i];

                for(char ch = 'a'; ch <= 'z'; ch++) {

                    word[i] = ch;

                    if(st.count(word) && !vis.count(word)) {
                        vis.insert(word);
                        q.push({word, steps + 1});
                    }
                }

                word[i] = original;
            }
        }

        return 0;
    }
};