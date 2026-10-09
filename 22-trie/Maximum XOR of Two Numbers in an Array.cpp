
class Solution {
public:

    struct TrieNode {
        TrieNode* children[2];

        TrieNode() {
            children[0] = nullptr;
            children[1] = nullptr;
        }
    };

    // Insert all numbers into the Binary Trie
    void populateTrie(vector<int>& nums, TrieNode* root) {

        for (int n : nums) {

            TrieNode* curr = root;

            // Process bits from MSB -> LSB
            for (int i = 31; i >= 0; i--) {

                int bit = (n >> i) & 1;

                if (curr->children[bit] == nullptr) {
                    curr->children[bit] = new TrieNode();
                }

                curr = curr->children[bit];
            }
        }
    }

    int findMaximumXOR(vector<int>& nums) {

        TrieNode* root = new TrieNode();

        // 1. Build Trie
        populateTrie(nums, root);

        int maximumXOR = 0;

        // 2. Find best XOR for every number
        for (int n : nums) {

            TrieNode* curr = root;

            int currentXOR = 0;

            // Again process MSB -> LSB
            for (int i = 31; i >= 0; i--) {

                int bit = (n >> i) & 1;

                // We want the opposite bit
                int opposite = 1 - bit;

                if (curr->children[opposite] != nullptr) {

                    // Opposite bit exists
                    // Therefore XOR bit = 1
                    currentXOR |= (1 << i);

                    curr = curr->children[opposite];
                }
                else {

                    // Opposite doesn't exist
                    // We must take the same bit
                    curr = curr->children[bit];
                }
            }

            maximumXOR = max(maximumXOR, currentXOR);
        }

        return maximumXOR;
    }
};