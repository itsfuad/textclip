#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int main(int argc,char **argv){unsigned width=72,column=0;int c,wordlen=0;char word[4096];FILE *in=stdin;
 if(argc>1){char *end;unsigned long value=strtoul(argv[1],&end,10);
 if(*end||value<8||value>200){fprintf(stderr,"width must be 8..200\n");return 2;}width=(unsigned)value;}
 if(argc>2){in=fopen(argv[2],"r");if(!in){perror(argv[2]);return 2;}}
 while((c=fgetc(in))!=EOF){
 if(c=='\n'){if(wordlen){word[wordlen]=0;printf("%s",word);column+=(unsigned)wordlen;wordlen=0;}putchar('\n');column=0;continue;}
 if(isspace((unsigned char)c)){
  if(wordlen){word[wordlen]=0;if(column && column+(unsigned)wordlen+1>width){putchar('\n');column=0;}
   if(column){putchar(' ');column++;}fputs(word,stdout);column+=(unsigned)wordlen;wordlen=0;}continue;}
 if(wordlen>=4094){fprintf(stderr,"word too long\n");return 2;}word[wordlen++]=(char)c;
 }
 if(wordlen){word[wordlen]=0;if(column && column+(unsigned)wordlen+1>width)putchar('\n');else if(column)putchar(' ');fputs(word,stdout);}if(in!=stdin)fclose(in);
 return 0;}
