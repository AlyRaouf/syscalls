#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main () { 
char *line = NULL;
  size_t len = 0;
  ssize_t read;
  while (1)
    {
      printf ("Pico prompt > ");
      read = getline (&line, &len, stdin);
      if (read == -1)
	break;
      if (read > 0 && line[read - 1] == '\n')
	line[read - 1] = '\0';
      int capacity = 16;
      char **args = malloc (capacity * sizeof (char *));
      if (!args)
	
	{
	  perror ("malloc");
	  continue;
	}
      int argc = 0;
      char *token = strtok (line, " ");
      while (token != NULL)
	
	{
	  args[argc++] = token;
	  if (argc >= capacity)
	    
	    {
	      capacity *= 2;
	      char **new_args = realloc (args, capacity * sizeof (char *));
	      if (!new_args)
		
		{
		  perror ("realloc");
		  break;
		}
	      args = new_args;
	    }
	  token = strtok (NULL, " ");
	}
      args[argc] = NULL;
      if (argc == 0)
	
	{
	  free (args);
	  continue;
	}
      if (strcmp (args[0], "exit") == 0)
	
	{
	  free (args);
	  printf ("Goodbye 7abiby o/ o/\n");
	  break;
	}
      
      else if (strcmp (args[0], "cd") == 0)
      {
	      if (argc > 1)
	  if (chdir (args[1]) != 0)
	    perror ("cd");
      
	  else
	    fprintf (stderr, "cd: missing argument\n");
      }
	else if (strcmp (args[0], "pwd") == 0)
	  
	  {
	    char cwd[1024];
	    if (getcwd (cwd, sizeof (cwd)) != NULL)
	      printf ("%s\n", cwd);
	    
	    else
	      perror ("pwd");
	  }
      
	else if (strcmp (args[0], "echo") == 0)
	  
	  {
	    for (int i = 1; i < argc; i++)
	      
	      {
		printf ("%s%s", args[i], (i == argc - 1) ? "" : " ");
	      } printf ("\n");
	  }
      
	else
	  
	  {
	    pid_t pid = fork ();
	    if (pid < 0)
	      perror ("fork");
	    
	    else if (pid == 0)
	      
	      {
		execvp (args[0], args);
		perror ("execvp");
		exit (EXIT_FAILURE);
	      }
	    
	    else
	      wait (NULL);
	  }
      free (args);
    }
  free (line);
  return 0;
}


