//RAFA SATRIA PRATAMA
//SOAL 1- 21 APRIL 2026
//MANUSKRIP RETAK

#include <stdio.h>
#include <string.h>

void checkbalance(char *st, int* open, int* close){
    int open_temp = 0; int close_temp = 0;
    for (int i = 0; i < strlen(st); i++){
        if (st[i] == '('){
            open_temp++;
        }else if (st[i] == ')'){
            close_temp++;
        }
    }

    *open = open_temp;
    *close = close_temp;
}

void check(char *st){
    int open = 0; int close = 0;
    int lastidx = 1000;
    for (int i = 0; i < strlen(st); i++){
        if (st[i] == '('){
            if (lastidx == 1000){
                for (int j = strlen(st); j > i; j--){
                    if (st[j] == '('){
                        memmove(&st[j], &st[j + 1], strlen(st) - j);
                    }else if (st[j] == ')'){
                        lastidx = j;
                        break;
                    }
                }
            }else{
                for (int j = lastidx; j > i; j--){
                    if (st[j] == '('){
                        memmove(&st[j], &st[j + 1], strlen(st) - j);
                    }else if (st[j] == ')'){
                        lastidx = j;
                        break;
                    }
                }
            }
        }else if (st[i] == ')'){
            checkbalance(st, &open, &close);
            if (open != close){
                memmove(&st[i], &st[i + 1], strlen(st) - i);
            }
        }
    }
}

int main(){
    char st[100];

    scanf("%s", st);
    check(st);
    printf("%s", st);
    return 0;
}
