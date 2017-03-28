/**************************************************************************************************
********* Program Name *               Singly Linked List In C language                   *********
***************************************************************************************************
*********              *   A user friendly C Language linked List which guild the user    *********
*********   Purpose    *    every step of the way through prompts. Which lets a user      *********
*********   of the     *   to add more than one node(numbers) at a time  to a linked      *********
*********   Program    *   list. The user also has the options to Remove any node from    *********
*********              * the list reverse the list, as well as exit at any point in time. *********
***************************************************************************************************
*********  Written By  *       Charles Amarachukwu Anurukem(Royalty)                      *********
***************************************************************************************************
********* Last Updated *        Saturday, March 25, 2017 @ 5:11 PM                        *********
**************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void creat_node(int countSize);
void delete_node(int index);
void printList();
void reverse_list();
void menu();
void clear();
void addNumber(int countSize);
struct node
{
	int data;
	struct node *next;
};
static struct node *head = NULL;
void main(){
	bool doAgain = true;
	struct node *currentNode;
	int countSize,option,index;

	
	do{
		menu();
		printf("\nEnter option: ");
		scanf("%d",&option);
		switch (option) {
			case 1:
				printList();
				break;
			case 2:
				printf("\nHow many numbers do you want to add number: ");
				scanf("%d",&countSize);
				addNumber(countSize);
				break;
			case 3:
				printList();
				if(head == NULL)
					break;
				printf("\nEnter index: ");
				scanf("%d",&index);
				delete_node(index);
				break;
			case 4: 
				if(head == NULL)
					break;
				reverse_list();
				break;
			case 5:
				doAgain = false;
				break;
			default:
				printf(" Invalid Input ");
				break;
		}
		
		printf("\nPress enter key to %s...",(doAgain == true)?"continue":"exit");
		getch();
	}while(doAgain == true);
}
void menu(){
	printf("\n");
	printf("|---------------------------------|\n");
	printf("|  %-30s |\n","     Menu(Select option)");
	printf("|---------------------------------|\n");
	printf("| %-7s| %-23s|\n","Option","Action");
	printf("|---------------------------------|\n");
	printf("| %-7s| %-23s|\n","1","Show List");
	printf("|---------------------------------|\n");
	printf("| %-7s| %-23s|\n","2","Add To List");
	printf("|---------------------------------|\n");
	printf("| %-7s| %-23s|\n","3","Remove From List");
	printf("|---------------------------------|\n");
	printf("| %-7s| %-23s|\n","4","Reverse List");
	printf("|---------------------------------|\n");
	printf("| %-7s| %-23s|\n","5","Exit");
	printf("|---------------------------------|\n");
}
void printList(){
	if(head == NULL){
		printf("|---------------------------------|\n");
		printf("|  %-30s |\n","Empty: No Elements to display");
		printf("|---------------------------------|\n");
	}
	else{
		struct node *currentNode;
		currentNode = head;
		int counter=0;
		printf("|---------------------------------|\n");
		printf("| %-15s| %-15s|\n","Index","Element");
		printf("|---------------------------------|\n");
		while(currentNode!=NULL){
			printf("| %-15d| %-15d|\n",++counter,(currentNode->data));
			currentNode = currentNode->next;
			printf("|---------------------------------|\n");
			
		}
	}
	
}
void addNumber(int countSize){
	int number,i=1;
	for(; i<=countSize;i++){
		printf("%d. Enter number: ",i);
		scanf("%d",&number);
		creat_node(number);
	}
}
void creat_node(int number){
	struct node *newNode;
	newNode=(struct node *)malloc(sizeof(struct node));
	newNode->data=number;
	newNode->next=head;
	head=newNode;
	printf("|---------------------------------|\n");
	printf("|   %7d %-21s |\n",number,"added to list");
	printf("|---------------------------------|\n");
	
}
void reverse_list(){
	struct node *nextNode,*currentNode;
	currentNode = head;
	head = NULL;
	while(currentNode != NULL){
		nextNode = currentNode->next;
		currentNode->next = head;
		head = currentNode;
		currentNode = nextNode;
	}
	printf("|---------------------------------|\n");
	printf("|  %-30s |\n","      Reversal Complete ");
	printf("|---------------------------------|\n");
}
void delete_node(int index){
	int counter = 1,num;
	struct node *currentNode,*temp;
	currentNode = head;
	while(currentNode!=NULL){
		if(counter++ == index){
			num = currentNode->data;
			currentNode->data = currentNode->next->data;
			temp = currentNode->next;
			currentNode->next = currentNode->next->next;
			free(temp);
			printf("|---------------------------------|\n");
			printf("|  %6d %-23s |\n",num,"deleted successfully");
			printf("|---------------------------------|\n");
			break;
		}
		currentNode=currentNode->next;
	}
	if(currentNode == NULL){
		printf("|---------------------------------|\n");
		printf("|  %-30s |\n","Index does not exit");
		printf("|---------------------------------|\n");
	}

}
