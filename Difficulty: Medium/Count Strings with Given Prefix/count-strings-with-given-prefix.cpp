class TrieNode
{
	public:
	int count;
	TrieNode* child[26];
	
	TrieNode()
	{
		count = 0;
		
		for (int i = 0; i<26; i++)
			{
			child[i] = NULL;
		}
	}
};
class Trie {
	public:
	
	TrieNode* root;
	Trie()
	{
		root = new TrieNode();
	}
	
	void insert(string &word)
	{
		TrieNode* curr = root;
		
		for (int i = 0; i<word.size(); i++)
			{
			char ch = word[i];
			int index = ch - 'a';
			
			if (curr->child[index] == NULL)
				{
				TrieNode* temp = new TrieNode();
				curr->child[index] = temp;
			}
			
			curr = curr->child[index];
			curr->count++;
		}
	}
	
	int search(string &word)
	{
		string res = "";
		
		TrieNode* curr = root;
		
		for (int i = 0; i<word.size(); i++)
			{
			char ch = word[i];
			int index = ch - 'a';
			
			if (curr->child[index] == NULL)
				return 0;
			else
				curr = curr->child[index];
			
		}
		return curr->count;
	}
	
};
class Solution {
	public:
	vector<int> prefCount(vector<string>& s, vector<string>& q) {
		
		vector<int>ans;
		Trie* root = new Trie();
		
		for (int i = 0; i<s.size(); i++)
			{
			root->insert(s[i]);
		}
		for (int i = 0; i<q.size(); i++)
			{
			int len = root->search(q[i]);
			
			ans.push_back(len);
		}
		return ans;
		
	}
};
