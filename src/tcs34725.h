#ifndef COLOR_SENSOR_H
#define COLOR_SENSOR_H

#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/i2c.h"

// --- Constantes do Sensor TCS34725 ---
#define SENSOR_ADDR       0x29
#define TCS_COMMAND_BIT   0x80
#define TCS_ENABLE_REG    0x00
#define TCS_CLEAR_REG     0x14
#define TCS_RED_REG       0x16
#define TCS_GREEN_REG     0x18
#define TCS_BLUE_REG      0x1A

// --- Pinos I2C utilizados ---
// Conectado na porta I2C 0 da BitDogLab
#define I2C_SDA_PIN 0
#define I2C_SCL_PIN 1

// Estrutura para guardar os quatro valores de cor
typedef struct {
    uint16_t r, g, b, c;
} color_data_t;

// Protótipos das Funções
void tcs34725_init();
void tcs34725_read(color_data_t *data);

#endif // COLOR_SENSOR_H