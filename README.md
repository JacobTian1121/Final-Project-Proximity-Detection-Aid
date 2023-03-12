# Proximity Detection Aid
- Jiayu Tian && Sandeep Alampalli
- Date 3/12/2023
- This project is designed for VISUALLY IMPAIRED INDIVIDUALS to help them improve the quality for daily life. Since, they often experience difficulty detecting fixed obstructions or moving objects in their path and use original detection tool which cannot give them a clear detection feedback in the daily life. Therefore, this project can help them detect obstacle during walking and give them a clear feedback through using ultrasonic sensor and buzzer as alarm. 

## Modules
- alarm : Control the alarm state is ON or OFF to make sure the siren will sound or not. (code is from scratch)
- Distance : Measuring the distance and calculating average distance and relative strobetime for buzzer to sound. (code is from online)
- ldr_sensor : Detection the time is daytime or night time. (code is from textbookcode)
- siren : Making the buzzer sound or not within a frequency which is depended on the strobetime. (code is from textbookcode)
- Glasses_Detector : Initialization whole modules and make sure them update in every 60ms. (code is from scratch)

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

#### Defines/Variables/Objects
|Module|Name|Type|Purpose|
|------|-------|------|--------|
|distance|SYSTEM_TIME_INCREMENT_MS|define|The time for system to delay, which means update.|
|distance|distanceMaxSample|define|Setting up the maxmimum sample for array to calculate is 10.|
|distance|stopWatch|Ticker|Setting up the ticker.|
|distance|Echo(PF_13)|InterruptIn|Setting up the input signal for interrupt.|
|distance|trig(PF_14)|DigitalOut|Setting up the digital out pin for trigger.|
|distance|Echodistance|float|The distance detected from ultrasonic sensor in centimeter.|
|distance|EchodistanceArray[distanceMaxSample]|float|The array for record 10 groups distance to calculate the average distance.|
|distance|StrobeTime|float|The time for buzzer to sound.|
|distance|echoTimer|integer|The value of echo time.|
|distance|EchoPulseTime|integer|The value of echo pulse time.|
|distance|distanceSampleIndex|integer|The value of EchodistanceArray to indicate the position.|
|distance|distanceReadSum|float|The value of 10 groups distance sum.|
|distance|distanceAverage|float|The value of average distance.|
|distance|i|integer|The value of array to indicate the current position in increment.|
|ldr_sensor|ldr(A2)|AnalogIn|The analog signal input pin.|
|siren|sirenPin(PC_9_ALT0)|PWMOut|The pin of PWN for siren.|
|siren|sirenState|Boolean variable|The state of siren.|
|siren|currentStrobeTime|integer|The current strobe time.|

##### Hardware
|Module|Name|Pins|
|------|-------|------|
|distance|Ultrasonic sensor|Echo PF_13|
|distance|Ultrasonic sensor|Trig PF_14|
|distance|Ultrasonic sensor|GND|
|distance|Ultrasonic sensor|Vcc 3.3V|
|ldr_sensor|LDR sensor|A2|
|ldr_sensor|LDR sensor|GND|
|ldr_sensor|LDR sensor|Vcc 3.3V|
|siren|siren|PC_9|
|siren|siren|Vcc 3.3V|

###### Test Explaination
- The ultrasonic sensor works correctly and the data has a linear relationship with buzzer to sound.
- Testing the ultrasonic sensor close to the obstacle less than 10cm or faraway from 4m or 3m. 
- The buzzer works correctly and the frequency is linear proportional to the distance from ultrasonic sensor.
- Testing if the buzzer sound within different frequency or not through moving the ultrasonic sensor.
- Testing if the buzzer will stop sound when the buzzer get so closed less than 10cm or faraway than 4m. 
- The LDR sensor works perfectly and it can identify the environment to system to work.
- Testing if the buzzer will suddenly sound into different environment.





