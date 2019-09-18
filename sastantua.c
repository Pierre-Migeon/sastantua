#include <stdio.h>
#include <unistd.h>

void	ft_putchar(char c);

typedef	struct s_stats
{
	int stars;
	int level;
	int base_num;
	int lines;
	int current_line;
}	t_stats;

int	check_char(t_stats info, int i)
{
	int right_border;
	int left_border;
	int middle;

	middle = info.stars / 2;
	right_border = middle - info.level / 2 + (!(info.level % 2));
	left_border = middle + info.level / 2 - (!(info.level % 2));
	if (info.current_line < 3 + (!(info.level % 2)))
		return (0);
	if (i < right_border || i > left_border)
		return (0);
	if (info.level > 4 && info.current_line == 3 + info.level / 2 && i == right_border + 1)
		return (2);
	return (1);
}

void	print_line(t_stats info, int last_flag)
{
	int i;

	i = 0;
	while(i++ < info.base_num)
		ft_putchar(' ');
	ft_putchar('/');
	i = info.stars;
	while(i--)
	{
		if (last_flag && check_char(info, i))
		{	
			if (check_char(info, i) == 1)
				ft_putchar('|');
			else
				ft_putchar('$');
		}
		else
			ft_putchar('*');
	}
	ft_putchar('\\');
	ft_putchar('\n');
}

int	get_base_num(int levels)
{
	int 	lines;
	int 	stars;
	int	i;

	lines = 0;
	stars = 1;
	i = 1;
	while (i <= levels)
		lines += i++ + 2;
	i = 2;
	if (levels > 1)
		while (i <= levels)
			stars += (i < 5) ? 4 + 2*(i++ / 4) : 2 + 2*(i++ / 2);
	stars += 2*(lines - 1);
	stars /= 2;
	return (stars);
}

void sastantua(int size)
{
	t_stats info;

	if (size <= 0)
		return ;
	info.level = 0;
	info.base_num = get_base_num(size);
	info.stars = 1;
	while (info.level++ < size)
	{
		info.lines = info.level + 3;
		for (info.current_line = 1; info.current_line < info.lines; info.current_line++)
		{
			print_line(info, (info.level == size));
			info.stars += 2;
			info.base_num--;
		}
		info.stars += (info.level < 5) ? 4 + 2 * ((info.level + 1) / 4) : 2 + 2 * ((info.level + 1) / 2);
		info.base_num -= (info.level < 5) ? 2 + ((info.level + 1) / 4) : 1 + ((info.level + 1) / 2);
	}
}

int	ft_atoi(char *str)
{
	int out;

	out = 0;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	if (*str == '-' || *str == '+')
		str++;
	while(*str >= '0' && *str <= '9')
		out = out * 10 + *(str++) - '0';
	return (out);
}

int	main(int argc, char **argv)
{
	int levels;

	if (argc == 1)
		return (0);
	if (argv[1][0] == '0' || argv[1][0] == '-')
		return (0);
	levels = ft_atoi(argv[1]);
	sastantua(levels);
	return (0);
}
