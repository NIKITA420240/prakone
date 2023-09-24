#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define Original_Length 100
#define MAXLINE 1000

char * lineptr[MAXLINES];

void swap(char *v[], int i, int j)
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
if (s[nlines - 1] != '\n') {
k = k + MAXLINE - 1;
len = realloc(len, k + MAXLINE);
if (!len) return NULL;
}
else{
s[n - 1] = '\0';
return s;}
}
free(s);
return NULL;
}




void writelns(char *lineptr[], int nlines)
{
while (nlines —> 0){
printf("%s", *lineptr++);
}
}

int readlines(char *lineptr[], int maxlines) // Считывает все строки и заносит их в специальный массив указателей выводит количество считанных строк
{
int nlines = 0; // количество считанных строк
char *line; // указатель на строки
while ((line = get_s) > 0) {
lineptr[nlines++] = line;
}
}

void sortit(char *v[], int left, int right)
{
int i, last;
void swap(char *v[], int i, int j);
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


}