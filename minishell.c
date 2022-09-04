#include "include/minishell.h"

int main(int ac, char *av[], char **env)
{
	t_minishell *minishell;

	minishell = malloc(sizeof(t_minishell));
	if (!minishell)
		return (0);
	while (true)
	{
		minishell->buff = readline("Minishell$~ ");
		if (!ft_strncmp(minishell->buff, "pwd", ft_strlen(minishell->buff)))
			printf("%s\n", getcwd(minishell->pwd, sizeof(minishell->pwd)));
		else if (!ft_strncmp(minishell->buff, "env", ft_strlen(minishell->buff)))
		{
			int i = 0;
			while (env[i])
				printf("%s ", (env[i++]));
		}
		else if (!ft_strncmp(minishell->buff, "exit", ft_strlen(minishell->buff)))
			exit(0);
		add_history(minishell->buff);
	}
}