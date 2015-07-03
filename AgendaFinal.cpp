#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>

int borag(int);
int nuevoreg(char[][4][30],int,int);
int boreg(char[][4][30],int,int);
void modreg(char[][4][30],int,int);
void verag(char[][4][30],int,int);
void verreg(char[][4][30],int,int);
void salir();
int main(){system("color 2f");
           system("cls");
           int  i=20,con=0;  
           char opc,cadena[i][4][30];
           for(int q=0;q==0;){ 
                  printf("*******************************************************************************\n\t\t\t\tSUPER AGENDA 2011\n");
                  printf("*******************************************************************************\n\n");
                  printf("1) INGRESAR NUEVO REGISTRO\n2) BORRAR REGISTRO\n3) VER AGENDA \n4) VER REGISTRO\n5) MODIFICAR REGISTRO\n6) BORRAR AGENDA\n7) SALIR\n ");
                  printf("\nSELECCIONE UNA OPCION: ");
                  opc=getche();
                  system("cls");
                  switch(opc){
                        case '1':con=nuevoreg(cadena,i,con);break;
                        case '2':con=boreg(cadena,i,con);break; 
                        case '3':verag(cadena,i,con);break;
                        case '4':verreg(cadena,i,con);break;
                        case '5':modreg(cadena,i,con);break;
                        case '6':con=borag(con);break;
                        case '7':salir();break;
                        default:printf("\aOPCION INVALIDA\n\n");}}}
int nuevoreg (char arr[][4][30], int x,int i){
   int z=1,k=1;
   printf("\t\tREGISTRO NUEVO\n\n");
   if(i>19)
       printf("\aLA AGENDA ESTA LLENA, NO PUEDE AGREGAR NUEVOS REGISTROS\n\n");
     else{printf("NOMBRE Y APELLIDO:");fflush(stdin);gets(arr[i][0]);arr[i][0][0]=toupper(arr[i][0][0]);
          printf("TELEFONO:");fflush(stdin);gets(arr[i][1]);
          printf("CORREO:");fflush(stdin);gets(arr[i][2]);
          printf("CELUAR:");fflush(stdin);gets(arr[i][3]);
          i++;system("cls");}      
          return i;}
int boreg(char arr[][4][30],int x,int i){
    int reg,num;
    printf("\t\tBORRAR REGISTROS\n\n");
    if(i==0)
       printf("\n\aAUN NO HAY REGISTROS EN LA AGENDA\n\n");
      else if(i>0 && i<21){  
          printf("REGISTRO A BORRAR");
          scanf("%d",&reg);
          reg-=1;
          num=reg;
          if(reg>=0 && reg<i){
          for(reg=reg;reg<i;reg++){
                     strcpy(arr[reg][0],arr[reg+1][0]);
                     strcpy(arr[reg][1],arr[reg+1][1]);
                     strcpy(arr[reg][2],arr[reg+1][2]);
                     strcpy(arr[reg][3],arr[reg+1][3]);}
          printf("EL REGISTRO #%d HA SIDO BORRADO SATISFACTORIAMENTE!\n\n",num+1);
          i--;}
            else
              printf("\a\nEL REGISTRO %d NO PUEDE SER ELIMINADO PORQUE NO EXISTE\n",num+1);}
    return i;}
void modreg(char arr[][4][30],int x,int i){   
   int cm,om;
   printf("\t\tMODIFICACION DE REGISTROS \n\n");
   if(i!=0){
      printf("CUAL REGISTRO DESEA MODIFICAR?");
      scanf("%d",&cm);
      cm-=1;
      if(cm>=i)
         printf("\n\aEL REGISTRO %d NO PUEDE SER MODIFICADO PORQUE NO EXISTE\n",cm+1);
        else{ 
           printf("\nEL REGISTO QUE VA A MODIFICAR ES:\nNOMBRE Y APELLIDO: %s\nTELEFONO         : %s\nCORREO           : %s\nCELULAR          : %s\n",arr[cm][0],arr[cm][1],arr[cm][2],arr[cm][3]);
           for(int w=0; w==0;w++){
             printf("\nQUE DESEA MODIFICAR?\n\n1)MODIFICAR NOMBRE\n2)MODIFICAR TELEFONO\n3)MODIFICAR CORREO\n4)MODIFICAR CELULAR\n5)MODIFICAR TODO\n\nSELECCIONE UNA OPCION:");
             om=getche();    
             switch(om){
                 case '1': printf("\nNOMBRE Y APELLIDO NUEVO:");fflush(stdin);gets(arr[cm][0]);arr[cm][0][0]=toupper(arr[cm][0][0]);break;
                 case '2': printf("\nTELEFONO NUEVO:");fflush(stdin);gets(arr[cm][1]);break;
                 case '3': printf("\nCORREO NUEVO:");fflush(stdin);gets(arr[cm][2]);break;
                 case '4': printf("\nCELUAR NUEVO:");fflush(stdin);gets(arr[cm][3]);break;
                 case '5': printf("\nNOMBRE Y APELLIDO NUEVO:");fflush(stdin);gets(arr[cm][0]);arr[cm][0][0]=toupper(arr[cm][0][0]);
                           printf("\nTELEFONO NUEVO:");fflush(stdin);gets(arr[cm][1]);
                           printf("\nCORREO NUEVO:");fflush(stdin);gets(arr[cm][2]);
                           printf("\nCELUAR NUEVO:");fflush(stdin);gets(arr[cm][3]);break;
                 default:  printf("\aOPCION INVALIDA\n");w--;break;}}
      if(om>'0' && om<'6')         
                printf("\nEL REGISTRO HA SIDO MODIFICADO SATISFACTORIAMENTE!\n");}}
      else 
         printf("\n\aAUN NO PUEDE MODIFICAR REGISTROS: LA AGENDA ESTA VACIA\n\n");
              }
void verreg(char arr[][4][30],int x,int i){
     int vr;
     printf("\t\tVER REGISTRO\n\n");
     if(i==0)
         printf("\n\aNO PUEDE VER REGISTROS: LA AGENDA ESTA VACIA\n\n");
       else{ 
         printf("CUAL REGISTRO DESEA VER?");
         scanf("%d",&vr);
         vr-=1;
         if(vr<i && vr>=0){
             fflush(stdout);
             printf("\nREGISTRO #%d\nNOMBRE Y APELLIDO: %s\nTELEFONO         : %s\nCORREO           : %s\nCELULAR          : %s\n",vr+1,arr[vr][0],arr[vr][1],arr[vr][2],arr[vr][3]);}
          else if(vr<0 || (vr>=i && vr<20))
              printf("\aEL REGISTRO #%d NO EXISTE\n",vr+1);
            else if(vr>19)
                printf("\a\nERROR: LA AGENDA SOLO ALMACENA 20 REGISTROS\n");}
                }  
void salir(){
     char s;
     for(int v=0;v==0;v++){
     printf("DESEA SALIR DE SUPER AGENDA (S/N)");
     s=getche();
     s=toupper(s);
     switch(s){
          case 'S':exit(0);break;
          case 'N':int main();system("cls");break;
          default:v--;printf("\a\nOPCION NO DISPONIBLE\n");}}   
            }
void verag(char arr[][4][30],int i,int con){
    int id=1,sc;
    char ayuda[1][4][30];
    printf("\t\tAGENDA\n\n");                        
    if(con==0) 
        printf("\n\aLA AGENDA ESTA VACIA\n\n");
      else {  
         for(int f=0;f<con;f++){
            for(int x=f;x<con;x++){
            sc=strcmp(arr[x][0],arr[f][0]);
            if(sc==-1){
                       strcpy(ayuda[0][0],arr[x][0]);
                       strcpy(arr[x][0],arr[f][0]);
                       strcpy(arr[f][0],ayuda[0][0]);       
                       strcpy(ayuda[0][1],arr[x][1]);
                       strcpy(arr[x][1],arr[f][1]);
                       strcpy(arr[f][1],ayuda[0][1]); 
                       strcpy(ayuda[0][2],arr[x][2]);
                       strcpy(arr[x][2],arr[f][2]);
                       strcpy(arr[f][2],ayuda[0][2]); 
                       strcpy(ayuda[0][3],arr[x][3]);
                       strcpy(arr[x][3],arr[f][3]);
                       strcpy(arr[f][3],ayuda[0][3]);}}} 
         for(int l=0;l<con;l++){
         fflush(stdout);
         printf("\nREGISTRO #%d\nNOMBRE Y APELLIDO: %s\nTELEFONO         : %s\nCORREO           : %s\nCELULAR          : %s\n",id,arr[l][0],arr[l][1],arr[l][2],arr[l][3]);
         id++;}}
     }
int borag(int con){
    char ba;
    printf("\t\tBORRAR AGENDA\n");
    if(con==0)
       printf("\a\nLA AGENDA ESTA VACIA\n\n");
     else{
         for(int q=0;q==0;q++){ 
         printf("ESTA SEGURO QUE DESEA BORRAR LA AGENDA(S/N)?");
         ba=getche();
         ba=toupper(ba);
         switch(ba){
                    case 'S':con=0;printf("\nLA AGENDA HA SIDO BORRADA EXITOSAMENTE\n\n");break;
                    case 'N':printf("\nLA AGENDA NO FUE BORRADA\n\n");con=con;break;
                    default: system("cls");printf("\nOPCION INVALIDA\n");q--;}}}
    return con;
         }
