# FIR FILTER

One Paragraph of project description goes here

## Description

Esta tarea consiste en programar un filtro FIR en C/C++ y optimizar la programación con el Code Composer Studio. 

La tarea tiene dos partes que pueden ser realizadas independientemente

    * Programación en C
    * Optimización en CCS

Programación en C/C++

Se puede comenzar a probar en cualquier compilador de C/C++. Se recomienda el Eclipse porque el Code Composer Studio está totalmente basado en Eclipsse.

    Implementar el programa totalmente (completar el main, etc...) para que el programa trabaje con un vector de datos y un vector de coeficientes cuyo tamaño se pueda modificar fácilmente. Se puede realizar un programa de prueba con pocos datos para comprobar la corrección del algoritmo pero, para la práctica, el tamaño mínimo debe ser de 1000 valores de datos y 50 coeficientes.
    * En la primera versión el bucle de cálculo estará implementado en el main de forma desenrrollada.
    * En la segunda versión, el bucle de cálculo en forma desenrrollada se colocará en una función.
    * En la tercera versión el bucle de cálculo estará en una función separada implementado como un doble bluce.
    * En la cuarta versión, los parámetros se pasarán mediante punteros.

Optimización en CCS

    1. Se deben implementar ambos programas en proyectos diferentes
    2. Se llevará a cabo la depuración hasta asegurarse de que funcionan correctamente
    2. En cada uno de ellos se debe llevar a cabo un profiling del código que nos dé información de los ciclos de reloj que tarda en ejecutarse el bucle si está dentro del main, o la función si se encuentra fuera del main.
    3. Se comenzará por la opción sin ninguna optimización y se apuntarán los ciclos de reloj que consume únicamente dicha función (excluded)
    4. A continuación se añadirá Restrict a los punteros de los vectores y se comprobará nuevamente los ciclos de reloj
    5. Se utilizarán los intrinsics que el alumno crea convenientes para acelerar dicho código y se volverá a comprobar los ciclos de reloj
    6. Con la situación que menos ciclos de reloj utilice se comienzan a aplicar las optimizaciones o1, o2, o3 y o3 -pm

Se creará una tabla donde se verán los ciclos de reloj empleados por cada uno de los programas en cada una de las optimizaciones que se hayan aplicado y se justificará el resultado.