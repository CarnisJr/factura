#include<stdlib.h>
#include<stdio.h>
#include<string.h>

int main(void){

    char cedula[10] = "1723372825";

    //variables de ingreso de datos
    char nombre[100], apellido[100], ingresoCedula[10], direccion[100], telefono[10];

    //variables precios y cantidad de productos
    int cant, precioUnidad, total;
    int arrayCantidad[5], arrayPrecioUnidad[5], arrayDescripcion[5][100];
    char descripcion[100];

    //Variables para verificar la cedula
    char digitoChar;
    int digito, numeroFinal = 0, residuo;
    int sumatoria = 0, flag = 0, verificarCedula;


    //Verificar cedula
    do{
        
        printf("\t---FACTURA---\n");
        fflush(stdin);
        printf("Cedula:\t ");
        scanf("%s", ingresoCedula);
        printf("\n");
        for (size_t i = 0; i < 9; i++){
            
            digito = (int) ingresoCedula[i] - 48;

            if(flag == 0){

                digito = digito * 2;
                if(digito > 9){

                    digito = digito - 9;
                }

                flag = 1;
            }else{

            flag = 0;
            }
            
            sumatoria = sumatoria + digito;
        }
        
        residuo = 10 - (sumatoria % 10);

        if(residuo == 10)
            numeroFinal = 0;
        else
            numeroFinal = (sumatoria + residuo) - sumatoria;
        ingresoCedula[9] = (char) numeroFinal + 48;
        
        verificarCedula = strcmp(cedula, ingresoCedula);
        
        if(verificarCedula != 0){

            printf("ERROR, Cedula incorecta\n");
            system("pause");
            system("cls");
        }

    }while(verificarCedula != 0);
        
    printf("Nombre:\t ");
    scanf("%s", nombre);
    printf("\n");
    printf("Apellido:\t ");
    scanf("%s", apellido);
    printf("\n");
    printf("Direccion:\t ");
    scanf("%s", direccion);
    printf("\n");
    printf("Telefono:\t ");
    scanf("%s", telefono);
    printf("\n");
    system("pause");
    system("cls");

        
    //ingreso de datos cantidad y precios
    for(int i = 1; i <= 5; i++){

        printf("Ingrese la cantidad del producto %d: ", i);
        scanf("%d", &cant);
        printf("Ingrese el precio por unidad del producto %d: ", i);
        scanf("%d", &precioUnidad);
        printf("Ingrese el nombre del producto del producto %d: ", i);
        scanf("%s", descripcion);

        arrayCantidad[i] = cant;
        arrayPrecioUnidad[i] = precioUnidad;
    }

    //Impresión de los detalles
    printf("--------------------------------\n");
    printf("------------DETALLES------------\n");
    printf("--------------------------------\n");

    printf("Cantidad | Precio por Unidad | Descripcion\n");
    for(int j = 0; j < 5; j++){

        printf("%d | %d\n", arrayCantidad[j], arrayPrecioUnidad[j]);
    }

    system("pause");

    return 0;
}