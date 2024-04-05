#ifndef HEADER_H
#define HEADER_H
#include<iostream>
#include <bits/stdc++.h>
using namespace std;

//-----------STACK-----------
template <class T=int>
class Stack
{
	T *st;
	int top;
	int max;
	public:
		void display();// Function to display the elements of the stack
		
		void initialise(int size);// Function to initialize the stack with a specified size
		
		int overflow();// Function to check if the stack is full

		int underflow();// Function to check if the stack is empty
		
		void push(T x);// Function to push an element onto the stack
		
		T pop();// Function to pop an element from the stack
		
		void peek();// Function to peek at the top element of the stack
		
		int size();// Function to display the current size of the stack
};
//---------------------------------QUEUE----------------------------
template <class T=int>
class Queue
{
	T *q;
	int f,r;
	int max;
	public:
		void display();// Function to display the elements in the queue
		
		void initialise(int size);// Function to initialize the queue with a specified size

		int overflow();// Function to check if the queue is full
		
		int underflow();// Function to check if the queue is empty
		
		void enqueue(T x);// Function to enqueue (insert) an element into the queue
		
		T dequeue();// Function to dequeue (remove) an element from the queue
		
		int size();// Function to return the current size of the queue
		
};

//------------SINGLY LINKED LIST--------------

template <class T=int>
struct link
{
	T data;
	link* next;
};

template <class T=int>
class linklist
{
	private:
		link<T>* first;
	public:
		linklist()			// no argument constructor
		{
			first=NULL;   	
		}
		void addItemFirst(T d); 	//add data item (one link) at starting
		 
		void addItemLast(T d);		//add data item (one link) at end
		
		T deleteItemFirst();		//delete item (one link) at starting
		
		T deleteItemLast();			//delete item (one link) at last
		
		void display(); 			//display all links
		
		void reverseList();			//reverse all links
		
		void reverseDisplay();		//display nodes in reverse order
		
		void sortListAO();			// sort list in ascending order
		
		void sortListDO();			//sort list in descending order
		
		int listSize();				// calculate the size of list(start from 1)
		
		T valueAt(int p);			//gives value of that index according to list(index start from zero)
		
		void mergeList(linklist<T> l1,linklist<T> l2);	//merge two lists	
		
		T add_data();//addition of data present at each node
		
		// Function to insert a node with a specific value at a given index
    	void insertAt(const T& value, int index);	
    	
    	// Function to remove a node with a specific value from the linked list
    	void removeValue(const T& value);
    	
    	// Function to find if a specific value exists in the linked list
    	bool contains(const T& value) const;
    	
    	// Function to split the linked list into two halves
    	void split_Middle(linklist<T>& firstHalf, linklist<T>& secondHalf);
    	
    	// Function to create a copy of the linked list
		linklist<T> copy() const;
		
		// Function to shuffle the elements of the linked list
		void shuffle();

};

//--------------------------------CIRCULAR QUEUE--------------------------
template <class T=int>
struct Cirlink
{
	T data;
	Cirlink* next;
};
template <class T>
class CircularQueue
{
	private:
		Cirlink<T>* tail;
	public:
		CircularQueue()
		{
			tail=NULL;
		}	
		// Function to enqueue an element in a circular queue
		void cir_enque(T d);
		// Function to dequeue an element from a circular queue
		T cir_deque();
		// Function to display the elements of a circular queue
		void display();
		
};
//----------------------HASHING(insert/delete/search)------------------------

template <class T=int>
class Hashing
{
	vector<vector<T> > hashtable;
	int buckets;
	int hashvalue(T key)
	{
		return key%buckets;// division method
	}
	public:
		Hashing(int size)
		{
			buckets = size;
			hashtable.resize(size);
		}
		
		// Function to add a key to the hash table
		void addKey(T key);
		
		// Function to delete a key from the hash table
		T deleteKey(T key);
		
		// Function to display the contents of the hash table
		void displayHash();
};
//------------------------------HEAP-----------------------------
//-----------------------PRIORITY QUEUE--------------------------

template <class T=int>
class Heap
{
	vector<T> v;
	int size;
	void adjust(int i,int size);
	void adjust_Min(int i,int size);
	public:
		Heap()
		{
			
			v.push_back(0);
			size=0;
		}
		
		void insert_Max(T val); // Function to insert a value into the max heap
		
		void insert_Min(T val); // Function to insert a value into the min heap
		
		T del_Max();// Function to delete the maximum value from the max heap
		
		T del_Min(); // Function to delete the minimum value from the min heap
		
		void max_Heapify();// Function to maintain max heap property
		
		void min_Heapify();// Function to maintain min heap property
		
		void max_HeapSort();// Function to perform heap sort on max heap
		
		void min_HeapSort(); // Function to perform heap sort on min heap
		
		void display();// Function to display the contents of the heap
};
//-------------------------------DYNAMIC ARRAY--------------------------
template <class T=int>
class DynamicArray {
private:
    T* array;
    size_t size;
    size_t capacity;

public:
    // Default Constructor
    DynamicArray();
    
    // Function to initialize the array with a given size and fill value
    void initialize_With_SizeAndValue(size_t newSize, const T& val);
    
    // Destructor
    ~DynamicArray();

    // Function to add an element to the dynamic array
    void addElement(const T& element);
    
    //Function which sort the dynamic array
    void sort();

    // Function to get the element at a specific index
    T getElementAt(size_t index) const;

    // Function to get the current size of the dynamic array
    size_t getSize() const;
    
    // Function to get the current capacity of the dynamic array
    size_t getCapacity() const;

    // Function to print the elements of the dynamic array
    void printArray() const;
    
    // Function to remove an element from the dynamic array
    void removeElement(const T& element);
    
    // Function to check if the dynamic array contains a specific element
    bool contains(const T& element) const;
    
    // Function to find the index of a specific element
    size_t findIndex(const T& element) const;
    
    // Function to merge the elements of another array into the current array
    void mergeWith(const DynamicArray<T>& otherArray);
    
    // Function to reverse the elements of the dynamic array
    void reverse();
    
    // Function to compute the prefix sum array
   	void computePrefixSum(DynamicArray<T> &prefixSumArray) const;
   	
   	// Function to find the sum of all elements in the dynamic array
    T findSum() const;
   	
   	// Function to compute the sufix sum array
   	//void computeSufixSum(DynamicArray<T> &sufixSumArray) const;
    
    // Function to clear all elements from the dynamic array
    void clear();
};


//----------------------------TRIE---------------------------------
const int ALPHABET_SIZE = 26;
// TrieNode represents a node in the Trie data structure
class TrieNode
{
	public:
		char data; // Data stored in the node
		TrieNode* children[ALPHABET_SIZE]; // Array of pointers to child nodes (assuming lowercase English letters)
		bool isTerminal; // Indicates whether the node represents the end of a word
		int childCount;
		
		TrieNode(char ch)
		{
			data=ch;
			for(int i=0;i<ALPHABET_SIZE;i++)
				children[i]=NULL;
			isTerminal=false;
			childCount=0;
		}
};
// Trie class represents a Trie data structure
class Trie
{
	private:
		
		// Private utility function to recursively find words with a given prefix in the Trie
		void printSuggestionsUtil(TrieNode* node, string prefix, vector<string>& suggestions) 
		{
	        if (node->isTerminal) 
			{
	            suggestions.push_back(prefix);
	        }

	        for (int i = 0; i < ALPHABET_SIZE; ++i) 
			{
	            if (node->children[i] != NULL) 
				{
	                char ch = 'a' + i;
	                printSuggestionsUtil(node->children[i], prefix + ch, suggestions);
	            }
	        }
    	}
    	
    	// Private utility function to recursively insert a word into the Trie
		void insertUtil(TrieNode *root,string word)
		{
			//base case
			if(word.length()==0)
			{
				root->isTerminal=true;
				return;
			}
			//assumption ,words will not in CAPS
			int index=word[0]-'a';
			TrieNode *child;
			
			//present
			if(root->children[index]!=NULL)
			{
				child=root->children[index];
			}
			else
			{
				//absent
				child=new TrieNode(word[0]);
				root->childCount++;
				root->children[index]=child;
			}
			//RECURSION
			insertUtil(child,word.substr(1));
		}
		
		// Private utility function to recursively search for a word in the Trie
		bool searchUtil(TrieNode* root,string word)
		{
			//base case
			if(word.length()==0)
			{
				return root->isTerminal;
			}
			
			int index = word[0]-'a';
			TrieNode* child;
			
			//present
			if(root->children[index]!=NULL)
			{
				child=root->children[index];
			}
			else
			{
				//absent 
				return false;
			}
			//RECURSION
			return searchUtil(child,word.substr(1));
		}
		
		// Private utility function to find the longest common prefix among a vector of strings
    	void lcp(string str,string &ans)
    	{
    		for (int i = 0; i < str.length(); i++)
    		{
		        char ch = str[i];
		        if (root->childCount == 1)
		        {
		            ans.push_back(ch);
		            int index = ch - 'a';
		            root = root->children[index];
		        }
		        else
		        {
		            break;
		        }
		        if (root->isTerminal)
		        {
		            break;
		        }
    		}
		}
    	bool prefixUtil(TrieNode* root,string word)
		{
			//base case
			if(word.length()==0)
			{
				return true;
			}
			int index = word[0]-'a';
			TrieNode* child;
			//present
			if(root->children[index]!=NULL)
			{
				child=root->children[index];
			}
			else
			{
				//absent 
				return false;
			}
			//RECURSION
			return prefixUtil(child,word.substr(1));
		}
		// Returns true if root has no children, else false
		bool isEmpty(TrieNode* root)
		{
		    for (int i = 0; i < ALPHABET_SIZE; i++)
		        if (root->children[i])
		            return false;
		    return true;
		}
 
		// Recursive function to delete a key from given Trie
		TrieNode* removeUtil(TrieNode* root, string word)
		{
		    // If tree is empty
		    if (!root)
		        return NULL;
		 
		    // If last character of key is being processed
		    if (word.size()==0) 
			{
		 
		        // This node is no more end of word after
		        // removal of given key
		        if (root->isTerminal)
		            root->isTerminal = false;
		 
		        // If given is not prefix of any other word
		        if (isEmpty(root)&& root->data != '\0') 
				{
					
					delete (root);
		           	root = NULL;
					
		        }
		 
		        return root;
		    }
		 
		    // If not last character, recur for the child
		    // obtained using ASCII value
		    int index = word[0] - 'a';
		    root->children[index] = 
		          removeUtil(root->children[index], word.substr(1));
		 	// Decrement child count when removing a child node
		    if (root->children[index] == NULL) 
			{
		        root->childCount--;
		    }
		 	
		    // If root does not have any child (its only child got 
		    // deleted), and it is not end of another word.
		    if (isEmpty(root) && root->isTerminal == false && root->data != '\0') 
			{
				delete (root);
	            root = NULL;

		    }
		 
		    return root;
		}
	public:
		TrieNode *root,*temp;
		Trie();
		// Public function to search for a word in the Trie
		bool searchWord(string word);
		
		// Public function to insert a word into the Trie
		void insertWord(string word);
		
		// Public function to remove a word from the Trie
    	void removeWord(string word);
    	
    	// Public function to check if there are any words in the Trie that start with the given prefix
    	bool startWith(string prefix);
    	
    	// Public function to find the longest common prefix among a vector of strings
		string longestCommonPrefix(string arr);
		
		// Public function to get suggestions for words with a given prefix
		vector<string> getSuggestions(const string& prefix);
};

//------------------------------------GRAPH-----------------------------------
//************UNDIRECTED************************

template <class T=int>
class uGraph 
{
	protected:
	    int V; // Number of vertices
	    vector<vector<T> > adjMatrix; // Adjacency list

	public:
	    // Constructor
	    uGraph(int vertices) : V(vertices), adjMatrix(vertices, vector<T>(vertices, 0)) {}

	    
	    // Default Constructor
	    uGraph(){}
	
	    // Function to add an edge between two vertices
	    void addEdge(int v1, int v2,T weight = 1);
	
	    // Function to remove an edge between two vertices
	    void removeEdge(int v1, int v2);
		
		// Function to print the adjacency matrix
	    void printAdjMatrix();
		
	    // Function to check if there is an edge between two vertices
    	bool hasEdge(int v1, int v2);
	
	    // Function to get the neighbors of a vertex
		vector<int> getNeighbors(int vertex);
	
	    // Function to get the number of vertices in the graph
	    int getNumVertices();
	
		// Function to get the number of edges in the graph
	   int getNumEdges();
	   
    	// Function to get the degree of a vertex
	    int getDegree(int vertex);
		    
	    // Function to check if the graph is connected
	    bool isConnected();
	
};
//*********************DIRECTED GRAPH******************
template <class T = int>
class dGraph {
protected:
    int V; // Number of vertices
    vector<vector<T> > adjMatrix; // Adjacency list

public:
    // Constructor
    dGraph(int vertices) : V(vertices), adjMatrix(vertices, vector<T>(vertices, 0)) {}

    // Default Constructor
    dGraph() {}

    // Function to add an edge between two vertices
    void addEdge(int v1, int v2, T weight = 1);

    // Function to remove an edge between two vertices
    void removeEdge(int v1, int v2);

    // Function to print the adjacency matrix
    void printAdjMatrix();

    // Function to check if there is an edge between two vertices
    bool hasEdge(int v1, int v2);

    // Function to get the neighbors of a vertex
    vector<int> getNeighbors(int vertex);

    // Function to get the number of vertices in the graph
    int getNumVertices();

    // Function to get the number of edges in the graph
    int getNumEdges();

    // Function to get the degree of a vertex
    int getDegree(int vertex);

    // Function to check if the graph is connected
    bool isConnected();
};
#endif //HEADER_H