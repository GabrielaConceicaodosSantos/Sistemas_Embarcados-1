1. Cite as vantagens e desvantagens das comunicação serial:

(a) Assíncrona (UART).

- Formato de comunicação simples
- É uma comunicação assíncrona, portanto não necessita de clock, reduzindo o número de fios
- Por conta de não usar clock, os dispositivos devem estar sincronizados para a informação ser transmitida e configurados de forma que possam saber quando se inicia e se finaliza a comunicação
- É uma comunicação FULL-DUPLEX, ou seja, os dispositivos podem enviar e receber dados ao mesmo tempo
- A UART é mais interessante para conexão de dois dispositivos. É até possível conectar mais de dois, mas os dispostivos que forem conectados devem saber que dados serão utilizados e quais serão jogados fora.
- A comunicação com UART exige um hardware mais robusto que no caso do SPI

(b) SPI.

- A comunicação SPI é uma comunicação síncrona, ou seja, os dispostivos enviam dados e uma linha de clock.
- Costuma ter a linha de dados, a linha de clock e a linha de seleção de dispositivos. Por conta disso, a comunicação SPI exige mais fios que a UART, ainda que seja para dois dispositivos.
- A comunicação SPI exige hardware mais simples que no caso do UART (por exemplo, com um shift register já é possível realizar a comunicação SPI)
- Existem ao menos dois dispositivos, o MASTER (mestre) e o SLAVE (escravo). Só existe 1 mestre, e podem existir vários escravos. O mestre que sempre envia o clock, e é pelo fio SCK (Source of Clock) que conecta a todos os dispostivos. Quando o mestre quer enviar um dado, este é enviado por uma linha chamada MOSI (MASTER-OUT-SLAVE-IN), e o escravo também possui esta linha. Quando o escravo quer enviar um dado, este é enviado pela linha chamada MISO (MASTER-IN-SLAVE-OUT). Pode exister mais um fio chamado SLAVE SELECT - SS, ou vários fios, para seleção dos escravos.
- A comunicação SPI é bem mais rápida que a assíncrona

2. Considere o caso em que a Raspberry Pi deve receber leituras analógico/digitais de um MSP430, e que a comunicação entre os dois é UART. É tecnicamente possível que o MSP430 mande os resultados da conversão A/D a qualquer hora, ou ele deve aguardar a Raspberry Pi fazer um pedido ao MSP430? Por quê?

Sim, é possível. Como existem fios separados para TX e RX, cada módulo pode receber e enviar dados ao mesmo tempo.

3. Considere o caso em que a Raspberry Pi deve receber leituras analógico/digitais de um MSP430, que a comunicação entre os dois seja SPI, e que o MSP430 seja o escravo. É tecnicamente possível que o MSP430 mande os resultados da conversão A/D a qualquer hora, ou ele deve aguardar a Raspberry Pi fazer um pedido ao MSP430? Por quê?

Não é possível. Neste caso, quando Raspberry Pi quiser saber os dados de uma leitura do conversor A/D, este deve enviar clock para a linha SCK e só depois disso o dado pode ser enviado. Portanto, fica a cargo da Raspberry Pi a hora de receber e enviar dados.

4. Se o Raspberry Pi tiver de se comunicar com dois dispositivos via UART, como executar a comunicação com o segundo dispositivo?

O TX da Raspberry Pi deve ser ligado ao RX do dispositivo 1 e ao RX do dispositivo 2. Porém só é possível se comunicar ou com o 1, ou com o 2, e deve ser escolhido qual dos dois se comunicar. Neste caso o dispositivo 1 poderia se comunicar enviando e recebendo dados, e o segundo só receberia dados. Se os dois dispositivos precisam enviar dados para o Raspberry Pi, então a UART não é interessante, é preferível usar o protocolo SPI ou I2C.

5. Se o Raspberry Pi tiver de se comunicar com dois dispositivos via SPI, como executar a comunicação com o segundo dispositivo?

Basta que seja usado um fio de SS - SLAVE SELECT, onde SS1 vai para o Slave 1 e o SS2 vai para o Slave 2. Quando a Raspberry Pi quiser se comunicar com o Slave 1, ela coloca a linha SS1 em nível baixo e quando quiser se comunicar com o Slave 2, coloca a linha SS2 em nível baixo. 

