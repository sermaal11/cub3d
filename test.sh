#!/bin/bash

# Pedir al usuario qué carpeta analizar
echo "Selecciona la carpeta a analizar:"
echo "1 = maps/valid/*.cub"
echo "2 = maps/invalid/*.cub"
echo "3 = maps/bonus/*.cub"
read -p "Opción: " option

case $option in
    1) folder="maps/valid/*.cub" ;;
    2) folder="maps/invalid/*.cub" ;;
    3) folder="maps/bonus/*.cub" ;;
    *) echo "Opción no válida"; exit 1 ;;
esac

# Recorremos todos los archivos .cub en la carpeta seleccionada
for file in $folder; do
    output=$(./cub3D "$file" 2>&1)
    exit_code=$?
    
    if [ $option -eq 2 ]; then
        if [ $exit_code -eq 0 ]; then
            echo -e "\e[32m$file\e[0m"  # Verde si es válido
            echo "$output"
        else
            echo "$output" > /dev/null  # Redirigir la salida a la basura si es inválido
        fi
    else
        if [ $exit_code -eq 0 ]; then
            if [ -z "$output" ]; then
                echo -e "\e[32m$file\e[0m"  # Verde si no hay salida
            else
                echo "$output" > /dev/null  # Redirigir la salida a la basura
            fi
        elif [ $exit_code -eq 1 ]; then
            echo -e "\e[31m$file\e[0m"  # Rojo para error (1)
			echo "$output"
        else
            echo -e "\e[33m$file (Código desconocido: $exit_code)\e[0m"  # Amarillo para otros códigos
        fi
    fi
done