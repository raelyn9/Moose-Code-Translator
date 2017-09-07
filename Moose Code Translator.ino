#define led GREEN_LED
int dot=1000,dash=3000,btsignal=1000;
String input;
String morseCode[26]={".-" , "-..." ,"-.-.", "-..", "." , "..-.", "--." ,  "....", "..",".---", ".-.-",   ".-..",  "--",  "-.",  "---" , ".--." , "--.-", ".-." , "..." , "-" , "..-","...-" , ".--" , "-..-" , "-.--" , "--.."};
char letter[26]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};



void setup()
{
  Serial.begin(9600);
  pinMode(led,OUTPUT);
  digitalWrite(led,LOW);
}

void loop()
{
  if(Serial.available())
  {
     input=Serial.readString();
     input.toUpperCase();
     
     translateIntoMorse(input);
    
  }  
}

void translateIntoMorse(String input)
 {
  for(int i=0;i<input.length();i++)
  {
    
     for(int l=0;l<26;l++)
     {
      if (input[i]==letter[l])
        { 
            displayMorseLetter( morseCode[l]);          
        }      
     }
     if(input[i]==' ')
    {
      if(input[i+1]!=' ')
      {
        digitalWrite(led,LOW);
        delay(4000);
        
      }
    }
  }
 } 


void displayMorseLetter(String morse)
{
  for(int i=0;i<morse.length();i++)
  {
    char p=morse[i];
   
    if(p=='.')
    {
     displayDot();      
    }
    else if(p=='-')
    {
     displayDash();      
    }
  }
   delay(2000);
}

void displayDot()
{
      digitalWrite(led,HIGH);
      delay(dot);
      digitalWrite(led,LOW);
      delay(btsignal);
}

void displayDash()
{
      digitalWrite(led,HIGH);
      delay(dash);
      digitalWrite(led,LOW);
      delay(btsignal); 
}



