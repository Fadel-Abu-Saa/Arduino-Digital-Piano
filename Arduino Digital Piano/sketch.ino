
const int buzzer = 3;

const int buttons [8] = {4, 5, 6, 7, 8, 9, 10, 11};

const int buttonUp = 12;

const int buttonDown = 13;

const int buttonScale = 2;

int notes [3] [8] = 
{

   {262, 294, 330, 349, 392, 440, 494, 523},

   {262, 277, 311, 349, 392, 415, 466, 523},

   {262, 311, 349, 370, 392, 466, 523, 587}

};

int currentScale = 0;

float multiplier = 1.0;

bool lastUpState = HIGH;

bool lastDownState = HIGH;

bool lastScaleState = HIGH;

void setup() {

Serial.begin(9600);
  
for (int i = 0; i < 8; i++)

{

pinMode(buttons[i], INPUT_PULLUP);

}

pinMode(buttonUp, INPUT_PULLUP);

pinMode(buttonDown, INPUT_PULLUP);

pinMode(buttonScale, INPUT_PULLUP);

pinMode(buzzer, OUTPUT);

}

void loop() {

  bool scaleState = digitalRead(buttonScale);

  if (scaleState == LOW && lastScaleState == HIGH) 
  
  {

    currentScale++;

    if (currentScale > 2) 
    
    {

      currentScale = 0;
    
    }

    Serial.print("Scale changed to: ");
    
    Serial.println(currentScale);

    delay(200);

  }

  lastScaleState = scaleState;
  
bool upState = digitalRead(buttonUp);

if (upState == LOW && lastUpState == HIGH)

{

  multiplier *= 2.0;

  if (multiplier > 4.0)

  multiplier = 4.0;
  
  delay(200);

}

lastUpState = upState;

bool downState = digitalRead(buttonDown);

if (downState == LOW && lastDownState == HIGH)

{
  
  multiplier /= 2.0;

  if (multiplier < 0.25)

  multiplier = 0.25;

  delay(200);

}

lastDownState = downState;

bool playing = false;

for (int i = 0; i < 8; i++)

{

  if (digitalRead(buttons[i]) == LOW)

{

int currentNote = notes[currentScale][i] * multiplier;

tone(buzzer, currentNote);

playing = true;

break;

}

}

if (!playing)

{

noTone(buzzer);

}

}
