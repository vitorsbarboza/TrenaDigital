# TrenaDigital
Este repositório contém o projeto do Gruopo E para a disciplina de "Microcontroladores e Microprocessadores".

## Proposta

O projeto consiste em utilizar um microcontrolador Arduino para a leitura da distância de um objeto e enviar essa informação para um smartphone. Para iniciar o projeto, é necessário ter em mãos um Arduino, o qual o tipo ainda será discutido, e um sensor ultrassônico. A partir disso, iremos desenvolver uma forma de transmissão dos dados para o smartphone seja por Bluetooth ou por aplicativo. 

## Plano de ação

  1. Escrever o programa para arduíno que controle o sensor e que tire as infomações das distâncias
  2. Encontrar uma forma de mandar as informações do microprocessador para o celular (sugestão do professor: usar um cabo de ethernet no arduíno para gerar um servidor)
  3. Aplicativo ou site que de controle ao usuário e que mostre a medida desejada.
  4. Utilizar comunicação assíncrona com mqtt ou síncrona com bluetooth 

## Componentes
O grupo irá utilizar a placa ESP32 (board) e um sensor ultrassônico HC-SR04. Para a programaçao da placa será utilizada a plataformIO através do VS code.
