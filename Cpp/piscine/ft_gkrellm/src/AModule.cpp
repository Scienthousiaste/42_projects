#include "AModule.hpp"

std::string AModule::getCommandResult() {
	return getCommandResult(_cmd);
}

std::string AModule::getCommandResult(std::string cmd) {
	std::string data;
	FILE *stream;
	const int max_buffer = 256;
	char buffer[max_buffer];

	stream = popen(cmd.c_str(), "r");
	if (stream) {
		while (!feof(stream)) {
			if (fgets(buffer, max_buffer, stream) != NULL)
				data.append(buffer);
		}
		pclose(stream);
	}
	return data;
	
}

bool AModule::isActive() {
	return _active;
}

void AModule::setActive(bool res) {
	_active = res;
}

std::string AModule::getName() { return _name; }
