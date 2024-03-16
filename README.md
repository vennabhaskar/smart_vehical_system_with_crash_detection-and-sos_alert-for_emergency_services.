# smart_vehical_system_with_crash_detection-and-sos_alert-for_emergency_services.

## Team Details

`Team number` : VH131

| Name                   | Email                          |
|------------------------|--------------------------------|
| venna bhaskarreddy     | vennabhaskarreddybro@gmail.com |
| pechetti prem narasimha| 9921030012@klu.ac.in           |
| shaik vazid            | 9921030006@klu.ac.in           |
| amarnath pandit        | 9921030016@klu.ac.in           |

## Problem statement 
vehical crashes or accidents deaths due to late or delay in the coummunication with the emergency ambulance services , all people in the world who is driving the vehicals will come under this problem statement.

## Inspiration : 
every day nearly 1 in 4 deaths in a city is due to accidents . Some of these causes are the difficulty to make the right decisions during an accident, and the ability to get help.

one year back, one of my friend was dead because of accident and due to delay in getting  emergency service , because he fell aside of the road and no one seen him and he can't make call for the emergency services.

After seeing his death , we decided to create a device to help the people in those situations.

## About the project
The device insatlled in the vehical will detects the accidents or crash happened to the vehical ,if crash is detected it swithch on the buzzer and starts the timer for 15 seconds. we have given an option to stop the alert in the 20 seconds ,after the crash detected .Because if the person is safe and he is willing no need of ambulance ,then he can stop the alert with in the time . if the time ranout the alert will sent automatically with his geo location and makes a call to services , delivers the recorded messege with his location coordinates. the location is detected by the gps module. And msg ,call will send by gsm module.

## What it does:
The device insatlled in the vehical will detects the accidents or crash happened to the vehical ,if crash is detected it swithch on the buzzer and starts the timer for 15 seconds. we have given an option to stop the alert in the 20 seconds ,after the crash detected .Because if the person is safe and he is willing no need of ambulance ,then he can stop the alert with in the time . if the time ranout the alert will sent automatically with his geo location and makes a call to services , delivers the recorded messege with his location coordinates. the location is detected by the gps module. And msg ,call will send by gsm module .And also we have installed another feature to avoid accidents, that is avoiding triple riding . we installed a loadcell under seat ,if the load is more than 200kgs automatically the ignition will stop until the weight is decreased.

## Technical implemntaion 
- sensors like accelerometer and vidration detection sensors used to detecting the crash.
- loadcell was used to detect the weight for the safety.
- gps module for the getting geo location.
![flow chart for load detection](https://github.com/vennabhaskar/smart_vehical_system_with_crash_detection-and-sos_alert-for_emergency_services./assets/163627309/8444b01e-3b7c-4dc2-8fac-1c6a361500eb)
![flow chart for crash detection](https://github.com/vennabhaskar/smart_vehical_system_with_crash_detection-and-sos_alert-for_emergency_services./assets/163627309/c841dac6-a889-4431-9581-c2ec46ef0659)

## Techstacks used 
`c language` , `Aurdunio Ide` , `loadcell` , `gsm module` , `ADXL335`

## How to run locally 

```
- step 1 : install the libraries in ardunio ide and enter the code
- step 2 : Upload the code into the ardunio uno board
- step 3 : make the circuit according to the circuit diagram.
```

## Challenges we ran into :
Some challenges we faced were linking the geolocation data and sending alert call .And to get threshhold values to detect accident and calibaration.in the hardware installation process also.we have to make  sure the device should to fit in the vehical.

## What's next ?: 
- we are palnning to install the accident detection in the cars.
- we are testing and caliberating the values for detecting the crashes in the cars'
- In future we are going to develop the device with more efficiently detecting the crashes and improve  other safety features in both cars and bikes.
- In future we are palnning to collect heartbeat and pulse rate of the person who is driving  vehical ,for better detection of crash and further patient 
  seviarity will be know by the ambulance service.

## Declaration
We confirm that the project showcased here was either developed entirely during the hackathon or underwent significant updates within the hackathon timeframe. We understand that if any plagiarism from online sources is detected, our project will be disqualified, and our participation in the hackathon will be revoked.



