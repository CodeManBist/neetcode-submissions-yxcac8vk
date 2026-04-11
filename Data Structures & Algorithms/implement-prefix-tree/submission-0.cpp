class PrefixTree {
public:
    unordered_map<char, PrefixTree*> children;
    bool endOfWord;

    PrefixTree() {
        endOfWord = false;    
    }
    
    void insert(string word) {
        PrefixTree* temp = this;
        for(char ch: word) {
            if(temp->children.count(ch) == 0) {
                temp->children[ch] = new PrefixTree;
            }
            temp = temp->children[ch];
        }
        temp->endOfWord = true;
    }
    
    bool search(string word) {
        PrefixTree* temp = this;
        for(char ch: word) {
            if(temp->children.count(ch) == 0) {
                return false;
            }
            temp = temp->children[ch];
        }
        return temp->endOfWord;
    }
    
    bool startsWith(string prefix) {
        PrefixTree* temp = this;
        for(char ch: prefix) {
            if(temp->children.count(ch) == 0) {
                return false;
            }
            temp = temp->children[ch];
        }
        return true;
    }
};
