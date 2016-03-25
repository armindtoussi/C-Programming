#include <stdlib.h>
#include "sort.h"
#include "io.h"

/*cmp by descending name and ascending score. */
int cmp_dsc_name_asc_score (const void *p, const void *q) {
	record *pp = *(record * const *)p;
	record *qq = *(record * const *)q;
	
	int n = strcmp(qq->name.last, pp->name.last);
	
	if(n != 0)
		return n;
	
	if(n == 0)
		n = strcmp(qq->name.first, pp->name.first);
	
	if(n != 0) 
		return n;
	
	return pp->score - qq->score;
}

/* cmp descending name and descending score.*/
int cmp_dsc_name_dsc_score (const void *p, const void *q) {
	record *pp = *(record * const *)p;
	record *qq = *(record * const *)q;
	
	int n = strcmp(qq->name.last, pp->name.last);
	
	if(n != 0)
		return n;
	
	if(n == 0)
		n = strcmp(qq->name.first, pp->name.first);
	
	if(n != 0) 
		return n;
	
	return qq->score - pp->score;
}


/*cmp ascending score and ascending name.*/
int cmp_asc_score_asc_name(const void *p, const void *q) {

	record *pp = *(record * const *)p;
	record *qq = *(record * const *)q;
	
	int n = pp->score - qq->score;
	
	if(n != 0)
		return n;
	
	if(strcmp(pp->name.last, qq->name.last) != 0) 
		return strcmp(pp->name.last, qq->name.last);
	
	return strcmp(pp->name.first, qq->name.first);
}

/*cmp ascending score and descending name.*/
int cmp_asc_score_dsc_name(const void *p, const void *q) {
	record *pp = *(record * const *)p;
	record *qq = *(record * const *)q;
	
	int n = pp->score - qq->score;
	
	if(n != 0)
		return n;
	
	if(strcmp(qq->name.last, pp->name.last) != 0) 
		return strcmp(qq->name.last, pp->name.last);
	
	return strcmp(qq->name.first, pp->name.first);
}

/*cmp descending score and ascending name.*/
int cmp_dsc_score_asc_name(const void *p, const void *q) {
	record *pp = *(record * const *)p;
	record *qq = *(record * const *)q;
	
	int n = qq->score - pp->score;
	
	if(n != 0)
		return n; 
	
	if(strcmp(pp->name.last, qq->name.last) != 0) 
		return strcmp(pp->name.last, qq->name.last);
	
	return strcmp(pp->name.first, qq->name.first);
}

/*cmp descending score and descending name */
int cmp_dsc_score_dsc_name(const void *p, const void *q) {
	record *pp = *(record * const *)p;
	record *qq = *(record * const *)q;
	
	int n = qq->score - pp->score; 
	
	if(n != 0) 
		return n;
	
	if(strcmp(qq->name.last, pp->name.last) != 0) 
		return strcmp(qq->name.last, pp->name.last);
	
	return strcmp(qq->name.first, pp->name.first);
}

/*cmp by ascending name and ascending score */
int cmp_asc_name_asc_score(const void *p, const void *q) {
	record *pp = *(record * const *)p;
	record *qq = *(record * const *)q;
	
	int n = strcmp(pp->name.last, qq->name.last); 
	
	if(n != 0)
		return n;
	
	if(n == 0)
		n = strcmp(pp->name.first, qq->name.first);
	
	if(n != 0) 
		return n;
	
	return (pp->score - qq->score);
}

/*cmp by ascending name and descending score.*/
int cmp_asc_name_dsc_score(const void *p, const void *q) {
	record *pp = *(record * const *)p;
	record *qq = *(record * const *)q;
	
	int n = strcmp(pp->name.last, qq->name.last); 
	
	if(n != 0)
		return n;
	
	if(n == 0)
		n = strcmp(pp->name.first, qq->name.first);
	
	if(n != 0) 
		return n;
	
	return (qq->score - pp->score);
}

/*cmp by ascending name */
int cmp_asc_name(const void *p, const void *q) {
	record *pp = *(record * const *)p;
	record *qq = *(record * const *)q;
	
	int n = strcmp(pp->name.last, qq->name.last); 
	
	if(n != 0)
		return n;
	
	return strcmp(pp->name.first, qq->name.first);
}

/*cmp by descending name */
int cmp_dsc_name(const void *p, const void *q) {
	record *pp = *(record * const *)p;
	record *qq = *(record * const *)q;
	
	int n = strcmp(qq->name.last, pp->name.last); 
	
	if(n != 0)
		return n;
	
	return strcmp(qq->name.first, pp->name.first);
}


/*cmp by ascending score */
int cmp_asc_score(const void *p, const void *q) {
	record *pp = *(record * const *)p;
	record *qq = *(record * const *)q;
	
	return pp->score - qq->score;
}
/*cmp by descending score */
int cmp_dsc_score(const void *p, const void*q) {
	record *pp = *(record * const *)p;
	record *qq = *(record * const *)q;
	
	return qq->score - pp->score;
}





