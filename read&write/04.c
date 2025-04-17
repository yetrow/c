// crt_fscanf_s.c
// This program writes formatted
// data to a file. It then uses fscanf to
// read the various data back from the file.

#include <stdio.h>
#include <stdlib.h>

FILE *stream;

int main( void )
{
   long l;
   float fp;
   char s[81];
   char c;

   errno_t err = fopen_s( &stream, "D:\\桌面11\\c读写\\1.txt", "r" );
   if( err )
      printf_s( "The file fscanf.out was not opened\n" );
   else
   {
    if(fscanf_s(stream,"%80s",s,(unsigned)_countof(s))!=1)
    {
        printf("读取字符串失败\n");
    }
    if(fscanf_s(stream,"%lds",&l)!=1)
    {
        printf("读取ld失败\n");
    }
    if(fscanf_s(stream,"%f",&fp)!=1)
    {
        printf("读取lf失败\n");
    }
    if(fscanf_s(stream," %c",&c,1)!=1)
    {
        printf("读取c失败\n");
    }


      // Output data read:
      printf( "%s\n", s );
      printf( "%ld\n", l );
      printf( "%f\n", fp );
      printf( "%c\n", c );

      fclose( stream );
   }
}