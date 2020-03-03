#include <stdio.h>
#include <stdlib.h>

void get_name( char line[], int maxlen )
{
  printf( "Please enter your name: " );

  // reads at most maxlen-1 chars from stdin, up to first newline, 
  // EOF or error.
  if( fgets( line, maxlen, stdin ) == 0 ) // we ALWAYS check for I/O errors
  {
    perror( "failed to read a name" );
    exit(1);
  }
}	

int main( void )
{
  char name[1024];
  get_name( name, 1024 );

  // we don't need to be lucky this time
  printf( "Your name is %s", name );

  return 0;
}	       
