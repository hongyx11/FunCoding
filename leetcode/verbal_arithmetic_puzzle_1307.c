#include "header.h"


int translate(char * word, int *map){
    int res = 0;
    for(int i=0; i<strlen(word); i++){
        res = 10 * res + map[(int)word[i] - (int)'A'];
    }
    return res;
}

bool addvalue(char ** words, int wordsSize, char * result, int *map){
    int leftVal = 0, rightVal = 0;
    for(int i=0; i<wordsSize; i++){
        leftVal += translate(words[i], map);
    }
    rightVal = translate(result, map);
    return leftVal == rightVal;
}

bool helper(char **words, char * result, int wordsSize, int i, int *charset, int charsize, int *map){
    // if(i == charsize) {
        
    // }
}

bool isSolvable(char ** words, int wordsSize, char * result){
    int map[30];
    for(int i=0; i<30; i++) map[i] = -1;
    // bool res = helper(0, 0, words, wordsSize, result, map);
    return true;
}



int main(){
    char w1[20], w2[20], w3[20], w4[20], w5[20], result[20];
    char *words[5];
    words[0] = w1;
    words[1] = w2;
    words[2] = w3;
    words[3] = w4;
    words[4] = w5;
    sprintf(w1, "I");
    sprintf(w2, "THINK");
    sprintf(w3, "IT");
    sprintf(w4, "BE");
    sprintf(w5, "THINE");
    sprintf(result, "INDEED");
    bool res = isSolvable(words, 5, result);
    printf("res %d \n", res);
    return 0;
}