//
// Created by Alihan Baysal on 3/23/26.
//

#ifndef SDL3_BROS_MOVECOMMAND_H
#define SDL3_BROS_MOVECOMMAND_H
#include "Command.h"

class MoveCommand : public Command
{
public:
    virtual void execute() {};
};

#endif //SDL3_BROS_MOVECOMMAND_H
