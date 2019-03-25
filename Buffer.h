//
// Created by elronbandel on 3/25/19.
//
#include <string.h>

#define WORD__MAX_SIZE 32
#define WORDS_MAX_NUM 32
#ifndef CUSTOMIZED_SHELL_PROMPT_STRING_H
#define CUSTOMIZED_SHELL_PROMPT_STRING_H
#define TRUE 1
#define FALSE 0

typedef struct Buffer{
    char words[WORD__MAX_SIZE][WORDS_MAX_NUM];
    int wordsCount;
    int (*set)(struct Buffer* this, char* string);
    void (*get)(struct Buffer* this, char* string);
} Buffer;

void init(Buffer* buffer);

int setBufferFromString(Buffer* buffer,char* string);
void getStringFromBuffer(Buffer* buffer,char* string);
#endif //CUSTOMIZED_SHELL_PROMPT_STRING_H
