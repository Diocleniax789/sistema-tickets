#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

struct tickCol{
    char incid[200];
    char modulo[15];
};

void carga_ticket(struct tickCol*,int*);
char * identifica_modulo(char*);
char * mayor_modulo(struct tickCol*,int,int*);

int main(){
    struct tickCol tickets[200];
    char op, *mayor_mod;
    int tickets_cargados = 0, ocurrencias_del_modulo = 0;

    do{

        carga_ticket(tickets,&tickets_cargados);

        do{
            fflush(stdin);
            printf("\n - Agregar otro ticket? Ingrese <s/n> : ");
            scanf("%c",&op);
            if(op != 's' && op != 'n'){
                printf("\n x ERROR. INGRESE 's' O 'n' x \n");
            }
        } while(op != 's' && op != 'n');

    } while(op != 'n');

    mayor_mod = mayor_modulo(tickets,tickets_cargados,&ocurrencias_del_modulo);

    printf("\n");
    printf("\n ----------------------------------------------------------------");
    printf("\n El modulo de mayor ocurrencia es: %s y tiene %i incidencias",mayor_mod,ocurrencias_del_modulo);

    return 0;
}

void carga_ticket(struct tickCol *tickets, int *tickets_cargados){
    int i,j = 0;
    static char cuerpo_mail[200];
    char modulo[15],caracter;

    printf("\n =======================");
    printf("\n - CARGA DE TICKETS - \n");
    for(i = 0; i < *tickets_cargados; i++){
        printf("\n + Escriba el cuerpo: ");
        while((caracter = getchar()) != EOF && j < 200){
            cuerpo_mail[j] = caracter;
            j++;
        }

        cuerpo_mail[j] = '\0';

        modulo = identifica_modulo(cuerpo_mail);
        if(strcmp(modulo,"Hotel") == 0){
            strcpy(tickets[*tickets_cargados].incid,cuerpo_mail);
            strcpy(tickets[*tickets_cargados].modulo,modulo);
            (*tickets_cargados)++;
        } else if(strcpy(modulo,"Vuelo") == 0){
            strcpy(tickets[*tickets_cargados].incid,cuerpo_mail);
            strcpy(tickets[*tickets_cargados].modulo,modulo);
            (*tickets_cargados)++;
        } else{
            strcpy(tickets[*tickets_cargados].incid,cuerpo_mail);
            strcpy(tickets[*tickets_cargados].modulo,modulo);
            (*tickets_cargados)++;
        }
    }

    printf("\n *** Carga finalizada * \n");
}


char * identifica_modulo(char *cuerpo_mail){
    static mensaje[20];
    int detectar_modulo,i;
    char copia_cuerpo_mail[200], delim[] = " ", *modulo;

    modulo = strtok(copia_cuerpo_mail,delim);

    strcpy(copia_cuerpo_mail,cuerpo_mail);

    while(modulo != NULL && delim[] != " " ){
        strcpy(mensaje,modulo);
        modulo = strtok(NULL,delim);
    }

    if(strcmp(modulo,"Modulo") == 0){
        return mensaje;
    } else if(strcmp(modulo,"Vuelo") == 0){
        return mensaje;
    } else if(strcmp(modulo,"Hotel")){
        return mensaje;
    } else{
        strcpy(mensaje,"***");
        return mensaje;
    }
}
