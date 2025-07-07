
Given two strings ransomNote and magazine, return true if ransomNote can be constructed by using the letters from magazine and false otherwise.
Each letter in magazine can only be used once in ransomNote.

 

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> magaHash;

        for (char c : magazine) {
            magaHash[c]++;
        }

        for (char c : ransomNote) {
            if (magaHash[c] <= 0) {
                return false;
            }
            magaHash[c]--;
        }

        return true;
    }
};