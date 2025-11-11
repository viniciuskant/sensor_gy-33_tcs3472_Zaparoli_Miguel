#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/i2c.h"
#include "tcs34725.h"

// Função para identificar a cor
const char* detectar_cor(void) {
    color_data_t data;
    tcs34725_read(&data);
    
    if (data.r == 0 && data.g == 0 && data.b == 0) {
        return "Sem luz";
    }
    
    // Encontra o canal dominante
    uint16_t max_val = data.r;
    if (data.g > max_val) max_val = data.g;
    if (data.b > max_val) max_val = data.b;
    
    // Calcula razões em relação ao máximo
    float r_ratio = (float)data.r / max_val;
    float g_ratio = (float)data.g / max_val;
    float b_ratio = (float)data.b / max_val;
    
    printf("R: %d, G: %d, B: %d - ", data.r, data.g, data.b);
    printf("Ratios: R=%.2f, G=%.2f, B=%.2f\n", r_ratio, g_ratio, b_ratio);
    
    // Lógica baseada nas razões - AJUSTADA PARA AMARELO
    if (r_ratio > 0.8 && g_ratio < 0.5 && b_ratio < 0.5) {
        return "Vermelho";
    } else if (r_ratio < 0.5 && g_ratio > 0.8 && b_ratio < 0.5) {
        return "Verde";
    } else if (r_ratio < 0.7 && g_ratio < 0.8 && b_ratio > 0.8) {
        return "Azul";
    } else if (r_ratio > 0.8 && g_ratio > 0.8 && b_ratio < 0.6) {
        return "Amarelo";
    } else if (r_ratio > 0.8 && g_ratio < 0.6  && b_ratio > 0.8 ) {
        return "Magenta";
    } else if (r_ratio < 0.6  && g_ratio > 0.8  && b_ratio > 0.8 ) {
        return "Ciano";
    } else if (r_ratio > 0.5 && g_ratio > 0.5 && b_ratio > 0.5) {
        // Para cores balanceadas, verifica valores absolutos
        if (data.r > 1500 && data.g > 1500 && data.b > 800) {
            return "Branco";
        } else if (data.r > 800 && data.g > 800 && data.b > 400) {
            return "Cinza Claro";
        } else {
            return "Cinza Escuro";
        }
    } else {
        // Verifica se é realmente preto ou outra cor
        if (data.r + data.g + data.b < 500) {
            return "Preto";
        } else {
            return "Outra Cor";
        }
    }
}

int main() {
    // Inicializa stdio via USB
    stdio_init_all();
    
    // Aguarda um pouco para a inicialização do USB
    sleep_ms(2000);
    printf("Iniciando sistema de detecção de cores...\n");

    // Inicializa sensor de cor (já configura o I2C0 internamente)
    tcs34725_init();
    printf("Sensor TCS34725 inicializado!\n");

    // Loop principal
    while (true) {
        const char* cor = detectar_cor();
        printf("Cor detectada: %s\n", cor);
        sleep_ms(1000); // Delay de 1 segundo
    }

    return 0;
}