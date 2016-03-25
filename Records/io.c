#include <stdio.h>
#include "io.h"
 
#define TMPSORT 2
#define NAMESIZE 20 
#define LINESIZE 256 
#ifndef BLOCK
	#define BLOCK 2
#endif
					
					
int main(int argc, char* argv[]) {
	record_list list;
	char line[LINESIZE];
	char fname[NAMESIZE];
	char lname[NAMESIZE];
	char srt_ordr[TMPSORT];
	char srt_ordr2[TMPSORT];
	int score;
	char *sort_order[8];
	unsigned int match = -1;
	
	score = 0; 
	list.data = 0; 
	list.nalloc = list.nused = 0;


	populate_sort_array(sort_order);
	
	if(argc > 3) {
		fprintf(stderr, "Usage: %s has two optional flags, -/+n and/or -/+s.\n"
			     , argv[0]);
		exit(1);
	}
	
	if(argc > 1) {
		flag_handle(argc, argv, srt_ordr, srt_ordr2);
	}
	
	while(fgets(line, LINESIZE, stdin) != 0) {
		
		int input = handle_input(line, fname, lname, &score);
		

		if (input != 1) {
			continue;
		}

		if(list.nused == list.nalloc) {
			record **tmp = realloc(list.data, 
								(list.nalloc + BLOCK)*sizeof(record));
			
			if(tmp == 0) {
				break;
			}
			
			#ifdef DEBUG 
				if(tmp != 0) 
					printf("%c\n", '#');
				
			#endif 
			
		list.data = tmp;
		list.nalloc += BLOCK;
		}
		
		list.data[list.nused] = malloc(sizeof(record));
		
		#ifdef DEBUG 
			if(list.data[list.nused] != 0)
				printf("%c\n", '%');
		#endif
		
		if(list.data[list.nused] == 0) {
			return 1;
		}
		
		strcpy((*list.data[list.nused]).name.last, lname);
		strcpy((*list.data[list.nused]).name.first, fname);
		(*list.data[list.nused]).score = score; 
		list.nused++;
	}
	
	if(argc > 2) {
		
		match = two_flag(match, sort_order, argv);
		
		if(match == 0) 
			goto print;
		
		
		if(two_args_switch(match, list) == 0) 
			goto print;
		
		
	} else if (argc > 1) {
			int flag_one = -1;
			
			flag_one = flag_match(sort_order, argv[1]);
			
			if(flag_one == -1) {
				goto print;
			}
			
			if(one_arg_switch(flag_one, list) == 0)
				goto print;
	}

	print:
		print_records(list);
	
	free_mem(list);
	free(list.data);
	
	#ifdef DEBUG 
		printf("%c\n", '@');
	#endif
	
	return 0;
}

/* switch statement to call qsort based on one */
int one_arg_switch(int flag_one, record_list list) {
	switch(flag_one) {
				case 0: 
					qsort(list.data, list.nused, sizeof(record*), cmp_asc_name);	
					break;
				case 1: 
					qsort(list.data, list.nused, sizeof(record*), cmp_dsc_name);
					break;
				case 2: 
					qsort(list.data, list.nused, sizeof(record*), cmp_asc_score);
					break;
				case 3:
					qsort(list.data, list.nused, sizeof(record*), cmp_dsc_score);
					break;
				default: 
					return 0;
			}
	return 1;
}

/*Switch statement to call qsort function based on two flags.*/
int two_args_switch(unsigned match, record_list list) {
	
	switch (match) {
			case 02: 
				qsort(list.data, list.nused, sizeof(record*), 				
															cmp_asc_name_asc_score);
				break;
			case 03:
				qsort(list.data, list.nused, sizeof(record*), 
															cmp_asc_name_dsc_score);
				break;
			case 12: 
				qsort(list.data, list.nused, sizeof(record*),
															cmp_dsc_name_asc_score);
				break;
			case 13: 
				qsort(list.data, list.nused, sizeof(record*), 
															cmp_dsc_name_dsc_score);
				break;			
			case 20: 
				qsort(list.data, list.nused, sizeof(record*), 
															cmp_asc_score_asc_name);
				break;
			case 21:
				qsort(list.data, list.nused, sizeof(record*), 
															cmp_asc_score_dsc_name);
				break;
			case 30: 
				qsort(list.data, list.nused, sizeof(record*), 
															cmp_dsc_score_asc_name);
				break;
			case 31: 
				qsort(list.data, list.nused, sizeof(record*), 
															cmp_dsc_score_dsc_name);
			default: 
				/* should never get here because of match check above*/
				return 0;
			}
	
	return 1;
}


/*matches a flag to an index in the flag sorting array */
int flag_match(char **sort_order, char *argv) {
	size_t i;

	for(i = 0; i < 4; i++) {
		if(strcmp(sort_order[i], argv) == 0) {
			return i;
		} 
	}
	
	return -1;
}

/*Finds index of two flags. */
unsigned two_flag(unsigned match, char **sort_order, char **argv) {
	int  flag_one = -1;
	int flag_two = -1;
		
		
	flag_one = flag_match(sort_order, argv[1]);
		
	if(flag_one == -1) {
		return 0;
	}
		
	flag_two = flag_match(sort_order, argv[2]);
		
	if(flag_two == -1) {
		return 0;
			
	}
		
		
	match = concatenate(flag_one, flag_two);
	
	return match;
}

/*populates an array with all possible flags */
void populate_sort_array(char **sort_order) {
	
	sort_order[0] = "+n";
	sort_order[1] = "-n";
	sort_order[2] = "+s";
	sort_order[3] = "-s";
	
}

/*Concatenates flag indeces or switch statement cmp sort */
unsigned concatenate(unsigned x, unsigned y) {
	unsigned pow = 10;
	
	while(y >= pow) 
		pow *= 10;
	return x * pow + y;
}


/*Assigns the flags to variables for later use.*/
void flag_handle(int argc, char *argv[], char *srt_ordr, char *srt_ordr2) {
	int assigned; 
	assigned = 0;
	
	if(argc > 2) {
			assigned = sscanf(argv[1], "%s", srt_ordr);
			
			if(assigned != 1) {
				exit(1);
			}
			
			assigned = 0;
			assigned = sscanf(argv[2], "%s", srt_ordr2);
			
			if(assigned != 1) {
				exit(1);
			}
			
	} else if(argc > 1) {
		assigned = sscanf(argv[1], "%s", srt_ordr);
		
		if(assigned != 1) {
				exit(1);
		}
		
	}
}


/*frees each element in the dynamic array*/
void free_mem(record_list list) {
	size_t i; 
	
	for(i = 0; i < list.nused; i++) {
		free(list.data[i]);
		#ifdef DEBUG 
			printf("%c\n", '@');
		#endif
	}
		
	
}


/*prints all the records currently stored */ 
void print_records(record_list list) {
	size_t i; 
	
	for(i = 0; i < list.nused; i++) {
		printf("%s %s %d\n", list.data[i]->name.last, list.data[i]->name.first, list.data[i]->score);
		
	}
	
}


/*makes letters in a string all lower case*/
void to_lower(char a[]){
	size_t i;
	
	for(i = 0; i < NAMESIZE; i++) {
		a[i] = tolower((unsigned char)a[i]);
	}
	
}

/* checks to ensure the score is all digits */
int check_score(char *tmp_score) {
	size_t i; 
	
	
	for (i = 0; i < strlen(tmp_score) - 1; i++) {
		if(!isdigit((unsigned char)tmp_score[i]))
			return 0;
	}
	return 1;
}


/*handles the inputed line from the user and validates */
int handle_input(char *line, char *fname, char *lname, int *score) {
	char  tmp_score[NAMESIZE];
	int assigned;
	int grade = 0;
	assigned = 0;

	
	assigned = sscanf(line, "%s %s %s\n", fname, lname, tmp_score);
		
	if(assigned != 3) {
		return 0;
	}
	
	if(check_score(tmp_score) == 0) 
		return 0; 
	
	assigned = -1; 
	assigned = sscanf(tmp_score, "%d\n", &grade);
	
	if(assigned != 1)
			return 0;
		
	if(strlen(fname) > NAMESIZE || strlen(lname) > NAMESIZE) {
		return 0;
	}
		
	if(grade < 0 || grade > 100) {
		return 0;
	}
	
	
	to_lower(lname);
	to_lower(fname);
	*score = grade;
				
		return 1;
}




