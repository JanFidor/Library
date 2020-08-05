#include <iostream>

struct node {
    int key;
    struct node *next;
};

class linked_list {
    public:
        struct node *head;
        struct node *tail;
        int length;
    public:
        linked_list() {
            head = nullptr;
            tail = nullptr;
            
        }
		/*
        void create(int key) {
            struct node *temp;
            temp = new struct node;
            temp->key = key;
            temp->next = nullptr;
            head = temp;
            tail = head;
        }
		*/
	
	void append(int number, char place = 'b')
	{
		Node *tmp = new Node;
		tmp->data = number;
		tmp->next = nullptr;
		/*{
		if (tmp == NULL)
		{
			cout << "memory overflow" << endl;
			return;
		}
		}*/
		
		if (head == nullptr)
		{
			head = tmp;
			tail = tmp;
			length++;
			return;
		}
		
		switch (place)
		{
		case 'f':
			tmp->next = head;
			head = tmp;
			length++;
			break;
		case 'b':
			tail->next = tmp;
			tail = tmp;
			length++;
			break;
		default:
			cout << "incorrect input" << endl;
			break;
		}
}
	
    void insert(int index, int number = 0)
	{

	if (index > length)
	{
		cout << "out of bounds of list" << endl;
		return;
	}

	Node *tmp = nullptr;
	Node *node = new Node;

	/*{
			
		
		if (tmp == NULL)
		{
			cout << "memory overflow" << endl;
			return;
		}
		}*/
		
	tmp = head;
	length++;
		
	node->data = number;
	node->next = nullptr;
		
	if (index == 0)
	{
		node->next = head;
		head = node;
		return;
	}
	else if (index = length)
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
	
    void del(int number) 
    {
        if (head == nullptr) 
        {
            return;
        }

        if (head->key == key) //case if deleting head , changes head, and tail if needed
        {
                if (head->next == nullptr) 
                {
                    delete(head);
                    head = tail = nullptr;
                    return;		//check
                }
                struct node *tmp = head;
                head = head->next;
                delete(tmp);
                return;			////check
            }
        else 
        {
            struct node *tmp = head;
            struct node *prev = tmp;
                
            while (tmp->next != nullptr ) //check logic
            {
            	if tmp->key == number
                {
                	prev->next == tmp->next;
                	delete(temp);
                	return;
            	}
                prev = tmp;
                tmp = tmp->next;
        	}
            	
            if (tmp->key == number) //tmp should equal tail, check that
            {
            		tail = prev;
            		delete(tmp)
            }
        }
    }
		
	int pop(int index) 
	{
	/*		check if can ignore this case
	{
        if (head == nullptr) 
        {
        	cout << "empty list" << endl;
			return -1;
        }
	}
	*/
        if (index >= length)		//check logic
		{
			cout << "out of bounds of list" << endl;
			return -1;
		}
			
		struct Node *tmp = nullptr;
		struct Node *prev = tmp;
		int value;
		
		if (index == 0)
		{
			tmp = head;
			value = tmp->key;
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
			tail->next = nullptr;
			value = tmp->data;
			free(tmp);
			length--;
			return value;
		}
			
    }
		
	bool search(int key) 
	{
		if (head == nullptr) return false;
        if (head->key == key || tail->key == key) return true;
        
        struct node *current = head;
        
        while (current != tail) 
		{
        	if (current->key == key) return true;
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
            return tail->key;
        }
        
        struct node *tmp = head;
        
        for (int i = 0; i < index; i++)
		{
			tmp = tmp->next;
		}
		
    	return tmp->key;
    }
		
    void print_nodes(void) 
	{
        struct node *current = head;

        while (current != nullptr) 
		{
        	cout << current->key << '\n';
            current = current->next;
        }
    }
    
    void clear()
	{
		Node *tmp = head;
		Node *prev = tmp;
		while (tmp)
		{
			prev = tmp;
			tmp = tmp->next;
			free(prev);
		}
		head, tail = nullptr;
		length = 0;
	}
};
