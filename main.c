#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char charCtersM[]={"ABCDEFGHIJKLMNOPQRSTVWXYZ"};
char charCters[]={"abcdefghijklmnopqrstvwxyz"};
char enc[]={'|','"','@','#','%','&','/','(',')','*','=','?','+','-','}','{','[',']'
        ,':','.',',',';','<','>','0'};
char stringEncrypted[100];
int compare(char caden[], char letras){
    int comparar=0;
    for (int k=0; k<strlen(caden); k++){
        if (letras == caden[k]){
            comparar += 1;
        }
    }

    return comparar;

}
int coincidence(char character,char stringTwo[]){
    int accumulator=0;
    for (int i = 0; i < strlen(stringTwo);++i) {
        if(character==stringTwo[i] || character==stringTwo[i]-32){
            accumulator++;
            i++;
        }
    }
    return accumulator > 0 ? 1 : 0;
}
void wordCounter(){
    int counter = 0;
    char *aux;
    char message[100];
    char word[10];
    do{
        printf("---------------Contar cantidad de palabras---------------\n");
        printf("Digite un mensaje:\n");
        gets(message);
        printf("Digite la palabra que desea buscar:\n");
        gets(word);
        fflush(stdin);
    }while (strlen(message)==0 && word!=NULL);
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
int verifMin(char character){
    int j=-1,k=0;
    for (int i = 0; i < strlen(charCters); ++i) {
        if(charCters[i]==character || charCtersM[k]==character){
            j=0;
            j=i;
            break;
        }
        k++;
    }
   // printf("El valor de j  es %d \n",j);
    return j!=-1?j:60;
}
void ownName() {
    int i;
    char cadena[150];
    do{
        printf("Ingrese la cadena de texto dejando un espacio inicial: \n" );
        gets(cadena);
    }while (strlen(cadena)==0);
    for(i=0; cadena[i]; i++){

        if(cadena[i - 1] == ' '){
            cadena[i] = toupper(cadena[i]);
        }
        else{
            cadena[i] = tolower(cadena[i]);
        }
    }
    printf("La cadena queda como:");
    printf(" %s ", cadena);
}
void intersection () {
    char cadena1 [ 100 ], cadena2 [ 100 ];
    for (int i = 0; i <strlen(cadena2 ); ++i) {
        char value=tolower(cadena2[i]);
        cadena2[i]=value;
    }
    int i, j;
    char interseccion [ 100 ] = " " ;

    printf ( "Ingrese una palabra: \n " );
    fgets (cadena1, 100 , stdin);
    printf ( "Ingrese otra palabra: \n " );
    fgets (cadena2, 100 , stdin);

    for(i = 0 ; i <( strlen (cadena1) - 1 ); i ++) {
        for (j = 0 ; j <( strlen (cadena2) - 1 ); j ++) {
            if (cadena1 [i] == cadena2 [j]) {
                if ( compare (interseccion, cadena1 [i]) == 0 ) {
                    interseccion [ strlen (interseccion)] = cadena1 [i];
                }
            }
        }
    }
    printf ( " \n " );
    printf ( "La interseccion es " );
    printf ( "%s \n " , interseccion);
}
int compareCharacters(char letras){
    int j=-1,k=0;
    for (int i = 0; i < strlen(charCters); ++i) {
        if(enc[i] == letras || enc[k] == letras){
            j=0;
            j=i;
            break;
        }
        k++;
    }
    // printf("El valor de j  es %d \n",j);
    return j!=-1?j:60;
}
void stringDecrypt(){
    if(strlen(stringEncrypted)>1){
        printf("La cadena encriptada es: %s\n",stringEncrypted);
        char paraDesencriptar[100];
        int k=0,posicion=0;
        for (int i = 0; i < strlen(stringEncrypted); ++i) {
            if(compareCharacters(stringEncrypted[i]) != 60 ){
                posicion= compareCharacters(stringEncrypted[i]);
                //printf("%d\n",posicion);
                paraDesencriptar[k]=charCtersM[posicion];
                k++;

            }else{
                paraDesencriptar[k]=stringEncrypted[i];
                k++;

            }
        }
        paraDesencriptar[k]='\0';

        printf("La cadena desenctriptada es: %s\n", paraDesencriptar);
    } else{
        printf("Debe primero hacer la encriptacion de una cadena");
    }
}
void encrypted(char string[]){
    char sEnctrypted[100];
    int k=0,posi=0;
    for (int i = 0; i <strlen(string)-1; ++i) {
        if(verifMin(string[i])!=60 ){
            posi=verifMin(string[i]);
            sEnctrypted[k]=enc[posi];
            k++;
        }else{
            sEnctrypted[k]=string[i];
            k++;
        }
    }
    sEnctrypted[k]='\0';
    printf("La cadena enctriptada es: %s\n",sEnctrypted);
    strcpy(stringEncrypted,sEnctrypted);

}
void encryptString(){
    char string[100];
    do {
        printf("---------------Encriptar cadena---------------\n");
        printf("Digite lo que quiere encriptar \n");
        fgets(string,100,stdin);
        fflush(stdin);
    }while (strlen(string)==0);
    encrypted(string);
}

void deleteCharactersLeft(char string[],char stringTwo[]){
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
        for (int i = accumulator; i <strlen (string); ++i) {
            res[k]=string[i];
            k++;
        }
        res[k]='\0';
        printf("%s\n",res);
    }else{
        printf("%s \n",string);
    }
}
void deleteCharactersRight(char string[],char stringTwo[]){
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
    }while (strlen(string)<3 && strlen(stringTwo)<3 || option!=1 && option!=2);
    if(option==1){
        deleteCharactersRight(string,stringTwo);
    }else if(option==2){
        deleteCharactersLeft(string,stringTwo);
    }
}
void removeCharacter(char string[], char character){
    int j=0;
    char stringTw[strlen(string)];
    for (int i = 0; i < strlen(string); ++i) {
        if(string[i]!=character && string[i]!=character-32){
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
void fillCharacterRL(){
    char message[100];
    char aux[100];
    char character[10];
    int nTimes = 0;
    int direction = 0;

    printf("---------------Llenar caracteres por izquierda o derecha---------------\n");
    printf("Digite un mensaje:\n");
    gets(message);
    printf("Digite el caracter que desea concatenar:\n");
    scanf("%c", character);
    printf("Digite el numero de veces que desea concatenar el caracter:\n");
    scanf("%d", &nTimes);
    printf("Digite 1 para insertar por derecha o 2 para insertar por izquierda: \n");
    scanf("%d", &direction);
    fflush(stdin);

    *aux=*character;

    for (int i = 0; i < nTimes-1; ++i) {
        aux[i] = *character;
    }
    strcat(aux,character);
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
    printf("%d\n%d",strlen(message1),strlen(message2));
    do{
        printf("---------------Diferencia entre dos cadenas---------------\n");

        printf("Digite el mensaje principal: \n");
        gets(message1);

        printf("Digite el mensaje guia: \n");
        gets(message2);

        fflush(stdin);
    }while (strlen(message1)<3 && strlen(message2)<3);
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
            case 1 :ownName();
                system("pause");
                break;

            case 2 :wordCounter();
                system("pause");
                break;

            case 3 :
                encryptString();
                system("pause");
                break;

            case 4 :stringDecrypt();
                system("pause");
                break;

            case 5 :fillCharacterRL();
                system("pause");
                break;

            case 6 :deleteCharacter();
                system("pause");
                break;

            case 7 :intersection();
                system("pause");
                break;

            case 8 :messagesDifference();
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
