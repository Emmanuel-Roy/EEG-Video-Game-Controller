#include <Brain.h>
#include <Keyboard.h>

//Setup Brain Library
Brain brain(Serial1);

//Initilize the variables used in the Arousal-Valence calculations. Unfortunately, since the MindFlex Duel only has one sensor this calculation tends to be inaccurate.
unsigned long Theta;
unsigned long LAlpha;
unsigned long HAlpha;
unsigned long LBeta;
unsigned long HBeta;
float Arousal;
float Valence;
float Engagement;
String Emotion;
unsigned long myTime;

//Due to a lack of sensors this calculation will be extremely rough and quite inaccurate. However it should suffice for our controller.
int ArousalCalc(unsigned long LAlpha, unsigned long HAlpha, unsigned long LBeta, unsigned long HBeta) {
  float Arousal;
  //I'm uncertain whether I should average the L and H values for Alpha and Beta respectively. I tentatively have chosen not too.
  Arousal = (LAlpha + HAlpha)/(LBeta + HBeta);
  return Arousal;
}

int ValenceCalc(unsigned long HBeta, unsigned long LBeta) {
  //Valence is equal to HBeta minus LBeta
  float Valence;
  //It seems that the number overflows on occasion so make sure that the variable above is unsigned
  Valence = HBeta - LBeta;
  return Valence;
}

int EngagementCalc(unsigned long LAlpha, unsigned long HAlpha, unsigned long LBeta, unsigned long HBeta, unsigned long Theta) {
  float Engagement;
  //Engagement is equal to (((BetaL+BetaH)/2)/(Alpha+Theta))
  Engagement = ((LBeta + HBeta)/2)/((LAlpha + HAlpha)/2 + Theta);
}

String EmotionCalc(unsigned long Arousal,unsigned long Valence){
  //Variables
  String Emotion;
  bool HighArousal;
  bool PositiveValence;
  
  //These calcs probably aren't very accurate, needs more testing
  if (Arousal = 0) {
    HighArousal - false;
  } 
  else {
    HighArousal = true;
  }

  if (Valence > 0) {
    PositiveValence = true;
  }
  else {
    PositiveValence = false;
  }

  //Emotion Decider, this should be accurate according to the Arousal Valence Diagram.
  if (HighArousal == true && PositiveValence == true) {
    Emotion = "Enthusiastic";
  }
  if (HighArousal == true && PositiveValence == false) {
    Emotion = "Nervous";
  }
  if (HighArousal == false && PositiveValence == true) {
    Emotion = "Calm";
  }
  if (HighArousal == false && PositiveValence == false) {
    Emotion = "Disappointed";
  }

  return Emotion;
}

void setup() {
  //Setup Serial Connection
  Serial.begin(9600);
  Serial1.begin(9600);
  //Setup Keyboard Control
  Keyboard.begin();
}

void loop() {
  if (brain.update()) {
    //Make sure that the headset is actually on.
    if(brain.readSignalQuality() != 200) {
      //Read in our Brain Band Values
      Theta = brain.readTheta();
      LAlpha = brain.readLowAlpha();
      HAlpha = brain.readHighAlpha();
      LBeta = brain.readLowBeta();
      HBeta = brain.readHighBeta();
      myTime = millis();
    
      //Calculate all the remaining values
      Arousal = ArousalCalc(LAlpha, HAlpha,LBeta, HBeta);
      Valence = ValenceCalc(HBeta, LBeta);
      Engagement = EngagementCalc(LAlpha, HAlpha, LBeta, HBeta, Theta);
      Emotion = EmotionCalc(Arousal, Valence);

      //Print Out the Arousal, Valence, and Engagement values for debugging purposes
      Serial.println(brain.readCSV());
      Serial.println(Arousal);
      Serial.println(Valence);
      Serial.println(Engagement);
      Serial.println(myTime);
    
      //Here is where controller calculations come into play, change them as wanted. Testing this out for geometry dash this works.
      //if (Emotion == "Enthusiastic") {
        //Keyboard.press(KEY_UP_ARROW);
      //}
    }
  }

}
