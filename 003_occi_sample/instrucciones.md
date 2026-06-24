# Instrucciones
Aplicacion de ejemplo para probar la conexion de una app gtkmm con OCCI a una BD de OCI
## Requisitos 
- Tener comfigurado el nombre de servicio mqroci_bd_lab
- haber inyectado la clave de bd_lab en el nombre de servicio para la Billera que se encuentra en TNS_ADMIN
- Haber intstalado oracle-instantclient-devel-linuxx64: DSK( rpm )
- Tener instaladas las librerias de gtkmm 4
### crear la tabla de pueba en la BD
```bash
sqlcl /@mqroci_bd_lab
*******
******
CREATE TABLE bitacora (
    id NUMBER GENERATED ALWAYS AS IDENTITY PRIMARY KEY,
    mensaje VARCHAR2(500),
    fecha_registro TIMESTAMP DEFAULT CURRENT_TIMESTAMP
);
```
## Compilar
compilar la aplicacion
```bash
sh compile.sh
```

## Ejecutar la aplicaicon

```bash
    ./my_gtk_app
```

