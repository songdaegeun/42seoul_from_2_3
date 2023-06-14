#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 25
#define READ_END 0
#define WRITE_END 1

int	main()
{
	char write_msg[BUFFER_SIZE] = "Hi";
    char read_msg[BUFFER_SIZE];
    char response_msg[BUFFER_SIZE];
    int fd[2];
    int fd2[2];
    pid_t pid;

    if (pipe(fd) == -1) {
        fprintf(stderr, "pipe failed.");
        return (1);
    }
    if (pipe(fd2) == -1) {
        fprintf(stderr, "pipe failed.");
        return (1);
    }
    pid = fork();
    if(pid < 0) {
        fprintf(stderr, "fork failed.");
        return (1);
    }
    if(pid > 0) {
        printf("parent\n");
        close(fd[READ_END]);
        close(fd2[WRITE_END]);

        write(fd[WRITE_END], write_msg, sizeof(write_msg) + 1);
        write(fd[WRITE_END], "second", 7);
        read(fd2[READ_END], response_msg, 7);
        printf("response: %s\n", response_msg);

        close(fd[WRITE_END]);
        close(fd2[READ_END]);
    }
    else {
        printf("child\n");
        close(fd[WRITE_END]);
        close(fd2[READ_END]);

        read(fd[READ_END], read_msg, sizeof(write_msg) + 1);
        printf("read: %s\n", read_msg);
        if(!strcmp(read_msg, "Hi")) {
            write(fd2[WRITE_END], "Hello~", 7);
        }

        close(fd[READ_END]);
        close(fd2[WRITE_END]);
    }
    return (0);
}