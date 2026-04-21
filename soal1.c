//RAFA SATRIA PRATAMA
//SOAL 1- 21 APRIL 2026
//MANUSKRIP RETAK

#include <stdio.h>
#include <string.h>

void check(char *st){
    for (int i = 0; i < strlen(st)/2; i++){
        int found = 0;
        if (st[i] == '('){
            for (int j = i+1; j < strlen(st); j++){
                if (found != 1){
                    if (st[j] == '('){
                        memmove(&st[j], &st[j + 1], strlen(st) - j);
                    }else if (st[j] == ')'){
                        found = 1;
                    }
                }else{
                    if (st[j] == '('){
                        break;
                    }else if (st[j] == ')'){
                        memmove(&st[j], &st[j + 1], strlen(st) - j);
                    }
                }
            }
            if (found ==  0){
                memmove(&st[i], &st[i + 1], strlen(st) - i);
            }
        }else if (st[i] == ')'){
            memmove(&st[i], &st[i + 1], strlen(st) - i);
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
