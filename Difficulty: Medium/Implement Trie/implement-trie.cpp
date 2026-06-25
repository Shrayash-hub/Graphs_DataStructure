class TrieNode
{
	public:
	TrieNode *children[26];
	bool isEndOfWord;
	
	TrieNode()
	{
		// Initialize all child pointers as NULL
		for (int i = 0; i < 26; i++)
			children[i] = nullptr;
		
		// Initially no word ends here
		isEndOfWord = false;
	}
};

class Trie
{
	public:
	TrieNode *root;
	
	Trie()
	{
		// Create the root node
		root = new TrieNode();
	}
	
	// Insert a word into the Trie
	void insert(string &word)
	{
		// Start from the root
		TrieNode *curr = root;
		
		// Traverse every character of the word
		for (int i = 0; i < word.size(); i++)
			{
			// Convert character into index (0-25)
			int index = word[i] - 'a';
			
			// Create a new node if it doesn't exist
			if (curr->children[index] == nullptr)
				curr->children[index] = new TrieNode();
			
			// Move to the next node
			curr = curr->children[index];
		}
		
		// Mark the end of the word
		curr->isEndOfWord = true;
	}
	
	// Search for a complete word
	bool search(string &word)
	{
		// Start from the root
		TrieNode *curr = root;
		
		// Traverse every character
		for (int i = 0; i < word.size(); i++)
			{
			// Convert character into index
			int index = word[i] - 'a';
			
			// Return false for invalid characters
			if (index < 0 || index >= 26)
				return false;
			
			// Character not found
			if (curr->children[index] == nullptr)
				return false;
			
			// Move to the next node
			curr = curr->children[index];
		}
		
		// Return true only if the complete word exists
		return curr->isEndOfWord;
	}
	
	// Check whether a prefix exists
	bool isPrefix(string &word)
	{
		// Start from the root
		TrieNode *curr = root;
		
		// Traverse every character of the prefix
		for (int i = 0; i < word.size(); i++)
			{
			// Convert character into index
			int index = word[i] - 'a';
			
			// Return false for invalid characters
			if (index < 0 || index >= 26)
				return false;
			
			// Prefix not found
			if (curr->children[index] == nullptr)
				return false;
			
			// Move to the next node
			curr = curr->children[index];
		}
		
		// All prefix characters exist
		return true;
	}
};
