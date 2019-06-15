#include "ft_gkrellm.hpp"
#include <pthread.h>

void *mainLoop(void *modulesThr) {
	std::list<AModule *> *modules = reinterpret_cast< std::list<AModule *> *>(modulesThr);

	time_t start;

	while (true) {
		start = time(NULL);

		for (std::list<AModule*>::iterator it = modules->begin();
		it != modules->end(); it++) {
			if ((*it)->isActive())
				(*it)->updateInfo();
		}

		if ((REFRESH_TIME_UPDATE - (time(NULL) - start)) > 0)
			usleep(REFRESH_TIME_UPDATE - (time(NULL) - start));
	}
	pthread_exit(NULL);
}

int main(int ac, char **av) {
	bool textGUI = true;
	ADisplay *gui = NULL;

	if (ac == 2) {
		if (std::string(av[1]).compare("-g") == 0) {
			textGUI = false;
		}
	}

	std::list<AModule *> modules;

	modules.push_back(new HostnameModule());
	modules.push_back(new OsInfosModule());
	modules.push_back(new TimeModule());
	modules.push_back(new CpuModule());
	modules.push_back(new MemoryModule());
	modules.push_back(new NetworkModule());
	modules.push_back(new DiskModule());

	for (std::list<AModule*>::iterator it = modules.begin();
	it != modules.end(); it++) {
		if ((*it)->isActive())
			(*it)->updateInfo();
	}

	if (textGUI)
		gui = new TerminalDisplay(modules);
	else
		gui = new GraphicalDisplay(modules);

	pthread_t threadT;
	if (pthread_create(&threadT, NULL, mainLoop, reinterpret_cast<void*>(&modules))) {
		std::cout << "Fail to create thread for gui" << std::endl;
		exit(-1);
	}

	gui->windowEventLoop();
	pthread_cancel(threadT);

	for (std::list<AModule*>::iterator it = modules.begin();
        it != modules.end(); it++)
    delete *it;

    return 0;
}
