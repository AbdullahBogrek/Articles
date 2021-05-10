#include <stdio.h> 
#include <unistd.h>
#include <sys/wait.h> 

int main(){

    printf("Fork() Fonksiyon Uygulaması\n");
    int pid = fork();
    if (pid > 0)
    {   
        wait(NULL);
        FILE *dosya = fopen("parent.txt","w");
        fprintf(dosya,"Merhaba. %d id'li parent process çalışmaktadır...\n",getpid());
    }
    else if (pid == 0)
    {
        FILE *dosya2 = fopen("child.txt","w");
        fprintf(dosya2,"Merhaba. %d id'li child process çalışmaktadır...\n",getpid());
    }
    else
    {
        printf("Process oluşturulamadı. Lütfen tekrar deneyiniz...\n");
    }
}