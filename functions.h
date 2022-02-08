/** Name: Charlie Hartsell
    Class: CPSC 2310
    Assignment: PA1
    Username: ckharts
*/

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

// Header file includes
#include <stdio.h>
#include <stdbool.h> // She made us use bool, which isn't a type in C
#include <stdlib.h>

// Birthday struct
typedef struct bday {
  int month;
  int day;
  int year;
} bday_t;

// Node struct
typedef struct node {
  // Using character pointers so we can dynamically allocate memory
  char firstName[15];
  char lastName[15];
  bday_t bday;
  char song[50];
  struct node *next;
} node_t;

// NotAMonth defined to resolve numbering issue
enum months{NotAMonth, January, Febuary, March, April, May, June, July, August,
              October, November, December};

/*
Parameters: Pointer to the node to add, pointer to head node
Return: void
This function adds a node to the linked list */
void add(node_t **node, node_t **head); // DONE

/*
Parameters: Pointer to input file
Return: A node containing data from the file
This function reads data from the input file
one node at a time, allocating memory and storing
the data. Used by createList. */
node_t* readNodeInfo(FILE *input); // DONE

/*
Parameters: Pointer to the input file, pointer to what i assume is the head node
Return: Pointer to the head node
Starts the process of creating the list. Uses a loop
to read each record in the file and add it to the list. */
node_t* createList(FILE*, node_t**); // DONE

/*
Parameters: Output file pointer, pointer to head node
Return: void
Prints data from the list to the output file */
void PrintList(FILE*, node_t*); // DONE

/*
Parameters: output file pointer, head node pointer
Return: void
Prints only the name from each node to the output file */
void PrintName(FILE*, node_t*); // DONE

/*
Parameters: output file pointer, head node pointer
Return: void
Prints birthdays to output file */
void PrintBDay(FILE*, node_t*); // Done

/*
Parameters: output file pointer, head node pointer
Return: void
Prints first and last names and songs to output file */
void Song(FILE*, node_t*); // DONE

/*
No parameters, no return. Prints 80 asterisks. */
void printBorder(FILE* output); // DONE

/*
Parameters: function pointer, output file pointer, head node pointer
Return: void
Function used to call the print functions listed above */
void print(void (*fp)(FILE*, node_t*), FILE*, node_t*); // DONE

/*
Parameters: int containing number of command line arguments
Return: void
Makes sure the correct number of command line arguments are used */
void checkArgs(int); // DONE

/*
Parameters: File pointer, character pointer
Return: void
Makes sure the file opens correctly */
void checkFile(FILE*, char*); // DONE

/*
Parameters: Pointer to head
Return: void
Deletes a node in the list */
void deleteList(node_t** ); // DONE

/*
Parameters: One birthday
Return: Boolean
Checks the validity of a birthday */
bool checkDate(bday_t); // DONE

/*
Parameters: Int containing the year
Return: boolean
Checks to see if the given year is a leap year */
bool isLeapYear(int); // DONE

#endif
