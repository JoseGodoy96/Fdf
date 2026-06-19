FdF (Fil de Fer)


Un visualizador en C que representa un mapa de alturas como un modelo 3D en
wireframe (malla de alambre) usando proyección isométrica y la librería
gráfica MiniLibX.



Proyecto realizado en la escuela 42 (campus de 42 Málaga). Por tratarse de una
entrega ya evaluada y cerrada, el repositorio contiene un único commit: el
proyecto está terminado y no recibe nuevos cambios.


📖 Descripción

FdF ("Fil de Fer", hilo de hierro en francés) es el primer proyecto gráfico de
42. A partir de un archivo .fdf que describe un terreno mediante una matriz de
alturas, el programa dibuja su relieve como una rejilla tridimensional.

El archivo de mapa es una cuadrícula de números, donde cada valor representa la
altura (z) de ese punto:

0 0 0 0 0
0 5 5 5 0
0 5 9 5 0
0 5 5 5 0
0 0 0 0 0

El programa:


Lee y valida el mapa .fdf con ayuda de get_next_line, construyendo una
matriz de alturas.
Proyecta cada punto (x, y, z) del espacio 3D a coordenadas 2D de pantalla
mediante una proyección isométrica (usando seno/coseno y la elevación de z).
Calcula la escala y el centrado automáticamente para que el modelo encaje en
la ventana, dejando un margen.
Dibuja las líneas que unen los puntos con el algoritmo de Bresenham.
Abre una ventana con MiniLibX y permite interactuar con el modelo mediante el
teclado.



🎮 Controles

TeclaAcciónFlechas ↑ ↓ ← →Desplazar el modelo (pan).+ / -Acercar / alejar (zoom).+ / - (alt)Aumentar / reducir la elevación de z.RResetear la cámara a su estado inicial.ESCCerrar la ventana y salir.


🧠 Conceptos trabajados


Programación gráfica con MiniLibX (ventana, imagen, mlx_pixel_put, hooks).
Proyección isométrica de coordenadas 3D a 2D.
Trazado de líneas con el algoritmo de Bresenham.
Lectura de ficheros con get_next_line.
Gestión de memoria y manejo de eventos de teclado/ventana.



🗂️ Estructura del proyecto

Fdf/
├── Makefile
├── include/
│   └── fdf.h
├── src/
│   ├── main.c            # inicialización y bucle principal
│   ├── parsing_init.c    # validación del archivo de entrada
│   ├── parsing_map.c     # lectura del mapa a matriz de alturas
│   ├── camera.c          # configuración de la cámara
│   ├── projection.c      # proyección isométrica + escala/centrado
│   ├── algorithm.c       # trazado de líneas (Bresenham)
│   ├── draw.c            # dibujado de la malla en la ventana
│   ├── hooks.c           # eventos de teclado y cierre
│   └── utils.c           # liberación de memoria
├── libft/                # librería propia (dependencia)
├── gnl/                  # get_next_line (dependencia)
├── minilibx-linux/       # librería gráfica MiniLibX (Linux)
├── test_maps/            # mapas .fdf de ejemplo
└── Personal/             # material de apoyo (enunciado, norma, notas)


El proyecto usa Libft, get_next_line y MiniLibX como dependencias. El
Makefile las compila automáticamente antes de enlazar el ejecutable.




🚀 Compilación y uso

bash# Compilar (compila también libft, gnl y MiniLibX)
make

# Ejecutar con un mapa
./fdf test_maps/42.fdf
./fdf test_maps/mars.fdf

Dependencias del sistema (MiniLibX en Linux)

MiniLibX necesita las librerías de X11. En sistemas basados en Debian/Ubuntu:

bashsudo apt install xorg libxext-dev

El enlazado utiliza -lXext -lX11 -lm.

Reglas del Makefile

ComandoDescripciónmakeCompila las dependencias y el ejecutable fdf.make cleanElimina los archivos objeto (.o).make fcleanElimina los .o, el ejecutable y las librerías.make reRecompila todo desde cero.


👤 Autor

jgodoy-m — Estudiante de 42 Málaga


📝 Nota sobre el repositorio

Este proyecto forma parte del currículo de 42. Al ser una entrega ya finalizada
y corregida, el historial del repositorio se compone de un solo commit. No está
en desarrollo activo: el código está completo y cumple los requisitos de la consigna.
