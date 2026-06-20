# Instrucciones
## Instalacion de dependencias
```bash
sudo dnf install gcc-c++ gtkmm4.0-devel pkgconf-pkg-config
```
## Compilacion
compila.sh
```bash
g++ main.cpp -o mi_app $(pkg-config --cflags --libs gtkmm-4.0) -std=c++17
```
## ejecucion
```bash
./mi_app
```
## Apariencia de la aplicacion de ejemplo
![mi_app_running](./imgs/mi_app_running.png)
