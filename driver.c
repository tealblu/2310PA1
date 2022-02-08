/** Name: Charlie Hartsell
    Class: CPSC 2310
    Assignment: PA1
    Username: ckharts
*/

#include "functions.h"

int main(int argc, char* argv[]) {
  // Check arguments before continuing
  checkArgs(argc);

  // Char pointer to reconcile function headers?
  char* charPointer = NULL;

  // Open input file
  FILE* input;
  input = fopen(argv[1], "r");
  checkFile(input, charPointer);

  // Open output file
  FILE* output;
  output = fopen(argv[2], "w");
  checkFile(output, charPointer);

  // Create the list
  node_t* head = (node_t*)malloc(sizeof(node_t));
  head = createList(input, &head);

  // create function pointer
  void (*fp)(FILE*, node_t*);

  // print list
  fp = &PrintList;
  print(fp, output, head);

  // name
  fp = &PrintName;
  print(fp, output, head);

  // bday
  fp = &PrintBDay;
  print(fp, output, head);

  // song
  fp = &Song;
  print(fp, output, head);

  // delete list
  deleteList(&head);
  
  return 0;
}
