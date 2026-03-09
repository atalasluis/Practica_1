# 1. Requerimientos Funcionales y No Funcionales
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

![Arquitectura del Sistema](https://ejemplo.com/logo.png)

# 2.4 Diagramas Estructurales y de Comportamiento
# 3. Implementacion
# 3.1 Codigo Fuente Documentado
# 4. Pruebas y Validasiones
# 5. Resultados
# 6. Concluciones
# 7. Recomendaciones
# 8. Anexos