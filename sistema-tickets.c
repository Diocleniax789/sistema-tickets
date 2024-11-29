#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

struct tickCol{
    char incid[200];
    char modulo[15];
};

void carga_ticket(struct tickCol*,int*);
void limpia_cadenas(char*,char*);
char * identifica_modulo(char*);
char * mayor_modulo(struct tickCol*,int,int*);
void mostrar_incidencias(struct tickCol*, int);

int main(){
    struct tickCol tickets[200];
    char op, *mayor_mod;
    int tickets_cargados = 0, ocurrencias_del_modulo = 0;

    do{
        fflush(stdin);
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

    mostrar_incidencias(tickets,tickets_cargados);

    printf("\n");
    printf("\n ----------------------------------------------------------------");
    printf("\n El modulo de mayor ocurrencia es: %s y tiene %i incidencias",mayor_mod,ocurrencias_del_modulo);

    return 0;
}

void carga_ticket(struct tickCol *tickets, int *tickets_cargados){
    int j = 0;
    char cuerpo_mail[200],*modulo,caracter;

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
            } else if(strcmp(modulo,"Vuelo") == 0){
                strcpy(tickets[*tickets_cargados].incid,cuerpo_mail);
                strcpy(tickets[*tickets_cargados].modulo,modulo);
            } else{
                strcpy(tickets[*tickets_cargados].incid,cuerpo_mail);
                strcpy(tickets[*tickets_cargados].modulo,modulo);
            }
            (*tickets_cargados)++;

    printf("\n *** Carga finalizada *** \n");
}



char * identifica_modulo(char *cuerpo_mail) {
    static char mensaje[15];
    int i, j = 0;
    char modulo[15] = {0};

    for (i = 0; i < strlen(cuerpo_mail) && j < 15; i++) {
        if (cuerpo_mail[i] != ':') {
            modulo[j] = cuerpo_mail[i];
            j++;
        } else {
            break;
        }
    }
    modulo[j] = '\0';


    if (strcmp(modulo, "Hotel") == 0 || strcmp(modulo, "Vuelo") == 0 || strcmp(modulo, "Paquete") == 0) {
        strcpy(mensaje, modulo);
    } else {
        strcpy(mensaje, "***");
    }

    return mensaje;
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

void mostrar_incidencias(struct tickCol *tickets, int tickets_cargados){
    int i;

    printf("\n Listado de todas las incidencias \n");
    printf("\n");
    for(i = 0; i < tickets_cargados; i++){
        printf("\n ------------------------------------------- \n");
        printf("\n - Modulo: %s\n",tickets[i].modulo);
        printf("\n - Incidencia: %s\n",tickets[i].incid);
        printf("\n -------------------------------------------- \n");
    }
}

