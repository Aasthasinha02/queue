#include <stdio.h>

#define MAX_CAPACITY 3 //maximum capacity of the array is 3

// Global stack variables
int queueArray[MAX_CAPACITY];  // queue Array
int head = 0;                 //head is an index from which value will be dequeued 
int tail = 0;                //tail is an index in which value will be enqueued
int totalValues = 0;     // Total nummber of values in queue

//----------------------------------------------------------------
// Name: enqueue
// Description: This function inserts "value" into the queue
// Parameters value: Value to insert in queue
// Return: Nothing
//-----------------------------------------------------------------
void enqueue(int value)
{ 
    
    if(tail==MAX_CAPACITY)
    {
        if(head=!0)
        {
            tail=0;
        }
        else
        {
            printf("queue is full\n");
            return -1;
        }
    }
    queueArray[tail]=value;
    totalValues++;
    tail++;
    
}

//----------------------------------------------------------------
// Name: dequeue
// Description: This function returns value at queue
// Parameters 
// Return: Value at head(integer)
//-----------------------------------------------------------------
int dequeue(void)
{
    if(totalValues==0)
    {
        printf("list is empty!\n");
        return -1;
    }
    int dequeuevalue=0;
    dequeuevalue=queueArray[head];
    head++;
    totalValues--;
    return dequeuevalue;
}

void display()
{
    int printed = 0; 
    
    printf("head: %d, tail: %d, totalValues: %d\n", head, tail, totalValues);
    int i = head;
    
    while (printed < totalValues)
    {
        if (i == MAX_CAPACITY)
        {
            i = 0;
        }
        
        printf("%d ", queueArray[i]);
        i++;
        printed++;
    }
   
    printf("\n");
}

// Main function to test enqueue and dequeue functions
int main()
{
	
	//int inputArray[] = {5, 10, 2, 30, 50, 7, 1, 0, 45};
	int inputArray[] = {5, 10};
	
	int numValues = sizeof(inputArray)/ sizeof(inputArray[0]);

	
    for (int i = 0; i < numValues; i++)
    {
        enqueue(inputArray[i]);
    }
    
    printf("\nQueue:\n");
	display();
   
    int dequeuevalue = 0;
    dequeuevalue = dequeue();
    printf("dequeue value: %d\n", dequeuevalue);
    
    printf("\nQueue:\n");
	display();
    
    printf("enqueue 15\n");
    enqueue(15);
	printf("\nQueue:\n");
	display();

    dequeuevalue = dequeue();
    printf("dequeue value: %d\n", dequeuevalue);
    
     return 0;
}