# Projetos M.C 20-05 

Ao início da aula do dia 20-05, nos foi proposto a execução e análise de quatro projetos, sendo dois deles com Arduíno, e o restante com o Microcontrolador Esp32. Os projetos e suas descrições podem ser vistas a seguir:

# Projeto 1: Código Arduino

    byte pin7 = 0;
    void setup() {
      pinMode (13, OUTPUT);
      pinMode (7, INPUT);
      Serial.begin(9600);
    }
    
    void loop() {
      digitalWrite (13, HIGH);
      delay (1000);
    
      digitalWrite (13, LOW);
      delay (1000);
    
      pin7 = digitalRead(7);
      Serial.println(pin7);
    }

+ Ao aplicar o código, vemos, no Serial Monitor, uma constante exibição de números zeros, isso ocorre pois o pin7 recebe 0 ao início do código, e, sem conexões de jumpers, esse valor não é alteradp.

# Projeto 2: Aplicação do Projeto 1

O mesmo código do Projeto 1 foi utilizado, no entanto, temos duas aplicações, ou configurações para realizar no microcontrolador, sejam elas:

    1. GND ligado na porta 7:
        + pudemos ver aqui, que o resultado exibido ainda é o mesmo, sempre o valor 0, pois, o gnd fornece a porta 7 o valor 0. A porta 7, por outro lado, fornece para o pin7 o valor recebido, 0;

    2. VCC (5V) ligado na porta 7:
        + pudemos, aqui, ver que o resultado foi modificado, agora exibindo o valor 1, pois o VCC fornece à porta 7 o valor 1, e, assim, pin7 também recebe 1;

    Basicamente podemos ver, nestes casos, que o pin7 reproduz o sinal que ele recebe pela porta 7 em byte, ou seja, se a porta 7 tiver um sinal 1, o pin7 terá sinal 1, e vice-versa.
    
+ Na mesma aplicação, pudemos ver que a porta 13 têm um sinal que fica sendo constantemente alternada dentro do loop principal, portanto, o sinal exibido por ela será sempre 0,1,0,1...

# Projeto 3: Touch no ESP32 

Neste projeto temos primeiramente o seguinte código que deve ser inserido na IDE Arduino:

    int LED_BUILTIN = 23;//Instancia a porta 23 como da variável LED_BuILTIN
    
    void setup() {
      pinMode(LED_BUILTIN, OUTPUT);//Define a variável LED_BuILTIN(porta 23) como uma saída de dados
      pinMode(T0, INPUT);//Define a porta T0(que no ESP32 é a D4) como uma entrada de dados
    }
    
    void loop() {
      if(touchRead(T0) < 20){//Caso a porta T0 leia algum toque, o LED irá acender. Caso contrário, o LED fica apagado
        digitalWrite(LED_BUILTIN, HIGH);//LED acende
      }else{
        digitalWrite(LED_BUILTIN, LOW);LED apaga
      }
      delay(100);//Delay de 100 milissegundos
    }

+ O presente circuito tem como principal função acender um LED caso uma porta esteja recebendo toques(touches), através da utilização de uma função chamada touchRead que verifica se a porta T0 está recebendo entradas de toque. Portanto, se a porta T0 estiver recebendo a entradas de toque, o LED acende. Caso contrário o LED não acende.

+ São usadas as portas 23 como saída de dados(LED), a porta T0(D4) como entra de dados e a porta GND como terra.


# Projeto 4: BlueThoth no ESP32

    #include <BluetoothSerial.h>
    
    BluetoothSerial SerialBT;
    
    void setup() {
      SerialBT.begin("ESP32 LED"); // Inicializa o Bluetooth com o nome "ESP32 LED"
      pinMode(2, OUTPUT); // Configura o pino 2 como saída
    }
    
    void loop() {
      if (SerialBT.available()) { // Verifica se há dados disponíveis para leitura no Bluetooth
        char c = SerialBT.read(); // Lê o caractere recebido
        if (c == '1') {
          digitalWrite(2, HIGH); // Liga o LED se o caractere recebido for '1'
          SerialBT.println("LED on"); // Envia a mensagem "LED on" via Bluetooth
        }
        if (c == '0') {
          digitalWrite(2, LOW); // Desliga o LED se o caractere recebido for '0'
          SerialBT.println("LED off"); // Envia a mensagem "LED off" via Bluetooth
        }
      }
      delay(20); // Pequeno atraso para evitar leitura excessiva
    }

+ No código mostrado a cima, a biblioteca <BluetoothSerial.h> permite que o ESP realize interações com um dispositivo celular por meio do aplicativo Serial Bluetooth Terminal (da Kai Morich), por meio dela podemos receber o valor c, como 0 ou 1. Utilizamos um led, ligado à porta 2, permitindo que visualizemos qual o sinal está sendo recebido por meio do bluetooth.

+ Se o valor recebido for 1, ligamos o led e exibimos uma mensagem no Terminal, já se o valor for 0, desligamos o led e exibimos essa mensagem no Terminal.

+ O que faz o led mudar de estado, principalmente, é o sinal enviado através do aplicativo, por exemplo, ao digitar 1 no app, o led será acesso, se 0 for digitado, o led será apagado.

*** Os presentes projetos foram desenvolvidos pelos discentes João Vitor de Souza Ribeiro e Vinicius Ferreira Couto, do 3º Ano do curso de Cência da Computação, da Universidade Estadual do Paraná (Unespar). ***

