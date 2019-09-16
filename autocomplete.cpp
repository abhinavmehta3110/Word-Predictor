// #include "TrieNode.h"
#include <string>
#include <vector>
#include <iostream>
using namespace std;
class TrieNode {
	public :
	char data;
	TrieNode **children;
	bool isTerminal;

	TrieNode(char data) {
		this -> data = data;
		children = new TrieNode*[26];
		for(int i = 0; i < 26; i++) {
			children[i] = NULL;
		}
		isTerminal = false;
	}
};

class Trie {
	TrieNode *root;

	public :
	int count;

	Trie() {
		this->count = 0;
		root = new TrieNode('\0');
	}

	bool insertWord(TrieNode *root, string word) {
		// Base case
		if(word.size() == 0) {
			if (!root->isTerminal) {
				root -> isTerminal = true;
				return true;	
			} else {
				return false;
			}
		}

		// Small Calculation
		int index = word[0] - 'a';
		TrieNode *child;
		if(root -> children[index] != NULL) {
			child = root -> children[index];
		}
		else {
			child = new TrieNode(word[0]);
			root -> children[index] = child;
		}

		// Recursive call
		return insertWord(child, word.substr(1));
	}

	// For user
	void insertWord(string word) {
		if (insertWord(root, word)) {
			this->count++;
		}
	}
    void printWords(TrieNode* root,string w){
        
        if(root->isTerminal==true){
            cout<<w;
            cout<<endl;
            //cout<<w;
        }
    
        for(int i=0;i<26;i++){
            if(root->children[i]==NULL)
                continue;
            //cout<<root->children[i]->data;
            //if(root->children[i]->isTerminal==true;)
              //  cout<<endl;
            printWords(root->children[i],w+root->children[i]->data);
        }
        return ;
    }
    void HelperAuto(TrieNode* root,string pattern,string w){
        if(pattern.size()==0){
            //cout<<w;
            printWords(root,w);
            return;
        }
        int index=pattern[0]-'a';
        if(root->children[index]==NULL)
            return ;
       
        HelperAuto(root->children[index],pattern.substr(1),w);
    }
    void autoComplete(vector<string> input, string pattern) {
        // Complete this function
        // Print the output as specified in question
        for(int i=0;i<input.size();i++){
            insertWord(input[i]);
        }
         HelperAuto(root,pattern,pattern);
    }
    
    
    

};


int main() {
	Trie t;
    int N;
    cin >> N;
    string pattern;
    vector<string> vect;
    for (int i=0; i < N; i++) {
        string word;
        cin >> word;
        vect.push_back(word);
    }
    cin >> pattern;
    t.autoComplete(vect, pattern);
}
