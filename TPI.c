#include <stdio.h>
#include <string.h>

const int CANT_CLIENTES = 10; // Cantidad de clientes.

struct usuario
{
    int nroCuenta;   // Número entero entre el 100 y el 999.
    int clave;       // Número entero positivo de 4 digitos.
    char nombre[20]; // Cadena de caracteres de maximo 10 caracteres.
    float saldo;     // Número entero positivo.
    int estado;      // Número entero (0 o 1).
};

/*******************************************************************************************************************/
// Recibe un arreglo de tipo Usuario y lo llena con datos de clientes.
void carga(struct usuario cliente[])
{
    // Cliente 1
    cliente[0].nroCuenta = 695;
    cliente[0].clave = 1126;
    strcpy(cliente[0].nombre, "Carlos");
    cliente[0].saldo = 4614;
    cliente[0].estado = 1;

    // Cliente 2
    cliente[1].nroCuenta = 361;
    cliente[1].clave = 1798;
    strcpy(cliente[1].nombre, "Laura");
    cliente[1].saldo = 18625;
    cliente[1].estado = 1;

    // Cliente 3
    cliente[2].nroCuenta = 711;
    cliente[2].clave = 2405;
    strcpy(cliente[2].nombre, "Micaela");
    cliente[2].saldo = 8619;
    cliente[2].estado = 1;

    // Cliente 4
    cliente[3].nroCuenta = 822;
    cliente[3].clave = 1058;
    strcpy(cliente[3].nombre, "Brenda");
    cliente[3].saldo = 18702;
    cliente[3].estado = 1;

    // Cliente 5
    cliente[4].nroCuenta = 536;
    cliente[4].clave = 9168;
    strcpy(cliente[4].nombre, "Oscar");
    cliente[4].saldo = 462;
    cliente[4].estado = 0;

    // Cliente 6
    cliente[5].nroCuenta = 493;
    cliente[5].clave = 7839;
    strcpy(cliente[5].nombre, "Lucas");
    cliente[5].saldo = 13371;
    cliente[5].estado = 0;

    // Cliente 7
    cliente[6].nroCuenta = 538;
    cliente[6].clave = 9996;
    strcpy(cliente[6].nombre, "Pedro");
    cliente[6].saldo = 12635;
    cliente[6].estado = 0;

    // Cliente 8
    cliente[7].nroCuenta = 848;
    cliente[7].clave = 8906;
    strcpy(cliente[7].nombre, "Daiana");
    cliente[7].saldo = 11100;
    cliente[7].estado = 0;

    // Cliente 9
    cliente[8].nroCuenta = 348;
    cliente[8].clave = 3066;
    strcpy(cliente[8].nombre, "Sergio");
    cliente[8].saldo = 3616;
    cliente[8].estado = 0;

    // Cliente 10
    cliente[9].nroCuenta = 982;
    cliente[9].clave = 4593;
    strcpy(cliente[9].nombre, "Natalia");
    cliente[9].saldo = 9467;
    cliente[9].estado = 1;
}
/*******************************************************************************************************************/
/*
Recibe un array de tipo usuario y un numero de cuenta, y busca ese número de cuenta en el array.
Si lo encuentra, devuelve el indice del array donde lo encontró, en caso contrario, devuulve -1.
*/
int busqueda(struct usuario cliente[], int cuenta)
{
    int i = 0; // Indice del array.

    while (i < CANT_CLIENTES && cuenta != cliente[i].nroCuenta)
    {
        i++;
    }

    // Verifica si se alcanzó el final del array y no se encontró coincidencia.
    if (i == CANT_CLIENTES)
    {
        i = -1;
    }

    // Si hubo coincidencia, devuelve el índice del array donde encontró el usuario, en caso contrario, devuelve -1.
    return i;
}
/*******************************************************************************************************************/
/*
Valida el incicio de sesion de un cliente.
Si los datos ingresados por el usuario son válidos, devuelve el índice del array de su ubicación, en caso contrario, devuelve -1.
*/
int sesion(struct usuario cliente[])
{
    int intestosMax = 3, // Número máximo de intentos permitidos
        user,            // Número de cuenta ingresado por el usuario
        pin,             // Contraseña ingresada por el usuario
        indice;          // Indice del usuario en el array

    // Solicita al usuario que ingrese su número de cuenta.
    printf("\nIngrese su n%cmero de cuenta:\n", 163);
    scanf("%d", &user);

    // Busca el número de cuenta en el array de clientes. Si el usuario no se encuentra en el array, devuelve -1.
    indice = busqueda(cliente, user);

    if (indice >= 0) // Si el usuario fue encontrado...
    {
        if (cliente[indice].estado) // Si la cuenta del usuario está activa...
        {
            do
            {
                // Solicita al usuario que ingrese su contraseña.
                printf("Ingrese su contrase%ca: (intentos restantes: %d)\n", 164, intestosMax);
                scanf("%d", &pin);

                // Si la contraseña ingresada no coincide, mustra un mensaje de error y reduce el número de intentos restantes.
                if (cliente[indice].clave != pin)
                {
                    printf("\nContrase%ca Incorrecta.\n", 164);
                    intestosMax--;
                }
            } while (intestosMax > 0 && cliente[indice].clave != pin);

            // Si se agotan los intentos, bloquea la cuenta y notifica al usuario.
            if (intestosMax == 0)
            {
                cliente[indice].estado = 0;
                printf("No se permiten mas intentos. Su cuenta ha sido bloqueada; comuníquese con la entidad bancaria.\n");
                indice = -1;
            }
        }
        else
        {
            // Si la cuenta está bloqueada, se le notifica al usuario.
            printf("Su cuenta está bloqueada; comuníquese con la entidad bancaria.\n");
            indice = -1;
        }
    }
    else
    {
        printf("Usuario no encontrado.\n");
        indice = -1;
    }

    return indice;
}
/*******************************************************************************************************************/

// Imprime el menú de opciones.
void menu()
{
    printf("\n-------- MENU --------\n");
    printf("1. Realizar un Deposito.\n");
    printf("2. Realizar una Extraccion.\n");
    printf("3. Consultar el Saldo de la Cuenta.\n");
    printf("4. Realizar una Transferencia entre Cuentas.\n");
    printf("5. Mostrar cantidad de Operaciones Realizadas y Saldo Actual.\n");
    printf("6. Salir de la Sesion.\n");
    printf("----------------------\n");
}
/*******************************************************************************************************************/
// Realiza una transferencia entre usuarios.
void trasferencia(struct usuario cliente[], int indice)
{
    int nroCuentaDestino;
    float montoTransferir = 0.0;
    int indiceDestino;

    printf("Ingrese numero de cuenta de destino: ");
    scanf("%d", &nroCuentaDestino);

    indiceDestino = busqueda(cliente, nroCuentaDestino);

    if (!cliente[indiceDestino].estado)
    {
        printf("La cuenta de destino esta bloqueda. \n");
        return;
    }

    if (cliente[indice].nroCuenta == nroCuentaDestino)
    {
        printf("\n El numero de destino es el mismo que de origen \n");
        return;
    }

    if (indiceDestino >= 0)
    {
        printf("Ingresar monto a tranferir: ");
        scanf("%f", &montoTransferir);
        if (cliente[indice].saldo >= montoTransferir)
        {
            cliente[indice].saldo -= montoTransferir;
            cliente[indiceDestino].saldo += montoTransferir;
            printf("*************************************\n");
            printf("Transferido con exito.\n");
            printf("Saldo cuenta origen: $ %.2f \n", cliente[indice].saldo);
            printf("Saldo cuenta destino: $ %.2f \n", cliente[indiceDestino].saldo);
            printf("*************************************\n");
            return;
        }
        else
        {
            printf("\n El monto ingresado es inferior al saldo de su cuenta ! \n");
            return;
        }
    }
    else
    {
        printf("\n La cuenta ingresada no existe ! \n");
        return;
    }
}
/*******************************************************************************************************************/
// Realiza la operación correspondiente a la opción ingresada.
void opciones(struct usuario cliente[], int opcion, int indice, int cantOp)
{
    switch (opcion)
    {
    case 1:
        printf("Ingresar monto: ");
        float montoDepositar;
        scanf("%f", &montoDepositar);
        cliente[indice].saldo += montoDepositar;
        break;

    case 2:
        printf("Ingresar monto: ");
        float extraer;
        scanf("%f", &extraer);
        if (cliente[indice].saldo >= extraer)
        {
            cliente[indice].saldo -= extraer;
        }
        else
        {
            printf("\nSu saldo es insuficiente para realizar esta operacion.\n");
        }
        break;
    case 3:
        printf("\nSaldo disponible: $%.2f\n", cliente[indice].saldo);
        break;
    case 4:
        trasferencia(cliente, indice);
        break;
    case 5:
        printf("\nOperaciones realizadas: %d \n", cantOp);
        printf("Saldo Actual: %.1f \n", cliente[indice].saldo);
        break;
    case 6:
        printf("\nGracias por utilizar nuestro servicio.\n");
        break;

    default:
        printf("\nOpcion invalida.\n");
        break;
    }
}
/*******************************************************************************************************************/
// Verifica si se ha llegado al limite de operaciones máximas permitidas por usuario.
void limiteOperaciones(int contador, int maximo)
{
    if (contador >= maximo)
    {
        printf("\nAlcanzó el máximo de %d operaciones, iniciar sesion nuevamente para seguir operando.\n", maximo);
    }
}
/*******************************************************************************************************************/

// Programa Principal.
void main()
{
    int indice,
        opcion,
        contadorOperaciones,
        operacionesMax = 10;

    struct usuario cliente[CANT_CLIENTES]; // Array de clientes.

    carga(cliente); // Carga el array de clientes con datos de tipo usuario.

    while (1)
    {
        indice = sesion(cliente); // Si el usuario es válido, devuelve su ubicación; en caso contrario, -1.

        contadorOperaciones = 0; // Reinicia el contador de operaciones.

        if (indice >= 0)
        {
            do
            {
                ++contadorOperaciones;

                menu(); // Muestra el menú de opciones.

                printf("Ingrese una opción: ");
                scanf("%d", &opcion);

                opciones(cliente, opcion, indice, contadorOperaciones);
                limiteOperaciones(contadorOperaciones, operacionesMax); // Verifica si llegó al límite de operaciones.

            } while (opcion != 6 && contadorOperaciones < operacionesMax);
        }
    }
}
/*******************************************************************************************************************/