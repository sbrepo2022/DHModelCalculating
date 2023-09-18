#!/bin/bash

# Проходимся по директориям всех зависимостей, собираем и устанавливаем их в директорию installed_dependencies в корне проекта

process_dependencies() {
    for item in "$1"/*; do
        if [ -d "$item" ]; then
            cd "$item" || continue
            mkdir cmake_build
            cd cmake_build
            
            cmake ..
            cmake --build .
            cmake --install . --prefix="../../../installed_dependencies"

            cd ..
            cd ..
        fi
    done
}

process_dependencies "dependencies"
