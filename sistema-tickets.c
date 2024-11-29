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
    int j = 0;
    static char cuerpo_mail[200];
    static char *modulo;
    char caracter;

        system("cls");
        printf("\n =======================");
        printf("\n - CARGA DE TICKETS - \n");
        printf("\n + Escriba el cuerpo: \n");
        printf("   -----------------\n");
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

    printf("\n *** Carga finalizada *** \n");
}


char * identifica_modulo(char *cuerpo_mail){
    static char modulo[15];
    int detectar_modulo,i,j;
    char copia_cuerpo_mail[200];

    strcpy(copia_cuerpo_mail,cuerpo_mail);

    j = 0;
    for(i = 0; i < 200 && j < 15; i++){
        if(copia_cuerpo_mail[i] != '\n'){
            modulo[j] = copia_cuerpo_mail[i];
            j++;
        }else{
            break;
        }
    }

    if(strcmp(modulo,"Hotel") == 0 || strcmp(modulo,"Vuelo") == 0 || strcmp(modulo,"Paquete") == 0){
        return modulo;
    } else{
        strcpy(modulo,"***");
        return modulo;
    }
}

char * mayor_modulo(struct tickCol *tickets, int tickets_cargados, int *ocurrencias_del_modulo){
    int ocurrencia_hotel = 0, ocurrencia_vuelo = 0, ocurrencia_paquete = 0,i,mayor_modulo;
    static char modulo[15];
    for(i = 0; i < tickets_cargados; i++){
        if(strcmp(tickets[i].modulo,"Hotel") == 0){
            ocurrencia_hotel++;
        } else if(strcmp(tickets[i].modulo,"Vuelo") == 0){
            ocurrencia_vuelo++;
        } else{
            ocurrencia_paquete++;
        }
    }

    if(ocurrencia_hotel > ocurrencia_vuelo && ocurrencia_hotel > ocurrencia_paquete){
        strcpy(modulo,"Hotel");
        *ocurrencias_del_modulo = ocurrencia_hotel;
    } else if(ocurrencia_vuelo > ocurrencia_hotel && ocurrencia_vuelo > ocurrencia_paquete){
        strcpy(modulo,"Vuelo");
        *ocurrencias_del_modulo = ocurrencia_vuelo;
    } else{
        strcpy(modulo,"Paquete");
        *ocurrencias_del_modulo = ocurrencia_paquete;
    }

    return modulo;
}
