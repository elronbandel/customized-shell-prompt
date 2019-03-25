//
// Created by elronbandel on 3/25/19.
//
#include <stdio.h>
#include <malloc.h>
#include "Console.h"
#define MAX_INPUT 512

Console newConsole() {
    Console this;
    this.writeLine = writeLine;
    this.writeChar = writeChar;
    this.getWords = getWords;
    this.writeWords = writeWords;
    return this;
}

void writeLine(char* s) {
    printf("%s",s);
}
void writeChar(char c) {
    printf("%c",c);
}
int getWords(Buffer* buf) {
    char* string = (char*)malloc(MAX_INPUT);
    size_t size = MAX_INPUT;
    getline(&string, &size, stdin);
    buf->set(buf, string);
    free(string);
    return buf->wordsCount;
}

void writeWords(Buffer* buf) {
    char string[MAX_INPUT];
    buf->get(buf, string);
    printf("%s", string);
}