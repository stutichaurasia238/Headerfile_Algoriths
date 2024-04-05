#include"header.h"
#include<iostream>
//------------------------------STACK---------------------------
template <class T>
void Stack<T>::push(T x)
{
	if(overflow())
		cout<<"Stack is Full"<<endl;
	else
		st[++top]=x;
}

template <class T>
int Stack<T>::underflow()
{
	if(top==-1)
		return 1;
	else
		return 0;
}

template <class T>
int Stack<T>::overflow()
{
	if(top==max-1)
		return 1;
	else
		return 0;
}

template <class T>
void Stack<T>::initialise(int size)
{
	st=new T[size];
	top=-1;
	max=size;
}

template <class T>
T Stack<T>::pop()
{
	if(underflow())
		cout<<"Stack is Empty"<<endl;
	else
	{
		T y=st[top--];
		return y;
	}
}

template <class T>
int Stack<T>::size()
{
	return top+1;
}

template <class T>
void Stack<T>::peek()
{
	if(underflow())
		cout<<"Stack is Empty"<<endl;
	else
		cout<<"Peek value is: "<<st[top]<<endl;
}

template <class T>
void Stack<T>::display()
{
	if(underflow())
		cout<<"Stack is Empty"<<endl;
	else
	{
		for(int i=top;i>=0;i--)
			cout<<st[i]<<endl;
	}
}

//-------------------------QUEUE-------------------------------

template <class T>
int Queue<T>::size()
{
	if(underflow())
		return 0;
	else
		return r-f+1;
}

template <class T>
T Queue<T>::dequeue()
{
	if(underflow())
		cout<<"Queue is Empty"<<endl;
	else
	{	
		T y=q[f];
		if(f==r)
			f=r=-1;
		else
			f++;
		return y;
	}
}

template <class T>
void Queue<T>::enqueue(T x)
{
	if(overflow())
		cout<<"Queue is Full"<<endl;
	else
	{
		if(r==-1)
			f=r=0;
		else
			r++;
		q[r]=x;
	}
}

template <class T>
int Queue<T>::underflow()
{
	if(f==-1)
		return 1;
	else
		return 0;
}

template <class T>
int Queue<T>::overflow()
{
	if(r==max-1)
		return 1;
	else
		return 0;
}

template <class T>
void Queue<T>::initialise(int size)
{
	q=new T[size];
	max=size;
	f=r=-1;
}

template <class T>
void Queue<T>::display()
{
	if(underflow())
		cout<<"Queue is Empty"<<endl;
	else
	{
		for(int i=f;i<=r;i++)
			cout<<q[i]<<"\t";
	}
}

//----------------------------SINGLY LINKLIST--------------------------------

// Function to shuffle the elements of the linked list

template <class T>
void linklist<T>::shuffle() 
{
    vector<T> elements;
    link<T>* current = first;

    // Copy elements to a vector
    while (current) 
	{
        elements.push_back(current->data);
        current = current->next;
    }

    // Shuffle the vector
    random_shuffle(elements.begin(), elements.end());

    // Copy elements back to the list
    current = first;
    for (int i=0;i<elements.size();i++) 
	{
        current->data = elements[i];
        current = current->next;
    }
}

// Function to create a copy of the linked list
template <class T>
linklist<T> linklist<T>::copy() const 
{
    linklist<T> copiedList;

    if (first==NULL) 
	{
        // If the original list is empty, return an empty copied list
        return copiedList;
    }

    link<T>* current = first;

    // Iterate through the original list and add elements to the copied list
    while (current) 
	{
        copiedList.addItemLast(current->data);
        current = current->next;
    }

    return copiedList;
}

// Function to split the linked list into two halves
template <class T>
void linklist<T>::split_Middle(linklist<T>& firstHalf, linklist<T>& secondHalf) {
    int length = listSize();
	
    if (length == 0) 
	{
        // Empty list
        return;
    }

    int middleIndex = length / 2;
	linklist<T> temp;
	temp=copy();
    link<T>* current =temp.first;
    int currentIndex = 0;

    // Traverse to the middle of the list
    while (currentIndex < middleIndex - 1) 
	{
        current = current->next;
        currentIndex++;
    }

    // Create the first half
    firstHalf.first = temp.first;
    link<T>* secondHalfHead = current->next;
    current->next = NULL;

    // Create the second half
    secondHalf.first = secondHalfHead;
}

// Function to find if a specific value exists in the linked list
template <class T>
bool linklist<T>::contains(const T& value) const 
{
    link<T>* current = first;

    while (current) {
        if (current->data == value) {
            return true;
        }
        current = current->next;
    }

    return false;
}

// Function to remove a node with a specific value from the linked list
template <class T>
void linklist<T>::removeValue(const T& value) 
{
    int i=0;
    int j=listSize();
	while(i!=j)
	{
		link<T>* current = first;
    	link<T>* prev = NULL;
	    while (current && current->data != value) 
		{
	        prev = current;
	        current = current->next;
	        i++;
	    }
	
	    if (!current) 
		{
	        // Node with the given value not found
	        return;
	    }
	
	    if (!prev) 
		{
	        // Node to be removed is the head
	    	first = current->next;
	    } 
		else 
		{
	        prev->next = current->next;
	    }
	
	    delete current;
	}
}

// Function to insert a node with a specific value at a given index
template <class T>
void linklist<T>::insertAt(const T& value, int index) {
    if (index > listSize() && index<0) 
	{
        // Invalid index
        throw out_of_range("Index out of range");
    }

    link<T>* newlink = new link<T>();
    newlink->data=value;
    newlink->next=NULL;

    if (index == 0) 
	{
        // Insert at the beginning
        newlink->next = first;
        first = newlink;
    } else 
	{
        // Insert at a specific index
        link<T>* current = first;
        int currentIndex = 0;

        while (currentIndex < index - 1) 
		{
            current = current->next;
            ++currentIndex;
        }

        newlink->next = current->next;
        current->next = newlink;
    }
}



template <class T>
void linklist<T>::addItemFirst(T d)
{
	link<T>* newlink = new link<T>;		//make a new link
	newlink->data=d;					//give it data
	newlink->next=first;			//it points to next link
	first=newlink;					//now first points to this
}

template <class T>
void linklist<T>::addItemLast(T d)
{
	link<T>* newlink = new link<T>;	
	link<T>* temp;
	newlink->data=d;
	newlink->next=NULL;
	if(first==NULL)
	{
		first=newlink;
	}
	else
	{
		temp=first;
		while(temp->next!=NULL)
			temp=temp->next;
		temp->next=newlink;
	}
	
}

template <class T>
T linklist<T>::deleteItemFirst()
{
	link<T>* temp;  // take temporary variable to delete a link
	T var;
	if(first==NULL)
	{
		cout<<"List is empty"<<endl;
		//return 0;
	}
	else
	{
		temp=first;
		first=first->next;
		var=temp->data;
		delete temp;		// free deleted link
		return var;
	}
}

template <class T>
T linklist<T>::deleteItemLast()
{
	link<T>* temp,*p;
	T var;
	if(first==NULL)
	{
		cout<<"List is empty"<<endl;
		//return 0;
	}
	else if(first->next==NULL)
	{
		temp=first;
		first=NULL;
		var=temp->data;
		delete temp;
		return var;
	}
	else
	{
		p=first;
		while(p->next&&p->next->next!=NULL)
			p=p->next;
		temp=p->next;
		p->next=NULL;
		var=temp->data;
		delete temp;
		return var;	
	}
}

template <class T>
void linklist<T>::reverseList()
{
	link<T> *c=first,*n,*p=NULL;
	while(c!=NULL)
	{
		n=c->next;
		c->next=p;
		p=c;
		c=n;
	}
	first=p;
}

template <class T>
void linklist<T>::reverseDisplay()
{
	revD(first);
}

template <class T>
void revD(link<T>* first)
{
	if(first==NULL)
		return;
	revD(first->next);
	cout<<first->data<<"\t";
}

template <class T>
int linklist<T>::listSize()
{
	link<T>* temp;
	int i;
	temp=first;
	for(i=1;temp!=NULL;temp=temp->next,i++);
	return i-1;
}

template <class T>
void linklist<T>::sortListAO()
{
	link<T>* p,*q;
	T temp;
	for(p=first;p->next!=NULL;p=p->next)
	{
		for(q=p->next;q!=NULL;q=q->next)
		{
			if((p->data)>(q->data))
			{
				temp=p->data;
				p->data=q->data;
				q->data=temp;
			}
		}	
	}
}

template <class T>
void linklist<T>::sortListDO()
{
	link<T>* p,*q;
	T temp;
	for(p=first;p->next!=NULL;p=p->next)
	{
		for(q=p->next;q!=NULL;q=q->next)
		{
			if((p->data)<(q->data))
			{
				temp=p->data;
				p->data=q->data;
				q->data=temp;
			}
		}	
	}
}
template <class T>
void linklist<T>::mergeList(linklist<T> l1,linklist<T> l2)
{
	link<T>* temp;
	for(temp=l1.first;temp!=NULL;temp=temp->next)
		addItemLast(temp->data);
	for(temp=l2.first;temp!=NULL;temp=temp->next)
		addItemLast(temp->data);
}

template <class T>
T linklist<T>::valueAt(int p)
{
	int n,i;
	n=listSize();
	if(p>=n || p<0)
		cout<<"Index not exist in list"<<endl;
	else
	{
		link<T> *temp;
		for(i=0,temp=first;i<=p-1;temp=temp->next,i++);
		return temp->data;
	}
}

template <class T>
T linklist<T>::add_data()
{
	link<T> *temp;
	T sum=0;
	for(temp=first;temp!=NULL;temp=temp->next)
	{
		sum += temp->data;
	}
	return sum;
}

template <class T>
void linklist<T>::display()
{
	if(first!=NULL)
	{
		link<T>* current=first;			//set ptr to first link
		while(current!=NULL)			//quit on last link
		{
			cout<<current->data<<"\t";	//print data
			current=current->next;		//move to next link
		}
	}
	else
		cout<<"List is Empty"<<endl;
}
//--------------------------------CIRCULAR QUEUE--------------------------
// Function to enqueue an element in a circular queue
template <class T>
void CircularQueue<T>::cir_enque(T d)
{
	Cirlink<T>* newlink = new Cirlink<T>;
	newlink->data=d;
	newlink->next=NULL;
	if(tail==NULL)
	{
		tail=newlink;
		tail->next=newlink;
	}
	else
	{
		newlink->next=tail->next;
		tail->next=newlink;
		tail=newlink;
	}
}
// Function to dequeue an element from a circular queue
template <class T>
T CircularQueue<T>::cir_deque()
{
	Cirlink<T>* temp;
	T var;
	if(tail==NULL)
	{
		cout<<"Queue is empty"<<endl;
	}
	else if(tail->next==tail)
	{
		temp=tail;
		tail=NULL;
		var=temp->data;
		delete temp;
		return var;
	}
	else
	{
		temp=tail->next;
		tail->next=temp->next;
		var=temp->data;
		delete temp;
		return var;
	}
		
}
// Function to display the elements of a circular queue
template <class T>
void CircularQueue<T>::display()
{
	Cirlink<T>* p;
	if(tail==NULL)
		cout<<"Queue is empty"<<endl;
	else
	{
		p=tail->next;
		do
		{
			cout<<p->data<<"\t";
			p=p->next;
		}while(p!=tail->next);
	}	
}
//----------------------HASHING(insert/delete/search)------------------------
// Function to add a key to the hash table
template <class T>
void Hashing<T>:: addKey(T key)
{
	int idx = hashvalue(key);
	hashtable[idx].push_back(key);
}

// Function to display the contents of the hash table
template <class T>
void Hashing<T>::displayHash() 
{ 
	// Display the contents 
    for (int i = 0; i < hashtable.size(); i++)
	{ 
        cout<< i; 
        for (int j = 0; j < hashtable[i].size(); j++) 
            cout << " -> " << hashtable[i][j]; 
        cout << endl; 
	}
} 

// Function to delete a key from the hash table
template <class T>
T Hashing<T>::deleteKey(T key)
{
	int idx = hashvalue(key);
	for (int j = 0; j < hashtable[idx].size(); j++)
	{
		if (hashtable[idx][j] == key)
		{ 
			hashtable[idx].erase(hashtable[idx].begin() + j);
			return key;
		}
	}
	cout<<"key is not present in hash table\n";
	return 0;
}
//------------------------------HEAP-----------------------------
//-----------------------PRIORITY QUEUE--------------------------

template <class T>
void Heap<T>:: insert_Max(T val)
{
	v.push_back(val);
	size = size+1;
			
	int index=size;
	T item=v[size];
	while((index>1)&&(v[index/2]<item))
	{
		v[index]=v[index/2];
		index=index/2;
	}
	v[index]=item;
}

template <class T>
void Heap<T>:: insert_Min(T val)
{
	v.push_back(val);
	size = size+1;
			
	int index=size;
	T item=v[size];
	while((index>1)&&(v[index/2]>item))
	{
		v[index]=v[index/2];
		index=index/2;
	}
	v[index]=item;
}

template <class T>
void Heap<T>::display()
{
	int i;
	if(size!=0)
	{
		for(int i=1;i<=size;i++)
			cout<<v[i]<<"\t";
	}
	else
		cout<<"Heap is empty"<<endl;
}

template <class T>
T Heap<T>::del_Max()
{
	if(size==0)
	{
		cout<<"Heap is Empty"<<endl;
		return 0;
	}
	else
	{
		max_Heapify();
		T val;
		val=v[1];
		v[1]=v[size];
		size=size-1;
		adjust(1,size);
		return val;
	}
}

template <class T>
T Heap<T>::del_Min()
{
	if(size==0)
	{
		cout<<"Heap is Empty"<<endl;
		return 0;
	}
	else
	{
		min_Heapify();
		T val;
		val=v[1];
		v[1]=v[size];
		size=size-1;
		adjust_Min(1,size);
		return val;
	}
}

template <class T>
void Heap<T>::adjust(int i,int size)
{
	T item;
	int j;
	item=v[i];
	j=2*i;
	while(j<=size)
	{
		if((j<size)&&(v[j]<v[j+1]))
			j=j+1;
		if(item>=v[j])
			break;
		v[j/2]=v[j];
		j=2*j;
	}	
	v[j/2]=item;
}


template <class T>
void Heap<T>::adjust_Min(int i,int size)
{
	T item;
	int j;
	item=v[i];
	j=2*i;
	while(j<=size)
	{
		if((j<size)&&(v[j]>v[j+1]))
			j=j+1;
		if(item<=v[j])
			break;
		v[j/2]=v[j];
		j=2*j;
	}	
	v[j/2]=item;
}

template <class T>
void Heap<T>::max_Heapify()
{
	for(int i=size/2;i>=1;i--)
		adjust(i,size);
}

template <class T>
void Heap<T>::min_Heapify()
{
	for(int i=size/2;i>=1;i--)
		adjust_Min(i,size);
}

template <class T>
void Heap<T>::max_HeapSort()
{
	T temp;
	max_Heapify();
	for(int i=size;i>=2;i--)
	{
		temp=v[i];
		v[i]=v[1];
		v[1]=temp;
		
		adjust(1,i-1);
	}
}

template <class T>
void Heap<T>::min_HeapSort()
{
	T temp;
	min_Heapify();
	for(int i=size;i>=2;i--)
	{
		temp=v[i];
		v[i]=v[1];
		v[1]=temp;
		
		adjust_Min(1,i-1);
	}
}
//-------------------------------DYNAMIC ARRAY--------------------------

// Default Constructor
template <class T>
DynamicArray<T>::DynamicArray() :array(NULL) ,size(0), capacity(1) 
{
    array = new T[capacity];
}

// Function to initialize the array with a given size and fill value
template <class T>
void DynamicArray<T>::initialize_With_SizeAndValue(size_t newSize, const T& val)
{
	// Release existing memory if any
    delete[] array;

    // Allocate new memory
    array = new T[newSize];
    size = newSize;
    capacity = newSize;

    // Fill the array with the specified value
    for (size_t i = 0; i < size; ++i) 
	{
        array[i] = val;
    }
}

// Destructor
template <class T>
DynamicArray<T>::~DynamicArray()
{
    delete[] array;
}

// Function to add an element to the dynamic array
template <class T>
void DynamicArray<T>::addElement(const T& element)
{

    if (size == capacity)
	{
        // Resize the array if it reaches capacity
        capacity *= 2;
        T* newArray = new T[capacity];
        for (size_t i = 0; i < size; ++i)
		{
            newArray[i] = array[i];
        }
        delete[] array;
        array = new T[capacity];
        array = newArray;
    }

    array[size++] = element;
}

// Function to get the element at a specific index
template <class T>
T DynamicArray<T>::getElementAt(size_t index) const
{
    if (index < size)
	{
        return array[index];
    }
	else
	{
        // Handle out-of-bounds access
        cerr << "Error: Index out of bounds" << endl;
        exit(EXIT_FAILURE);
    }
}

// Function to get the current size of the dynamic array
template <class T>
size_t DynamicArray<T>::getSize() const
{
    return size;
}

// Function to get the current capacity of the dynamic array
template <class T>
size_t DynamicArray<T>::getCapacity() const
{
    return capacity;
}

// Function to print the elements of the dynamic array
template <class T>
void DynamicArray<T>::printArray() const
{
    for (size_t i = 0; i < size; ++i)
	{
        cout << array[i] << " ";
    }
    cout << endl;
}

// Function to remove an element(all no of occurences) from the dynamic array
template <class T>
void DynamicArray<T>::removeElement(const T& element) 
{
    size_t index = 0;
    int i=0;
    while(i<size)
    {
	
	    while (index < size && array[index] != element) 
		{
	        index++;
	        i++;
	    }
	
	    if (index < size)
		{
	        // Shift elements to fill the gap
	        for (size_t i = index; i < size - 1; i++) 
			{
	            array[i] = array[i + 1];
	        }
	        --size;
	    }
	}
}

// Function to check if the dynamic array contains a specific element

template <class T>
bool DynamicArray<T>::contains(const T& element) const
{
    for (size_t i = 0; i < size; ++i)
	{
        if (array[i] == element) 
		{
            return true;
        }
    }
    return false;
}

// Function to find the index of a specific element

template <class T>
size_t DynamicArray<T>::findIndex(const T& element) const
{
    for (size_t i = 0; i < size; i++) 
	{
        if (array[i] == element) 
		{
            return i;
        }
    }
    // Return a special value if the element is not found
    return numeric_limits<size_t>::max();
}

// Function to clear all elements from the dynamic array
template <class T>
void DynamicArray<T>::clear() 
{
    size = 0;
}

// Function to reverse the elements of the dynamic array
template <class T>
void DynamicArray<T>::reverse() 
{
    //reverse(array, array + size);
     for(int i=0;i<size/2;i++)
         swap(array[i],array[size-i-1]);
}

// Function to compute the prefix sum array
template <class T>
void DynamicArray<T>::computePrefixSum(DynamicArray<T> &prefixSumArray) const 
{
	prefixSumArray.clear();
	// Initialize the prefixSumArray with the first element of the input array
	prefixSumArray.addElement(array[0]);
	
	// Calculate the cumulative sum for the remaining elements
	for (size_t i = 1; i < size; ++i) 
	{
	    T prefixSum = prefixSumArray.getElementAt(i - 1) + array[i];
	    prefixSumArray.addElement(prefixSum);
	}
		
}

template <class T>
void DynamicArray<T>::sort() 
{
    std::sort(array, array + size);
}

// Function to merge the elements of another array into the current array
template <class T>
void DynamicArray<T>::mergeWith(const DynamicArray<T>& otherArray) 
{
    size_t newSize = size + otherArray.size;

    // Create a new array with the combined size
    T* newArray = new T[newSize];

    // Copy elements from the current array
    for (size_t i = 0; i < size; ++i) 
	{
        newArray[i] = array[i];
    }

    // Copy elements from the other array
    for (size_t j = 0; j < otherArray.size; ++j) 
	{
        newArray[size + j] = otherArray.array[j];
    }

    // Release existing memory
    delete[] array;

    // Update to the new array
    array = newArray;
    size = newSize;
    capacity = newSize;
}

// Function to find the sum of all elements in the dynamic array
template <class T>
T DynamicArray<T>::findSum() const 
{
    T sum = 0;
    
    for (size_t i = 0; i < size; ++i) 
	{
        sum += array[i];
    }

    return sum;
}
//----------------------------TRIE---------------------------------
Trie::Trie()
{
	root=new TrieNode('\0');
}		
void Trie::insertWord(string word)
{	temp=root;
	insertUtil(root,word);
	root=temp;
}
		
bool Trie::searchWord(string word)
{	temp=root;
	bool t;
	t=searchUtil(root,word);
	root=temp;
	return t;
	
}
void Trie::removeWord(string word)
{
	if(searchWord(word)==false)
	{
		cout << "Word not found!! Unable to delete!!\n";
	    cout<<endl;
	}
	else
	{	temp=root;
	    removeUtil(root,word);
	    root=temp;
	}
}
bool Trie::startWith(string prefix)
{
	return prefixUtil(root,prefix);
}
string Trie::longestCommonPrefix(string arr)
{	temp=root;
	//Trie *t =new Trie();
 /*	for(int i=0;i<n;i++)
 	{
 		t->insertWord(arr[i]);
	}*/
	string first=arr;
	string ans="";
			
	lcp(first,ans);
	root=temp;
	if(ans.length()==0)
		ans="nothing common";
	return ans;
}
vector<string> Trie::getSuggestions(const string& prefix) 
{
	temp=root;
	vector<string> suggestions;
	TrieNode* current = root;
	for (size_t i = 0; i < prefix.size(); ++i) 
	{
		char ch = prefix[i];
		int index = ch - 'a';
		if (!current->children[index]) 
		{
		    // Prefix not found in trie
		     return suggestions;
		}
        		current = current->children[index];
    }
	printSuggestionsUtil(current, prefix, suggestions);
	root=temp;
	return suggestions;
}

//------------------------------------GRAPH-----------------------------------
//************UNDIRECTED************************
// Function to get the neighbors of a vertex
template <class T>
vector<int> uGraph<T>::getNeighbors(int vertex) 
{
	vector<int> neighbors;
	for (int i = 0; i < V; ++i) 
	{
		if (adjMatrix[vertex][i] != 0) 
		{
		    neighbors.push_back(i);
		}
	}
	return neighbors;
}

// Function to check if the graph is connected
template <class T>
bool uGraph<T>::isConnected() 
{
	vector<bool> visited(V, false);
	queue<T> q;
	q.push(0); // Start BFS from vertex 0
	visited[0] = true;
	        
	// Perform BFS traversal
	while (!q.empty()) 
	{
	    int currVertex = q.front();
	    q.pop();
	    vector<T> neighbors = getNeighbors(currVertex);
	    for (int i = 0; i < neighbors.size(); ++i) 
		{
	        int neighbor = neighbors[i];
	        if (visited[neighbor]==0)
			{
	            visited[neighbor] = true;
	            q.push(neighbor);
	        }
	    }
	}
	
	// Check if all vertices are visited
	for (int i = 0; i < visited.size(); ++i) 
	{
	    if (visited[i]==0) 
		{
	        return false; // Graph is not connected
	    }
	}
	return true; // Graph is connected
}


// Function to add an edge between two vertices
template <class T>
void uGraph<T>::addEdge(int v1, int v2,T weight) 
{
	adjMatrix[v1][v2] = weight;
    adjMatrix[v2][v1] = weight;
}

// Function to remove an edge between two vertices
template <class T>
void uGraph<T>::removeEdge(int v1, int v2) 
{
	adjMatrix[v1][v2] = 0;
    adjMatrix[v2][v1] = 0;
}

// Function to print the adjacency matrix
template <class T>
void uGraph<T>::printAdjMatrix() 
{
	for (int i = 0; i < V; ++i) 
	{
	    for (int j = 0; j < V; ++j) 
		{
	        cout << adjMatrix[i][j] << " ";
	    }
	    cout << endl;
	}
}

// Function to check if there is an edge between two vertices
template <class T>
bool uGraph<T>::hasEdge(int v1, int v2)
{
	return adjMatrix[v1][v2]!=0  && adjMatrix[v2][v1]!=0;
}

// Function to get the number of vertices in the graph
template <class T>
int uGraph<T>::getNumVertices() 
{
	return V;
}

// Function to get the number of edges in the graph
template <class T>
int uGraph<T>::getNumEdges() 
{
	int count = 0;
	for (int i = 0; i < V; ++i) 
	{
	    for (int j = 0; j < V; ++j) 
		{
	        if (adjMatrix[i][j]!=0) 
			{
	            count++;
	        }
	    }
	}
	// Divide by 2 because each edge is counted twice (for undirected graphs)
	return count / 2;
}

// Function to get the degree of a vertex
template <class T>
int uGraph<T>::getDegree(int vertex) 
{
	int degree = 0;
	for (int i = 0; i < V; ++i) 
	{
	    if (adjMatrix[vertex][i] != 0) 
		{
	        ++degree;
	    }
	}
	return degree;
}   	

template <class T>
class BFS : public uGraph<T> 
{
public:
    BFS(int vertices) : uGraph<T>(vertices) {}
    BFS() : uGraph<T>() {}
	// Declaration of bfsTraversal function for Breadth-First Search (BFS) traversal starting from a specified vertex.
    void bfsTraversal(int start);
	
};

// Declaration of bfsTraversal function for Breadth-First Search (BFS) traversal starting from a specified vertex.
template <class T>
void BFS<T>::bfsTraversal(int start) 
{
	vector<bool> visited(this->V, false);
    queue<T> q;
    q.push(start);
    visited[start] = true;
    cout << start << " ";
    while (!q.empty()) 
	{
    	int vertex = q.front();
        q.pop();
        vector<int> neighbors = this->getNeighbors(vertex);
        for (int i = 0; i < neighbors.size(); ++i) 
		{
            int neighbor = neighbors[i];
            if (visited[neighbor]==0) 
			{
                q.push(neighbor);
                visited[neighbor] = true;
                cout << neighbor<< " ";
            }
        }
    }
    cout << endl;
}

template <typename T>
class DFS : public uGraph<T> 
{
	private:
	    void dfsUtil(int vertex, vector<bool>& visited) 
		{
	        visited[vertex] = true;
	        cout << vertex << " ";
	        vector<int> neighbors = this->getNeighbors(vertex);
	        for (int i = 0; i < neighbors.size(); ++i) 
			{
	            int neighbor = neighbors[i];
	            if (!visited[neighbor]) 
				{
	                dfsUtil(neighbor, visited);
	            }
	        }
	    }
	public:
	    DFS(int vertices) : uGraph<T>(vertices) {}
		DFS() : uGraph<T>() {}
		
		// Declaration of dfsTraversal function for Depth-First Search (DFS) traversal starting from a specified vertex.
	    void dfsTraversal(int start);
};
// Declaration of dfsTraversal function for Depth-First Search (DFS) traversal starting from a specified vertex.
template <class T>
void DFS<T>::dfsTraversal(int start) 
{
	vector<bool> visited(this->V, false);
	dfsUtil(start, visited);
	cout << endl;
}
//*********************DIRECTED GRAPH******************
// Function to get the neighbors of a vertex
template <class T>
vector<int> dGraph<T>::getNeighbors(int vertex) 
{
    vector<int> neighbors;
    for (int i = 0; i < V; ++i) 
	{
        if (adjMatrix[vertex][i] != 0) 
		{
            neighbors.push_back(i);
        }
    }
    return neighbors;
}

// Function to check if the graph is connected
template <class T>
bool dGraph<T>::isConnected() 
{
    vector<bool> visited(V, false);
    queue<T> q;
    q.push(0); // Start BFS from vertex 0
    visited[0] = true;

    // Perform BFS traversal
    while (!q.empty()) 
	{
        int currVertex = q.front();
        q.pop();
        vector<T> neighbors = getNeighbors(currVertex);
        for (int i = 0; i < neighbors.size(); ++i) 
		{
            int neighbor = neighbors[i];
            if (visited[neighbor] == 0) 
			{
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }

    // Check if all vertices are visited
    for (int i = 0; i < visited.size(); ++i) 
	{
        if (visited[i] == 0) 
		{
            return false; // Graph is not connected
        }
    }
    return true; // Graph is connected
}

// Function to add an edge between two vertices
template <class T>
void dGraph<T>::addEdge(int v1, int v2, T weight) 
{
    adjMatrix[v1][v2] = weight;
}

// Function to remove an edge between two vertices
template <class T>
void dGraph<T>::removeEdge(int v1, int v2) 
{
    adjMatrix[v1][v2] = 0;
}

// Function to print the adjacency matrix
template <class T>
void dGraph<T>::printAdjMatrix() 
{
    for (int i = 0; i < V; ++i) 
	{
        for (int j = 0; j < V; ++j) 
		{
            cout << adjMatrix[i][j] << " ";
        }
        cout << endl;
    }
}

// Function to check if there is an edge between two vertices
template <class T>
bool dGraph<T>::hasEdge(int v1, int v2) 
{
    return adjMatrix[v1][v2] != 0;
}

// Function to get the number of vertices in the graph
template <class T>
int dGraph<T>::getNumVertices() 
{
    return V;
}

// Function to get the number of edges in the graph
template <class T>
int dGraph<T>::getNumEdges() 
{
    int count = 0;
    for (int i = 0; i < V; ++i) 
	{
        for (int j = 0; j < V; ++j) 
		{
            if (adjMatrix[i][j] != 0) 
			{
                count++;
            }
        }
    }
    return count;
}

// Function to get the degree of a vertex
template <class T>
int dGraph<T>::getDegree(int vertex) 
{
    int degree = 0;
    for (int i = 0; i < V; ++i) 
	{
        if (adjMatrix[vertex][i] != 0) 
		{
            ++degree;
        }
    }
    return degree;
}
