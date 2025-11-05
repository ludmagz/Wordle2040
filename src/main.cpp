#include <Adafruit_GFX.h>
#include <Adafruit_ILI9341.h>

// Defina os pinos do Raspberry Pi Pico para o display
#define TFT_CS    5  // Chip Select
#define TFT_RST   17  // Reset
#define TFT_DC    16
#define TFT_MOSI  11
#define TFT_SCK   2
// Data/Command

// Crie um objeto Adafruit_ILI9341
Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC, TFT_MOSI, TFT_SCK, TFT_RST);

void setup() {
  Serial.begin(115200);

  // Inicializa o display
  tft.begin();
  tft.setRotation(2);  // Ajuste a rotação do display, dependendo da sua preferência
  tft.fillScreen(ILI9341_BLACK);  // Preenche o fundo com a cor preta

  // Defina as propriedades de texto
  tft.setTextColor(ILI9341_WHITE);
  tft.setTextSize(3);
  tft.setCursor(25, 40);
  tft.println("WORDLE 2040");  // Texto de teste

  tft.drawRect(10, 140, 40, 40, ILI9341_WHITE);
  tft.drawRect(55, 140, 40, 40, ILI9341_WHITE);
  tft.drawRect(100, 140, 40, 40, ILI9341_WHITE);
  tft.drawRect(145, 140, 40, 40, ILI9341_WHITE);
  tft.drawRect(190, 140, 40, 40, ILI9341_WHITE);
}

void loop() {
  // Você pode adicionar código adicional aqui


}