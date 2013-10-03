#include <stdio.h>
#include <string.h>

int main()
{
	char s[256];
	int i, n, k = 0;
	
	while(fgets(s, 256, stdin) != NULL)
	{
		n = strlen(s);
		
		for (i = 0; i < n; i++)
		{
			if (s[i] == '"')
			{
				if (k == 0)
				{
					printf("``");
					k = 1;
				}
				else
				{
					printf("''");
					k = 0;
				}
			}
			else
			{
				printf("%c", s[i]);
			}
		}
	}
	
	return 0;
}
