#include <Arduino.h>

#include <EEPROM.h>

#define EEPROM_SIZE 1200 // 4KB EEPROM size for ESP8266

int address =  0; // Starting address of the Writing data
int add1 = 0;



char str[1200] = "Finance Minister Arun Jaitley Tuesday hit out at former RBI governor Raghuram Rajan for predicting that the next banking crisis would be triggered by MSME lending, saying postmortem is easier than taking action when it was required. Rajan, who had as the chief economist at IMF warned of impending financial crisis of 2008, in a note to a parliamentary committee warned against ambitious credit targets and loan waivers, saying that they could be the sources of next banking crisis.";

long int len = strlen(str);

void setup() {
  ESP.wdtDisable();
  Serial.begin(2400);
  EEPROM.begin(EEPROM_SIZE);

  // Write data to EEPROM
  for (int i = 0; i < len; i++) {
    EEPROM.write(address + i, str[i]);
  }
  EEPROM.commit();

  // Read and print data from EEPROM
  for (int i = 0; i < len ; i++) {
    char a = EEPROM.read(address + i);
    Serial.print(a);
  }
}



void loop() {

  

}
