#include <Ethernet.h>
#include <EthernetUdp.h>

byte mac[] = {
  0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED
};
IPAddress ip(192, 168, 1, 200);
byte contador = 0; // Dato que se envía

// IP donde se encuentra el servidor
const char * udpAddress = "192.168.1.103";
// Puerto donde se reciben los datos
const int udpPort = 30000;
EthernetUDP Udp;

void setup() {
   Ethernet.begin(mac, ip);
  Serial.begin(9600);
  while (!Serial) {
    ;
  }

  if (Ethernet.hardwareStatus() == EthernetNoHardware) {
    Serial.println(F("ERROR en la placa Ethernet("));
    while (true) {
      delay(1); 
    }
  }
  if (Ethernet.linkStatus() == LinkOFF) {
    Serial.println(F("El cable de rer no esta conectado."));
  }
  Udp.begin(udpPort);
}

void loop() {
  
  Udp.beginPacket(udpAddress, udpPort);
  Udp.print(contador); // Envía el contador
  Udp.endPacket(); // Fin de transacción
  
 // Espera un segundo e incrementa contador
  delay(1000);
  contador++;
  }
