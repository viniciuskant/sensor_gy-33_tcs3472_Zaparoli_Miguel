# Sensor de Cor GY-33 TCS34725 — Sensores na BitDogLab

**Dupla:** Tiago Silveira Zaparoli (237310 / TZShinobi), Vinicius P. M. Miguel (260731 / viniciuskant)
**Turma:** EA801 — 2025S2  

## 1. Descrição do sensor
- Fabricante / modelo: GY-33 TCS34725
- Princípio de funcionamento:
>  O sensor TCS3472 retorna uma saída digital correspondendo às leituras de luz vermelha, verde e azul, bem como a intensidade total da luz recebida pelo sensor. Para tanto o sensor segue o seguinte fluxo de operação:
>- A luz é percebida pelo sensor e passada por um filtro bloqueador de luz infravermelha (IR blocking filter), responsável por diminuir a contribuição da luz infravermelha no espectro de luz obtido e permitindo melhor precisão na leitura dos dados.
>- Um grid 3x4 de fotodiodos sensíveis à cor (vermelho, verde, azul e intensidade de luz) localizados no circuito integrado realizam a leitura da luz filtrada, mandando os dados para 4 conversores ADC (analógico para digital).
>- Cada um dos 4 ADCs integrados realiza a conversão do valor lido pelos fotodiodos para um valor digital de 16 bits, transferindo os dados obtidos para 4 registradores dedicados (um para cada ADC).
>- Finalmente, os dados são comunicados via interface de 2 fios do tipo I²C serial de alta velocidade (400 kHz).
>- Adicionalmente, o sensor provê separadamente um sinal de interrupção como saída, sendo útil para configuração de limites inferiores e superiores para as leituras, delimitando a faixa de leitura relevante para a aplicação (valores lidos fora da região de leitura são automaticamente assumidos como zero).
- Tensão/consumo típicos:
> A tensão de alimentação recomendada é de 2,7 V à 3,3 V.

- Faixa de medição / resolução:
- Datasheet (URL): [GY-33 CS3472](https://cdn-shop.adafruit.com/datasheets/TCS34725.pdf)

## 2. Conexões de hardware
- Para realiza a conexão utiliza-se a conexão J6, conforme a tabela:

| Pino GY-33 (TCS34725) | BitDogLab (RP2040) | Função                           |
| --------------------- | ------------------ | -------------------------------- |
| VIN                   | 3V3                | Alimentação                      |
| GND                   | GND                | Referência (Ground)              |
| SDA                   | GP0 (I2C0 SDA)     | Comunicação I2C                  |
| SCL                   | GP1 (I2C0 SCL)     | Comunicação I2C                  |

- O pino INT de interrupção não é utilizado na implementação.

## 3. Dependências
- MicroPython versão: 1.26
- Bibliotecas utilizadas: 

- Para instalar o micro python:
    ``` bash 
    yay -Sy micropython
    ```

- Para instalar o PicoTool:

    ```bash
    sudo pacman -S picotool
    ```


- Para instalar o interpretador acesso o [site](https://www.raspberrypi.com/documentation/microcontrollers/micropython.html) instale o `.uf2`, após instalador use o comando:

    ``` bash
    picotool load nome_do_arquivo.uf2 -f
    ```

- Após isso teremos o Pi Pico configurado para executar programas em micropython, para isso basta carregar o arquivo para a placa da seguinte forma:
    ``` bash
    mpremote connect /porta/pi_pico fs cp main.py: main.py
    ```

## 4. Exemplos de uso
- `src/exemplo_basico.py` — leitura bruta  
- `src/exemplo_filtrado.py` — leitura com média móvel  
- `test/` — códigos de teste com instruções  

## 5. Resultados e validação
- Prints/plots, fotos do setup, limitações, ruídos, dicas.


> **Checklist de entrega**
> - [ ] README preenchido  
> - [ ] Foto/diagrama em `docs/`  
> - [ ] Código comentado em `src/`  
> - [ ] Testes em `test/` com instruções  
> - [ ] `relatorio.md` com lições aprendidas

## 📁 6. Estrutura do Repositório

O projeto segue o padrão definido pela disciplina EA801 — Sistemas Embarcados, 
visando padronizar as entregas e facilitar o reuso dos códigos e documentação.

Todos os arquivos de código devem estar em src/.
Diagramas, fotos, gráficos e documentos vão em docs/.
Scripts ou logs de teste ficam em test/.
O relatório técnico (relatorio.md) documenta todo o processo de engenharia.

Mantenha os nomes dos arquivos em minúsculas, sem acentos ou espaços, usando _ ou -.

```text
template_sensor/
├── README.md          → Descrição completa do projeto (sensor, ligações, execução e checklist)
├── relatorio.md       → Relatório técnico da dupla (resultados, análise e conclusões)
├── LICENSE            → Licença MIT de uso e distribuição
├── .gitignore         → Regras para ignorar arquivos temporários e binários
│
├── docs/              → Documentação e mídias
│   ├── ligacao.jpg    → Diagrama ou foto da ligação na BitDogLab
│   ├── esquema.pdf    → Esquemático opcional
│   └── outros arquivos de apoio
│
├── src/               → Códigos-fonte principais
│   ├── main.py        → Código principal (MicroPython)
│   ├── main.c         → Versão alternativa (C / Pico SDK)
│   ├── exemplos/      → Códigos ilustrativos adicionais
│   └── bibliotecas/   → Drivers, módulos auxiliares
│
└── test/              → Testes e validações
    ├── test_basico.py → Teste de leitura e resposta do sensor
    ├── test_ruido.py  → Avaliação de ruído ou estabilidade
    └── logs/          → Registros experimentais, dados e gráficos

```
