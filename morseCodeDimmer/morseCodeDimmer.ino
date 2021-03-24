/*
Copyright (c) 2021, Dylan Starink
All rights reserved.

This source code is licensed under the BSD-style license found in the
LICENSE file in the root directory of this source tree. 

*/

#define timeUnitMS 500
#define outputPin 2

/* Writing Morse Code Conventions

   . for dots
   - for Dahs
   Spaces between Letters
   | between words

*/
const String morseCode = ".--. --- --. ...";

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
