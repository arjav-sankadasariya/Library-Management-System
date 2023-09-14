#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

struct book *BookHead = NULL;
struct student *StudHead = NULL;

struct book{
    char name[10];
    char author[10];
    int id;
    struct book *next;
};

struct student{
    char name[15];
    char email[20];
    char book[10];
    char a[10];
    int id;
    struct student *next;
};
//////////////////////////////////////////////////////////////////
int add_new()
{

    // making a new book node to add book 
    struct book* temp=(struct book*)malloc(sizeof(struct book));
    printf("\n\t\t\t-----> Enter book details <----- ");
    printf("\n\t\t\t\t     Book Title: ");
    gets(temp->name);
    fflush(stdin);
    printf("\n\t\t\t\t     Author: ");
    gets(temp->author);
    fflush(stdin);
    printf("\n\t\t\t\t     Book ID: ");
    scanf("%d",&temp->id);
    fflush(stdin);
    
    // adding node to list 
    if(BookHead == NULL)
    {
        BookHead = temp;
        temp->next = NULL;
    }   
    else 
    {
        struct book *ptr = BookHead; 
        while(ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = temp; 
        temp->next = NULL;
    }
    printf("\n\n\t\t\t-----> Book Added to Library Data <-----");
}
////////////////////////////////////////////////////////
int ListBook()
{
    if(BookHead == NULL) printf("\n\t\t\t           -----> NO BOOK IN LIBRARY <-----");
    else 
    {
        struct book *ptr  = BookHead;
        printf("\n\t\t\t*************************************************\n");
        printf("\n\t\t\t           -----> BOOK LIST <-----\n");
        printf("\n\t\t\t*************************************************\n\n");
        int i=1;
        while(ptr != NULL)
        { 
            printf("\n\t\t\t_____________________________________________\n");
            printf("\n\t\t\t Book %d",i++);
            printf("\n\t\t\t\t Book Title: %s",ptr->name);
            printf("\n\t\t\t\t Author: %s",ptr->author);
            printf("\n\t\t\t\t Book ID: %d",ptr->id);
            printf("\n\t\t\t_____________________________________________\n\n");
            ptr = ptr->next;
        }
    }
    return 0;
}
///////////////////////////////////////////////////////////////
void IssueBook()
{
    ListBook();
    int bookId;
    printf("\n\t\t\t Enter book Id : ");
    scanf("%d",&bookId);

    
    struct book *ptr = BookHead;
    struct book *previ = NULL;
    while(ptr->id != bookId)
    {
        previ = ptr;
        ptr=ptr->next;
    }

    // making new student node = temp
    struct student* temp=(struct student*)malloc(sizeof(struct student));
    printf("\n\t\t\t -----> Enter Student Details <-----\n ");
    printf("\n\t\t\t\t Enter your Name: ");
    fflush(stdin);
    scanf("%s",&temp->name);
    fflush(stdin);
    printf("\n\t\t\t\t Enter your Email: ");
    fflush(stdin);
    scanf("%s",&temp->email);
    fflush(stdin);
    strcpy(temp->book,ptr->name);
    strcpy(temp->a,ptr->author);
    temp->id = bookId;
    temp->next = NULL;
    
    // adding created new student node to student list 
    if(StudHead == NULL)
        StudHead = temp;
    else 
    {
        struct student *ptrr = StudHead;
        while(ptrr->next != NULL)
            ptrr= ptrr->next;
        ptrr->next = temp;
    }
    
    printf("\n\t\t\t\t Issue of Book ID %d done successfully!\n",bookId);
    printf("\n\n\t\t\t*************************************************\n");

    // removing book from the list 
    if(ptr->next == NULL) previ->next = NULL;
    else if(ptr == BookHead) BookHead = ptr->next;
    else previ->next = ptr->next;

}
//////////////////////////////////////////////////////////
void BookReturn()
{
    int bookId;
    printf("\t\t\t Enter book Id : ");
    scanf("%d",&bookId);

    //removing student from the list 
    struct student *ptr = StudHead;
    struct student *previ = StudHead;
    while(ptr->id != bookId)
    {
        previ = ptr;
        ptr = ptr->next;
    }
    if(ptr == StudHead) StudHead = ptr->next;
    else if(ptr->next == NULL) previ->next = NULL;
    else previ->next = ptr->next;

    printf("\n\t\t\t_________________________________________________\n");
    printf("\n\t\t\t\t     Student Name: %s",ptr->name);
    printf("\n\t\t\t\t     Student Email: %s",ptr->email);
    printf("\n\t\t\t\t     Name of Book Issued: %s",ptr->book);
    printf("\n\t\t\t\t     Book ID: %d",ptr->id);
    printf("\n\t\t\t_________________________________________________\n\n");

    // creating new book node to add book back to library
    struct book* temp=(struct book*)malloc(sizeof(struct book));
    strcpy(temp->name,ptr->book);
    strcpy(temp->author,ptr->a);
    temp->id = ptr->id;
    temp->next = NULL;
    // Adding book back to library 
    struct book *ptrr = BookHead;
    if(BookHead == NULL) BookHead = temp;
    else 
    {
        while(ptrr->next != NULL)
            ptrr = ptrr->next;
        ptrr->next = temp;
    }
    printf("\n\t\t\t\tBook with ID %d returned successfully!\n",ptr->id);
    printf("\n\n\t\t\t*************************************************\n");
}
////////////////////////////////////////////////////////
void display()
{
    if(StudHead == NULL) printf("\n\t\t\t           -----> NO STUDENT IN THE LIST <-----");
    else 
    {
        struct student *ptr  = StudHead;
        printf("\n\t\t\t*************************************************\n");
        printf("\n\t\t\t           -----> STUDENT LIST <-----");
        printf("\n\t\t\t*************************************************\n\n");
        while(ptr != NULL)
        {
            printf("\n\t\t\t_________________________________________________\n");
            printf("\n\t\t\t\t     Student Name: %s",ptr->name);
            printf("\n\t\t\t\t     Student Email: %s",ptr->email);
            printf("\n\t\t\t\t     Name of Book Issued: %s",ptr->book);
            printf("\n\t\t\t\t     Book ID: %d",ptr->id);
            printf("\n\t\t\t_________________________________________________\n\n");
            ptr = ptr->next;
        }
    }
}


int main(){
    
    printf("\n\t\t\t*************************************************\n");
    printf("\n\t\t\t                * LIBRARY *\n");
    int choice;
    do{
        printf("\n\n");
        printf("\n\t\t\t*************************************************\n");
        printf("\n\t\t\t\t      MAIN MENU: ");
        printf("\n\t\t\t\t     1.ADD A NEW BOOK TO LIBRARY");
        printf("\n\t\t\t\t     2.ISSUE A BOOKS ");
        printf("\n\t\t\t\t     3.RETURN A BOOK ");
        printf("\n\t\t\t\t     4.DISPLAY STUDENT DETAILS ");
        printf("\n\t\t\t\t     5.LIST OF BOOKS ");
        printf("\n\t\t\t\t     0.EXIT\n ");
        printf("\n\t\t\t*************************************************\n");
        printf("\n\t\t\t\t      Enter your choice: ");
        
        scanf("%d",&choice);
        fflush(stdin);
        switch(choice){
            case 1:{
                add_new();
                break;
            }
            case 2:{
                IssueBook();
                break;
            }
            case 3:{
                BookReturn();
                break;
            }
            case 4:{
                display();
                break;
            }
            case 5:{
                ListBook();
                break;
            }
            case 0:{
                exit(1);
            }
            default:{
                printf("\n\t\t\t\t    Invalid Option! Try again\n");
                
            }
        }
    }while(choice!=0);
    return 0;
}