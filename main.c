#include <stdio.h>
#include <unistd.h>
#include "Shell.h"
#include "Customized.h"
#define BUFFER_SIZE 512

int exitC(const char* cmd, char* const argv[]);
int jobs(const char* cmd, char* const argv[]);
int cd(const char* cmd, char* const argv[]);

#define CUSTOMIZED_NUM 3
char* commandsNames[] = {"exit", "jobs", "cd"};
Executer commandsExecuters[] = {exitC, jobs, cd};

Executer getExecuter(char* name) {
    int i;
    for (i = 0;  i < CUSTOMIZED_NUM ; i ++) {
        if (strcmp(name, commandsNames[i]) == 0)
            return commandsExecuters[i];
    }
    return execvp;
}


int main() {
    char content[BUFFER_SIZE];
    Buffer buffer;
    init(&buffer);
    Shell shell = newShell(&buffer);
    shell.start(shell);
    return 0;
}