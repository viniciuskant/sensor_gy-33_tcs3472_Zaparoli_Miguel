# <NOME DO SENSOR> — Sensores na BitDogLab

**Dupla:** Nome A (RA / @usuario), Nome B (RA / @usuario)  
**Turma:** EA801 — 2025S2  
**Repositório:** (URL deste repo)

## 1. Descrição do sensor
- Fabricante / modelo:
- Princípio de funcionamento:
- Tensão/consumo típicos:
- Faixa de medição / resolução:
- Datasheet (URL):

## 2. Conexões de hardware
- Tabela indicando as conexões entre BitDogLab e sensor:
- Observações (resistores, alimentação externa, níveis lógicos):

**Tabela de conexões (imagem em `docs/`):**  
![conexoes](docs/conexoes.jpg)

## 3. Dependências
- MicroPython/C versão:
- Bibliotecas utilizadas:
- Como instalar (passo a passo):

## 4. Como executar
```bash
# MicroPython (Thonny): copiar src/main.py para a placa e rodar
# C (Pico SDK): ver docs/compilacao.md
```

## 5. Exemplos de uso
- `src/exemplo_basico.py` — leitura bruta  
- `src/exemplo_filtrado.py` — leitura com média móvel  
- `test/` — códigos de teste com instruções  

## 6. Resultados e validação
- Prints/plots, fotos do setup, limitações, ruídos, dicas.

## 7. Licença
- Ver arquivo `LICENSE`.

---

> **Checklist de entrega**
> - [ ] README preenchido  
> - [ ] Foto/diagrama em `docs/`  
> - [ ] Código comentado em `src/`  
> - [ ] Testes em `test/` com instruções  
> - [ ] `relatorio.md` com lições aprendidas

## 📁 7. Estrutura do Repositório

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