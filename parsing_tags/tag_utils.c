#include "../minishell.h"

int	determine_redirection_type(char *str)
{
	int	type;
	int	i;

	type = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '<')
		{
			if (str[i + 1] == '<')
			{
				if (type == 0)
					type = 2;
				else if (type == 1)
					type = 3;
				i++;
			}
			else
			{
				if (type == 0)
					type = 1;
				else if (type == 2)
					type = 3;
			}
		}
		i++;
	}
	return (type);
}

int	determine_redirection_type_2(char *str)
{
	int	type2;
	int	i;

	type2 = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '>')
		{
			if (str[i + 1] == '>')
			{
				type2 = 2;
				break;
			}
			else
			{
                type2 = 1;
                break;
			}
		}
		i++;
	}
	return (type2);
}

int	determine_last_in_type(char *str)
{
	int	last_type;
	int	i;

	last_type = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '<')
		{
			if (str[i + 1] == '<')
			{
				last_type = 2;
				i++;
			}
			else
			{
				last_type = 1;
			}
		}
		i++;
	}
	return (last_type);
}

int	determine_last_out_type(char *str)
{
	int	last_type;
	int	i;

	last_type = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '>')
		{
			if (str[i + 1] == '>')
			{
				last_type = 2;
				i++;
			}
			else
			{
				last_type = 1;
			}
		}
		i++;
	}
	return (last_type);
}