void	print_stacks(t_bucket *a, t_bucket *b, int size)
{
	int	i;

	i = 0;
	printf("\nA             B          \n");
	printf("-             -          \n");
	while (i < size)
	{
		if (i < a->current_size)
			printf("%-14d", a->stack[i]);
		else
			printf("              ");
		if (i < b->current_size)
			printf("%-11d\n", b->stack[i]);
		else
			printf("           \n");
		i++;
	}
	printf("-             -          \n");
}