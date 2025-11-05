@echo off
set NOMBRE_EJECUTABLE=gestion_pedidos.exe

echo.
echo ===================================================
echo COMPILANDO PROYECTO C++ (Estructura src/include)
echo ===================================================
echo.

:: La bandera -I include le dice a G++ donde buscar los archivos .h
:: Lista los archivos .cpp desde la carpeta src/

g++ -std=c++17 -Wall -I include/ src/main.cpp src/Pedido.cpp src/SistemaGestion.cpp -o %NOMBRE_EJECUTABLE%

echo.

:: ----------------------------------------------------
:: FASE DE VERIFICACION Y EJECUCION
:: ----------------------------------------------------
if exist %NOMBRE_EJECUTABLE% (
    echo COMPILACION EXITOSA!
    echo ===================================================
    echo EJECUTANDO %NOMBRE_EJECUTABLE%...
    echo.
    :: Ejecuta el programa
    %NOMBRE_EJECUTABLE%
) else (
    echo ERROR: Fallo la compilacion. Revisa los errores de G++.
    echo.
)

echo.
echo Proceso finalizado. Presiona cualquier tecla para continuar...
pause > nul