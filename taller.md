## Actividad 1
Supongamos que se seleciona la opcion de agregar una propiedad al sistema.
### Pregunta 1: ¿Qué objeto recibe primero la solicitud?  
El primer objeto que recibe la solicitud es el objeto de `Administracion` que creamos en `Main`, esta es la clase controladora y maneja todas las solicitudes que se realizan en el menu. A partir de este ya se llama a la clase `Propiedad` para poder instanciar un objeto de este tipo y añadirlo a la lista de propiedades.
### Pregunta 2: ¿Qué método se invoca primero?
Los primeros metodos que se invocan en el sistema son los metodos de Administracion ya que esta es la clase controladora, en este caso se llama el metodo `agregarPropiedad()`.
### Pregunta 3: ¿Ese metodo resuelve todo por sí solo envía mensajes a otros objetos?
Para resolver `agregarPropiedad()`, debe utilizar otros objetos. En este caso los objetos son `Propiedad` y `CuartoUtil` ya que debe instanciar objetos de este tipo y luego almacenarlo en `propiedades`.
### Pregunta 4: ¿Qué otras clases participan en la respuesta?
Las clases `Propiedad` y `CuartoUtil` son necesarias para responder esta solicitud.
### Rastro de navegacion entre clases
- `main -> Administracion -> agregarPropiedad() -> Propiedad() y CuartoUtil()`  

Nota: El constructor de cuarto util solo se llama si la propiedad tiene un cuarto util  

***

## Actividad 2
Cuando se quieren ver todos los propietarios ingresados en el sistema con el metodo `imprimirPropietarios()` es necesario no solamente ver la informacion del propietario si no tambien del cuarto frio si se tiene.
### Pregunta 1: ¿Qué método permite pasar de `Propietario` a `Propiedad`
Para pasar de `Propietario` a `Propiedad` se usa el operador `->` para acceder a la direccion guardada en el miembro `Propietario::propiedad` y acceder a su informacion, en el caso de `imprimirPropietarios()` se necesita usar el metodo `Propiedad::mostrarDatos()` para imprimir la informacion en la consola. Pero si unicamente queremos obtener la propiedad que controla el propietario podemos usar el metodo `getPropiedad()`.
### Pregunta 2: ¿Qué tipo devuelve este método?
El metodo `getPropiedad()` devuelve un `Propiedad*`.
### Pregunta 3: ¿La navegación ocurre mediante `.` o mediante `->`?
La navegacion ocurre mediante `->` ya que estamos manejando apuntadores a un objeto y no el objeto en si.
### Pregunta 4: ¿Por qué en este punto no basta solo con consultar el objeto `Propietario`?
No basta unicamente con consultar `Propietario` ya que la informacion a la que queremos acceder no le pertenece a `Propietario` sino a la `Propiedad` que tiene.
### Secuencia de mensajes
- `imprimirPropietarios() -> Propietario -> Propietario::mostrarInformacion -> Propiedad -> Propiedad::mostarDatos()`  

Aunque si queremos incluir lo que se menciono de `getPropiedad()` se puede ver como:  
- `imprimirPropietarios() -> Propietario -> Propietario::mostrarInformacion -> getPropiedad() -> Propiedad -> Propiedad::mostrarDatos()`

***

## Actividad 3
Continuando con el mismo ejemplo anterior, cuando se usa `imprimirPropietarios()` y un propietario tiene un apartamente que a su vez tiene un cuarto util, a la hora de usar `cuartoUtil::mostrarDatos()` necesitamos saber si esta terminado o no para imprimirlo en pantalla.
### Pregunta 1: ¿Desde qué objeto comienza la consulta?
La consulta inicia en `Administracion` que es llamada por `main`.
### Pregunta 2: ¿Qué mensajes hay que enviar para llegar hasta `CuartoUtil`?
Para llegar a `CuartoUtil` tiene que pasar por `Propietario` y `Propiedad`, para esto usa los metodos `imprimirPropietarios() -> Propietario -> Propietario::mostrarDatos() -> Propiedad::mostrarDatos() -> CuartoUtil`
### Pregunta 3: ¿Qué validación había que hacer antes de acceder al cuarto útil?
Antes de acceder al cuarto util tenemos que asegurarnos que `cuartoUtil` no sea un `nullptr` ya que esto lleva a comportamiento indefinido, es decir, tenemos que asegurarnos de que la propiedad tenga un cuarto util.
### Pregunta 4: ¿Qué podría salir mal si se intenta acceder directamente sin verificar?
Si se accede a `cuartoUtil` sin verificar si es un `nullptr` puede generar comportamiento indefinido y a la hora de intentar acceder al puntero mediante el operador `->` el programa se detiene.

***

## Ejercicio 4
* `main -> Administracion -> imprimirPropietarios()`
* `Propietario -> getPropiedad() -> piso de la propiedad`
* `Propietario -> getPropiedad() -> getCuartoUtil() -> estado del cuarto util` 
* `Administracion -> recaudarAdministracion() -> Propiedad -> valor de la administracion`

***

## Notas adicionales
Wow, eso fue un trabajo largo. zPrincipalmente poque nunca habia usado Markdown y estaba determinado a aprender a usarlo, pero tambien porque queria responder todas las preguntas tan bien como fuera posible y no solo entregar un trabajo a medias. Estuve un buen rato realizando cambios al proyecto intentando mejorarlo tanto como fuera posible e incluso arregle algunos erorres!  

Por ejemplo, `Propiedad` tiene dos dueños, `Propietario` y `Administracion`. Esto no es un problema como tal y de hecho asi esta diseñado en el UML, la cosa es que al terminar el programa ambos intentan usar `delete` sobre `Propiedad`, esto genera un error de double delete lo cual rompe completamente el programa cuando intenta terminar. Para arreglarlo tenemos que decidir a quien le vamos a dar ownership de `Propiedad`, en mi opinion es prudente que `administracion` sea el dueño por lo que quite el destructor de `Propietario` y se arreglo el crasheo al final del programa.  

Aparte de esto que es un error de memoria fatal, CodeBlocks devolvia aproximadamente 8 advertencias cada vez que intentaba compilar el programa por la comparacion entre un `int` y un `size_t` que es de tipo `unsigned long long`, para arreglarlo remplaze la mayoria de bucles a bucles basados en rangos ya que es mas facil trabajar con estos.  

Entre otras cosas la verificacion de entradas definitivamente es uno de los principales problemas del sistema, si ingresas una letra o simbolo en el momento equivocado el sistema se enloquece por completo y tienes que cerrarlo y volverlo a abrir perdiendo todo el progreso. No diria que lo arregle ya que solamente limpio el buffer de `std::cin` despues de cada entrada del usuario PERO el programa ya no explota simplemente por ingresar "a"... algo es algo.