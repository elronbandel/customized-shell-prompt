//
// Created by elronbandel on 3/25/19.
//

#include "Buffer.h"
void init(Buffer* buffer) {
    buffer->set = setBufferFromString;
    buffer->get = getStringFromBuffer;
    buffer->wordsCount = 0;
}

int parseWords(char *base, char target[WORD__MAX_SIZE][WORDS_MAX_NUM]) {
    int i=0;
    char* token;
    token = strtok(base, " ");
    while(token != NULL) {
        strcpy(target[i], token);
        i++;
        token = strtok(NULL, " ");
    }
    strtok(target[i-1], "\n"); // take off the '\n' at the last word
    return i;
}
int setBufferFromString(Buffer* buffer,char* string) {
    buffer->wordsCount = parseWords(string, buffer->words);
    return buffer->wordsCount;
}

void getStringFromBuffer(Buffer* buffer,char* string) {
    int i;
    char space[2] = {' ',0};
    string[0] = 0;
    for (i = 0; i < (buffer->wordsCount)-1; i++) {
        strcat(string, buffer->words[i]);
        strcat(string, space);
    }
    strcat(string, buffer->words[i]);
}