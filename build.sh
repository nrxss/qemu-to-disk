#!/bin/bash

set -e

rm -rf build
rm -rf dist

mkdir build
mkdir dist

cd build

cmake ..
cmake --build .

cd ..

if [ $# -gt 0 ]; then
    for arg in "$@"; do
        case $arg in
            --run)
                ./dist/QemuToDisk
                ;;
            --help)
                echo "Usage: build.sh [options]"
                echo "Options:"
                echo "  --run       Run the QemuToDisk application"
                echo "  --help      Show this help message"
                exit 0
                ;;
            *)
                echo "Unknown option: $arg"
                exit 1
                ;;
        esac
    done
fi
