#pragma once

class EmailAction {
public:
    virtual ~EmailAction() = default;
    virtual void execute() = 0;
};