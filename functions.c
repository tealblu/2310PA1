/** Name: Charlie Hartsell
    Class: CPSC 2310
    Assignment: PA1
    Username: ckharts
*/

#include "functions.h"

// Function descriptions are in functions.h

void add(node_t **node, node_t **head) {
  // Create iterator
  node_t *it = *head;

  // Move iterator to end of list
  while(it->next != NULL) {
    it = it->next;
  }

  // Iterator is now pointing at the last node of the list
  it->next = node;
  it = it->next;
  it->next = NULL;
} // Done

node_t* readNodeInfo(FILE *input) {
  // Create empty node
  node_t* newNode = (node_t*)malloc(sizeof(node_t));

  // Read formatted data from file
  fscanf(input, "%[^,],%[^,],%i,%i,%i,%[^\n]\n", newNode->lastName, newNode->firstName,
    &newNode->bday.month, &newNode->bday.day, &newNode->bday.year,
    newNode->song);

  // Set next pointer to null
  newNode->next = NULL;

  if(checkDate(newNode->bday)) {
    return newNode;
  } else {
    // Date error.
    return NULL;
  }
} // Done

node_t* createList(FILE* input, node_t** head) {
  // Loop through the file
  while(feof(input)==0) {
    // Create temp node
    node_t* temp = readNodeInfo(input);
    // Add node to list
    if(temp!=NULL) {
      add(temp,head);
    }
  }
  return *head;
} // Done

void PrintList(FILE* output, node_t* head) {
  node_t* iterator = head;
  enum months mn;
  char* mnths[] = {"NotAMonth", "January", "Febuary", "March", "April", "May", "June",
    "July", "August", "September", "October", "November", "December"};

  // Formatting
  printBorder(output);
  fprintf(output,"LIST INFO:\n");

  // Loop through the list, printing node data
  while(iterator->next != NULL) {
    mn = iterator->bday.month;
    fprintf(output, "%s, %s, %s %i, %i, %s\n", iterator->lastName,
      iterator->firstName, mnths[mn], iterator->bday.day, iterator->bday.year,
      iterator->song);

    iterator = iterator->next;
  }

  // Final border
  printBorder(output);
} // Done

void PrintName(FILE* output, node_t* head) {
  node_t* iterator = head;

  // Formatting
  printBorder(output);
  fprintf(output,"All names:\n");

  // Loop through the list and print
  while(iterator->next != NULL) {
    fprintf(output, "%s, %s\n", iterator->lastName, iterator->firstName);
    iterator = iterator->next;
  }

  // Formatting
  printBorder(output);
} // Done

void PrintBDay(FILE* output, node_t* head) {
  node_t* iterator = head;
  //enum months mn;
  char* mnths[] = {"NotAMonth", "January", "Febuary", "March", "April", "May", "June",
    "July", "August", "September", "October", "November", "December"};

  // Formatting
  printBorder(output);
  fprintf(output,"Birthdays:\n");

  // Loop and print
  while(iterator->next != NULL) {
    fprintf(output, "%s %s's date of birth is %s %i, %i\n", iterator->firstName,
      iterator->lastName, mnths[iterator->bday.month], iterator->bday.day,
      iterator->bday.year);

    iterator = iterator->next;
  }
} // Done

void Song(FILE* output, node_t* head) {
  node_t* iterator = head;

  // Formatting
  printBorder(output);
  fprintf(output,"Favorite songs:\n");

  // Loop through the list and print
  while(iterator->next != NULL) {
    fprintf(output, "%s %s's favorite song is %s\n", iterator->firstName,
      iterator->lastName, iterator->song);

    iterator = iterator->next;
  }

  // Formatting
  printBorder(output);
} // Done

void printBorder(FILE* output) {
  // Kind of self explanatory
  fprintf(output,"\n");
  for(int i = 0; i < 80; i++) {
    fprintf(output,"*");
  }
  fprintf(output,"\n");
} // Done

void print(void (*fp)(FILE*, node_t*), FILE* output, node_t* head) {
  fp(output, head);
} // Done

void checkArgs(int arguments) {
  // Also self explanatory
  if(arguments != 3) {
    fprintf(stderr, "Please use 3 command line arguments!");
    exit(0);
  }
} // Done

void checkFile(FILE* fp, char* idk) {
  // Not gonna lie i have no idea what the char is for
  if(fp == NULL) {
    // File opened incorrectly
    fprintf(stderr, "File opened incorrectly!");
    exit(0);
  }
} // Done

void deleteList(node_t** head) {
  node_t** iterator = head;
  node_t** prev;

  // Loop through list and delete it
  while((*iterator)->next != NULL) {
    prev = iterator;
    iterator = &(*iterator)->next;
    free(*prev);
  }

  // Delete the final node
  free(*iterator);
} // Done

bool checkDate(bday_t bday) {
  bool day, month, year;

  // Check year
  if(bday.year >= 1900 && bday.year <= 2020) {
    // Year is between 1900 and 2020, valid
    year = 1;
  } else {
    // Year is not between 1900 and 2020, not valid
    year = 0;
    fprintf(stderr, "Year is not in bounds!");
  }

  // Check month
  if(bday.month <= 12) {
    month = 1;
  } else {
    month = 0;
    fprintf(stderr, "Month is not in bounds!");
  }

  // Check days
  if(bday.month==1||bday.month==3||bday.month==5||bday.month==7||bday.month==8||bday.month==10||bday.month==12) {
    // Month has 31 days
    if(bday.day > 31) {
      day = 0;
      fprintf(stderr, "Day is not in bounds!");
    } else {
      day = 1;
    }
  } else if(bday.month!=2) {
    // Month has 30 days
    if(bday.day > 30) {
      day = 0;
      fprintf(stderr, "Day is not in bounds!");
    } else {
      day = 1;
    }
  } else {
    // Month is february
    if(isLeapYear(bday.month)) {
      // Is leap year
      if(bday.day > 29) {
        day = 0;
        fprintf(stderr, "Day is not in bounds!");
      } else {
        day = 1;
      }
    } else {
      // Is not leap year
      if(bday.day > 28) {
        day = 0;
        fprintf(stderr, "Day is not in bounds!");
      } else {
        day = 1;
      }
    }
  }

  // Set up return DELETED CODE
  if(day==1 && month==1 && year==1) {
    // Everything checks out!
    return 1;
  } else {
    return 0;
  }
} // Done

bool isLeapYear(int year) {
  bool leap;

  if(year % 4 == 0) {
    if(year % 100 != 0) {
      // Year is divisible by 4 and NOT 100, leap
      leap = 1;
    } else if(year % 100 == 0 && year % 400 == 0) {
      // Year is divisible by 100 AND 400, leap
      leap = 1;
    } else {
      // Divisible by 100 NOT 400
      // Not a leap year.
      leap = 0;
    }
  } else {
    // Not divisible by 4, not a leap year
    leap = 0;
  }

  return leap;
} // Done
