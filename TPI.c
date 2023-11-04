#include <stdio.h>
#include <string.h>

const int CANT_CLIENTES = 10; // Cantidad de clientes.

struct usuario
{
    int nroCuenta;   // Número entero entre el 100 y el 999.
    int clave;       // Número entero positivo de 4 digitos.
    char nombre[10]; // Cadena de caracteres de maximo 10 caracteres.
    float saldo;     // Número entero positivo.
    int estado;      // Número entero (0 o 1).
};

// Carga el arreglo con datos de clientes.
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
    cliente[2].nroCuenta = 294;
    cliente[2].clave = 1668;
    strcpy(cliente[2].nombre, "Micaela");
    cliente[2].saldo = 8619;
    cliente[2].estado = 0;

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

// Recibe el array de clientes y el numero de cuenta ingresado por el cliente y verifica si su cuenta existe en el sistema.
// Si lo encuentra, devulve el indice donde se ubica, en caso contrario, devuelve -1.
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
        return -1;
    }

    // Si hubo coincidencia, devuelve el índice en el array donde se encuentra el usuario.
    return i;
}

// Devuelve el índice del array del usuario si es apto para iniciar sesión, en caso contrario, devuelve -1.
int sesion(struct usuario cliente[])
{
    int intestosMax = 3, // Número máximo de intentos permitidos
        user,            // Número de cuenta ingresado por el usuario
        pin,             // Contraseña ingresada por el usuario
        indice;          // Indice del usuario en el array

    // Solicita al usuario que ingrese su número de cuenta.
    printf("\nIngrese su n%cmero de cuenta:\n", 163);
    scanf("%d", &user);

    // Busca el usuario en el array de clientes.
    indice = busqueda(cliente, user);

    // Si el usuario no se encuentra en el array, devuelve -1.
    if (indice < 0)
    {
        printf("Usuario no encontrado.\n");
        return -1;
    }

    // Si la cuenta del usuario está activa...
    if (cliente[indice].estado)
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
            printf("No se permiten más intentos. Su cuenta ha sido bloqueada; comuníquese con la entidad bancaria.\n");
            return -1;
        }

        // Si la autenticación fue exitosa, devolve el índice del array donde se ubica el usuario.
        return indice;
    }
    else
    {
        // Si la cuenta está bloqueada, se le notifica al usuario.
        printf("Su cuenta está bloqueada; comuníquese con la entidad bancaria.\n");
        return -1;
    }
}

// Muestra en pantalla el menú de opciones.
void menu()
{
    printf("\n-------- MENU --------\n");
    printf("\nSeleccione una opción:\n");
    printf("1. Realizar un Depósito.\n");
    printf("2. Realizar una Extracción.\n");
    printf("3. Consultar el Saldo de la Cuenta.\n");
    printf("4. Realizar una Transferencia entre Cuentas.\n");
    printf("5. Mostrar cantidad de Operaciones Realizadas y Saldo Actual.\n");
    printf("6. Salir de la Sesión.\n");
}

// Recibe la opción elegida por el usuario y ejecuta su función correspondiente.
void opciones(int opcion)
{
    switch (opcion)

    {
    case 1:
        //
        break;

    case 2:
        //
        break;

    case 3:
        //
        break;

    case 4:
        //
        break;
    case 5:
        //
        break;
    case 6:
        printf("Gracias por utilizar nuestro servicio.\n");
        printf("¡Vuelva pronto!\n");
        break;

    default:
        printf("Opci%cn inv%clida.", 162, 161);
        break;
    }
}

// Programa Principal.
void main()
{
    int indice,
        opcion;

    struct usuario cliente[CANT_CLIENTES]; // Array de clientes.

    carga(cliente); // Carga el array de clientes con datos de tipo usuario.

    while (1)
    {
        indice = sesion(cliente); // Si el usuario es válido, devuelve su ubicación; en caso contrario, -1.

        if (indice >= 0)
        {
            do
            {
                menu();               // Imprime el menú.
                scanf("%d", &opcion); // Lee la opción.
                opciones(opcion);     // Escoje la operación.

            } while (opcion != 6);
        }
    }
}