#include "../push_swap.h"

t_stack *ft_filllist(char **argv)
{
	t_stack *seq;
	char **str;
	int argc;
	int count;
	int amount;

	seq = NULL;
	argc = 1;
	amount = 0;
	while (*(argv + argc))
	{
		if (ft_strchr(*(argv + argc), 32))
		{
			str = ft_split(*(argv + argc++), 32);
			count = 0;
			while (*(str + count))
				ft_numintolist(&seq, ft_lstnew((int)ft_atoi(*(str + count++)), amount++));
			free(*str);
		}
		else
			ft_numintolist(&seq, ft_lstnew((int)ft_atoi(*(argv + argc++)), amount++));
	}
	return (seq);
}

void	ft_numintolist(t_stack **seq, t_stack *new)
{
	t_stack *seqnum;

	if (*seq == NULL)
		*seq = new;
	else
	{
		seqnum = ft_lstlast(*seq);
		seqnum->next = new;
		seqnum->next = NULL;
	}
}

t_stack *ft_lstlast(t_stack *seq)
{
	while (seq->next)
		seq = seq->next;
	return (seq);
}

t_stack	*ft_lstnew(int content, int amount)
{
	t_stack *seq;

	seq = malloc(sizeof(t_stack));
	if (!seq)
		return (NULL);
	seq->value = content;
	seq->order = amount;
	seq->next = NULL;
	return (seq);
}

//t_stack *ft_order(t_stack *seq)
//{
//	while (seq->next)
//}