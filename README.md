Repositorio de Arquitecturas de Microprocesadores


Preguntas orientadoras

1. Describa brevemente los diferentes perfiles de familias de microprocesadores/microcontroladores de ARM. Explique alguna de sus diferencias características.

En ARM v7 nos encontramos con 3 perfiles de familias: Cortex A, Cortex R y Cortex M. 

Cortex A 
Esta serie está pensada para aplicaciones que tienen altos requisitos informáticos, ejecutan sistemas operativos de proposito general y pensado para manejar grande volumenes de procesamiento y no tanto en restricciones de tiempo. Ejemplo un celular, en este queremos que tenga alto rendimiento el manejo de varias aplicaciones a la vez y no tanto que se tenga siempre la misma respuesta temporal.

Cortex R 
Esta serie está pensada a aplicaciones en tiempo real de alto rendimiento. Son usados en aplicaciones donde hay restricciones de tiempo, nos importa que la respuesta temporal de determinada acción sea siempre la misma.

Cortex M 
Esta serie es igual a los cortex R pero más chicas, más simple y por lo tanto menos costosos.

1. Describa brevemente las diferencias entre las familias de procesadores Cortex M0, M3 y M4.

Los Cortex M0 / M0+ tienen una implementación mínima para tener un bajo consumo y un bajo costo
Los Cortex M3 / M4 / M7 tienen como objetivo tener una mayor performance, para eso agregan funcionalidades para procesamiento digital de señales, unidad de protección de memoria, etc

2. ¿Por qué se dice que el set de instrucciones Thumb permite mayor densidad de código?
Explique

Los procesadores más recientes traen un conjunto de instrucciones adicional llamado Thumb, de 16 bits de longitud en lugar de 32 bits. Esto hace que al tener la mitad de longitud, más instrucciones entran en una misma cantidad de memoria que instrucciones de 32 bits.

3. ¿Qué entiende por arquitectura load-store? ¿Qué tipo de instrucciones no posee este tipo de arquitectura?

Arquitecturas Load-Store solamente procesará (suma, resta, etc) valores que estén en sus registros o que esten especificados en la instrucción y siempre se obtendrá el resultado en un registro. Este tipo de arquitecturas no tienen instrucciones que realicen operaciones de memoria a memoria. Las únicas operaciones que se aplican a la memoria son aquellas que copian datos de la memoria en los registros o de registros a memoria.

4. ¿Cómo es el mapa de memoria de la familia?

El mapa de memoria del cortex es un mapa de 4GB continuo de direcciones donde se mapea la memoria ram, la memoria flash y los periféricos. Esto hace que sea muy fácil acceder en C tanto a la memoria ram, periféricos, etc a través de punteros.

5. ¿Qué ventajas presenta el uso de los “shadowed pointers” del PSP y el MSP?

El MSP es el puntero de stack por defecto, Main Stack Pointer. Este se usa en el modo Thread y siempre se usa en el modo Handler. En cambio el PSP, Processor Stack Pointer, es usado por las tareas cuando se ejecutan en modo no privilegiado. En general se va a utilizar el MSP si se tiene un programa sencillo sin nigun sistema de operativo.

6. Describa los diferentes modos de privilegio y operación del Cortex M, sus relaciones y como se conmuta de uno al otro. Describa un ejemplo en el que se pasa del modo privilegiado a no priviligiado y nuevamente a privilegiado.

Los procesadores Cortex-M soportan la ejecución de código en modo privilegiado y modo usuario (No privilegiado). El modo privilegiado asegura un acceso a todos los recursos del sistema. El modo usuario tiene restricciones en el acceso de algunos recursos.
El Cortex M soporta dos modos de operación, el Thread y Handler.  El modo Thread tiene la posibilidad de ser ejecutado en modo privilegiado o no, además permite decidir si se usa el MSP o PSP. En cambio, el modo Handler siempre es ejecutado es modo privilegiado, usa el MSP y se entra cuando ocurre una excepción o una interrupción en el microcontrolador.

Estando en modo no priviligado no podemos ir a modo priviligado, en cambio estando en modo priviligado podemos ir a no priviligado. Entonces para ir a priviligado estando en no priviligado hay que generar una excepción para ir a handler modo. En este momento tenemos permiso de acceder a los registros de control y modificar el modo. 

7. ¿Qué se entiende por modelo de registros ortogonal? Dé un ejemplo

Los registros ortogonales son los que al modificar uno, no afectamos el comportamiento de otro registro.

8. ¿Qué ventajas presenta el uso de intrucciones de ejecución condicional (IT)? Dé un ejemplo

La instrucción IT permite ejecutar un bloque de instrucciones condicionales, con el fin de reducir los saltos. Se puede colocar hasta 4 sentencias. La estructura IT es como “IF-Then-(Else)” y la sintaxis es con dos letras T y E:

IT se refiere a If-Then (la siguiente instrucción es condicional)
ITT se refiere a If-Then-Then (las siguientes 2 instrucciones son condicionales)
ITE se refiere a If-Then-Else (las siguientes 2 instrucciones son condicionales)
ITTE se refiere a If-Then-Then-Else (las siguientes 3 instrucciones son condicionales)
ITTEE se refiere a If-Then-Then-Else-Else (las siguientes 4 instrucciones son condicionales)

Ejemplo:

cmp r0, 10      
    ite eq           @ if R0 is equal 10...
    addeq r1, 2     @ ... then R1 = R1 + 2
    addne r1, 3     @ ... else R1 = R1 + 3

Si r0 es igual a o mayor a 10, realizará el "then" addeq r1 #2, en cambio si r0 es menor a 10 se ejecutará el "else" addne r1, #3.


9. Describa brevemente las excepciones más prioritarias (reset, NMI, Hardfault).

La excepción de reset es la que se produce cuando ocurre un reset. La excepción de NMI es una excepción producida por una interrupcion no enmascarable y la excepcion Hardfault es cuándo ocurre una falla. Estas tienen diferenes prioridades, reset es la de mayor prioridad (-3), luego le sigue NMI (-2) y por último Hardfault (-1). Menor número mayor prioridad.

10. Describa las funciones principales de la pila. ¿Cómo resuelve la arquitectura el llamado a funciones y su retorno?

La pila tiene como prinicipales funciones pasar datos a funciones o subrutinas, guardar variables locales, guardar el estado del procesador, por ejemplo cuando se atiende una interrupción o se salta a una subrutina, el micro debe guardar su estado. 
Cuando es llamada una subrutina el PC se guarda en el registro LR (link register) para luego poder retornar a donde estaba (quedará apuntando a la siguiente instrucción). Al final de la subrutina hay que saltar, esto lo podemos hacer con bx lr. Saltamos al lr, que es donde está el PC guardado. En caso de llamar una subrutina dentro de otra hay que guardar en stack el valor de lr, para que no sea sobreescrito.

11. Describa la secuencia de reset del microprocesador.

Cuando se realiza el reset, el PC se incializa con la dirección 0x0, la primera línea de código, en la dirección 0x00000000 contiene el valor del SP (ejemplo 0x20008000), (MSB= 0x20008000). Luego la siguiente posición de memoria (0x000000004) está la dirección de memoria de la rutina que atiende el reset, el PC toma ese valor y el programa salta a ese valor. En esta rutina estará la inicialización del microntrolador. Luego finalmente está la ubicación del programa principal, el main, se salta a ese valor y el microncontroaldor sigue con nuestro programa.


12. ¿Qué entiende por “core peripherals”? ¿Qué diferencia existe entre estos y el resto de los periféricos?

Los "core-peripherals" son los que están en el procesador diseñado por ARM. Estos son el contradolor de interrupción NVIC, SysTick Timer y la MPU. El resto de los periféricos los va a poner los distintos fabricantes.

13. ¿Cómo se implementan las prioridades de las interrupciones? Dé un ejemplo

14. ¿Qué es el CMSIS? ¿Qué función cumple? ¿Quién lo provee? ¿Qué ventajas aporta?

El CMSIS es una librería provista por ARM que permiten usar funcionalidades estandar de Cortex, esto hace que a la hora de programar utilizando CMSIS es que es muy facil portar el programa a otro Cortex.

15. Cuando ocurre una interrupción, asumiendo que está habilitada ¿Cómo opera el microprocesador para atender a la subrutina correspondiente? Explique con un ejemplo

17. ¿Cómo cambia la operación de stacking al utilizar la unidad de punto flotante?

16. Explique las características avanzadas de atención a interrupciones: tail chaining y late arrival.

17. ¿Qué es el systick? ¿Por qué puede afirmarse que su implementación favorece la portabilidad de los sistemas operativos embebidos?

El Systick es el periferico que se utiliza en los sistemas operativos para llevar una base de tiempo.

18. ¿Qué funciones cumple la unidad de protección de memoria (MPU)?

La función de la MPU es proteger sectores de memoria para que estos no puedan ser escritos o leídos por otros procesos. Esto se usa fundamentalmente en los RTOS para que las tareas no accedan a memoria de otras tareas.


19. ¿Cuántas regiones pueden configurarse como máximo? ¿Qué ocurre en caso de haber solapamientos de las regiones? ¿Qué ocurre con las zonas de memoria no cubiertas por las regiones definidas?

La MPU puede gestionar hasta 8 regiones de memoria a las cuales se les pueden asignar permisos a cada una de ellas. Las zonas de memoria no cubiertas quedan sin protección y se pueden acceder sin restricciones. Cuando ocurre solapamiento entre las regiones la prioridad viene dada por su orden, es decir, aquella con la numeración más alta.  

20. ¿Para qué se suele utilizar la excepción PendSV? ¿Cómo se relaciona su uso con el resto de las excepciones? Dé un ejemplo

21. ¿Para qué se suele utilizar la excepción SVC? Expliquelo dentro de un marco de un sistema operativo embebido.

La excepción del SVC es una interrupción por software que nos permite pasar de modo no privilegiado a privilegiado.

ISA

1. ¿Qué son los sufijos y para qué se los utiliza? Dé un ejemplo

Los sufijos nos permiten agregar funcionalidad a las instrucciónes. Existen sufijos que nos permiten operar con 8 y 16 bits. Ejemplo: ldrh esta instrucción cargar en un registro 16bits del contenido de una memoria. Si no se le pone sufijo está implicito que se trabaja con 32bits.


2. ¿Para qué se utiliza el sufijo ‘s’? Dé un ejemplo

El sufijo s es para indicar que se modifiquen las banderas al realizar una operación aritmética. En caso que no se agrege, la operación no afectaran las flags, excepto la instrucción de cmp.

3. ¿Qué utilidad tiene la implementación de instrucciones de aritmética saturada? Dé un ejemplo con operaciones con datos de 8 bits.

Hay aplicaciones que cuando nos pasamos del rango de representación de un dato no queremos que este "de la vuelta" si no que queremos que sature. Ejemplo con 8 bits sin signo, podemos representar hasta 255, si tenemos una variable de 8bits sin signo con valor 250 y le sumamos 10, obtenemos el número 4. En aplicaciones esto puede ser grave, y se opta por usar aritmética saturada, en este caso el número saturaría a 255.

Ejemplo: Sin saturar 250 + 10 = 4
	 Saturando 250 + 10 = 255   

4. Describa brevemente la interfaz entre assembler y C ¿Cómo se reciben los argumentos de las funciones? ¿Cómo se devuelve el resultado? ¿Qué registros deben guardarse en la pila antes de ser modificados?

Cuando se llama a una función en asembler el compilador salva los registros r0 al r3 y pasa los parámetros en dichos regitros. Si tiene datos para devolver se guarda en el registro r0. Al salir de la función los registros r0 al r3 recuperan su estado. Si se desea utilizar otros registros se deben preservar.

5. ¿Qué es una instrucción SIMD? ¿En qué se aplican y que ventajas reporta su uso? Dé un
ejemplo.

Una instrucción SIMD es una instrucción que puede procesar múltiples datos en una sola operación. Estos se aplican generalmente en algoritmos de procesamiento de imágenes. La ventaja que tiene es que obtenemos una mejor perfomance, ya que utilizando las instrucciones "simples" esto llevaría varios ciclos de reloj. Por ejemplo, con SIMD podemos sumar dos números de 16bits a la vez (a1+b1, a2+b2) en cambio utilizando las instrucciones del micro necesitamos más pasos.


