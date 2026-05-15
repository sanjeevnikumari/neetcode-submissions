class PrefixTree {
public:
    struct trieNode {
        trieNode* children[26];
        bool isEndOfWord;
    };
    
    trieNode* getNode() {
        trieNode* newNode = new trieNode();
        newNode->isEndOfWord = false;
        for(int i = 0; i < 26; i++) {
            newNode->children[i] = NULL;
        }
        return newNode;
    }
    
    trieNode* root;
    PrefixTree() {
        root = getNode();
    }
    
    void insert(string word) {
        trieNode* crawler = root;
        for(int i = 0; i < word.length(); i++) {
            int index = word[i] - 'a';
            if(!crawler->children[index]) {
                crawler->children[index] = getNode();
            }
            crawler = crawler->children[index];
        }
        crawler->isEndOfWord = true;
    }
    

    bool search(string word) {
        trieNode* crawler = root;
        for(int i = 0; i < word.length(); i++) {
            int index = word[i] - 'a';
            if(!crawler->children[index]) {
                return false;
            }
            crawler = crawler->children[index];
        }
        return (crawler != NULL && crawler->isEndOfWord);
    }

    
    
    bool startsWith(string prefix) {
        trieNode* crawler = root;
        for(int i = 0; i < prefix.length(); i++) {
            int index = prefix[i] - 'a';
            if(!crawler->children[index]) {
                return false;
            }
            crawler = crawler->children[index];
        }
        return true;
    }
};