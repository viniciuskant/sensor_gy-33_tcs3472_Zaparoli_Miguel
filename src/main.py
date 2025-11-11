import ssd1306
import machine
import time
import tcs34725

# Configuração do I2C para o display e sensor
i2c = machine.I2C(1, scl=machine.Pin(3), sda=machine.Pin(2), freq=400000)

# Inicializando o display OLED SSD1306
oled = ssd1306.SSD1306_I2C(128, 64, i2c)

# Inicializando o sensor TCS34725
sensor = tcs34725.TCS34725(i2c)

# Função para identificar a cor
def detectar_cor():
    r, g, b, c = sensor.get_raw_data()
    
    r, g, b = r / c, g / c, b / c
    
    if r > 1.5 and g < 1 and b < 1:
        return "Vermelho"
    elif r < 1 and g > 1.5 and b < 1:
        return "Verde"
    elif r < 1 and g < 1 and b > 1.5:
        return "Azul"
    elif r > 1.5 and g > 1 and b < 1:
        return "Amarelo"
    elif r > 1 and g < 1 and b > 1:
        return "Magenta"
    elif r < 1 and g > 1 and b > 1:
        return "Ciano"
    elif r > 1 and g > 1 and b > 1:
        return "Branco"
    else:
        return "Preto"

# Inicializando o sensor
sensor.enable()

# Função para exibir a cor no display OLED
def exibir_no_display(cor):
    oled.fill(0)  # Limpar o display
    oled.text("Cor detectada:", 0, 0)
    oled.text(cor, 0, 20)
    oled.show()

# Loop de leitura das cores e exibição no display
while True:
    cor = detectar_cor()
    exibir_no_display(cor)  # Exibe a cor no display
    print("Cor detectada:", cor)
    time.sleep(1)


