#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	
	char command[6];
	while(1)
	{
		printf("Femto prompt > ");
		fgets(command, sizeof(command), stdin);
		while(command[0] == ' ')
		{
			for(int i = 0; i < sizeof(command) - 1; i++)
			{

				command[i] = command[i + 1];
			}	
			command[4] = fgetc(stdin);

		}
		if(strcmp(command, "echo ") == 0)
		{

			int space_flag = 0;
			char *buffer = malloc(sizeof(char));
			scanf("\n");
			do
			{
				*buffer = fgetc(stdin);
				if((*buffer == ' ') && space_flag) continue;
				printf("%c", *buffer);
				if(*buffer == ' ') space_flag = 1;
				else space_flag = 0;

			} while(*buffer != '\n');
			free(buffer);
		}

		else if(strcmp(command, "exit\n") == 0)
		{
			printf("Ma3 Alf Salama O/\n");
			exit(0);
		}
		else if(command[0] == '\n') continue;
		else
		{
			printf("Femto shell, so only echo or exit!\n");
			char *buffer = malloc(sizeof(char));
			do *buffer = fgetc(stdin);
			while(*buffer != '\n');
			free(buffer);
		}

	}
	
	return 0;

}
