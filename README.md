# Cub3D

## 📌 Descripción
Cub3D es un proyecto de gráficos en 3D basado en raycasting, desarrollado como parte del currículo de la academia **42 Madrid**. Inspirado en el motor gráfico de Wolfenstein 3D, este proyecto permite renderizar un entorno 3D simple en tiempo real utilizando la librería **MiniLibX**.

## 🚀 Características
- Implementación de un motor de raycasting para representar un entorno en 3D.
- Soporte para texturas en las paredes.
- Movimiento del jugador en un espacio tridimensional con colisiones básicas.
- Lectura y validación de mapas desde archivos `.cub`.
- Gestión de colores para el cielo y el suelo.

## 📜 Requisitos
Para compilar y ejecutar **Cub3D**, se requieren las siguientes dependencias:

- **GNU Make** y **GCC**
- **MiniLibX**
- **Valgrind** (para detección de errores de memoria, opcional)
- **Linux o macOS**

## ⚙️ Instalación
Clona el repositorio y compílalo con:
```sh
$ git clone https://github.com/tuusuario/cub3d.git
$ cd cub3d
$ make
```

## 🎮 Uso
Para ejecutar el programa, usa:
```sh
$ ./cub3D maps/valid/map.cub
```

### Controles:
- `WASD`: Movimiento del jugador
- `← →`: Rotación de la vista
- `ESC`: Salir del juego

## 🗺️ Formato del Mapa
El mapa debe estar en formato **.cub** y debe contener:
- **Identificadores de texturas:** `NO`, `SO`, `WE`, `EA` (seguidos de la ruta de la textura)
- **Colores de cielo y suelo:** `F` (Floor), `C` (Ceiling)
- **Mapa del entorno:** Representado con `1` (paredes) y `0` (espacios abiertos)
- **Ubicación del jugador:** `N`, `S`, `E`, `W` (indica la posición y dirección inicial)

Ejemplo de mapa válido:
```txt
NO ./textures/wall_1.xpm
SO ./textures/wall_2.xpm
WE ./textures/wall_3.xpm
EA ./textures/wall_4.xpm

F 205,180,219
C 189,224,254

1111111111
1000000001
10N0000001
1000000001
1111111111
```

## 🛠️ Desarrollo
Para limpiar y recompilar el proyecto:
```sh
$ make fclean && make
```
Para depuración con Valgrind:
```sh
$ valgrind --leak-check=full ./cub3D maps/valid/map.cub
```

## 📌 Autores
- **Sergio Marín Álvarez** ([smarin-a](https://github.com/tuusuario))
- **Juan Delorme** ([jdelorme](https://github.com/jdelorme))

## 📜 Licencia
Este proyecto es parte del currículo de 42 Madrid y se distribuye bajo los términos de la academia.