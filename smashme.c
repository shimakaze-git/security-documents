#include<stdio.h>
#include<string.h>
#include<stdlib.h>
 
int main(int argc, char *argv[]){
    char input[0x40];
 
    puts("Welcome to the Dr. Phil Show. Wanna smash?");
    fflush(stdin);

    // 0x40(64バイト)以上でオーバーフロー
    gets(input);
  
    // 特定の文字列を含んでいるかチェック
    if(strstr(input, "Smash me outside, how bout dAAAAAAAAAAA")){
        return 0;
    }
    exit(0);
}
