#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void wordCounter(){
    int counter = 0;
    char *aux;
    char message[100];
    char word[10];
    printf("---------------Contar cantidad de palabras---------------\n");
    printf("Digite un mensaje:\n");
    gets(message);
    printf("Digite la palabra que desea buscar:\n");
    fflush(stdin);
    gets(word);
    aux = strtok(message," ,.:;");

    while (aux != NULL){
        if (stricmp(aux, word)==0){
            counter++;
        }
        aux=strtok(NULL," ,.:;");
    }
    fflush(stdin);
    printf("La palabra - %s - esta %d veces.\n",word,counter);
}

void fillCharacterRL(){
    char message[100];
    char *aux;
    char character[10];
    int nTimes = 0;
    int direction = 0;

    printf("---------------Llenar caracteres por izquierda o derecha---------------\n");

    printf("Digite un mensaje:\n");
    gets(message);

    printf("Digite el caracter que desea concatenar:\n");
    scanf("%c",character);

    printf("Digite el numero de veces que desea concatenar el caracter:\n");
    scanf("%d",&nTimes);

    printf("Digite 1 para insertar por derecha o 2 para insertar por izquierda: \n");
    scanf("%d", &direction);

    fflush(stdin);

    aux=character;

    strncat(aux,character,(nTimes-1));

    if (direction==1){
        strcat(message,aux);
        printf("%s\n",message);
    }else{
        strcat(aux,message);
        printf("%s\n",aux);
    }

}

void messagesDifference() {
    int size1;
    int size2;
    short i = 0;
    char message1[100];
    char message2[100];
    printf("---------------Diferencia entre dos cadenas---------------\n");

    printf("Digite el mensaje principal: \n");
    gets(message1);

    printf("Digite el mensaje guia: \n");
    gets(message2);

    size1=strlen(message1);
    size2=strlen(message2);
    fflush(stdin);
    while (message1[i]!='\0') {
        for (int j = 0; j < size2; ++j) {
            if (message1[i]==message2[j] || message1[i]==message2[j]-32 || message1[i]-32==message2[j]) {
                for (int k = i; k < size1 ; ++k) {
                    message1[k]=message1[k+1];
                }
                size1--;i--;
            }
        }
        i++;
    }

    printf("%s\n",message1);
}

void mainMenu(){
    char *menu="\n---------------Taller---------------\n "
               "1.Convertir nombre propio\n "
               "2.Contar cantidad de palabras \n "
               "3.Encriptar cadena \n "
               "4.Desencriptar cadena \n "
               "5.Llenar caracteres por izquierda o derecha \n "
               "6.Borrar caracteres de una cadena \n 7.Interseccion \n"
               " 8.Diferencia entre dos cadenas \n"
               " 9.Borrar caracteres izquierda o derecha \n"
               " 10.Salir \n"
               "-----------------------------------\n";
    int option;
    do{
        system("cls");
        printf("%s",menu);
        scanf("%d",&option);
        fflush(stdin);
        switch (option) {
            case 1 :
                system("pause");
                break;

            case 2 :
                wordCounter();
                system("pause");
                break;

            case 3 :
                system("pause");
                break;

            case 4 :
                system("pause");
                break;

            case 5 :
                fillCharacterRL();
                system("pause");
                break;

            case 6 :
                system("pause");
                break;

            case 7 :
                system("pause");
                break;

            case 8 :
                messagesDifference();
                system("pause");
                break;

            case 9 :
                system("pause");
                break;
        }
    }while(option!=10);
    printf("Cerrando ...");
}
int main() {
    mainMenu();
    return 0;
}
