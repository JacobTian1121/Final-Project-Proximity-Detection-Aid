# Proximity Detection Aid
This project is designed for VISUALLY IMPAIRED INDIVIDUALS to help them improve the quality for daily life. Since, they often experience difficulty detecting fixed obstructions or moving objects in their path and use original detection tool which cannot give them a clear detection feedback in the daily life. Therefore, this project can help them detect obstacle during walking and give them a clear feedback through using ultrasonic sensor and buzzer as alarm. 

## Modules
- alarm : Control the alarm state is ON or OFF to make sure the siren will sound or not.
- Distance : Measuring the distance and calculating average distance and relative strobetime for buzzer to sound.
- ldr_sensor : Detection the time is daytime or night time.
- siren : Making the buzzer sound or not within a frequency which is depended on the strobetime.
- Glasses_Detector : Initialization whole modules and make sure them update in every 60ms.

### Funtions

|Module|Name|Type|Purpose|
|------|-------|------|--------|
|alarm|alarmInit()|Public|Initialize the alarm state, siren and distance. |
|alarm|alarmUpdate()|Public|Identify if the distance from obstacle to user is in the detection range within different environment, and activate the buzzer to sound or not.|
|alarm|alarmStateRead()|Public|Getting the state of alarm.|
|alarm|alarmDeactivate()|Private|Deactivate the siren.|
|Distance|EchoFallCallback()|Private|Interrupting to calculate the EchoPulseTime when the falling edge of signal from ultrasonic sensor is received.|
|Distance|EchoRiseCallback()|Private|Interrupting to set up the echoTimer is 0 for calculating the EchoPulseTime.|
|Distance|timerCounter()|Public|Increment the echoTimer until the EchoFallCallback() funtion is called.|
|Distance|DistanceInit()|Public|Initialization callback functions and make sure the timerCounter is counted in every 10us.|
|Distance|DistanceUpdate()|Public|Send the triggle signal in every 10us.|
|Distance|DistanceRead()|Public| Calculating the EchoPulseTime into distance within centimeter unit.|
|Distance|StrobeTimeRead()|Public|Calculating the StrobeTime within rational range for buzzer to sound in different environment time.| 
|Distance|DistanceReadAVG()|Public|Calculating the distance in average to ensure the reaction will be more smoothly.|
|ldr_sensor|ldrSensorInit()|Public|Initialization the LDR sensor.|
|ldr_sensor|ldrSensorUpdate()|Public|Making the LDR sensor update.|
|ldr_sensor|ldrSensorRead()|Public|Getting the value of LDR sensor.|
|siren|sirenInit()|Public|Initialization the buzzer in actual frequency.|
|siren|sirenStateRead()|Public|Getting the state of siren.|
|siren|sirenStateWrite( bool state )|Public|Changing the state of siren.|
|siren|sirenUpdate( float StrobeTime )|Public|Updating the frequency of buzzer to sound within different proximity.|
|Glasses_Detector|GlassesDetectorInit()|Public|Initialization alarm, siren and distance module.|
|Glasses_Detector|GlassesDetectorUpdate()|Public|Updating the alarm, siren and distance module in every 60ms.|

#### Variable and Objects
|Module|Name|Type|Purpose|
|------|-------|------|--------|


