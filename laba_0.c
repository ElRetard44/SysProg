#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
int main()
{
int a;
int lm=0;
int nm=0;
int line[100][100];
char ch;
FILE *file = fopen("hello.txt","r");
line[0][0];
while (read(file, &ch , sizeof(char))>0){
nm++;
if (ch == ('\n')) {
line[lm][0]=nm;
line[lm-1][1]=nm-line[lm-1][0];
lm ++;
}

}
scanf("%d", &a);
lseek(file,line[a][0],SEEK_SET);
for(int i=0;i<line[a][1];i++){
read(file, &ch , sizeof(char));
printf("%c",ch);
}
return 0;
}
