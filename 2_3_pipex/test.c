/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdg <sdg@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 15:41:52 by sdg               #+#    #+#             */
/*   Updated: 2023/06/15 22:48:17 by sdg              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ./pipex file1 cmd1 cmd2 file2

//  ./pipex test.txt "ls -l" "wc -l" outfile
//  < infile ls -l | wc -l > outfile

// < test.txt grep a1 | wc -w > outfile
// ./pipex test.txt "grep a" "wc -w" outfile
// < test.txt /usr/bin/grep a
/*
sudo:
pipe operator의 read end와 write end 각각의 명령을 실행할 프로세스는 2개 필요하다.
./pipex [args]를 실행하는 순간, 쉘에서 fork되어 'pipex 프로세스'가 생성된다.

pipex프로세스에서 infile을 읽고, 그 결과를 입력으로 받을 프로세스는 pipe_read_end이다.
pipe_read_end의 출력을 입력으로 받을 프로세스는 pipe_write_end이다.
pipex프로세스에서 pipe_read_end와 pipe_write_end와 통신하기 위한 pipe는 2개이므로,
pipe_fd1, pipe_fd2를 pipe로 한다.

pipex프로세스의 실행흐름은 다음과 같다.

pipe(pipe_fd1);
pipe(pipe_fd2);
dup2(stdout, pipe_fd2[1])으로 돌려놓는다.
ls -l을 실행할 프로세스인 pipe_read_end프로세스를 fork한다.

pipex프로세스에서
infile을 읽은 내용을 pipe_fd1[1]에 write,
pipe_read_end에서
pipe_fd1[0]에서 read.
read한 내용을 ls -l에 대한 입력으로 주면서 execve하여 pipe_read_end의 memory를 덮어쓴다.
표준출력은 pipex프로세스의 pipe_fd2[1]으로 write된다.

이제 "wc -l"을 실행할 pipe_write_end프로세스를 fork한다.
dup2(stdout, outfile)으로 돌려놓는다.
pipe_write_end프로세스는 pipe_fd2[0]에서 read한다.
read한 내용을 wc -l의 입력으로 주면서 execve하여 pipe_write_end의 memory를 덮어쓴다.
표준출력은 pipex프로세스에서 open한 outfile으로 write된다.
*/

#include "pipex.h"
#include <string.h>

int	main(int argc, char **argv, char **envp)
{
	char **env_pt;
	
	env_pt = envp;
	while (*env_pt)
	{
		char **res = ft_split(*env_pt, '=');
		if(!ft_strncmp(res[0], "PATH", 4))
			write(1, res[1], strlen(res[1]));
		env_pt++;
	}
    return (0);
}
