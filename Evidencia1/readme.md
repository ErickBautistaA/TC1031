# Proyecto: Lector de ondas sonoras
Programa que lee las muestras de datos de las ondas maritimas, estas pueden ser dadas por el usuario como por medio de un archivo .txt. El programa permite al usuario buscar datos de los conjuntos guardados y le dice al usuario si existen o no, al finalizar la busqueda devuelve los datos encontrados de menor a mayor.

## Descripción del avance 1
Se creo un vector de 12 objetos que tienen una variable numerica y una string, estos son el mes y ganancias, obtenidas de un archivo .txt, ordenamos los objetos de menor a mayor usando un shell sort.

## Descripción del avance 2
No se entrego segundo avance. 

### Cambios sobre el primer avance
1. Podria decirce que gran parte del programa cambio lo mas notorio seria los datos que se ingresan ya que ahora solo son valores numericos, en el avance uno eran valores numericos y strings que representaban las ventas por meses del año y las ganancias obtenidas, ahora el contexto es compara las muestras de unas ondas sonoras captadas en el oceano por lo que solo usamos variables int.
2. cambio de uso de vectores a arboles avl: la razón de este cambio es para hacer uso de memoria dinamica y que el programa sea mas eficiente y rapido.


## Descripción del avance 3
En este avance se creo un programa que lee un archivo txt (OndasS.txt) que contiene los datos muestra de una serie de ondas maritimas, usando arboles avl se almacenara los datos de una forma ordenada para despues mostrarlos al usuario y sea mas facil denotar cuales fueron las ondas mas potentes y las mas debiles, se agrego la opcion de poder ingresar datos nuevos para que el programa tenga flexibilidad y variabilidad en sus opciones, despues de almacenar los datos el programa los muestra ordenados y crea un nuevo txt que almacenara los datos.
Esto servira para que el usuario pueda tener una herramienta visual cuantitativa que le permita de manera mas facil y concreta de analizar el proceso en el que se esta interesado, en este caso es el estudio de las ondas maritimas en el oceano. 

### Cambios sobre el segundo avance
No se entrego segundo avance.

## Entrega final
Para este avance se implemento una opcion de busqueda de datos que le permite al usuario corroborar si algun dato esta en los arboles, si se encuentra los datos buscados se confirma su existencia y cuando termine de buscar datos el programa mostrara los valores que si encontro de forma ordenada.

### Cambios sobre el tercer avance avance
1. se agrego un algoritmo de busqueda para mejorar la experiencia de usuario.
2. Ahora al finalizar la busqueda de valores se muestran los valores encontrados en un vector ordenado por medio del uso de un selection sort.

## Instrucciones para compilar el proyecto
Ejecuta el siguiente comando en la terminal:

`g++ main.cpp -o primer_avance` 

## Instrucciones para ejecutar el proyecto
Ejecuta el siguiente comando en la terminal:

`./primer_avance` 
o picarle al boton run

## Descripción de las entradas del avance de proyecto
Como entrada necesita un archivo .txt llamado OndasS.txt esto solo para la opcion 1.

## Descripción de las salidas del avance de proyecto
regresa un archivo .txt con los valores registrados y ordenados.

## Desarrollo de competencias

### SICT0301: Evalúa los componentes
#### Hace un análisis de complejidad correcto y completo para los algoritmos de ordenamiento usados en el programa.
El algoritmo selectionSort en el peor y mejor de los casos tiene una complejidad de O(N^2) esto se debe a que utiliza dos bucles.

#### Hace un análisis de complejidad correcto y completo de todas las estructuras de datos y cada uno de sus usos en el programa.
La estructura principla serian los arbol avl en los cuales se hace uso de add, balance_tree e inorder.
add y balance_tree estan relacionados ya que add agrega los valores al arbol y llama a balance_tree para que balance los datos por lo que los dos son O(log n)
para el inorder en el peor de los casos, realizar un recorrido en orden en un árbol AVL toma tiempo lineal, ya que visitas todos los nodos una vez por lo que su complejidad es de O(n).

en el main tenemos la lectura de archivo en la linea 18 que seria O(n) y la escritura en archivo que se encuentra en la linea 42 y 72 son O(n).

#### Hace un análisis de complejidad correcto y completo para todos los demás componentes del programa y determina la complejidad final del programa.
Tomando todo lo anterior en cuenta se podria decir que la complejidad del codigo es de O(log n) en el peor de los casos mientras que el recorrido en orden tiene una complejidad de O(n).

### SICT0302: Toma decisiones
#### Selecciona un algoritmo de ordenamiento adecuado al problema y lo usa correctamente.
Se selecciono los arboles avl ya que el programa se vuelve mas eficiente en primera instancia porque usa memoria dinamica lo cual lo hace mas versatil, parte de los arboles avl es que se orden solos y esto me facilitaba el acomodo de datos por lo que no tendria que crea una funcion externa que ordenara estos datos.

al usar inorder a lo mucho el codigo llega a ser O(n) y esto comparado con el shellsort que use en mi primer avance es mucho mejor ya que este era O(n^2) por lo que se puede notar una diferencia en el uso de memoria.

#### Selecciona una estructura de datos adecuada al problema y la usa correctamente.
Para el segundo avance quise usar listas doblemente ligadas lo cual fue una mala decicion ya que me complicaba mucho el codigo al querer ordenar los datos usando un shellsort por lo que despues de pensarlo bien vi que no era la mejor opcion, despues de pensar las necesidades que tenia mi programa se me ocurrio que la mejor opcion para almacenar estos datos y acomodarlos seria usar un arbol avl ya que facilitaba gran parte de las necesidades que tenia y al usar la funcion inorder obtendria los valores ordenados con una complejidad menor que si usara shellsort y listas doblemente ligadas. 
Tomando en consideracion aspectos de eficiencia esta fue la mejor decicion.

### SICT0303: Implementa acciones científicas
#### Implementa mecanismos para consultar información de las estructras correctos.
Para la busqueda de datos implemente una funcion llamada find esta se encuentra en avl.h en la linea 62, esta me ayuda a encontrar valores dentro del arbol de esta forma el usuario puede corroborar si los datos existen o se guardaron de forma correcta.

#### Implementa mecanismos de lectura de archivos para cargar datos a las estructuras de manera correcta.
En el programa se usa la lectura de archivos para obtener los datos que se van a usar en la corrida del programa esto me permite tener un espacio mas limpio en la parte del codigo, la subida de datos se puede ver en la linea 21 de main.cpp.

### Implementa mecanismos de escritura de archivos para guardar los datos  de las estructuras de manera correcta
En el programa hago uso de la escritura de archivos en la linea 43 y 74 del main.cpp para almacenar los datos ordenados del archivo cargado como los que pueda proporcionar el usuario para tener un registro de los datos y este se pueda checar despues.