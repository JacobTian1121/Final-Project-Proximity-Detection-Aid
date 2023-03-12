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
|Distance|
