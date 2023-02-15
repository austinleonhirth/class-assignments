///////////////////////////////////////////////
//Add program description, author name, last edit date as in project1




//Add necessary include statements (I added for you!)
#include "p2-support.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/////////////////////////////////////////////
// Function Definitions
// //////////////////////////////////////////

void initialize(struct Mailbox *ib)
{
  //allocate memory for 2000 emails
  ib->emails = malloc(sizeof(struct Email) * MAILBOX_SIZE);
  ib->size = 0;

  create_email("asonmez@mail.com", user_email, "Welcome to your inbox.",
    "Welcome to your inbox, just wanted to say hi. Here's hoping you get all your code done.",
    11, 20, 2020, ib);
  create_email("mmartinez@mail.com", user_email, "Padding out your inbox.",
    "Yet another email just to pad out your inbox, have fun!",
    11, 30, 2020, ib);
  create_email("dboyle@mail.com", user_email, "3rd email!",
    "Alright, time for another email for your inbox. Not going too lie, it's a bit of a pain coming up with stuff for these strings. Anyways, have fun with your code!",
    12, 2, 2020, ib);
  create_email("cbluer@mail.com", user_email, "4th email!",
    "Content of fourth email. More coding, more fun!",
    12, 8, 2020, ib);
  create_email("cboyle@mail.com", user_email, "5th email!",
    "Content of fifth email. Coding is fun-tastic!",
    12, 18, 2020, ib);
  create_email("sblack@mail.com", user_email, "6th email!",
    "Content of sixth email. Coding is fun-tastic!",
    1, 1, 2021, ib);
  create_email("sblack@mail.com", user_email, "7th email!",
    "Body of seventh email. Coding is fun-tastic!",
    1, 5, 2021, ib);
  create_email("sblack@mail.com", user_email, "8th email!",
    "Body of eighth email. Coding is fun-tastic!",
    2, 15, 2021, ib);
  create_email("sblack@mail.com", user_email, "9th email!",
    "Body of ninth email. Coding is fun-tastic!",
    2, 25, 2021, ib);
  create_email("dboyle@mail.com", user_email, "Last email!",
    "Body of tenth email. Coding is fun-tastic!",
    3, 15, 2021, ib);
}

//Other function definitions go below

void display_inbox_menu(struct Mailbox *ib){
  printf("*************** %10s ***************\n", user_email);
  printf("**************** Total Inbox: %04d ****************\n", ib->size);
  printf("1. Show inbox\n2. Show Email by ID\n3. Sort Inbox by sender\n4. Sort Inbox by ID\n5. Search Inbox by keyword\n6. Delete\n7. Exit inbox\n");
  
  int input;
  printf("Make Selection: ");
  scanf("%d",&input);

  switch(input){
    case 1:
      showInbox(ib);
      break;
    case 2:
      showEmailByID(ib);
      break;
    case 3:
      sortInboxBySender(ib);
      break;
    case 4:
      sortInboxByID(ib);
      break;
    case 5:
      searchInboxByKeyword(ib);
      break;
    case 6:
      deleteEmail(ib);
      break;
    case 7:
      printf("\nExiting, Goodbye.\n");
      break;
  }
}

void create_email(char *sen, char *rec, char *sub, char *bod, int month, int day, int year, struct Mailbox *ib){
  strcpy(ib->emails[ib->size].sender,sen);
  strcpy(ib->emails[ib->size].receiver,rec);
  strcpy(ib->emails[ib->size].subject,sub);
  strcpy(ib->emails[ib->size].body,bod);
  ib->emails[ib->size].sent_date.day = day;
  ib->emails[ib->size].sent_date.month = month;
  ib->emails[ib->size].sent_date.year = year;
  ib->emails[ib->size].ID = ib->size;

  ib->size = ib->size+1;
}


void showInbox(struct Mailbox *ib){
  printf("\nID   SENDER--------------   MM/DD/YYYY   SUBJECT--------\n");
  printf(  "--   --------------------   --/--/----   ---------------\n");
  int x;
  for(x=0; x<ib->size;x++){
    struct Email current = ib->emails[x];
    printf("%02d - %-20.20s - %02d/%02d/%04d - %-15.15s\n", current.ID, current.sender, current.sent_date.month, current.sent_date.day, current.sent_date.year,current.subject);
  }
  display_inbox_menu(ib);
}



void showEmailByID(struct Mailbox *ib){
//get input
  int index;
  printf("Enter Email ID: ");
  scanf("%d",&index);
  if(index>ib->size || index<0){
    printf("Invalid ID");
    return;
  }

//get correct current
  struct Email current;
  int c;
  for(c = 0; c < ib->size; c++){
    if(ib->emails[c].ID==index){
      current = ib->emails[c];
    }
  }

//print
  printf("\n%-s - %-s\n", current.sender ,current.subject);
  printf("Email recieved on: %02d/%02d/%04d\n", current.sent_date.month, current.sent_date.day, current.sent_date.year);
  printf("%s\n\n",current.body);
  display_inbox_menu(ib);
}




void sortInboxBySender(struct Mailbox *ib){
struct Email temp;
int i,j;
for(i=0;i<ib->size-1;i++)
   {
     for(j=i+1;j<ib->size;j++)
     {
       if(strcmp(ib->emails[i].sender,ib->emails[j].sender)>0)
       {
        temp = ib->emails[i];
        ib->emails[i]=ib->emails[j];
        ib->emails[j]=temp;
       }
     }
   }
   display_inbox_menu(ib);
}




void sortInboxByID(struct Mailbox *ib){
struct Email temp;
int i,j;
for (i = 0; i < ib->size - 1; i++)
        for (j = 0; j < ib->size - i - 1; j++)
            if (ib->emails[j].ID > ib->emails[j+1].ID )
            {
              temp = ib->emails[j];
              ib->emails[j]=ib->emails[j+1];
              ib->emails[j+1]=temp;
            }
   display_inbox_menu(ib);
}



void searchInboxByKeyword(struct Mailbox *ib){
  char keyword[20];
  printf("Enter keyword: ");
  scanf("%s",&keyword);

  struct Email e;
  int x;
  printf("-----Search Results for \"%s\"-----\n",keyword);
  for(x = 0; x < ib->size; x++){
    e = ib->emails[x];
    if(strstr(e.sender,keyword) != NULL)
          printf("%02d - %-20.20s - %02d/%02d/%04d - %-15.15s\n", e.ID, e.sender, e.sent_date.month, e.sent_date.day, e.sent_date.year,e.subject);
    else if(strstr(e.subject,keyword) != NULL)
          printf("%02d - %-20.20s - %02d/%02d/%04d - %-15.15s\n", e.ID, e.sender, e.sent_date.month, e.sent_date.day, e.sent_date.year,e.subject);
    else if(strstr(e.body,keyword) != NULL)
          printf("%02d - %-20.20s - %02d/%02d/%04d - %-15.15s\n", e.ID, e.sender, e.sent_date.month, e.sent_date.day, e.sent_date.year,e.subject);
  }
}


void deleteEmail(struct Mailbox *ib){
//get input
int index;
printf("Enter Email ID: ");
scanf("%d",&index);

//check for valid ID
int x;
struct Email e;
bool cont = false;
for(x = 0; x < ib->size;x++){
  e = ib->emails[x];
  if(e.ID==index){
    cont = true;
    break;
  }
}
if(!cont){
  printf("\nEmail does not exist with given ID\n");
  return;
}

//delete
int i;
for(i = x+1; i<ib->size-1;i++){
  ib->emails[i-1]=ib->emails[i];
}
ib->size=ib->size-1;
display_inbox_menu(ib);
}