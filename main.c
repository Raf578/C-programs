#include <stdio.h>
#include <stdlib.h>
#define MAX 80+1
int main()
{
    FILE *fpIN,*fpOUT;
    char filename[FILENAME_MAX];
    char s[MAX];
    int i,cont,charinput,charoutput;
    /*apertura con controllo dei due file*/
    printf("Inserisci il nome del file di input\n");
    gets(filename);
    if((fpIN=fopen(filename,"r"))==NULL)
    {
        fprintf(stderr,"Errore nell'paertura del file: %s\n",filename);
        return EXIT_FAILURE;
    }

    printf("Inserisci il nome del file di output\n");
    gets(filename);
    if((fpOUT=fopen(filename,"w"))==NULL)
    {
        fprintf(stderr,"Errore nell'paertura del file: %s\n",filename);
        return EXIT_FAILURE;
    }
    charinput=charoutput=0;
    /*acquisisco la stringa e la comprimo*/
    while(fgets(s,MAX,fpIN)!=NULL)
    {
        cont=1;
        for(i=0; s[i]!='\0' && s[i]!='\n' ; i++)
        {
            charinput++;
            if(s[i]==s[i+1])
                cont++;
            else
            {
                charoutput+=fprintf(fpOUT,"%c%d",s[i],cont);
                cont=1;
            }
        }
        fprintf(fpOUT,"\n");
    }
    fclose(fpIN);
    fclose(fpOUT);
    printf("File originale: %d caratteri\n",charinput);
    printf("File compresso: %d caratteri\n",charoutput);
    printf("Rapporto compressione: %.2f%% \n",((double)charoutput/charinput)*100.0);
    return 0;
}
