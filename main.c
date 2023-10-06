#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main(void){

    char cedula[10] = "1723372825";

    //variables de ingreso de datos
    char nombre[100], apellido[100], ingresoCedula[10], direccion[100], telefono[10];

    //variables precios y cantidad de productos
    int cant, precioUnidad, total, subtotal;
    int arrayCantidad[5], arrayPrecioUnidad[5];
    char descripcion[100], arrayDescripcion[5][100];

    //Variables para verificar la cedula
    char digitoChar;
    int digito, numeroFinal = 0, residuo;
    int sumatoria = 0, flag = 0, verificarCedula;


    //Verificar cedula
    do{
        
        printf("\t---FACTURA---\n");
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
        
        verificarCedula = strcmp("1723372825", ingresoCedula);
        
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

        strcpy(arrayDescripcion[i - 1], descripcion);
        arrayCantidad[i - 1] = cant;
        arrayPrecioUnidad[i - 1] = precioUnidad;
        subtotal = subtotal + (cant * precioUnidad);
    }

    system("clear");

    //Descuento calcular
    if(subtotal >= 1000){
        subtotal = subtotal * 0.90;

    }else if(subtotal > 500){
        
        subtotal = subtotal * 0.93;

    }else if(subtotal > 100){
        subtotal = subtotal * 0.95;

    }

        
    total = subtotal * 1.12;

    //Impresion de los detalles
    printf("Nombre: %s %s\n", nombre, apellido);
    printf("Direccion: %s\n", direccion);
    printf("Telefono: %s\n", telefono);
    printf("--------------------------------\n");
    printf("------------DETALLES------------\n");
    printf("--------------------------------\n");

    printf("Cantidad | Precio por Unidad | Descripcion\n");
    for(int j = 0; j < 5; j++){

        printf("%d        | %d                 | %s                \n", arrayCantidad[j], arrayPrecioUnidad[j], arrayDescripcion[j]);
    }

    printf("Subtotal: %d$\n", subtotal);
    printf("Total: %d$\n", total);


    system("pause");

    return 0;
}