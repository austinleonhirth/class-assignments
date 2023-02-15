#ifndef CMSC257_P2SUPPORT_INCLUDED
#define CMSC257_P2SUPPORT_INCLUDED

#define MAILBOX_SIZE 2000
#define ADDRESS_SIZE 50
#define SUBJECT_SIZE 200
#define BODY_SIZE 2000
#define NAME_SIZE 20
#define user_email "leonhirthag@vcu.edu"
//add other define Macros as needed

struct Email
{
  char sender[ADDRESS_SIZE];
  char receiver[ADDRESS_SIZE];
  char subject[SUBJECT_SIZE];
  char body[BODY_SIZE];
  struct date
  {
    int day;
    int month;
    int year;
  }sent_date;
  int ID;
};

struct Mailbox
{
  int size;
  struct Email *emails;
};

///////////////////////////////////////////////////////////////////////////////
// Function     : initialize
// Description  : Initializes the database for CMSC257 project #2 by manually 
//                entering the records using create_email function
// Inputs       : struct Mailbox *ib - pointer to the database
// Outputs      : void

void initialize(struct Mailbox *ib);


///////////////////////////////////////////////////////////////////////////////
// Function     : display_inbox_menu
// Description  : Displays a menu with options to the user
//                
// Inputs       : struct Mailbox *ib - pointer to the database
// Outputs      : void
void display_inbox_menu(struct Mailbox *ib);


///////////////////////////////////////////////////////////////////////////////
// Function     : create_email
// Description  : adds an email to the mailbox "emails" array
//                
// Inputs       : sender address, receiver address, subject, body, month, day, year, mailbox struct
// Outputs      : void
void create_email(char *sen, char *rec, char *sub, char *bod, int month, int day, int year, struct Mailbox *ib);


///////////////////////////////////////////////////////////////////////////////
// Function     : showInbox
// Description  : lists all emails in email array with formatted info
//                
// Inputs       : mailbox
// Outputs      : void
void showInbox(struct Mailbox *ib);


///////////////////////////////////////////////////////////////////////////////
// Function     : showEmailByID
// Description  : shows the contents of a specifc email based on ID
//                
// Inputs       : mailbox
// Outputs      : void
void showEmailByID(struct Mailbox *ib);


///////////////////////////////////////////////////////////////////////////////
// Function     : sortEmailBySender
// Description  : moves the elements of the emails array around according to 
//                alphabetial order
// Inputs       : mailbox
// Outputs      : void
void sortInboxBySender(struct Mailbox *ib);


///////////////////////////////////////////////////////////////////////////////
// Function     : sortEmailByID
// Description  : moves the elements of the emails array around according to 
//                numerical order (bubble sort)
// Inputs       : mailbox
// Outputs      : void
void sortInboxByID(struct Mailbox *ib);


///////////////////////////////////////////////////////////////////////////////
// Function     : searchInboxByKeyword
// Description  : prints out emails with occurances of keyword in the subject,
//                body, or sender.
// Inputs       : mailbox
// Outputs      : void
void searchInboxByKeyword(struct Mailbox *ib);

///////////////////////////////////////////////////////////////////////////////
// Function     : deleteEmail
// Description  : deletes an email with specific ID
//                
// Inputs       : mailbox
// Outputs      : void
void deleteEmail(struct Mailbox *ib);
#endif // CMSC257_P2SUPPORT_INCLUDED
