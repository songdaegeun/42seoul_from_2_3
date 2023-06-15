static void	pipe_write_end(char **av, char **envp)
{
	pid_t	pid;
	int		outfile;

	pid = fork();
	if (pid == -1)
		perror_exit("fork error");
	if (pid == 0)
	{
		outfile = open(av[4], O_RDWR | O_CREAT | O_TRUNC, 0644);
		if (outfile == -1)
			perror_exit("outfile error");
		if (dup2(outfile, STDOUT_FILENO) == -1)
			perror_exit("dup2 error");
		execute(av[3], envp);
	}
}