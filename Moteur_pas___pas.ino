/*on fait appel à la bibliothèque Stepper*/
#include <Stepper.h>

const int nbrpas = 32*64; /*Nous permet d'avoir une vitesse compris entre 0 et 10*/
int potentiometre = 0;

/*(step, 1N2, 1N4, 1N3, 1N1)*/
Stepper monMoteur1(nbrpas, 9, 11, 10, 8);
Stepper monMoteur2(nbrpas, 3, 5, 4, 2);
Stepper monMoteur3(nbrpas, 17, 15,16 ,14);

void setup() {
  Serial.begin(9600);
}

void loop() {
  /*Dans un premier temps on va lire la valeur du potentiomètre (il permet de faire varier le vitesse)*/
  int valPotentiometre = analogRead(potentiometre);
  Serial.println(valPotentiometre);

  /*on convertit la valeur du potentiomètre (entre 0 et 1023) en une valeur allant de 0 à 10 (nos vitesses possibles.*/
  int vitesseMoteur = map(valPotentiometre, 0, 1023, 0, 10);

  if (vitesseMoteur> 0){
    monMoteur1.setSpeed(vitesseMoteur);
    monMoteur2.setSpeed(vitesseMoteur);
    monMoteur3.setSpeed(vitesseMoteur);
    
    Serial.print("vitesse:");
    Serial.println(vitesseMoteur);

    //On vient alors faire un tour puis un tour en sens inverse

    monMoteur1.step(2048);
    monMoteur2.step(-2048);
    monMoteur3.step(2048);
    
    delay(100);
    
    monMoteur1.step(-2048);
    monMoteur2.step(2048);
    monMoteur3.step(2048);
    
    delay(100);
  }

}
