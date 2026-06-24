mkdir -p build
g++ main.cpp -o ./build/mi_app_gtkmm \
    `pkg-config gtkmm-4.0 --cflags --libs` \
    -I/usr/include/oracle/23/client64 \
    -L/usr/lib/oracle/23/client64/lib \
    -locci -lclntsh
