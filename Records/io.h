#ifndef IO_H
#define IO_H 
#include "sort.h"
#include <stdio.h> 
#include <stdlib.h> 
#include <ctype.h> 
#include <string.h> 
#define NAMESIZE 20 

typedef struct {
	char last[NAMESIZE];
	char first[NAMESIZE];
} name;

typedef struct {
	name name; 
	int score;
} record;

typedef struct {
	record **data;
	size_t nalloc;
	size_t nused; 
} record_list;

/*makes all elements of a char array lower case */
void to_lower(char a[]);
/* handles the input */
int handle_input(char *line, char *fname, char *lname, int *score);
/*frees each element in the dynamic array*/
void free_mem(record_list list);
/* prints all records that are currently stored*/
void print_records(record_list list);
/*Handles the optional sorting flags .*/
void flag_handle(int argc, char * argv[], char *srt_ordr, char *srt_ordr2);
/* populates the flag array for comparision */
void populate_sort_array(char **sort_order);
/*matches a flag to an index in the flag sorting array */
int flag_match(char **sort_order, char *argv);
/*For concatenating numbers.*/
unsigned concatenate(unsigned x, unsigned y);
/*Finds index of two flags. */
unsigned two_flag(unsigned match, char **sort_order, char **argv);
/*Switch statement to call qsort function based on two flags.*/
int two_args_switch(unsigned match, record_list list);
/* switch statement to call qsort based on one */
int one_arg_switch(int flag_one, record_list list);


#endif
