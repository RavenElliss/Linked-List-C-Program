#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct list
{
    char gametitle[20];      
	struct list * next;     
	
}*start;

struct queue
{
	char gamename[20];             
	struct queue * next;            
	
}*head;

struct stack
{
	char gamenamesold[20];
	struct stack * next;
	
}*top;

void insert_at_head(struct list * newnode)
{
	start = newnode;         //start pointer will now be pointing to newnode
    newnode->next = NULL;    //the next link will now equal NULL 
	
}

void display()
{
	struct list * temp;      //creates a temporary pointer to the linked list
	printf("The list is currently\n");
	temp = start;            //allocates this pointer to start
	
	    do                   //moves the temp pointer through the linked list increasing its position each time to print the list.
	    {   
	     	printf("%s ->", temp->gametitle);
	    	temp=temp->next;
	    }
	    while(temp != NULL); //prints NULL to show the end of the linked list 
                                
	
	printf("NULL\n");
}

void insert_at_tail(struct list * newnode)
{
	struct list * current;
	struct list * prev;
	current=start;
	prev=start;
	
	    while(current != NULL)   //as current moves through the linked list its last position will be pointing to NULL, therefore prev is created so that it points to the last data value before NULL.
	    {
	    	prev=current;
	    	current=current->next;
     	}
	
	prev->next=newnode;
	newnode->next=NULL;     //newnode will now be the last node in the list
}


void delete_head()
{
    struct list * temp;  
	
	   if(start->next == NULL)  //if there is only one node in the list it will free this node only
	   {
	      free(start);
		  start=NULL;
       }
	   else
	   {
         temp = start;
         start = start->next;   //start keeps moves along to next node 
         free(temp);            //the OG node will be deleted
	   }
}

void delete_tail()
{
	struct list * temp;
	struct list * current;
	struct list * prev;
	
	current=start;
	prev=start;
	
	   if(start->next == NULL)   //if there is only one node in the list then this will be deleted 
	   {
	    	free(start);
	    	start=NULL;
	   }
	   else                     
	   {
	        while(current != NULL)       //will traver the list untill it current is pointing to NULL
	        {
	        	temp=prev;
        		prev=current;
        		current=current->next;
         	}
			                            //after it runs current will point to NULL then prev will point to last game then temp will point to the game before that
    free(prev);
	temp->next=NULL;
	}
}

void delete_element()
{
	char result[20];
	struct list * temp;
	struct list * ptr;
	struct list * prev;
	struct list * current;
	struct list * end;
	struct list * endptr;
	int count=1;
	int i=1;
	temp=start;
	current=start;
	ptr=start;
	prev=start;
	end=start;
	endptr=start;
	
	    while(end != NULL)         //allocates a pointer to the NULL value (end) in the linked list and the last nocde (endptr)
	    {
	    	endptr=end;
	    	end=end->next;
	    }
	
	printf("Enter the name of the game you wish to delete (cannot be 1st or last element must be in the middle)\n");
	scanf("%s", &result);
	
	
	    while(temp != NULL)
	    {
	        if(strcmp(result, temp->gametitle) == 0)   //compares what the user enters to check if it is in the list. 
		    {
		        printf("Found %s\n", temp->gametitle);
	      		break;
	     	}
		
		    else
		    {
	    		count++;               //if it doesnt find the name on that iteration count will increase by 1
			    temp=temp->next;       //temp moves to check the next node
		    }
	    }
	
	    if(temp->next != NULL)         //checks node has a nocde infront of it
        {
		
            if(count <= 2)            //this if function is if the game to be deleted is the 1st one after start pointer
			{
		        ptr=temp->next;       //ptr is going to be pointing to the next node after temp
			    free(temp);           //temp will be freed
				start->next=ptr;      //the next node after start will now be ptr.
	        }
			
			else
			{
			    	while(i < count-1)      //this while loops sets the pointer prev to point to the node before temp (game to be deleted)
				    {
				    	prev=prev->next;
				    	i++;           
				    }
				
			    ptr=temp->next;       //ptr now points to the node infront of temp
			    free(temp);          // temp is now freed
				prev->next=ptr;      //the previous pointer now links to ptr deleting temp from the list
			}
			
	    }
	
	
}




void enqueue()
{
	printf("Please enter the customer orders based on the current list. Please enter from 1st ordered to last\n");
	
	char result;
	do{
	    struct queue * newnode;
	    struct queue * current;
	    struct queue * prev;
	    newnode=(struct queue *)malloc(sizeof(struct queue));
	    printf("Enter the name of the game ordered\n");
	    scanf("%s", &newnode->gamename);
		
	    if(head == NULL)            //if the head is NULL then the newnode will be inserted at the start of the queue
	    {
	        head = newnode;
            newnode->next = NULL;
	    } 
	    else                       //if queue does not equal NULL then it will have to travse the list until it reaches the end to insert it does this by using prev and current pointers
	    {
	        current=head; 
	        prev=head;
	
	        while(current != NULL)
	        {
	        	prev=current;     // prev will be pointing to the last node while current will point to NULL
	        	current=current->next;
	        }
	
	        prev->next=newnode;   //therefore prev->next = newnode
	        newnode->next=NULL;
	    }
	
	
	    printf("Another order? Enter Y or N\n");
	    scanf("%s", &result);
	
	}while(result != 'n');
	
}

void printqueue()
{
	//this function is the same as display except it only prints the queue not the list 
	
	struct queue * temp;
	printf("The list of customer orders (queue) is:\n");
	temp = head;
	
	    do
	    {   
		    printf("%s ->", temp->gamename);
	     	temp=temp->next;
	    }
	    while(temp != NULL);

	
	printf("NULL\n");
	
}

void search()
{
	//this function will first compare the name of the game entered by the user to what games are stored in the linked list by using string compare.
	//if there is a match then it will use PUSH function in the if statement to push the game into the stack 
	
	struct stack * newnode;
	newnode=(struct stack *)malloc(sizeof(struct stack));
	struct queue * temp;
	struct list * ptr;
	temp=head;
	ptr=start;
	
	while(ptr != NULL)
	{
		if(strcmp(temp->gamename, ptr->gametitle) == 0)      //compares the name in the queue to the 1st name in the list
		{
		     printf("Found %s\n", ptr->gametitle);
		     strcpy(newnode->gamenamesold, ptr->gametitle);    //compies this value using string copy into the new node for the stack
		
		     printf("Now inserting %s from the customer order into the stack as it has been sold...\n", newnode->gamenamesold);
		         if(top == NULL)              //this is the PUSH function for the stack
		         {
		              top = newnode;
                      newnode->next = NULL;
		         }
		         else
		         {
                      newnode->next = top;
                      top = newnode;
		         }
		       
			    break;
	    }
		else
		{
			  ptr=ptr->next;
		}
	}
	
	
}

void printstack()
{
	//once again another print function that prints only the stack using temp pointer 
	
	struct stack * temp;
	printf("The list of stack is\n");
	temp = top;
	
	do
	{   
		printf("%s ->", temp->gamenamesold);
		temp=temp->next;
	}
	while(temp != NULL);

	
	printf("NULL\n");
}

void dequeue()
{
	//deletes elements from the queue from 1st to last
	 struct queue * temp;
	
	
	if(head->next == NULL)  //if there is only one element then will delete it
	{
		free(head);
		head=NULL;
	}
	else  //if there is more than one element will make a temp pointer to head, make head = the link to the next node then free the temp
	{
    temp = head;
    head = head->next;
    free(temp);
	}
	
}

int main()
{	
	char result;
	printf("Welcome to the program. Please start by entering games into the list.\n");
	
	    do{          //this do while loop is entering new nodes into the linked list
	        struct list * newnode;
	        newnode=(struct list *)malloc(sizeof(struct list));
	        printf("Enter the name of the game\n");
	        scanf("%s", &newnode->gametitle);
		
	           if(start == NULL)   
	           {
	               insert_at_head(newnode);
	           }
	           else
	           {
	              insert_at_tail(newnode);
	           }
	
	
	        printf("Another game? Enter Y or N\n");
	        scanf("%s", &result);
	
	    }while(result != 'n');         //will be scanning for the users input
	
	display();   //calling display function to show the contents of linked list
	
	printf("Would you like to delete from the head? Enter Y or N\n");
	scanf("%s", &result);
	
	        if(result == 'y')
	        {
		         delete_head();
		         display();
	        }
	        else
	        {}

    printf("Would you like to delete from the tail? Enter Y or N\n");
	scanf("%s", &result);
	
            if(result == 'y')
	        {
	            delete_tail();
	            display();
	        }
	        else
	        {}

    printf("Would you like to delete a specific element from the middle? Enter Y or N\n");
    scanf("%s", &result);
            if(result == 'y')
	        {
	           delete_element();
	           display();
	        }
	        else
	        {}

    enqueue();
	printqueue();
	
	printf("The program will now search for the 1st ordered game in the list\n");
	
	        do
	        {
	           search();
	
	           printstack();
	
	           dequeue();
               printqueue();
	        }while(head != NULL);
	
	return 0;
}