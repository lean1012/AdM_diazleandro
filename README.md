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

3. ¿Qué entiende por arquitectura load-store? ¿Qué tipo de instrucciones no posee este
tipo de arquitectura?

Arquitecturas Load-Store solamente procesará (suma, resta, etc) valores que estén en sus registros o que esten especificados en la instrucción y siempre se obtendrá el resultado en un registro. Este tipo de arquitecturas no tienen instrucciones que realicen operaciones de memoria a memoria. Las únicas operaciones que se aplican a la memoria son aquellas
que copian datos de la memoria en los registros o de registros a memoria.

4. ¿Cómo es el mapa de memoria de la familia?

El mapa de memoria del cortex es un mapa de 4GB continuo de direcciones donde se mapea la memoria ram, la memoria flash y los periféricos. Esto hace que sea muy fácil acceder en C tanto a la memoria ram, periféricos, etc a través de punteros.

5. 

6. 

7. ¿Qué se entiende por modelo de registros ortogonal? Dé un ejemplo

Los registros ortogonales son los que al modificar uno, no afectamos el comportamiento de otro registro.

14. ¿Qué es el CMSIS? ¿Qué función cumple? ¿Quién lo provee? ¿Qué ventajas aporta?

El CMSIS es una librería provista por ARM que permiten usar funcionalidades estandar de Cortex, esto hace que a la hora de programar utilizando CMSIS es que es muy facil portar el programa a otro Cortex.

18. ¿Qué es el systick? ¿Por qué puede afirmarse que su implementación favorece la portabilidad de los sistemas operativos embebidos?

El Systick es el periferico que se utiliza en los sistemas operativos para llevar una base de tiempo.
