
// start...
struct Node {
	Node *links[26];
	int cntEndWith = 0, cntPrefix = 0;
	//checks if the reference trie is present or not
	bool containKey(char ch){
		return (links[ch - 'a'] != NULL);
	}
	//creating reference trie
	void put(char ch, Node *node){
		links[ch - 'a'] = node;
	}
	//to get the next node for traversal
	Node *get(char ch){
		return links[ch - 'a'];
	}
	
	void increaseEnd(){
		cntEndWith++;
	}
	void increasePrefix(){
		cntPrefix++;
	}
	void deleteEnd(){
		cntEndWith--;
	}
	void reducePrefix(){
		cntPrefix--;
	}
	int getEnd(){
		return cntEndWith;
	}
	int getPrefix(){
		return cntPrefix;
	}
};

class Trie{
private:
	Node* root;
public:
	Trie(){
		//creating new obejct
		root = new Node();
	}
	
	void insert(string &word){
		Node * node = root;
		for (int i = 0; i < word.length(); i++){
			if (!node -> containKey(word[i])){
				node -> put(word[i], new Node());
			}
			node = node -> get(word[i]);
			node -> increasePrefix();
		}
		node -> increaseEnd();
	}
	
	int countWords(string &word){
		Node *node = root;
		for (int i = 0; i < word.length(); i++){
			if (node -> containKey(word[i])){
				node = node -> get(word[i]);
			}
			else return 0;
		}
		return node -> getEnd();
	}

	int startsWith(string &word){
		Node * node = root;
		for (int i = 0; i < word.length(); i++){
			if(node -> containKey(word[i])){
				node = node -> get(word[i]);
			} 
			else return 0;
		}
		return node -> getPrefix();
	}
	
	void erase(string &word){
		Node * node = root;
		for (int i = 0; i < word.length(); i++){
			if (node -> containKey(word[i])){
				node = node -> get(word[i]);
				node -> reducePrefix();
			} 
			else return;
		}
		node -> deleteEnd();
	}
};
// end...

void solve(){
	Trie trie;
	//trie.insert(s);
	//trie.countWords(s);
	//trie.startsWith(s);
	//trie.erase(s);
}
