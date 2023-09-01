/**
 * print_binary - prints binary representation of a decimal number
 * @n: number to print in binary
 */
void print_binary(unsigned long int n)
{
	int i, count = 0;
	unsigned long int current;

	for (i = 63; i >= 0; i--)
	{
		current = n >> i;

		switch (current & 1)
		{
		case 1:
			putchar('1');
			count++;
			break;
		default:
			if (count)
				putchar('0');
			break;
		}
	}

	if (!count)
		putchar('0');
}
