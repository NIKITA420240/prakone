#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define Original_Length 100
#define MAXLINE 5





void swap(char **v, int i, int j)
{
 char *temp;
 temp = v[i];
 v[i] = v[j];
 v[j] = temp;
}



char* get_s(void) // Считываем строку произвольного размера результат функции - строка
{
 int nlines,k = 0;
 char *len = malloc(MAXLINE);
 if (!len) {
  return NULL;
 }
 while (fgets(len + k, MAXLINE, stdin)){
  nlines = strlen(len);
  if (len[nlines - 1] != '\n') {
   k = k + MAXLINE - 1;
   len = realloc(len, k + MAXLINE);
   if (!len) return NULL;
  }
  else{
   len[nlines - 1] = '\0';
   return len;}
  }
 
 free(len);
 return NULL;
 }
 
 
 



void writelns(char **lineptr, int nlines)
{
 while (nlines --> 0){
  printf("%s\n", lineptr[nlines]);
  free(*lineptr);
  lineptr++;
 }
}



int readlines(char ***lineptr) // Считывает все строки и заносит их в специальный массив указателей выводит количество считанных строк
{
 int k = MAXLINES;
 int nlines = 0; // количество считанных строк
 char *line; // указатель на строки
 *lineptr = malloc(MAXLINE*sizeof(char*));
 if (*lineptr == NULL){
  printf("Нехватило памяти");
  return -1;
 }
 while ((line = get_s()) > 0) {
  (*lineptr)[nlines++] = line;
  if (nlines + 1 >= k){
   k = k + MAXLINE;
   *lineptr = realloc(*lineptr, (k + MAXLINE) * sizeof(char*));
   if (*lineptr == NULL){
   printf("Нехватило памяти");
   return -1;
   }
  }
 }
 return nlines;
}



void sortit(char **v, int left, int right)
{ 
 int i, last;
 void swap(char **v, int i, int j);
 if (left >= right)
  {return;}
 swap(v, left, (left + right)/2);
 last = left;
 for (i = left + 1; i <= right; i ++)
  {
   if (strcmp(v[i],v[left]) < 0)
    {
     swap(v, ++ last, i);
    }
  }
 swap(v, left, last);
 sortit(v, left, last - 1);
 sortit(v, last + 1, right);
}




int main(void){
  char ** lineptr;
  printf("Ввод строк: \n");
  int nlines;
  if ((nlines = readlines(&lineptr)) >= 0) {
   sortit(lineptr, 0, nlines - 1);
   printf("\nВаш ответ:\n");
   writelns(lineptr, nlines);
   return 0;
  }
  else {
   printf("Ошибка: слишком много строк или переполнение\n");
  }
  
}
 
 
 
 
 
 


