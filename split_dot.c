//* Problem 1: Split string at period based on integer choice */
#include<stdio.h>
void split( char s[], int n)
{
int i;
if(n==0)
{

for(i=0;s[i]!='.'&&s[i]!='\0';i++)
{
printf("%c",s[i]);
}
}
else {
for (i=0; s[i]!='.';i++);
for(i=i+1;s[i]!='\0';i++)
{
printf("%c",s[i]);
}
}
printf("\n");
}
int main()
{
char s[]="kiit.jpg";
split(s,0); // /Print before the period/
split(s,1); // /Print after period/
return 0;
}
