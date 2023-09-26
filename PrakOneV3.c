#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define Original_Length 100
#define MAXLINE 3


char **lineptr;

void swap(int i, int j)
{
 char *temp;
 temp = *(lineptr) + i;
 *(lineptr) + i = *(lineptr) + j;
 *(lineptr) + j = temp;
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
 
 
 



void writelns( int nlines)
{
 while (nlines --> 0){
  printf("%s\n", *lineptr);
  free(*lineptr);
  lineptr++;
 }
}



int readlines() // Считывает все строки и заносит их в специальный массив указателей выводит количество считанных строк
{
 int k = MAXLINE; // счётчик для для реалока, количество отведенной памяти
 int nlines = 0; // количество считанных строк
 char *line; // указатель на строки
 while ((line = get_s()) > 0) {
  *(lineptr) + nlines++ = line;
  if (nlines >= k) {
   k = k + MAXLINE;
   lineptr = realloc(lineptr, k + MAXLINE); 
   
  }
 }
 return nlines;
}



void sortit( int left, int right)
{ 
 int i, last;
 void swap(int i, int j);
 if (left >= right)
  {return;}
 swap( left, (left + right)/2);
 last = left;
 for (i = left + 1; i <= right; i ++)
  {
   if (strcmp(*lineptr + i,*lineptr + left) < 0)
    {
     swap( ++ last, i);
    }
  }
 swap(left, last);
 sortit( left, last - 1);
 sortit( last + 1, right);
}




int main(void){
  lineptr = malloc(MAXLINE);
  printf("Ввод строк: \n");
  int nlines;
  if ((nlines = readlines() ) >= 0) {
   sortit(0, nlines - 1);
   printf("\nВаш ответ:\n");
   writelns(nlines);
   return 0;
  }
  else {
   printf("Ошибка: слишком много строк или переполнение\n");
  }
  
}
 
 
 
 
 
 


