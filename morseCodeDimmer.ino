#define timeUnitMS 500
#define outputPin LED_BUILTIN


/* Writing Morse Code Conventions

   . for dots
   - for Dahs
   Spaces between Letters
   | between words

*/
const String morseCode = "... --- ...";

//Morse Code Timings

/*Between Times*/
#define betweenSymbolTime 1
#define betweenLetterTime 3
#define betweenWordTime 7
#define betweenRepeatTime 15


/*Symbol Times*/

#define ditTime 1
#define dahTime 3

/******************/

void setup() {
  pinMode(outputPin, OUTPUT);
}

void loop() {
  for (int i = 0; i < morseCode.length(); i++) {

    char charIndex = morseCode.charAt(i);

    //Check for Spaces
    if (charIndex == '|') {                 //Delay between Words
      delay(timeUnitMS * betweenWordTime);
      continue;
    } else if ( charIndex == ' ') {         //Delay between Letters
      delay(timeUnitMS * betweenLetterTime);
      continue;
    }

    digitalWrite(outputPin, HIGH);

    if (charIndex == '.') {                //Dit
      delay(timeUnitMS * ditTime);
    }
    else if ( charIndex == '-') {          //Dah
      delay( timeUnitMS * dahTime);
    }
    digitalWrite(outputPin, LOW);


    delay(timeUnitMS * betweenSymbolTime); //Delay between Symbols
  }

  delay(timeUnitMS * betweenRepeatTime);   //Time Between Repeats

}