*This project has been created as part of the 42 curriculum by smarin-a, jdelorme.*

# cub3D

## Description

cub3D is a first-person graphical project based on ray-casting, developed in C with
the MiniLibX graphics library. Its purpose is to render a maze from an interior
perspective, following the technical principles popularized by early FPS engines such
as Wolfenstein 3D.

The project combines file parsing, map validation, real-time rendering, texture
sampling, keyboard event handling, and basic movement physics. Scene data is provided
through a `.cub` file that defines wall textures, floor and ceiling colors, and the
layout of the map.

## Features

- Ray-casting renderer for a first-person maze representation.
- Different wall textures for the north, south, west, and east faces.
- Floor and ceiling colors defined through RGB values.
- Player movement with `W`, `A`, `S`, and `D`.
- Camera rotation with the left and right arrow keys.
- Collision handling against walls.
- Scene parsing and validation from `.cub` files.
- Bonus-oriented minimap and weapon texture support.

## Instructions

### Requirements

- `cc` or `gcc`
- GNU Make
- MiniLibX dependencies
- X11 development libraries on Linux, or the required AppKit/OpenGL environment on
  macOS

On many Linux systems, MiniLibX requires X11 headers and libraries such as
`libx11-dev` and `libxext-dev`.

### Compilation

Build the Linux target:

```sh
make
```

Build the macOS target:

```sh
make macos
```

Clean generated objects:

```sh
make clean
```

Remove generated objects, libraries, and the executable:

```sh
make fclean
```

Rebuild from scratch:

```sh
make re
```

### Execution

Run the program with a valid `.cub` scene file:

```sh
./cub3D maps/valid/map_subject.cub
```

Controls:

- `W`: move forward
- `S`: move backward
- `A`: strafe left
- `D`: strafe right
- `Left Arrow`: rotate left
- `Right Arrow`: rotate right
- `ESC`: close the program

## Scene File Format

A valid `.cub` file contains texture paths, floor and ceiling colors, and a closed
map. The map must be the final section of the file.

Example:

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

Mandatory identifiers:

- `NO`: north wall texture
- `SO`: south wall texture
- `WE`: west wall texture
- `EA`: east wall texture
- `F`: floor color in `R,G,B` format
- `C`: ceiling color in `R,G,B` format

Map symbols:

- `1`: wall
- `0`: empty space
- `N`, `S`, `E`, `W`: player start position and orientation
- Space characters are interpreted as part of the map and must be handled carefully.

## Project Structure

- `src/parsing/`: scene parsing and map validation.
- `src/rendering/`: ray initialization, DDA traversal, wall projection, and frame
  rendering.
- `src/textures/`: texture loading and wall texture sampling.
- `src/movement/`: player movement, strafing, and rotation.
- `src/bonus/minimap/`: minimap rendering utilities.
- `include/`: public project structures, constants, and function prototypes.
- `libft/`: local implementation of selected standard C utilities.
- `minilibx-linux/` and `minilibx-opengl/`: MiniLibX sources for Linux and macOS.
- `maps/`: valid, invalid, and bonus scene files used for testing.
- `textures/`: XPM texture assets.

## Resources

- 42 cub3D subject PDF.
- MiniLibX documentation and manual pages.
- Lode Vandevenne, "Raycasting Tutorial":
  https://lodev.org/cgtutor/raycasting.html
- Wolfenstein 3D technical references and historical material.
- C manual pages for memory management, file descriptors, math functions, and time
  utilities.

## AI Usage

AI assistance was used as a review aid for documentation quality, requirement
cross-checking, and general project auditing. The implementation remains the
responsibility of the project authors, and all AI-assisted suggestions should be
validated through compilation, testing, peer review, and direct understanding of the
code.

## Authors

- Sergio Marin Alvarez, `smarin-a`
- Juan Delorme, `jdelorme`
