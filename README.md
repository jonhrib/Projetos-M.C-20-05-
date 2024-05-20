# Projetos M.C 20-05 

Ao início da aula do dia 20-05, nos foi proposto a execução e análise de cinco projetos, sendo dois deles com Arduíno, e o restante com o Microcontrolador Esp32. Os projetos e suas descrições podem ser vistas a seguir:

# Projeto 1: Código Arduíno

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
