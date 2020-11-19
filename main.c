#include <stdio.h>
#include <stdlib.h>
void mainMenu(){
    char *menu="\n---------------Taller---------------\n "
               "1.Convertir nombre propio\n "
               "2.Contar cantidad de palabras \n "
               "3.Encriptar cadena \n "
               "4.Desencriptar cadena \n 5.Llenar caracteres por izquierda o derecha \n "
               "6.Borrar caracteres de una cadena \n 7.Interseccion \n"
               " 8.Diferencia entre dos cadenas \n"
               " 9.Borrar aracteres izquierda o derecha \n"
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
            break;

            case 2 :;
            break;

            case 3 :;
            break;

            case 4 :;
            break;

            case 5 :;
            break;

            case 6 :;
            break;
            case 7 :;
            break;
            case 8 :;
            break;
            case 9 :;
            break;
        }
    }while(option!=10);
    printf("Cerrando ....");
}
int main() {
    mainMenu();
    return 0;
}
