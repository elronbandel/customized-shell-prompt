//
// Created by elronbandel on 3/25/19.
//

#ifndef CUSTOMIZED_SHELL_PROMPT_CONSOLE_H
#define CUSTOMIZED_SHELL_PROMPT_CONSOLE_H


#include "Buffer.h"

typedef struct Console {
    void (*writeLine)(char* s);
    void (*writeChar)(char s);
    void (*writeWords)(Buffer* buf);
    int (*getWords)(Buffer* buf);
} Console;

void writeLine(char* s);
void writeChar(char c);
void writeWords(Buffer* buf);
int getWords(Buffer* s);

Console newConsole();


#endif //CUSTOMIZED_SHELL_PROMPT_CONSOLE_H
