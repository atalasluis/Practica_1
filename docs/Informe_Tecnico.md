# 1. Requerimientos Funcionales y No Funcionales

### 1.1 Requerimientos Funcionales

        El sistema debe ser capaz de medir la distancia hacia un objeto cercano, encendiendo:
            - Un led color verde a una distancia entre 20 cm a 30 cm.
            - Un led color amarillo a una distancia entre 10 cm a 20 cm.
            - Un led color rojo a una distancia entre 5 cm a 10 cm.
            - Los 3 leds parpadean a una distancia mayor a 3cm.

# 1.2 Requerimientos No Funcionales

    - El sistema debe medir distancias con un margen de error aproximado de +- 3 cm
    - El software debe estar estructurado utilizando programación orientada a objetos, separando el control del sensor y de los LEDs en clases independientes.
    - El sistema debe utilizar múltiples muestras para reducir fluctuaciones en la lectura del sensor.

# 2. Diseño del Sistema

### 2.1 Diagrama de Bloques

### 2.2 Diagrama de Circuito

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

### 2.3 Diagrama de Arquitectura del Sistema

![Arquitectura del Sistema](/docs/images/DE2.png)

### 2.4 Diagramas Estructurales y de Comportamiento

![Diagramas Estructurales y de Comportamiento](/docs/images/DE3.png)

# 3. Implementacion

### 3.1 Codigo Fuente Documentado

# 4. Pruebas y Validasiones

| Objeto            | Distancia Real (cm) | Error (cm) | Error (%) |
|-------------------|---------------------|------------|-----------|
| Bloque de madera  | 30                  | 0.5        | 1.67 %    |
| Bloque de madera  | 20                  | 1          | 5 %       |
| Bloque de madera  | 10                  | 2.5        | 25 %      |
| Bloque de madera  | 5                   | 1          | 20 %      |
| Bloque de madera  | 3                   | 1          | 33.33 %   |
| Celular           | 30                  | 1          | 3.33 %    |
| Celular           | 20                  | 1.5        | 7.5 %     |
| Celular           | 10                  | 1          | 10 %      |
| Celular           | 5                   | 1.5        | 30 %      |
| Celular           | 3                   | 1          | 33.33 %   |
| Caja de cartón    | 30                  | 1          | 3.33 %    |
| Caja de cartón    | 20                  | 2          | 10 %      |
| Caja de cartón    | 10                  | 1.5        | 15 %      |
| Caja de cartón    | 5                   | 2.5        | 50 %      |
| Caja de cartón    | 3                   | 0.5        | 16.67 %   |

### Análisis de resultados

    Las pruebas muestran que el sensor ultrasónico presenta mayor precisión en distancias largas (20–30 cm), donde el porcentaje de error se mantiene generalmente por debajo del 10%.

    Sin embargo, al disminuir la distancia (5 cm y 3 cm) el porcentaje de error aumenta significativamente. Esto se debe a limitaciones propias del sensor HC-SR04, el cual tiene menor precisión en distancias muy cortas.

    También se observó que el tipo de objeto influye ligeramente en la medición, debido a factores como la textura y la capacidad de reflejar la onda ultrasónica.

# 5. Resultados

# 6. Concluciones

# 7. Recomendaciones

# 8. Anexos