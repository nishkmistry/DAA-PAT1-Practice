#include<iostream>
#include<queue>
#include<unordered_map>
#include<vector>
using namespace std;
struct Node{
    char data;
    int freq;
    Node *left, *right;
    Node(char data, int freq){
        this->data = data;
        this->freq = freq;
        left = right = nullptr;
    }
    Node(char data, int freq, Node *left, Node *right){
        this->data = data;
        this->freq = freq;
        this->left = left;
        this->right = right;
    }
};

struct compare{
    bool operator()(Node *a, Node *b){
        return a->freq > b->freq;
    }
};

void printCodes(Node *root, string str, unordered_map<char, string>& huffmanCode){
    if(root == nullptr){
        return;
    }
    if(!root->left && !root->right){
        huffmanCode[root->data] = str;
    }
    printCodes(root->left, str + "0", huffmanCode);
    printCodes(root->right, str + "1", huffmanCode);
}

void buildHuffmanTree(string text){
    unordered_map<char, int> freq;
    for(char ch : text){
        freq[ch]++;
    }
    priority_queue<Node*, vector<Node*>, compare> pq;
    for(auto pair : freq){
        pq.push(new Node(pair.first, pair.second));
    }
    while(pq.size() > 1){
        Node *left = pq.top(); pq.pop();
        Node *right = pq.top(); pq.pop();
        Node *newNode = new Node('\0', left->freq + right->freq, left, right);
        pq.push(newNode);
    }
    Node *root = pq.top();
    unordered_map<char, string> huffmanCode;
    printCodes(root, "", huffmanCode);
    cout << "Huffman Codes: " << endl;
    for(auto pair : huffmanCode){
        cout << pair.first << ": " << pair.second << endl;
    }
    cout <<"\nOriginal string: " << text << endl;
    string str = "";
    for(char ch : text){
        str += huffmanCode[ch];
    }
    cout << "Encoded string: " << str << endl;
    auto decode = [&](string str){
        cout << "Decoded string: ";
        Node *curr = root;
        for(char bit : str){
            if(bit == '0'){
                curr = curr->left;
            }
            else{
                curr = curr->right;
            }
            if(!curr->left && !curr->right){
                cout << curr->data;
                curr = root;
            }
        }
        cout << "\n";        
    };
    decode(str);
}

int main(){
    string text;
    cout << "Enter the string to be encoded: ";
    cin >> text;
    buildHuffmanTree(text);
    return 0;
}