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

Ao aplicar o código, vemos, no Serial Monitor, uma constante exibição de números zeros, isso ocorre pois o pin7 recebe 0 ao início do código, e, sem conexões de jumpers, esse valor não é alteradp.

# Projeto 2: Aplicação do Projeto 1

O mesmo código do Projeto 1 foi utilizado, no entanto, temos duas aplicações, ou configurações para realizar no microcontrolador, sejam elas:

    1. GND ligado na porta 7:
        + pudemos ver aqui, que o resultado exibido ainda é o mesmo, sempre o valor 0, pois, o gnd fornece a porta 7 o valor 0. A porta 7, por outro lado, fornece para o pin7 o valor recebido, 0;

    2. VCC (5V) ligado na porta 7:
        + pudemos, aqui, ver que o resultado foi modificado, agora exibindo o valor 1, pois o VCC fornece à porta 7 o valor 1, e, assim, pin7 também recebe 1;

    Basicamente podemos ver, nestes casos, que o pin7 reproduz o sinal que ele recebe pela porta 7 em byte, ou seja, se a porta 7 tiver um sinal 1, o pin7 terá sinal 1, e vice-versa.
    
Na mesma aplicação, pudemos ver que a porta 13 têm um sinal que fica sendo constantemente alternada dentro do loop principal, portanto, o sinal exibido por ela será sempre 0,1,0,1...

# Projeto 3: 
