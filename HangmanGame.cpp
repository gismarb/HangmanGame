#include <iostream>
#include <stdlib.h>
#include <string>

#define MAX_WORD_SIZE 100

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::getline;

void gameTitle();
void missed(int opt);


int main() {
  char word[MAX_WORD_SIZE];
  char secretWord[MAX_WORD_SIZE];
  char letter[0];
  string question;

  int size;
  int index;
  int life;
  int correct;

  bool right;

  life = 6;
  size = 0;
  index = 0;
  correct = 0;
  right = false;

  system("clear");
  
  gameTitle();

  cout << endl << "Digite uma pergunta para iniciar o Jogo: ";
  // Exemplos:
    // 1 - De onde os Indios retiram seu sustento (alimentos):
    // Resposta: Natureza
    // 
    // 2 - Nas aldeias Indigenas, quem e o lider religioso: 
    // Resposta: Paje
    // 
    // 3 - Segunda dados de 2006 (Funasa), com uma populcao 46.566, estão os Indios: 
    // Resposta: Guaranis
  getline(cin, question);
  //cin.ignore();

  cout << endl << "Digite a Resposta: ";
  cin >> word;
  system("clear");

  while (word[index] != '\0') {
    index++;
    size++;
  }
  
  for (index = 0; index < MAX_WORD_SIZE; index++) {
    secretWord[index] = '-';
  }

  while ((life > 0) && (correct < size)) { 
    gameTitle();

    missed(life);
    
    cout << endl << question << endl;
    cout << endl << "Chances Restantes: " << life << endl << endl;
    cout << "Palavra Secreta: ";

    for (index = 0; index < size; index++)
    cout << secretWord[index];

    cout << endl << endl << "Digite uma letra: ";
    cin >> letter[0];

    for (index = 0; index < size; index++){
      if (word[index] == letter[0]) {
        right = true;
        secretWord[index] = word[index];
        correct++;
      }
    }

    if (!right)
    life--;

    right = false;
    system("clear");
  }

  gameTitle();

  if (correct == size)
    cout << endl << "OK! Você Acertou!" << endl;

  else
    cout << endl << "NOK! Você Errou!" << endl << endl;

  getchar();

  return 0;
}

void gameTitle() {
  cout << endl << "Jogo da Forca (Atividade 5 RERCAB)" << endl;
  cout << "Jogo Educativo (Siga as Instrucoes)" << endl << endl;
}

void missed(int opt) {
  if (opt == 6) {
    cout << endl << " \xe2\x98\xb9" << endl;
    cout << "|()|" << endl;
    cout << " ||" << endl;
  } 
  
  if (opt == 5) {
    cout << endl << " \xe2\x98\xb9" << endl;
    cout << "|()|" << endl;
    cout << " |" << endl;
  } 
  
  if (opt == 4) {
    cout << endl << " \xe2\x98\xb9" << endl;
    cout << "|()|" << endl;
    cout << " " << endl;
  } 

  if (opt == 3) {
    cout << endl << " \xe2\x98\xb9" << endl;
    cout << "|()" << endl;
    cout << " " << endl;
  } 

  if (opt == 2) {
    cout << endl << "\xe2\x98\xb9" << endl;
    cout << "()" << endl;
    cout << " " << endl;
  } 

  if (opt == 1) {
    cout << endl << "\xe2\x98\xb9" << endl;
    cout << " " << endl;
    cout << " " << endl;
  } 
}