class Solution {
public:

    struct TrieNode {
        TrieNode* children[10];

        TrieNode() {
            for (int i = 0; i < 10; i++) {
                children[i] = nullptr;
            }
        }
    };

    // Insert number into Trie
    void insert(TrieNode* root, int num) {

        string s = to_string(num);

        TrieNode* curr = root;

        for (char c : s) {

            int digit = c - '0';

            if (curr->children[digit] == nullptr) {
                curr->children[digit] = new TrieNode();
            }

            curr = curr->children[digit];
        }
    }

    // Find prefix length of num in Trie
    int findPrefix(TrieNode* root, int num) {

        string s = to_string(num);

        TrieNode* curr = root;

        int length = 0;

        for (char c : s) {

            int digit = c - '0';

            if (curr->children[digit] == nullptr) {
                break;
            }

            length++;

            curr = curr->children[digit];
        }

        return length;
    }

    int longestCommonPrefix(vector<int>& arr1,vector<int>& arr2) {

        TrieNode* root = new TrieNode();

        // Build Trie using arr2
        for (int num : arr2) {
            insert(root, num);
        }

        int answer = 0;

        // Search every number from arr1
        for (int num : arr1) {
            answer = max(answer, findPrefix(root, num));
        }

        return answer;
    }
};