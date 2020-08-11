#include <iostream>
#include <cstdlib>

using namespace std;

struct Node {
    int data;
    struct Node *next;
};

class linked_list {
    private:
        struct Node *head;
        struct Node *tail;
        int length;
    public:
        linked_list() {
            head = NULL; 		//find how to change into "nullptr"
            tail = NULL;		//find how to change into "nullptr"
            length = 0;
        }
		
	//---------------------------------------------NODE ADDITION AREA----------------------------------------------------------------//
	void append(int number)    //do i wand to keep char, considering insert() override
	{
		Node *tmp = new Node;
		tmp->data = number;
		tmp->next = NULL;
		
		if (length == 0)
		{
			head = tmp;
			tail = tmp;
			length++;
			return;
		}
		
		tail->next = tmp;
		tail = tmp;
		length++;
	}

	void insert(int number, int index = 0)
	{

		if (index > length)
		{
			cout << "out of bounds of list" << endl;
			return;
		}

		if (length  == 0)
		{
			append(number);
			return;
		}
		
		Node *tmp = NULL;
		Node *node = new Node;
		
		tmp = head;
		length++;
			
		node->data = number;
		node->next = NULL;
		
		if (index == 0)
		{
			node->next = head;
			head = node;
			return;
		}
		else if (index == length)   //sth breaks, find 
		{
			tail->next = node;
			tail = node;
			return;
		}
	
		for (int i = 0; i < index - 1; i++)
		{
			tmp = tmp->next;
		} 
	
		node->next = tmp->next;
		tmp->next = node;
	}

	//--------------------------------------------SINGLE OBJECT MANIPULATION AREA----------------------------------------------------------------//
	int change(int number, int index)
	{
		if (index >= length)
		{
			cout << "out of bounds of list" << endl;
			return 1;
		}

		Node *tmp = head;

		for (int i = 0; i < index; i++)
		{
			tmp = tmp->next;
		}
		tmp->data = number;
		return 0;	
	}	
	
    //--------------------------------------------LIST ITERATION AREA----------------------------------------------------------------//
    bool search(int key) 
	{
		if (head == NULL) return false;
        if (head->data == key || tail->data == key) return true;
        
        Node *current = head;
        
        while (current != tail) 
		{
        	if (current->data == key) return true;
            current = current->next;
        }
    	return false;
    }
    
    int find(int index) 
	{
		if (index >= length)		//check logic same as pop()
		{
			cout << "out of bounds of list" << endl;
			return -1;
		}
		
        if (index == length - 1)
        {
            return tail->data;
        }
        
        Node *tmp = head;
        
        for (int i = 0; i < index; i++)
		{
			tmp = tmp->next;
		}
		
    	return tmp->data;
    }
    
	void display(void) 
	{
		if (length == 0) return; 
        Node *current = head;
		
        while (current != NULL) 
		{
        	cout << current->data << '\n';
            current = current->next;
        }
    }
    
    //--------------------------------------------MEMORY DEALLOCATION AREA----------------------------------------------------------------//
    
    void del(int number) 
    {
        if (head == NULL) 
        {
            return;
        }
		if (length == 1) 
    	{	
        	free(head);
            head = tail = NULL;
            length = 0;
            return;		//check
        }
        
        if (head->data == number) //case if deleting head , changes head, and tail if needed
        {
           	Node *tmp = head;
            head = head->next;
            free(tmp);
			length--;
            return;	
		}		////check
        
        else 
        {
            Node *tmp = head;
            Node *prev = tmp;
                
            while (tmp->next != NULL ) //check logic
            {
            	//cout << "del :" << tmp->data << endl;
            	if (tmp->data == number)
                {
	                prev->next = tmp->next;

	                free(tmp);
					length--;
	                return;
            	}
            	
            	prev = tmp;
            	tmp = tmp->next;
        	}
            	
	        if (tmp->data == number) //tmp should equal tail, check that
	        {
	            	tail = prev;
	            	free(tmp);
			length--;
	        }
        }
    }
    
    int pop(int index) 
	{
	
	    if (head == NULL) 
	    {
	        cout << "empty list" << endl;
			return -1;
	    }
    
	    if (index >= length)		//check logic
		{
			cout << "out of bounds of list" << endl;
			return -1;
		}
			
		struct Node *tmp = NULL;
		struct Node *prev = tmp;
		int value;
		
		if (length == 1)
		{
			value = head->data;
			free(head);
			tail = head = NULL;
			length = 0;
			return value;
		}
		
		if (index == 0)
		{
			tmp = head;
			value = tmp->data;
			head = tmp->next;
			free(tmp);
			length--;
			return value;
		}
		
		tmp = head;
		for (int i = 0; i < index; i++)
		{
			prev = tmp;
			tmp = tmp->next;
		}
		
		if (tmp == tail)	//check, especially tail manipulation
		{
			tail = prev;
			tail->next = NULL;
			value = tmp->data;
			free(tmp);
			length--;
			return value;
		}

		prev->next = tmp->next;
		value = tmp->data;
		free(tmp);
		length--;
		return value;	
    }
    
    void clear()
	{
		Node* current = head;  
		Node* next;  
  
		while (current != NULL)  
		{  
		    next = current->next;  
		    free(current);  
		    current = next;  
		}
		
		head, tail = NULL;
		length = 0;
	}
};
