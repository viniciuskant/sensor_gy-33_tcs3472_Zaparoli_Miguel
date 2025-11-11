#include "tcs34725.h"

// Função auxiliar privada para ler um valor de 16 bits de um registrador
static uint16_t read_register_16bit(uint8_t reg) {
    uint8_t buffer[2];
    uint8_t command = TCS_COMMAND_BIT | reg;

    i2c_write_blocking(i2c0, SENSOR_ADDR, &command, 1, true);
    i2c_read_blocking(i2c0, SENSOR_ADDR, buffer, 2, false);

    return (buffer[1] << 8) | buffer[0];
}

void tcs34725_init() {
    printf("Configurando Sensor de Cor GY-33 (TCS34725)...\n");

    // 1. Inicializa o barramento I2C
    i2c_init(i2c0, 100 * 1000);

    // 2. Define os pinos GPIO para as funções I2C
    gpio_set_function(I2C_SDA_PIN, GPIO_FUNC_I2C);
    gpio_set_function(I2C_SCL_PIN, GPIO_FUNC_I2C);
    gpio_pull_up(I2C_SDA_PIN);
    gpio_pull_up(I2C_SCL_PIN);

    // 3. "Acorda" o sensor e ativa a leitura
    // Escreve no registrador ENABLE para ligar o Power (PON) e o ADC (AEN)
    uint8_t enable_cmd[] = {TCS_COMMAND_BIT | TCS_ENABLE_REG, 0x01 | 0x02};
    i2c_write_blocking(i2c0, SENSOR_ADDR, enable_cmd, 2, false);

    sleep_ms(3); // Pequena pausa para o sensor estabilizar
    printf("Sensor de Cor pronto.\n");
}

void tcs34725_read(color_data_t *data) {
    // Lê cada um dos 4 canais de cor usando a função auxiliar
    data->c = read_register_16bit(TCS_CLEAR_REG);
    data->r = read_register_16bit(TCS_RED_REG);
    data->g = read_register_16bit(TCS_GREEN_REG);
    data->b = read_register_16bit(TCS_BLUE_REG);
}