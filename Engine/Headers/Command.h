//
// Created by Alihan Baysal on 3/23/26.
//

#ifndef SDL3_BROS_COMMAND_H
#define SDL3_BROS_COMMAND_H

class Command
{
public:
    virtual ~Command() = default;
    virtual void execute() = 0;
};

#endif // SDL3_BROS_COMMAND_H
