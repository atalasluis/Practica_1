# 1. Requerimientos Funcionales y No Funcionales
    # 1.1 Requerimientos Funcionales

    El sistema debe ser capaz de medir la distancia hacia un objeto cercano, encendiendo:
        -Un led color verde a una distancia entre 20 cm a 30 cm.
        -Un led color amarillo a una distancia entre 10 cm a 20 cm.
        -Un led color rojo a una distancia entre 5 cm a 10 cm.
        -Los 3 leds parpadean a una distancia menor a 3cm.

# 1.2 Requerimientos No Funcionales

    -El sistema debe medir distancias con un margen de error aproximado de +- 3 cm
    -El software debe estar estructurado utilizando programación orientada a objetos, separando el control del sensor y de los LEDs en clases independientes.
    -El sistema debe utilizar múltiples muestras para reducir fluctuaciones en la lectura del sensor.

# 2. Diseño del Sistema
    # 2.1 Diagrama de Bloques
    # 2.2 Diagrama de Circuito

                    ESP32-WROOM-32
                ┌──────────────────┐
                │                  │
    5V ──────────┤5V            G15 ├──────── TRIG (HC-SR04)
                │                  │
    GND ─────────┤GND           G2  ├──────── ECHO (HC-SR04)
                │                  │
                │              G5  ├───[220Ω]───|>|─── GND   LED1
                │                  │
                │             G18  ├───[220Ω]───|>|─── GND   LED2
                │                  │
                │             G19  ├───[220Ω]───|>|─── GND   LED3
                │                  │
                └──────────────────┘


                HC-SR04 Sensor
                ┌─────────────────┐
    5V ─────────┤ VCC             │
    G15 ────────┤ TRIG            │
    G2  ────────┤ ECHO            │
    GND ────────┤ GND             │
                └─────────────────┘

    # 2.3 Diagrama de Arquitectura del Sistema

![Arquitectura del Sistema](/docs/images/DE1.png)

    # 2.4 Diagramas Estructurales y de Comportamiento
# 3. Implementacion
    # 3.1 Codigo Fuente Documentado
# 4. Pruebas y Validasiones
# 5. Resultados
# 6. Concluciones
# 7. Recomendaciones
# 8. Anexos