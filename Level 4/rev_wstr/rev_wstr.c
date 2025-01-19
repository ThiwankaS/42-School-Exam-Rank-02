#include <unistd.h>

int main(int argc, char **argv)
{
	int start;
	int end;
	int i = 0;
	int first;
		
	if(argc == 2)
	{   
		while( argv[1][i] != '\0' && (argv[1][i] == ' ' || argv[1][i] == '\t'))
			i++;
		first = i;
		while(argv[1][i] != '\0')
			i++;
		while(i >= first)
		{
			while( argv[1][i] == '\0' || argv[1][i] == ' ' || argv[1][i] == '\t')
				i--;
			end = i;
			while(argv[1][i] && argv[1][i] != ' ' && argv[1][i] != '\t')
				i--;
			start = i + 1;
			int  flag;
			flag = start;
			while(start <= end)
			{
				write (1, &argv[1][start],1);
				start++;		
			}
			if (flag !=first)
				write(1, " ", 1);
		}
	}
	write(1, "\n", 1);
}
