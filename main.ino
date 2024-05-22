const int Trigger = 3;   //Pin digital 2 para el Trigger del sensor
const int Echo = 2;   //Pin digital 3 para el Echo del sensor
const int ZumbadorPin = 6; //Pin ZumbadorPin

int c=261; 
int d=294;
int e=329;
int f=349;
int g=391;
int gS=415;
int a=440;
int aS=455;
int b=466;
int cH=523;
int cSH=554;
int dH=587;
int dSH=622;
int eH=659;
int fH=698;
int fSH=740;
int gH=783;
int gSH=830;
int aH=880;
 

float t = 0; //timepo que demora en llegar el eco
float distancia = 0; //distancia en centimetros
bool init_val = 0;

float distancia_anterior = 0;
float delta_var = 2, var = 0;

void setup() {
  Serial.begin(9600);//iniciailzamos la comunicación
  pinMode(Trigger, OUTPUT); //pin como salida
  pinMode(ZumbadorPin, OUTPUT); //pin como salida
  pinMode(Echo, INPUT);  //pin como entrada
  digitalWrite(Trigger, LOW);//Inicializamos el pin con 0
  digitalWrite(ZumbadorPin, LOW);//Inicializamos el pin con 0
}
 
 
void loop()
{
 
  digitalWrite(Trigger, HIGH);
  delayMicroseconds(10);          //Enviamos un pulso de 10us
  digitalWrite(Trigger, LOW);
  
  t = pulseIn(Echo, HIGH); //obtenemos el ancho del pulso
  distancia = t/59;             //escalamos el tiempo a una distancia en cm
  var = distancia-distancia_anterior;
  if (var > 0 && var*var >= delta_var){
    Serial.println("Se esta alejando");
    //tone(ZumbadorPin, 1000);
    //delay(1000);
    //noTone(ZumbadorPin);
    StarWars();
    delay(500);

  }

  distancia_anterior = distancia;
  init_val = true;
  delay(100);          //Hacemos una pausa de 100ms
}


void StarWars(void){
  tone(ZumbadorPin, a, 500);
    delay(500+50);
    tone(ZumbadorPin, a, 500);
    delay(500+50);     
    tone(ZumbadorPin, a, 500); 
    delay(500+50);
    tone(ZumbadorPin, f, 350);  
    delay(350+50);
    tone(ZumbadorPin, cH, 150);
    delay(150+50); 
    
    tone(ZumbadorPin, a, 500);
    delay(500+50);
    tone(ZumbadorPin, f, 350);
    delay(350+50);
    tone(ZumbadorPin, cH, 150);
    delay(150+50);
    tone(ZumbadorPin, a, 1000);   
    delay(1000+50);
    
}
