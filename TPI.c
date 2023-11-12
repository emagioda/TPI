/*
TRABAJO PRÁCTICO INTEGRADOR
"CAJERO AUTOMÁTICO"

Integrantes:

* Banquero Juan
* Coveri Lautaro
* Gioda Emanuel
* Landriel Santiago
* Servín Agustín
*/

#include <stdio.h>
#include <string.h>

const int CANT_CLIENTES = 10; // Cantidad de clientes.
int contadorOperaciones = 0;  // Contador de operaciones realizadas.

// Estructura utilizada para organizar clientes.
struct usuario
{
    int nroCuenta;   // Número entero entre el 100 y el 999.
    int clave;       // Número entero positivo de 4 digitos.
    char nombre[20]; // Cadena de caracteres de maximo 10 caracteres.
    float saldo;     // Número positivo.
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
    cliente[1].saldo = 0;
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
// Recibe un array de tipo usuario y un numero de cuenta, y busca ese número de cuenta en el array.
//  Si lo encuentra, devuelve el indice del array donde lo encontró, en caso contrario, devuulve -1.
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
// Recibe un número de cuenta y verifica si cumple con las condiciones previamente establecidas.
int validarCuenta(int cuenta)
{
    int minimo = 100; // Valor mímnimo del rango.
    int maximo = 999; // Valor máximo del rango.

    while (cuenta < minimo || cuenta > maximo)
    {
        printf("\nN%cmero de cuenta inv%clido, ingrese un n%cmero entre %d y %d", 163, 160, 163, minimo, maximo);
        printf("\nIngrese el n%cmero de cuenta nuevamente:\n", 163);
        scanf("%d", &cuenta);
    }

    return cuenta; // Devuelve un número de cuenta válido.
}
/*******************************************************************************************************************/
// Valida el incicio de sesion de un cliente.
// Si los datos ingresados por el usuario son válidos, devuelve el índice del array de su ubicación, en caso contrario, devuelve -1.
int sesion(struct usuario cliente[])
{
    int intestosMax = 3, // Número máximo de intentos permitidos.
        user,            // Número de cuenta ingresado por el usuario.
        pin,             // Contraseña ingresada por el usuario.
        indice;          // Indice del usuario en el array.

    // Solicita al usuario que ingrese su número de cuenta.
    printf("\nIngrese su n%cmero de cuenta:\n", 163);
    scanf("%d", &user);

    user = validarCuenta(user); // Verifica que el número ingresado sea válido.

    indice = busqueda(cliente, user); // Busca el número de cuenta en el array de clientes. Si el usuario no es encuentrado, devuelve -1.

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
                    printf("\nContrase%ca incorrecta.\n", 164);
                    intestosMax--;
                }
            } while (intestosMax > 0 && cliente[indice].clave != pin);

            // Si se agotan los intentos, bloquea la cuenta y notifica al usuario.
            if (intestosMax == 0)
            {
                cliente[indice].estado = 0;
                printf("No se permiten m%cs intentos. Su cuenta ha sido bloqueada, comun%cquese con la entidad bancaria.\n", 160, 161);
                indice = -1;
            }
            else // Sino se muestra un mensaje de bienvenida.
            {
                printf("\n¡Bienvenido/a %s!\n", cliente[indice].nombre);
            }
        }
        else
        {
            // Si la cuenta está bloqueada, se le notifica al usuario.
            printf("Su cuenta est%c bloqueada, comun%cquese con la entidad bancaria.\n", 160, 161);
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
    printf("1. Realizar un Dep%csito.\n", 162);
    printf("2. Realizar una Extracci%cn.\n", 162);
    printf("3. Consultar el Saldo de la Cuenta.\n");
    printf("4. Realizar una Transferencia entre Cuentas.\n");
    printf("5. Mostrar cantidad de Operaciones Realizadas y Saldo Actual.\n");
    printf("6. Salir de la Sesi%cn.\n", 162);
    printf("----------------------\n");
}
/*******************************************************************************************************************/
// Realiza una opreación de depósito en la cuenta de un cliente.
void deposito(struct usuario cliente[], int indice)
{
    float montoDeposito; // Dinero a depositar.

    printf("Ingrese el monto a depositar en su cuenta: ");
    scanf("%f", &montoDeposito);

    while (montoDeposito < 0)
    {
        printf("El monto ingresado es inv%clido. Ingrese un valor positivo.\n", 160);
        scanf("%f", &montoDeposito);
    }

    cliente[indice].saldo += montoDeposito;

    printf("--------------------------------------\n");
    printf("Dep%csito realizado de forma exitosa.\n", 162);
    printf("Saldo actual: $%.2f\n", cliente[indice].saldo); // Se muestra el saldo actual del cliente.
    printf("--------------------------------------\n");
}
/*******************************************************************************************************************/
// Realiza una opreación de extracción en la cuenta de un cliente.
void extraccion(struct usuario cliente[], int indice)
{
    float montoExtraccion; // Dinero a extraer.

    printf("Ingrese el monto a extraer en su cuenta: ");
    scanf("%f", &montoExtraccion);

    while (montoExtraccion < 0 || montoExtraccion > cliente[indice].saldo)
    {
        printf("\nEl monto ingresado no es v%clido!\n", 160);
        printf("Su saldo actual es: $%.2f\n", cliente[indice].saldo);
        printf("Ingresar el monto nuevamente: "); // Se ingresa el dinero a transferir.
        scanf("%f", &montoExtraccion);
    }

    cliente[indice].saldo -= montoExtraccion;
    printf("--------------------------------------\n");
    printf("Extracci%cn realizada de forma exitosa.\n", 162);
    printf("Saldo actual: $%.2f\n", cliente[indice].saldo); // Se muestra el saldo actual del cliente.
    printf("--------------------------------------\n");
}
/*******************************************************************************************************************/
// Realiza una transferencia entre dos usuarios.
void trasferencia(struct usuario cliente[], int indice)
{
    int nroCuentaDestino,  // Número de cuanta a transferir.
        indiceDestino;     // Indice del número de cuanta a transferir.
    float montoTransferir; // Dinero a transferir

    if (cliente[indice].saldo == 0)
    {
        printf("\nSu cuenta no tiene saldo para realizar tranferencias.\n");
        return;
    }

    printf("Ingrese n%cmero de cuenta de destino: ", 163);
    scanf("%d", &nroCuentaDestino);

    nroCuentaDestino = validarCuenta(nroCuentaDestino); // Verifica que el número ingresado sea válido.

    indiceDestino = busqueda(cliente, nroCuentaDestino); // Busca el número de cuenta en el array de clientes. Si el usuario no es encuentrado, devuelve -1.

    if (indiceDestino >= 0) // Si el cliente de destino existe..
    {
        if (cliente[indice].nroCuenta == nroCuentaDestino)
        {
            printf("\nEl n%cmero de destino es el mismo que de origen\n", 163);
            return;
        }

        printf("Ingresar monto a tranferir: "); // Se ingresa el dinero a transferir.
        scanf("%f", &montoTransferir);

        while (montoTransferir < 0 || montoTransferir > cliente[indice].saldo)
        {
            printf("\nEl monto ingresado no es v%clido!\n", 160);
            printf("Su saldo actual es: $%.2f\n", cliente[indice].saldo);
            printf("Ingresar el monto nuevamente: "); // Se ingresa el dinero a transferir.
            scanf("%f", &montoTransferir);
        }

        cliente[indice].saldo -= montoTransferir;
        cliente[indiceDestino].saldo += montoTransferir;
        printf("\n*************************************\n");
        printf("La transferencia a %s se realiz%c con %cxito\n", cliente[indiceDestino].nombre, 162, 130);
        printf("Saldo actual de su cuenta: $%.2f \n", cliente[indice].saldo);
        printf("*************************************\n");
        return;
    }
    else
    {
        printf("El número de cuenta ingresado no existe!\n");
        return;
    }
}
/*******************************************************************************************************************/
// Verifica si se ha llegado al limite de operaciones máximas permitidas por usuario.
void limiteOperaciones(int contador, int maximo)
{
    if (contador >= maximo)
    {
        printf("\nAlcanz%c el maximo de %d operaciones, iniciar sesion nuevamente para seguir operando.\n", 162, maximo);
    }
}
/*******************************************************************************************************************/
// Realiza la operación correspondiente a la opción ingresada.
void opciones(struct usuario cliente[], int opcion, int indice, int cantOp)
{
    switch (opcion)
    {
    case 1:
        ++contadorOperaciones;     // Suma 1 al contador de operaciones.
        deposito(cliente, indice); // Ejecuta la función de depósito.
        break;

    case 2:
        ++contadorOperaciones;       // Suma 1 al contador de operaciones.
        extraccion(cliente, indice); // Ejecuta la función de extracción.
        break;
    case 3:
        ++contadorOperaciones;                                        // Suma 1 al contador de operaciones.
        printf("\nSaldo disponible: $%.2f\n", cliente[indice].saldo); // Muetra  el saldo disponible.
        break;
    case 4:
        ++contadorOperaciones;         // Suma 1 al contador de operaciones.
        trasferencia(cliente, indice); // Ejecuta la función de transferencia.
        break;
    case 5:
        printf("\nOperaciones realizadas: %d\n", cantOp);        // Muetra el total de operaciones realizadas hasta el momento.
        printf("Saldo Actual: $%.2f \n", cliente[indice].saldo); // Muestra el saldo actual.
        break;
    case 6:
        printf("\nGracias por utilizar nuestros servicios.\n"); // Mensaje de despedida.
        break;

    default:
        printf("\nOpci%cn inv%clida.\n", 162, 160);
        break;
    }
}
/*******************************************************************************************************************/
// PROGRAMA PRINCIPAL.
void main()
{
    int indice,              // Ubicación en el array de clientes.
        opcion,              // Opción ingresada por el cliente.
        operacionesMax = 10; // Número de operaciones permitidas por cliente.

    struct usuario cliente[CANT_CLIENTES]; // Array de clientes.

    carga(cliente); // Carga el array de clientes con datos de tipo usuario.

    while (1)
    {
        indice = sesion(cliente); // Si el usuario es válido, devuelve su ubicación; en caso contrario, -1.
        contadorOperaciones = 0;  // Reinicia el contador de operaciones.

        if (indice >= 0) // Si el cliente existe...
        {
            do
            {
                menu(); // Muestra el menú de opciones.

                printf("Ingrese una opci%cn: ", 162); // Pide que ingrese una opción.
                scanf("%d", &opcion);

                opciones(cliente, opcion, indice, contadorOperaciones); // Ejecuta la opción elegida.
                limiteOperaciones(contadorOperaciones, operacionesMax); // Verifica si llegó al límite de operaciones.

            } while (opcion != 6 && contadorOperaciones < operacionesMax);
        }
    }
}
/*******************************************************************************************************************/
