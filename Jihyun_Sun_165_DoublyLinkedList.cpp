#include <iostream>
using namespace std;
  
const int (SIZE) = 8;
struct LinkedList 
{
   int value;
   struct LinkedList* next;
   struct LinkedList* prev;
};


void insert(struct LinkedList** head, struct LinkedList** tail, int new_valu);
void append_node(struct LinkedList** head, struct LinkedList** tail, int new_valu);
void displayList(struct LinkedList* node);
void deleteall(struct LinkedList** head, struct LinkedList** tail);


int main() 
{
   struct LinkedList* head = nullptr;
   struct LinkedList* tail = nullptr;
   int choice, value;
   do
   {
      // c1.Display the opreation.
      cout << "\n1. Insert number\n";
      cout << "2. Delete number\n";
      cout << "3. View\n";


      cout << "Enter your choice (1-3): ";
      cin >> choice;
      
      // c2.Validate loop of the selection.
      while (choice < 1 || choice > 3)
      {
         cout << "ERROR. Enter 1, 2, or 3: ";
         cin >> choice;
      }
   
      
      cin.get();
      switch (choice)
      {
         
         case 1: 
            cout << "\nEnter Number."; 
            cin >> value;
            insert(&head, &tail, value);
            break;
         case 2: 
            cout << "\nEnter Number."; 
            cin >> value;
            //delete(&head, &tail, value);
            break;
         case 3: 
            displayList(head);
            break;
         default:
         cout<<"wrong choice";
      }      
     
   } while (choice != 3);

   deleteall(&head, &tail);
   cout << "Delete all\n";
   displayList(head);
   

   return 0;
}



void insert(
      //c3. We need head, tail nodes basically.
      struct LinkedList** head, 
      struct LinkedList** tail, 
      int new_value)
{
   LinkedList* new_node = new LinkedList;
   new_node->value = new_value;

   if ((*head) == nullptr)
   {
      new_node->next = new_node->prev = nullptr;
      (*head) = new_node;
      (*tail) = new_node;      
   }
   else if ((*head)->value >= new_value)
   {
      new_node->next = (*head);
      (*head)->prev = new_node;
      (*head) = new_node;
   }
   else
   {
      LinkedList *ptr = *head;
      while (ptr && ptr->value <= new_value )
      {
         ptr = ptr->next;

      }
      
      if (ptr)
      {
         new_node->next = ptr;
         new_node->prev = ptr->prev;         
         ptr->prev->next = new_node;    
         ptr->prev = new_node;    
      }
      else
      {
         append_node(head, tail, new_value);
      }
   }
}
  

//c5.insert a new node at the end of the list
void append_node(struct LinkedList** head, struct LinkedList** tail, int new_value)
{
   //c6.Allocate memory for node
   LinkedList* new_node = new LinkedList;
  
   new_node->value = new_value;
   new_node->next = nullptr;
  
   while ((*tail)->next != nullptr)
      (*tail) = (*tail)->next;

   (*tail)->next = new_node;
   new_node->prev = (*tail);
   
   return;
}
  
void deleteall(struct LinkedList** head, struct LinkedList** tail)
{
   LinkedList *ptr = *head;
   LinkedList *curr = nullptr;

   while(ptr)
   {
      curr = ptr;
      ptr = ptr->next;
      delete curr;
   }   

   *head = nullptr;
   *tail = nullptr;
}

//c7 This function prints the list
void displayList(struct LinkedList* node) 
{
 
   bool firstTime = true;
   while (node != nullptr) {
      if (!firstTime)
      {
         cout << "<==>";
      }
      else
      {
         firstTime = false;
      }
      
      cout<<node->value;
      node = node->next;
   }
   if(node == nullptr)
      cout<<endl;
}
  


