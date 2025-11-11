# Relatório Técnico da Dupla

## 1. Escopo e Objetivos
Implementar um sistema de detecção de cores utilizando o sensor GY-33 TCS34725 via interface I2C na plataforma BitDogLab (RP2040), com capacidade de calibração interativa e detecção em tempo real de cores predefinidas. O sistema deve permitir a identificação de cores básicas (Vermelho, Verde, Azul, Amarelo, Magenta, Ciano, Branco e Preto) através de dois métodos: comparação com intervalos calibrados e interpolação via espaço de cores HSL para cores não calibradas.

**Critérios de sucesso:**
- Comunicação I2C estável com o sensor TCS34725 a 100 kHz
- Rotina de calibração funcional via botão físico
- Detecção precisa das cores calibradas com margem de erro de ±15%
- Sistema de fallback para detecção via HSL quando a cor não estiver calibrada
- Saída serial em tempo real com a cor detectada

## 2. Metodologia e Implementação

**Arquitetura do Sistema:**
- **Hardware:** BitDogLab (RP2040) + Sensor GY-33 TCS34725
- **Comunicação:** I2C a 100 kHz usando GPIO0 (SDA) e GPIO1 (SCL)
- **Interface:** Botão físico (GPIO5) para controle da calibração
- **Saída:** Comunicação serial via USB para monitoramento

**Estratégias de Programação:**
- Desenvolvimento em C usando Pico SDK
- Implementação de driver específico para TCS34725 (tcs34725.c/h)
- Sistema de calibração com armazenamento de intervalos RGB
- Algoritmo duplo de detecção (RGB calibrado + HSL interpolado)
- Filtragem por média móvel (10 leituras) durante calibração

**Configurações BitDogLab:**
- I2C0 configurado em GPIO0 (SDA) e GPIO1 (SCL)
- Pull-ups internos ativados no barramento I2C
- Botão A (GPIO5) com pull-up para controle de calibração
- Taxa de serial: 115200 baud

**Fluxo Lógico:**
1. Inicialização do sensor e barramento I2C
2. Rotina de calibração guiada para 8 cores
3. Leitura contínua dos valores RGB do sensor
4. Detecção primária por comparação com intervalos calibrados
5. Detecção secundária por conversão RGB→HSL e comparação com faixas de matiz
6. Saída serial do resultado

## 3. Resultados e Análise

**Validação Técnica:**
- Comunicação I2C estabelecida com sucesso no endereço 0x29
- Leituras estáveis dos registradores de cor (16 bits por canal)
- Tempo de resposta do sistema: < 500ms por detecção
- Faixa dinâmica confirmada: 0-65535 para cada canal RGB

**Desempenho de Detecção:**
- Precisão com cores calibradas: >90% em condições controladas
- Detecção HSL: funcional para cores básicas não calibradas
- Margem de erro medida: ±12% nos testes de repetibilidade

**Limitações Identificadas:**
- Necessidade de proximidade sensor-superfície (< 1cm)
- Sensibilidade a condições de iluminação ambiente
- Limitação a 8 cores predefinidas na calibração
- Interpolação HSL menos precisa para cores saturadas

**Evidências:**
- Montagem física funcional com sensor posicionado adequadamente
- Capturas demonstrando detecção precisa de azul e vermelho
- Logs de calibração mostrando intervalos consistentes

## 4. Dificuldades e Soluções

**Desafio 1: Timing do Barramento I2C**
- *Problema:* Leituras inconsistentes nos registradores do sensor
- *Solução:* Implementação de delays adequados entre comandos e verificação de ACK

**Desafio 2: Calibração Robusta**
- *Problema:* Variação nas leituras devido a ruído e condições de luz
- *Solução:* Média móvel de 10 leituras durante calibração e margem de 15%

**Desafio 3: Detecção de Cores Não Calibradas**
- *Problema:* Como detectar cores fora do conjunto calibrado
- *Solução:* Implementação de algoritmo HSL com faixas de matiz predefinidas

**Desafio 4: Interface de Usuário**
- *Problema:* Como guiar o usuário através do processo de calibração
- *Solução:* Sistema de prompts via serial e controle por botão único

## 5. Conclusões e Trabalhos Futuros

**Conclusões:**
- Sistema de detecção de cores funcional e eficaz para aplicações básicas
- Abordagem de calibração interativa mostrou-se intuitiva e prática
- Método duplo (RGB+HSL) aumentou significativamente a versatilidade do sistema
- Plataforma BitDogLab adequada para prototipagem com sensores I2C

**Trabalhos Futuros:**
- Implementação de algoritmo de machine learning para classificação de cores
- Expansão para detecção de tons específicos (pastéis, terros, etc.)
- Sistema de calibração automática baseado em cores de referência
- Integração com display OLED para feedback visual direto
- Adaptação para ambiente MicroPython para facilitar prototipagem
- Desenvolvimento de biblioteca genérica para família de sensores TCS

## 6. Referências

1. **AMS-TAOS USA** - *TCS34725 Datasheet* - Documentação técnica do sensor de cor
2. **Raspberry Pi Foundation** - *Pico C/C++ SDK* - Documentação de desenvolvimento
3. **BitDogLab** - *Pinout and Specifications* - Diagramas e especificações da plataforma
4. **Wikipedia** - *HSL and HSV Color Models* - Fundamentos teóricos do espaço de cores HSL
5. **Adafruit Industries** - *TCS34725 Application Notes* - Notas de aplicação e exemplos