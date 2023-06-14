/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasong <dasong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 15:41:52 by sdg               #+#    #+#             */
/*   Updated: 2023/06/14 19:20:22 by dasong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ./pipex file1 cmd1 cmd2 file2
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/wait.h>

#define BUFFER_SIZE 1024

int main(int argc, char **argv)
{
    (void)argc;
    
    int pipe_fd[2];
    char read_buff[BUFFER_SIZE];
    pid_t pid;
    
	// if(argc != 5)
    //     return (0);
    
    // argv[2] process의 pipe_fd[0]에서 argv[1]의 내용을 read한다.
	if (pipe(pipe_fd) == -1)
	{
		perror("Failed to make pipe.\n");
		return (1);
	}
	pid = fork();
	if (pid < 0)
	{
		perror("Failed to fork.\n");
		return (1);
	}
	if (pid == 0)
	{
		close(pipe_fd[1]);
		dup2(pipe_fd[0], STDIN_FILENO);
		execlp("/bin/ls", "ls", "-l", 0);
		perror("Failed to execute 'ls' command.\n");
		return (1);
	}
	else
	{
		close(pipe_fd[0]);
		int file_fd = open(argv[1], O_RDONLY);
		if (file_fd == 0) {
			perror("Failed to open file.\n");
			return (1);
		}
        ssize_t bytesRead;
		bytesRead = read(file_fd, read_buff, BUFFER_SIZE);
        while (bytesRead != -1) {
			bytesRead = read(file_fd, read_buff, BUFFER_SIZE);
            write(pipe_fd[1], read_buff, bytesRead);
		}
        close(file_fd);
        close(pipe_fd[1]);
        wait(0);
	}
    return (0);
}