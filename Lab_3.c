#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include <string.h>
char *strtok(char *str, const char *sep); 
int main(int argc, char *argv[]) {
    
int n=1;
while(argv[n]!=NULL){
struct stat buff;
stat(argv[n], &buff);
char *tp;
char size[100]={};  

if(S_ISREG(buff.st_mode)==1){ //обычный файл
tp = "-";
sprintf(size,"%ld",buff.st_size);
}
else if(S_ISDIR(buff.st_mode)){ // папка
tp="d";
} 
else tp="?"; 
int flag=0;
char userAccess[3] = {'-', '-', '-'};
if (S_IRUSR & buff.st_mode)
userAccess[0] = 'r';
else flag=1;
if (S_IWUSR & buff.st_mode)
userAccess[1] = 'w';
if (S_IXUSR & buff.st_mode)
userAccess[2] = 'x';

char groupAccess[3] = {'-', '-', '-'};
if (S_IRGRP & buff.st_mode)
groupAccess[0] = 'r';
if (S_IWGRP & buff.st_mode)
groupAccess[1] = 'w';
if (S_IXGRP & buff.st_mode)
groupAccess[2] = 'x';

char othersAccess[3] = {'-', '-', '-'};
if (S_IROTH & buff.st_mode)
othersAccess[0] = 'r';
if (S_IWOTH & buff.st_mode)
othersAccess[1] = 'w';
if (S_IXOTH & buff.st_mode)
othersAccess[2] = 'x';
char *access;
if(flag==1){
struct passwd *pw = getpwuid(buff.st_uid);
struct group  *gr = getgrgid(buff.st_gid);
access=strcat(pw->pw_name," ");
access=strcat(access,gr->gr_name);
            
}

time_t lt; //последняя модификация
lt = buff.st_mtime;
char *time = ctime(&lt);
time = strncpy(time,time,strlen(time)-3);

char pars[] ="/"; //название файла
char *str;
str = strtok(argv[n],pars);
char *name;
do {
name = str;
str=strtok(NULL,pars);
} while (str!=NULL);
n++;
if(flag==1)
printf("| %s |%20s| %10s | %15s | %s\n",tp, access, size, name, time );
else printf("| %s | %10c%c%c %c%c%c %c%c%c | %10s | %15s | %s\n",tp, userAccess[0], userAccess[1], userAccess[2],
groupAccess[0], groupAccess[1], groupAccess[2],
othersAccess[0], othersAccess[1], othersAccess[2], size, name, time );

}
   
}
