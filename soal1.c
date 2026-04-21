//RAFA SATRIA PRATAMA
//SOAL 1- 21 APRIL 2026
//MANUSKRIP RETAK

#include <stdio.h>
#include <string.h>

void check(char *st){
    int lastidx = strlen(st);
    int lastidxfound = 0;
    for (int i = 0; i < lastidx; i++){
        if (st[i] == '('){
            if (lastidxfound == 0){
                for (int j = strlen(st); j > i; j--){
                    if (st[j] == '('){
                        memmove(&st[j], &st[j + 1], strlen(st) - j);
                    }else if (st[j] == ')'){
                        lastidxfound = 1;
                        lastidx = j;
                        break;
                    }
                }
            }else{
                int j = lastidx;
                while (j != i){
                    j--;
                    if (st[j] == '('){
                        memmove(&st[j], &st[j + 1], strlen(st) - j);
                    }else if (st[j] == ')'){
                        lastidx = j;
                        break;
                    }
                }
            }
        }else if (st[i] == ')' && i < lastidx-1){
            memmove(&st[i], &st[i + 1], strlen(st) - i);
        }
    }
}

int main(){
    char st[100];

    fgets(st, sizeof(st), stdin);
    check(st);
    printf("%s", st);
    return 0;
}
