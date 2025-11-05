#include <Adafruit_GFX.h>
#include <Adafruit_ILI9341.h>

// Defina os pinos do Raspberry Pi Pico para o display
#define TFT_CS    5  // Chip Select
#define TFT_RST   17  // Reset
#define TFT_DC    16
#define TFT_MOSI  11
#define TFT_SCK   2

enum class GameState : uint8_t { 
  MENU, 
  PLAY, 
  END, 
  NONE 
};

// Data/Command
GameState game_state = GameState::NONE;

// Crie um objeto Adafruit_ILI9341
Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC, TFT_MOSI, TFT_SCK, TFT_RST);

void draw_menu_principal () {

  // Defina as propriedades de texto
  tft.setTextColor(ILI9341_WHITE);

  tft.setTextSize(3);
  tft.setCursor(25, 40);
  tft.println("WORDLE 2040");  

  tft.setTextSize(2);
  tft.setCursor(25, 85);
  tft.println("START para jogar");

  // desenha 5 quadrados
  for (int j = 0; j < 5; j++){
      tft.drawRect((10 + (45 * j)), 140, 40, 40, ILI9341_WHITE);
    }

  tft.setTextSize(1);
  tft.setCursor(67, 300);
  tft.println("marsales & ludmagz");

}

void draw_tela_game () {

  // Defina as propriedades de texto
  tft.setTextColor(ILI9341_WHITE);

  // desenho de todos os 30 quadrados
  for (int i = 0; i < 6; i++){
    for (int j = 0; j < 5; j++){
      tft.drawRect((10 + (45 * j)), (5 + (45 * i)), 40, 40, ILI9341_WHITE);
    }
  }

  tft.setTextSize(1);
  tft.setCursor(67, 300);
  tft.println("marsales & ludmagz");

}

void draw_menu_end (bool win) {

  // Defina as propriedades de texto
  tft.setTextColor(ILI9341_WHITE);

  tft.setTextSize(3);
  tft.setCursor(53, 35);
  tft.println(win ? "VITORIA!" : "DERROTA!");  

  tft.setTextSize(2);
  tft.setCursor(34, 85);
  tft.println("PLAY para jogar");
  tft.setCursor(38, 110);
  tft.println("MENU para sair");

  for (int j = 0; j < 4; j++){
    tft.drawRect((33 + (45 * j)), 160, 40, 40, ILI9341_WHITE);
  }

  tft.setTextSize(1);
  tft.setCursor(67, 300);
  tft.println("marsales & ludmagz");

}

void setup() {
  Serial.begin(115200);

  // Inicializa o display
  tft.begin();
  tft.setRotation(2);  // Ajuste a rotação do display, dependendo da sua preferência
}

// dentro dos cases do loop, chamamos as funções lógicas a serem implementadas
void loop() {
  
  switch (game_state){

  case GameState::MENU:
    char str[5]; //TODO: Uma struct com as variáveis globais do jogo

    if(str == "START"){
      tft.fillScreen(ILI9341_BLACK);
      draw_tela_game();
      game_state = GameState::PLAY;
    }
    
    break;
  

  case GameState::PLAY:
    bool end, victory;

    if(end){
      tft.fillScreen(ILI9341_BLACK);
      draw_menu_end(victory);
    }

    break;


  case GameState::END:

    char mode[5]; //TODO: Uma struct com as variáveis globais do jogo

    if(mode == "MENU"){
      tft.fillScreen(ILI9341_BLACK);
      draw_menu_principal();
      game_state = GameState::MENU;
    }
    else if(mode == "PLAY"){
      tft.fillScreen(ILI9341_BLACK);
      draw_tela_game();
      game_state = GameState::PLAY;
    }

    break;

  case GameState::NONE:
    tft.fillScreen(ILI9341_BLACK);  // Preenche o fundo com a cor preta
    draw_menu_principal();
    game_state = GameState::MENU;
    break;

  default:
    //adicionar algo para reportar erro
    game_state = GameState::NONE;
    break;
  }

}