#pragma once
#include <Poco/Net/MailMessage.h>

class EmailAction {
public:

	virtual ~EmailAction() = default;

	virtual void execute() = 0;


};
