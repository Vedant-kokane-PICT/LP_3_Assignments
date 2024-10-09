#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

// Structure for the Huffman Tree Node
struct HuffmanNode {
    char character;           // Character stored in the node
    int frequency;            // Frequency of the character
    HuffmanNode* left;        // Pointer to the left child
    HuffmanNode* right;       // Pointer to the right child

    // Constructor for leaf nodes
    HuffmanNode(char character, int frequency)
        : character(character), frequency(frequency), left(nullptr), right(nullptr) {}

    // Constructor for internal nodes
    HuffmanNode(int frequency, HuffmanNode* left, HuffmanNode* right)
        : character('\0'), frequency(frequency), left(left), right(right) {}

    // Comparator for priority queue to create the min-heap
    struct Compare {
        bool operator()(HuffmanNode* left, HuffmanNode* right) {
            return left->frequency > right->frequency;
        }
    };
};

// Function to generate Huffman codes
void generateHuffmanCodes(HuffmanNode* root, const string& code, unordered_map<char, string>& huffmanCodes) {
    if (!root) return;

    // If the node is a leaf, save the code
    if (root->character != '\0') {
        huffmanCodes[root->character] = code;
    }

    // Traverse left and right subtrees
    generateHuffmanCodes(root->left, code + "0", huffmanCodes);
    generateHuffmanCodes(root->right, code + "1", huffmanCodes);
}

// Function to print the Huffman codes
void printHuffmanCodes(const unordered_map<char, string>& huffmanCodes) {
    for (const auto& pair : huffmanCodes) {
        cout << pair.first << ": " << pair.second << endl;
    }
}

// Function to build the Huffman Tree
HuffmanNode* buildHuffmanTree(const unordered_map<char, int>& frequencies) {
    priority_queue<HuffmanNode*, vector<HuffmanNode*>, HuffmanNode::Compare> minHeap;

    // Create a leaf node for each character and insert into the priority queue
    for (const auto& pair : frequencies) {
        minHeap.push(new HuffmanNode(pair.first, pair.second));
    }

    // Merge two nodes with the smallest frequencies until one node remains
    while (minHeap.size() > 1) {
        HuffmanNode* left = minHeap.top();
        minHeap.pop();
        HuffmanNode* right = minHeap.top();
        minHeap.pop();

        int sum = left->frequency + right->frequency;
        minHeap.push(new HuffmanNode(sum, left, right));
    }

    return minHeap.top();
}

int main() {
    // Input string
    string text = "this is an example for huffman encoding";

    // Calculate frequency of each character in the input string
    unordered_map<char, int> frequencies;
    for (char c : text) {
        frequencies[c]++;
    }

    // Build the Huffman Tree
    HuffmanNode* root = buildHuffmanTree(frequencies);

    // Generate Huffman codes
    unordered_map<char, string> huffmanCodes;
    generateHuffmanCodes(root, "", huffmanCodes);

    // Print the Huffman codes
    cout << "Huffman Codes for each character:\n";
    printHuffmanCodes(huffmanCodes);

    return 0;
}
