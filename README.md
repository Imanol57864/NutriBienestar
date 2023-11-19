# Proyecto: Base de datos del centro NutriBienestar
Este proyecto utiliza la base de datos de ejemplo de la empresa NutriBienestar para visualizar, ordenar, y comprobar el siguiente comporamiento de los diferentes algoritmos de ordenamiento y búsqueda. Incluyendo el uso de estructura de datos abstractos, y nuevas mejoras al sistema.

## Descripción del avance 1
Ordenamiento y búsqueda:
Si se desea ver el progreso de una persona en específico o buscar algún dato en particular, puedes visualizar la implementación de los algoritmos de búsqueda binaria o el ordenamiento tipo merge. Se debe destacar que el ordenamiento merge apoya directamente a la búsqueda binaria ya que satisface la precondición de tener los datos ordenados.

## Descripción del avance 2
El programa fue adaptado para funcionar aún mejor dentro del entorno de Replit. La interfaz es intutiva, simplemente se escribe la opción que se desea ver. Se cumple con las sub-competencias debido a que se implementaron los algoritmos de ordenamiento mejores que la versión anterior. Además, se pulieron los procesos anteriores de lectura de archivos, e impresión de la interfaz.

### Cambios sobre el primer avance
1. Se actualizó el tipo de dato de la base de datos para tener un mejor algoritmo de ordenamiento.
2. Se actualizó el array de punteros de la clase "Freshman" donde se encontraba la base de datos, a una lista de punteros de la clase "Freshman". Esto logró que tuviesemos acceso al algoritmo de ordenamiento de las listas de C++, el cual es uno de lo más potentes que existen.
3. Se fragmentó la base de datos en diferentes listas para tener una mayor visibilidad de las información ordenada. Además permite que el sistema ser más veloz.

## Descripción del avance 3
En sí, se han simplificado y pulido el archivo main por completo. Se han actualizado las listas para trabajar únicamente con una lista, lo cual significa menor uso de almacenamiento. Se añadió la función de escribir un archivo csv de la base de datos con la manera en que se ha ordenado la base de datos. Se han optimizado las funciones para una mejor lectura y funcionamiento, incluyendo la eliminación código que no se estaba utilizando.

### Cambios sobre el segundo avance
Se eliminaron las listas de más donde se extraían las columnas para aplicar el algoritmo de ordenamiento directamente sobre dicha lista. Se cambiaron "if"s y "while"s por otras funciones más compactas y eficientes. Se añadió la funcionalidad de escitura de un archivo donde se guarda la base de datos como está ordenada recientemente. Se organizó el código por funciones donde se agregaron 5 prototipos para una mejor lectura y entendimiento del código. Y por último, se elimió la necesidad de utilizar un vector doble para la lectura del csv, guardando directamente una lista de punteros freshman.

## Instrucciones para compilar el avance de proyecto
Puede dar click en el botón "Run" en la parte superior de replit, o puede ejecutar el siguiente comando en el shell. `g++ main.cpp Freshman.cpp Freshman.h -o exe` 

## Instrucciones para ejecutar el avance de proyecto
Ejecuta el siguiente comando en la terminal: `./exe` 

## Descripción de las entradas del avance de proyecto
El archivo "freshman_kgs.csv" es un archivo csv que se utiliza como base de datos para la lectura de la información delimitado por coma. Ejemplifica una base de datos de un centro de nutrición llamado Nutribienestar donde se encuentra la información de 54 alumnos de primer semestre. Esto, para tener datos con los que aplicar los algoritmos al peso, bmi, etc.

## Descripción de las salidas del avance de proyecto
En primera instancia, se muestra la interfaz del menú principal. Donde se puede observar las diferentes opciones que el usuario puede visualizar. Luego puede seleccionar y continuar con otras visualizaciones.

## Desarrollo de competencias

### SICT0301: Evalúa los componentes
#### Hace un análisis de complejidad correcto y completo para los algoritmos de ordenamiento usados en el programa.
El algoritmo de ordenamiento que usa *std::list:::sort* es *Introsort*. Según la documentación, este comienza con el *Quicksort*, cambia al *Heapsort* cuando la profundidad de la recursión supera un nivel basado en el logaritmo del número de elementos a ordenar y cambia al *Insertionsort* cuando el número de elementos es menor que cierto umbral. Esto resulta en una combinación de las partes buenas de los tres algoritmos, con un tiempo de ejecución en el peor caso de O(n log n) debido al *Heapsort*.
*Quicksort*, un algoritmo basado en la técnica divide y vencerás, exhibe un rendimiento promedio y en el mejor caso de O(n log n), pero puede degradarse a O(n^2) en el peor caso. Por otro lado, *Heapsort*, aunque siempre mantiene una complejidad de O(n log n) en todos los casos, no es adaptativo, lo que significa que su rendimiento no se ajusta a características particulares del conjunto de datos. En contraste, *Insertionsort* destaca en pequeñas listas o ya parcialmente ordenadas, mostrando una complejidad en el mejor caso de O(n) y en el peor caso de O(n^2). La elección del algoritmo depende del tamaño y la naturaleza del conjunto de datos, así como de las restricciones de rendimiento específicas.
*Quicksort*: Mejor caso O(n log n), Caso promedio O(n log n), Peor caso O(n^2).
*Heapsort*: Mejor caso O(n log n), Caso promedio O(n log n), Peor caso O(n log n).
*Insertionsort*: Mejor caso O(n), Caso promedio O(n^2). Peor caso O(n^2).

#### Hace un análisis de complejidad correcto y completo de todas las estructuras de datos y cada uno de sus usos en el programa.
El uso de *std::list* es una lista doblemente vinculada, lo que implica que las operaciones de inserción y eliminación en cualquier posición tienen complejidad O(1), ya que solo requieren manipulación de punteros. Sin embargo, el acceso a elementos mediante iteración impone una complejidad O(n), ya que la lista no proporciona acceso aleatorio. 
En el contexto del programa, las operaciones de inserción y eliminación de objetos *Freshman* durante la lectura del archivo CSV y el posterior ordenamiento mediante *std::list::sort* son perfectas para este escenario. Debido a que la mayoria de las funcionalidades no requieren el accesso a un objeto *Freshman* en especifico y más que nada son aplicar un orden a la base de datos, es mejor no implementar algo como un árbol splay, donde este ayuda a una búsqueda con cada vez menor complejidad para datos visitados recientemente, y simplemete programar un algoritmo de búsqueda sólido como *binarysearch*.

#### Hace un análisis de complejidad correcto y completo para todos los demás componentes del programa y determina la complejidad final del programa.
La lectura del archivo CSV en la función `readDB` tiene una complejidad de O(n), ya que implica la lectura de cada línea del archivo y la inserción de nuevos objetos `Freshman` en la lista `DB`. 
La función de escritura `writeDBToFile` también tiene una complejidad O(n) debido a la iteración a través de la lista y la escritura en el archivo.
La función `binarySearchByID` realiza una búsqueda binaria sobre la lista ordenada. Dado que la lista está organizada previamente mediante el algoritmo de ordenamiento proporcionado por `std::list::sort`, esta operación de búsqueda tiene una complejidad O(log n), donde "n" representa el tamaño de la lista.
La función `menu` y otras funciones de impresión y comparación presentan complejidades más bajas, principalmente O(1) o O(n), dependiendo de las operaciones básicas realizadas.
Por lo tanto, tomando en cuenta todo el analisís previo, se determina que la complejidad final del programa es de O(n log n) ya que en promedio la mayoría de las funciones maneja un rango entre O(1) y O(n). Además que los algoritmos críticos manejan una complejidad O(n log n).

### SICT0302: Toma decisiones
#### Selecciona un algoritmo de ordenamiento adecuado al problema y lo usa correctamente.
El algoritmo de ordenamiento que usa *std::list:::sort* es *Introsort*. Si se compara con la implementación previa que fue donde se utilizó el algoritmo de tipo *Mergesort*, el cual permite organizar los componentes creando pequeños arreglos, se puede apreciar una gran diferencia de rendimiento entre ambos algoritmos. Por lo cual, si se habla elegir el más adecuado, *Introsort* es el más eficiente.

#### Selecciona una estructura de datos adecuada al problema y la usa correctamente.
Comparando la estructura de datos de tipo lista de punteros de objetos clase contra la estructura de datos de tipo arreglo de punteros de objetos clase. Se puede observar que la lista ofrece una mayor eficiencia de algoritmos de ordenamiento en costa de tener un acceso más complicado a los punteros con la información. Además, se estableció una función que permite tabular el algoritmo de ordenamiento tomando en cuenta los datos de una sola columna, pero conservando la información de toda la fila.

### SICT0303: Implementa acciones científicas
#### Implementa mecanismos para consultar información de las estructras correctos.
En este caso, se podría considerar que el fragmentar la base de datos en varias listas para acceder a los datos ordenados de manera más sencilla seria una buena implementación de mecanismo de consulta. Además, se conserva una lista con la base de datos original.

#### Implementa mecanismos de lectura de archivos para cargar datos a las estructuras de manera correcta.
En este caso, continuamos con la lectura del archivo utilizando un vector. Considero personalmente que el vector es muy eficiente para acceder a todos los datos de un archivo excel. Ya que, como son pocos, un vector de dos dimensiones es más que suficiente.

### Implementa mecanismos de escritura de archivos para guardar los datos  de las estructuras de manera correcta
En este caso, se implementó una función que permite escribir un archivo csv con los datos como se encuentran actualmente organizados dentro de la lista de la base de datos. Utilizando ofstream y ciclando con un ciclo for toda la lista extrayendo los datos en el orden en el que se encuentren.
