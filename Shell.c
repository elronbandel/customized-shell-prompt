//
// Created by elronbandel on 3/25/19.
//

#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include "Shell.h"
#include "Customized.h"

Shell newShell(Buffer* buffer) {
    Shell this;
    this.start = start;
    this.console = newConsole();
    this.buffer = buffer;
    return this;
}
void start(Shell this) {
    Executer execute;
    Command cmd;
    int pid;
    while (1) {
        getInput(this);
        buildCommand(this, &cmd);
        execute = getExecuter(cmd.cmd);
        if (pid = fork() == 0) {
            execute(cmd.cmd, cmd.argv); //if you are the child processs
        } else  {
            wait(NULL);
        }


    }

}

void getInput(Shell this) {
    this.console.writeChar('>');
    this.console.getWords(this.buffer);
}
void buildCommand(Shell shell, Command* cmd) {
    int i;
    cmd->cmd = shell.buffer->words[0];
    for(i = 0; i < shell.buffer->wordsCount; i++)
        cmd->argv[i] = shell.buffer->words[i];
    cmd->argv[i] = NULL;
}

void executeCommand(Shell shell) {

}
