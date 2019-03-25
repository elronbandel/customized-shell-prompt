//
// Created by elronbandel on 3/25/19.
//

#ifndef CUSTOMIZED_SHELL_PROMPT_COMMAND_H
#define CUSTOMIZED_SHELL_PROMPT_COMMAND_H
#define MAX_ARGV_SIZE 33

typedef struct Command {
    char* cmd;
    char* argv[MAX_ARGV_SIZE];
} Command;

#endif //CUSTOMIZED_SHELL_PROMPT_COMMAND_H
