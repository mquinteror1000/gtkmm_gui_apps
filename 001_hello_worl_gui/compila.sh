mkdir -p build
g++ main.cpp -o ./build/mi_app $(pkg-config --cflags --libs gtkmm-4.0) -std=c++17
