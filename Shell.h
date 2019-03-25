//
// Created by elronbandel on 3/25/19.
//
#include <malloc.h>
#include "Console.h"
#include "Command.h"

#ifndef CUSTOMIZED_SHELL_PROMPT_SHELL_H
#define CUSTOMIZED_SHELL_PROMPT_SHELL_H


typedef int (*Executer)(const char* cmd, char* const argv[]);
typedef struct Shell Shell;
struct Shell {
    Buffer* buffer;
    Console console;
    void (*start)(Shell this);
};
void start(Shell this);

Shell newShell(Buffer* buffer);

void getInput(Shell shell);
void buildCommand(Shell shell, Command* cmd);
Executer getExecuter(char* name);
void executeCommand(Shell shell);

#endif //CUSTOMIZED_SHELL_PROMPT_SHELL_H
