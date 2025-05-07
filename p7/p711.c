#include <stdio.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>

void list_open_files(pid_t pid) {

    char path[256];

    snprintf(path, sizeof(path), "/proc/%d/fd", pid);
    DIR *dir = opendir(path);

    if (dir == NULL) return;

    struct dirent *entry;

    while ((entry = readdir(dir)) != NULL) {

        if (entry->d_name[0] == '.') continue;

        char file_path[256];
        snprintf(file_path, sizeof(file_path), "/proc/%d/fd/%s", pid, entry->d_name);

        char real_path[256];

        if (readlink(file_path, real_path, sizeof(real_path) - 1) != -1) {

            real_path[sizeof(real_path) - 1] = '\0';
            printf("Процес %d відкрив файл: %s\n", pid, real_path);

        }
    }

    closedir(dir);

}

void list_processes() {

    DIR *dir = opendir("/proc");

    if (dir == NULL) {

        perror("Не вдалося відкрити каталог /proc");
        return;
    }

    struct dirent *entry;

    while ((entry = readdir(dir)) != NULL) {

        if (entry->d_type == DT_DIR && isdigit(entry->d_name[0])) {

            pid_t pid = atoi(entry->d_name);
            list_open_files(pid);

        }
    }

    closedir(dir);

}

int main() {

    list_processes();

    return 0;

}
