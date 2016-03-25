#ifndef SORT_H
#define SORT_H  


/* cmp by ascending name descending score */
int cmp_asc_name_dsc_score(const void *p, const void *q);
/*cmp by ascending name ascending score */
int cmp_asc_name_asc_score(const void *p, const void *q);
/*cmp by descending score descending name*/
int cmp_dsc_score_dsc_name(const void *p, const void *q);
/*cmp by descending score ascending name.*/
int cmp_dsc_score_asc_name(const void *p, const void *q);
/*cmp by ascending score descending name.*/
int cmp_asc_score_dsc_name(const void *p, const void *q);
/*cmp by ascending score and ascending name*/
int cmp_asc_score_asc_name(const void *p, const void *q);
/*cmp by descending name and descending score.*/
int cmp_dsc_name_dsc_score (const void *p, const void *q);
/*cmp by descending name and ascending score.*/
int cmp_dsc_name_asc_score (const void *p, const void *q);
/*cmp by ascending name */
int cmp_asc_name(const void *p, const void *q);
/*cmp by descending name */
int cmp_dsc_name(const void *p, const void *q);
/*cmp by ascending score */
int cmp_asc_score(const void *p, const void *q);
/*cmp by descending score */
int cmp_dsc_score(const void *p, const void*q);

#endif
