#include "fillit.h"
#include "global.h"

void init_global()
{
	int i;

	num = 0;
	i = 0;
	while (i < 26)
	{
		letter[i] = 'A' + i;
		i++;
	}
}

void	fillit(int argc, char** argv)
{
	t_list	*list;
	t_data	*data;

	list = ft_init_list(list);
	data = ft_init_data(data);
	if (argc == 2)
	{
		if ((list = ft_pre_openfile(argv[1], list) != NULL)
		{


			return;
		}
	}
	ft_putstr("error/n");
}
