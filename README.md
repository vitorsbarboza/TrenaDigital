# TrenaDigital
Este repositório contém o projeto do Grupo E para a disciplina de "Microcontroladores e Microprocessadores".

Integrantes do grupo:
- Letícia Borges Medeiros - 769159
- Lourdes Mikalef - 791401
- Pedro Gomes - 727651
- Vitor de Souza Barboza - 791446

## Proposta

O projeto consiste em utilizar um microcontrolador Arduino para a leitura da distância de um objeto e enviar essa informação para um smartphone. Para iniciar o projeto, é necessário ter em mãos um Arduino, o qual o tipo ainda será discutido, e um sensor ultrassônico. A partir disso, iremos desenvolver uma forma de transmissão dos dados para o smartphone seja por Bluetooth ou por aplicativo. 

## Plano de ação

  1. Escrever o programa para arduíno que controle o sensor e que tire as infomações das distâncias
  2. Encontrar uma forma de mandar as informações do microprocessador para o celular (sugestão do professor: usar um cabo de ethernet no arduíno para gerar um servidor)
  3. Aplicativo ou site que de controle ao usuário e que mostre a medida desejada.
  4. Utilizar comunicação assíncrona com mqtt ou síncrona com bluetooth 

## Componentes
O grupo irá utilizar a placa ESP32 (board) e um sensor ultrassônico HC-SR04. Para a programaçao da placa será utilizada a plataformIO através do VS code. A placa sera colocada em um protoboard que ligará todos os componentes utilizados. Para receber a informação, será utilizado o aplicativo Serial Bluetooth Terminal.

### Placa ESP32
Esta placa de desenvolvimento possui processador dual core, o que deixa o tempo de processamento muito menor, e conexão Wifi sem fio. Também possui um Sistema operacional de Tempo Real ouo RTOS, que permite executar multiplas tarefas de forma rapida e efetiva. Porém, a principal vantagem que motivou a escolha desta placa foi sua capacidade de conexão de bluetooth. Assim, o principal obstaculo, deenviar as medidas retiradas pelo sensor ao monitor, foi superado.

### Sensor ultrassonico HC-SR04
O sensor envia ondas ultrassonicas que quando se encontram com algum objeto retormam um echo ao sensor. Assim, com o tempo que levou para esse echo atingir novamente o sensor, é possivel calcular a distancia entre o sensor e o objeto. Este sensor se liga à placa com dois pinos de alimentação e dois pinos digitais, o 4 para o Trigger (responsavel pelo pulso inicial) e o 5 para o echo.

## Montagem do projeto

As conecções foram feitas a partir do pinout da placa:

![Pinout ESP32](https://github.com/vitorsbarboza/TrenaDigital/blob/main/Imagens/ESP32-DOIT-DEV-KIT-v1-pinout-mischianti.png)

Dessa forma, a placa foi colocada na protoboard de forma que o GND e o VIN (tensão de 5V) pudessem ser acessados facilmente, assim como os demais pinos. Com isso, foi possível conectar também o GND e o VCC tanto do sensor ultrassônico quanto do botão. Depois, conectou-se o botão ao pino 18, o echo do sensor no pino 5 e o trigger no pino 4. O botão foi conectado no pino 18, pois pode ser usado como um pino de entrada/saída digital comum. Os pinos 4 e 5 foram escolhidos para conectar o sensor pois são neles que a placa realiza leitura de sensor e conexões externas. Por fim, conectou-se a placa ao notebook para que fosse possível programá-la, com o código disponível em: `/src/main.cpp`.

Além disso, foi instalado o aplicativo Serial Terminal Bluetooth num dispositívo móvel e, ao pareá-lo com a placa e apertar o botão, foi possível ver o resultado de saída ou o "monitor" no aplicativo.

##Explicação do código

A princípio, incluiu-se a biblioteca BluetoothSerial.h para possibilitar a utilização do módulo Bluetooth em conjunto com o ESP32. Feito isso, criou-se uma instância de BluetoothSerial chamada SerialBT e declarou-se as constantes: trigPin, echoPin e buttonPin, que representam os pinos da placa aos quais estão conectados o pino de saída do sensor ultrassônico, o pino de entrada do sensor ultrassônico e o pino do botão, respectivamente.

Na função setup(), são configurados os pinos trigPin, echoPin e buttonPin como saída, entrada e entrada e iniciado o módulo Bluetooth.

Na função loop(), é feita uma verificação se o botão foi pressionado através da leitura do estado do buttonPin. Se o botão foi pressionado, é enviado um sinal para o pino trigPin do sensor ultrassônico, e em seguida é medida a duração do sinal de resposta do pino echoPin do sensor. A distância é calculada com base na duração do sinal e é enviada via Bluetooth e Serial. As medidas são enviadas com um delay de 1s.

## Deselvolvimento do projeto
O projeto foi realizado ao longo de três semanas:

### Primeira Semana
O foco foi na montagem do projeto, fazer a parte de interação com o sensor ultrassônico, estudar o processador que vamos utilizar e o método de transmissão de informação. 

Utilizaremos um aplicativo que funciona via bluetooth que imprime a parte de "monitor", mostrando, portanto, as distâncias calculadas pelo sensor.

### Segunda Semana
O trabalho vai ser voltado para a parte de captação e processamento de dados.

Ademais, foi incluído o código que será utilizado  no microcontrolador ESP32. Vale resslatar que não foi possível enviar a informação para o microcontrolador via app, devido ao alto grau de complexidade. Para resolver o problema, será utilizado um botão analógico ligado ao microcontrolador ESP32.

### Terceira Semana 
Na ultima semana os passos finais do projeto foram realizados. Com a montagem do projeto protoboard feita, o codigo foi rodado algumas vezes, realizando alguns testes com a trena:
- Teste 1: 
Para ver se de fato a trena funciona, foi escolhido um objeto, e foram retiradas varias medidas, aumentando a distância do objeto em relação ao sensor. Foram obtidas medidas diferetes, cada vez maiores. Isso mostrou que o código e a montagem estavam corretos, portanto a trena estava funcional.
- Teste 2:
O segundo teste foi realizado para analisar a precisão das medidas realizadas. Foi colocado um objeto à uma distancia conhecida (dimensões de uma caixa 13cmx9cm), e novamente foram tiradas varias medidas. Houve pequenas variações nas medidas em relação ao valor esperado.   

A partir dos resultados observados nos testes, foi concluído que o objetivo do projeto foi alcançado com sucesso 

