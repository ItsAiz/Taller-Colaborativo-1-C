#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
int encrypted(char string[]){

}
void encryptString(){
    char string[4];
    printf("Digite lo que quiere encriptar \n");
    scanf("%s",&string);
}

int coincidence(char character,const char *stringTwo){
    int accumulator=0;
    for (int i = 0; i <strlen(stringTwo); ++i) {
        if(character==stringTwo[i]){
            accumulator++;
        }
    }
    return accumulator > 0 ? 1 : 0;
}
void deleteCharactersLeft(char *string,const char *stringTwo){
    int accumulator=0,k=0;
    char res[100];
    for (int j = 0; j <strlen(string)-2 ; ++j) {
        if(coincidence(string[j],stringTwo)==1){
            string[j]=' ';
            accumulator++;
        }else{
            break;
        }
    }
    if(accumulator>0){
        for (int i = 0; i <strlen(string); ++i) {
            if(string[i]!=' '){
                res[k]=string[i];
                k++;
            }
        }
        res[k]='\0';
        printf("%s\n",res);
    }else{
        printf("%s \n",string);
    }
}
void deleteCharactersRight(char *string,const char *stringTwo){
    for (int i = strlen(string)-2; i >= 0; --i) {
        if(coincidence(string[i],stringTwo)==1){
            string[i]=' ';
        }else{
            break;
        }
    }
    printf("%s\n",string);
}
void deleteCharactersRightOrLeft(){
    int option=0;
    char string[100];
    char stringTwo[100];
    do{
        printf("---------------Borrar caracteres izquierda o derecha---------------\n");
        printf("Digite una cadena: \n");
        fgets(string,100,stdin);
        printf("Digite una segunda cadena: \n");
        fgets(stringTwo,100,stdin);
        printf("Digite 1.Derecha 2.Izquierda\n");
        scanf("%d",&option);
        fflush(stdin);
    }while (strlen(string)==1 || strlen(stringTwo)==1 || option!=1 || option!=2);
    if(option==1){
        deleteCharactersRight(string,stringTwo);
    }else if(option==2){
        deleteCharactersLeft(string,stringTwo);
    }
}
void removeCharacter(const char *string, char character){
    int j=0;
    char stringTw[strlen(string)];
    for (int i = 0; i < strlen(string); ++i) {
        if(string[i]!=character){
            stringTw[j]=string[i];
            j++;
        }
    }
    stringTw[j]='\0';
    printf("La cadena sin el caracter %c es :%s \n",character,stringTw);
}
void deleteCharacter(){
    char string[100];
    char character;
    do{
        printf("---------------Borrar caracter de una cadena---------------\n");
        printf("Digite una cadena: \n");
        fgets(string,100,stdin);
        printf("Digite el caracter que desea borrar: \n");
        scanf("%c",&character);
        fflush(stdin);
    }while(strlen(string)==1 || character==' ');
    printf("Cadena inicial: %s\n ",string);
    removeCharacter(string, character);
}
void mainMenu(){
    char *menu="\n---------------Taller---------------\n "
               "1.Convertir nombre propio\n "
               "2.Contar cantidad de palabras \n "
               "3.Encriptar cadena \n "
               "4.Desencriptar cadena \n 5.Llenar caracteres por izquierda o derecha \n "
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
            case 1 :;
                system("pause");
                break;

            case 2 :;
                system("pause");
                break;

            case 3 :
                encryptString();
                system("pause");
                break;

            case 4 :;
                system("pause");
                break;

            case 5 :;
                system("pause");
                break;

            case 6 :deleteCharacter();
                system("pause");
                break;

            case 7 :;
                system("pause");
                break;

            case 8 :;
                system("pause");
                break;

            case 9 : deleteCharactersRightOrLeft();
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
