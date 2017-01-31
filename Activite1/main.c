#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN 1

int menu();
unsigned int valRand(unsigned int max);
unsigned int choix(unsigned int max);
unsigned int coup(unsigned int number,unsigned int choice,unsigned int compt);

int main()
{
    srand(time(NULL));

    unsigned int number;
    unsigned int choice = 0;
    unsigned int compt = 0;
    unsigned int max =100;

    printf("Bienvenue au jeu du plus ou moins!\n");
    do{
        max = menu();
        if(max == 0)
            break;
        number = valRand(max);

        //Test valeur aléatoire
        //printf("number = %u\n", number);

        do{
            choice = choix(max);
            compt = coup(number,choice,compt);
        }while(choice != number);
    }while(max != 0);
    printf("Au revoir!\n");
    return 0;
}

int menu(){
 int choix = 0;

    while (choix < 1 || choix > 4)
    {
        printf("Menu :\n");
        printf("1 : max = 100\n");
        printf("2 : max = 1000\n");
        printf("3 : max = 10000\n");
        printf("4 : quitter\n");
        printf("Votre choix ?");
        scanf("%d", &choix);
    }
    switch(choix){
        case 1:
            return 100;
        break;
        case 2:
            return 1000;
        break;
        case 3:
            return 10000;
        break;
        case 4:
            return 0;
        break;
    }
}

unsigned int valRand(unsigned int max){
    return (rand()%(max - MIN + 1)) + MIN;
}

unsigned int choix(unsigned int max){
    unsigned int choice = 0;
    do{
        printf("Quel est le nombre ? ");
        scanf("%u",&choice);
    }while(choice > max-1 || choice < MIN);
    return choice;
}

unsigned int coup(unsigned int number,unsigned int choice,unsigned int compt){
    if(choice == number){
        compt++;
        printf("Bravo! Vous avez trouvez le chiffre qui etait : %u\nNombre de coup egale : %u\n\n",number,compt);
    }else{
        if(choice > number){
            compt++;
            printf("Plus petit :) \nNombre de coup egale : %u\n",compt);
        }else{
            compt++;
            printf("Plus grand :) \nNombre de coup egale : %u\n",compt);
        }
    }
    return compt;
}
