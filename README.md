# ⚔️ Epic RPG Battle Simulator (C++ Edition)

Esta es la versión nativa en **C++** de mi simulador interactivo de batallas RPG. 

Diseñé e implementé este juego con el propósito de demostrar mi dominio de la **arquitectura de software a bajo nivel** y mi capacidad para aplicar conceptos avanzados de la Programación Orientada a Objetos en entornos de consola.

## 🧠 Conceptos Avanzados de POO que apliqué:

*   **Punteros y Referencias:** Manejo la instanciación dinámica en el `main.cpp` utilizando la palabra reservada `new` y libero la memoria con `delete` para evitar *memory leaks*. Controlo las entidades a través de punteros de la clase base (`Personaje*`).
*   **Herencia y Polimorfismo:** Creé una clase base abstracta `Personaje`. A partir de ella, heredan mis clases `Heroe` y `Enemigo`. Utilicé funciones virtuales (`virtual void atacar() = 0`) e implementaciones de sobrescritura (`override`) para garantizar que cada personaje se comporte distinto.
*   **Cast Dinámico:** Implementé `dynamic_cast` en tiempo de ejecución para acceder a los métodos exclusivos de las subclases.
*   **Persistencia de Datos (I/O):** Desarrollé un sistema de registro utilizando la librería `<fstream>` para guardar un histórico de las partidas y resultados directamente en un archivo de texto plano (`registro_partidas.txt`).

## ⚙️ Cómo ejecutar el juego:

El proyecto está diseñado para ser compilado con **g++ (MinGW)**. 
Para compilar y jugar automáticamente en entornos Windows, simplemente haz doble clic en el archivo `compilar_y_jugar.bat` que preparé.
