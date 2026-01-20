#include <stdio.h>
#include <unistd.h>


int main(int argc, char **argv)
{
    int i = 0;
    char *str = "Hello wolrd";
    while(str[i])
    {
        printf("%C", str[i]);
        i++;
    } 
    printf("\n");
    // Etape 1, ouvrir le fichier executable passer en parametre, donc un truc du style fopen(argv[1]) 
    // Etape 2, C'est un peut flou mais je crois que en gros je vais devoir identifier la partie "header", puis deplacer mon pointeur a l'endroit d'apres  
    // Etape 3, Alors la c'est un peut "chaud" il faut crypter ? une partie qui est le printf("woody-woodpacker") et le placer juste apres la partie header
    // Etape 4, Re copier le reste du fichier apres le printf 
    // Etape 5, Fin ? 

    // Pour ce qui est du "cryptage" je crois que en faite tu veux dire que je dois faire en sorte que sa soit compiler pour que sa soit un executable, ce qui correspond donc a une injection de code assembly non ? 
}
