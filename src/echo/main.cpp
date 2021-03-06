#include <signal.h>
#include "service.h"
#include "echo_service.h"

static void on_quit(int signal){
    printf("(%d):quiting...\n", signal);
	service_quit();
}

int main(int argc, char* argv[]) {
    if(argc < 4) {
        printf("Usage: %s ip port instances\n", argv[0]);

        return 0;
    }

    const char* ip = argv[1];
    int port = atoi(argv[2]);
    int instances = atoi(argv[3]);
    int delta = instances > 10 ? instances/10 : 1;

	signal(SIGINT, on_quit);
    workers_init(instances, delta);

    echo_service_init();
    service_start(ip, port, echo_get_worker_ops());

    service_loop();
    echo_service_deinit();

    return 0;
}

