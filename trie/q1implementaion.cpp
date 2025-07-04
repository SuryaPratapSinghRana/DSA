struct Node {
    Node* links[26]; 
    bool flag = false;

    Node() {
        for (int i = 0; i < 26; i++) links[i] = NULL;
    }

    bool containkey(char ch) {
        return (links[ch - 'a'] != NULL);
    }

    void put(char ch, Node* node) {
        links[ch - 'a'] = node;
    }

    Node* get(char ch) {
        return links[ch - 'a'];
    }

    void setend() {
        flag = true;
    }

    bool isend() {
        return flag;
    }
};

class Trie {
private:
    Node* root;

public:
    Trie() {
        root = new Node();
    }

    void insert(string word) {
        Node* node = root;
        for (int i = 0; i < word.size(); i++) {
            if (!node->containkey(word[i])) {
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
        }
        node->setend();
    }

    bool search(string word) {
        Node* node = root;
        for (int i = 0; i < word.length(); i++) {
            if (!node->containkey(word[i])) {  
                return false;
            }
            node = node->get(word[i]);
        }
        return node->isend();
    }

    bool startsWith(string prefix) {
        Node* node = root;
        for (int i = 0; i < prefix.length(); i++) {
            if (!node->containkey(prefix[i])) {  // ❌ you had missing `!`
                return false;
            }
            node = node->get(prefix[i]); // ❌ you used `word[i]` which is undefined
        }
        return true;
    }
};
