# SpaceTravel

Este proyecto consiste en un renderizador desarrollado en C++ utilizando SDL y GLM. La aplicación acepta archivos .obj que deben estar previamente triangulados, y los procesa a través de un pipeline de renderizado tradicional para generar imágenes. En este caso, se utiliza una esfera generada en Blender para representar los planetas, y estos planetas son pintados exclusivamente mediante shaders, sin el uso de texturas en el proyecto.

El sistema solar que se muestra en los videos incluye una estrella, dos planetas rocosos, una luna y un gigante gaseoso. La aplicación permite explorar el sistema solar, visitando los diferentes planetas mientras una nave espacial, creada en Blender, acompaña la cámara en todo momento. El sistema de movimiento de la cámara es sencillo: W para avanzar, S para retroceder y A o D para girar a la izquierda o derecha, respectivamente. Al presionar la tecla "G", la cámara se trasladará a una posición que proporciona una vista cenital del sistema solar. Para regresar a la posición inicial, basta con presionar la tecla "F".

## Orbits

https://github.com/adrianRFlores/SpaceTravel/assets/84111818/19f2ed84-9ac0-4cab-b394-58536492667a

## 3D Movement and Spaceship

Presionar imagen para ver video en Youtube:

[![Ver video en Youtube](http://img.youtube.com/vi/MiT8qdrzukA/0.jpg)](https://youtu.be/MiT8qdrzukA?si=BHhRsvc5CSv6OUrn)

## Planets

Para obtener una mejor vista de los planetas y sus shaders, se recomienda ver el repositorio realizado específicamente para esto: [planetShaders](https://github.com/adrianRFlores/planetShaders)

## Compilación
Se proporciona un archivo makefile para compilar este proyecto. En mi caso, utilicé la herramienta make incluida en el paquete de MinGW para llevar a cabo la compilación (```mingw32-make.exe```). Es importante destacar que el compilador debe contar con una implementación de pthreads para aprovechar el uso de threading con OpenMP. No es necesario tener instalados SDL y GLM, ya que estos vienen empaquetados dentro de la carpeta src.
