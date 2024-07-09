#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

void touch_memory(char *memory, size_t size) {
    for (size_t i = 0; i < size; i++) {
        memory[i] = (memory[i] + 1) % 256;
    }
}

int main(int argc, char *argv[]) {
    int pid;
    pid = getpid();
    printf("PID: %d\n", pid);

    size_t memory_size_in_mb = atoi(argv[1]);
    size_t memory_size = memory_size_in_mb * 1024 * 1024;
    int duration = (argc == 3) ? atoi(argv[2]) : -1;

    char *memory = (char *)malloc(memory_size);
    if (memory == NULL) {
        fprintf(stderr, "Failed to allocate memory\n");
        return 1;
    }
    memset(memory, 0, memory_size);

    time_t start_time = time(NULL);

    while (1) {
        touch_memory(memory, memory_size);

        if (duration > 0 && difftime(time(NULL), start_time) >= duration) {
            break;
        }
    }

    free(memory);
    return 0;
}
