class Node {
public:
    unordered_map<char, Node*> children;
    bool endOfWord;

    Node() {
        endOfWord = false;
    }
};

class WordDictionary {
    Node* root;
public:
    WordDictionary() {
        root = new Node();
    }
    
    void addWord(string word) {
        Node* curr = root;
        for(char ch: word) {
            if(curr->children.count(ch) == 0) {
                curr->children[ch] = new Node();
            }
            curr = curr->children[ch];
        }
        curr->endOfWord = true;
    }
    
    bool search(string word) {
        return searchHelper(word, 0, root);
    }
private:
    bool searchHelper(const string& word, int index, Node* node) {
        if(index == word.size()) {
            return node->endOfWord;
        }

        char ch = word[index];
        if(ch == '.') {
            for(auto& [key, child]: node->children) {
                if(searchHelper(word, index+1, child))
                    return true;
            }
            return false;
        }else {
            if(node->children.count(ch) == 0) 
                return false;
            return searchHelper(word, index+1, node->children[ch]);
        }
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */