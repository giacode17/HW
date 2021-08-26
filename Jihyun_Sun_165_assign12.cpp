#include <iostream>
using namespace std;

const int (SIZE) = 7;
struct LinkedList
{
	int value;
	LinkedList* next;

};

int get_the_fisrt_value();
int get_new_node_value();
void traverse_list(LinkedList* &head);
int search_node (LinkedList* &head, int num);
void append_node(int value, LinkedList* new_node, LinkedList* ptr);
void insertion_node(LinkedList** head);//, LinkedList *new_node);
void delete_node(LinkedList* &head, int index);
void destroy_list (LinkedList* &head);


int main()
{
    
    LinkedList* head = nullptr;
    LinkedList* new_node = nullptr;
	
    int first_num = get_the_fisrt_value();
    int add_num = get_new_node_value();
    int num;

    
    new_node = new LinkedList;
    new_node->value = first_num;
    new_node->next = nullptr;
    new_node->next = head;
    head = new_node; 
    //C1.Now both head and new_node point at the dynamically allocated LinkedList.
    
    insertion_node(&head);//, new_node);

    cout << "Here are the initial values in the linked list. \n";
    traverse_list(head);

    /*
    cout << "Enter the number of the node that"
         << "you want to delete from the linked list. \n";
    cin >> num;

    int del_idx = search_node(head, num);
    delete_node(head, del_idx);

    cout << "Here is the updated linked list. \n";
    traverse_list(head);

    cout << "Enter the number that you want to search for in the list: \n\n";
    cin >> num;
    int search_idx = search_node(head, num);
    cout << "Number found at index "
         << search_idx << " in the linked list \n";

    */
    
    return 0; 
    
}

int get_the_fisrt_value()
{
    int num;
    do
    {
        cout << "Enter the number of initial nodes (must be at least 1): \n" ;
        cin >> num;
    }while( num < 1);
    
    return num;
}
int get_new_node_value()
{
    int num;
    cout << "Enter a number \n";
    cin >> num;
    return num;

}

void traverse_list(LinkedList* &head)
{
    cout << "Traversing list \n\n";
    LinkedList* ptr = head;

    while (ptr != nullptr)
	{
        cout << ptr->value << endl;
		// C2.This traverse the list by following the next pointers.
		ptr = ptr->next;
    }
    
}

//C3.Searches the list for a value.
int search_node (LinkedList* &head, int num)
{
    LinkedList* ptr =  head;
    int idx = 0;
    while(ptr!= nullptr)
    {
        idx++;
        if(ptr->value == num)
            return idx;
        ptr = ptr->next;
    }
    return -1;

    /*for (int i = 0; i < SIZE; i++)
    {
        if(ptr->value == num)
            return i;
        ptr = ptr -> next;
    }
    return -1;*/
    delete ptr;
    ptr = nullptr;
}

//C4.append node end of list.
void append_node(int value, LinkedList* new_node, LinkedList* ptr)
{
    cout << "here\n"; 
    //new_node = new LinkedList;
    new_node->value = value;
    new_node->next = nullptr;
    ptr->next = new_node;// C5.connect previous node
    
}

// void insertion_node()//(LinkedList* & head, LinkedList *node)
void insertion_node(LinkedList** head)//, LinkedList *new_node)
{
    LinkedList* temp = *head;
    struct LinkedList* new_node = new LinkedList;

    for (int i = 1; i < SIZE-1; i++)
    {
        int num = get_new_node_value();
        
        for (int j = 0; 
            temp->next->value < num && temp->next != nullptr; 
            j++, temp = temp->next)
        {
            if (j != SIZE - 1)
            {
                
                new_node->value = num;
                new_node->next = temp->next;
                temp->next = new_node;
            }
            else
            {
                append_node(num, new_node, temp);
            }            
        }
            
    }
    
	return;    
}

//c6.Deletes a node form the sepecipic location
void delete_node(LinkedList* &head, int index)
{
        LinkedList* ptr = head;
        LinkedList* ptr2 = nullptr;

        //c7case 1: list is already empty
        if (head == nullptr)
            cout << "The list is already empty!!!\n\n";

        // c8case 2: node to be deleted is the head node
        else if (head->next == nullptr || index <= 0)
        {
            head = head->next;
            delete ptr; //ptr = head
        }

        else
        {
            for (int i = 0; i < (index - 1) && ptr->next->next != nullptr; i++, ptr = ptr->next);
            //c9.Now we moved to ptr->next : the point to be deleted,
            ptr2 = ptr->next; // make ptr2 point at the node
                        
            ptr->next = ptr2->next; //connect the next, the next node of the node tobe deleted 

        }
        
        delete ptr2; // c10.ptr2 point the node to deleted.
        ptr2 = nullptr;  //c11.Make ptr2 point at nullptr to avoid a dangling pointer.

}


//c12.At the end the program, destroys the liste by using th delete statment on each dynmiclly allocated linekd list(to avoid memory leak)
void destroy_list (LinkedList* &head)
{
    LinkedList* ptr =  head;
    LinkedList* ptr2 = ptr;

        while (ptr != nullptr)
        {
            ptr2 = ptr2->next;
            delete ptr;
            ptr = ptr2;
        }

        head = nullptr;
}



