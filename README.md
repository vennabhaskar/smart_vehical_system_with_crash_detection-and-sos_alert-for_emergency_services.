# smart_vehical_system_with_crash_detection-and-sos_alert-for_emergency_services.

## Inspiration : 
every day nearly 1 in 4 deaths in a city is due to accidents . Some of these causes are the difficulty to make the right decisions during an accident, and the ability to get help.

one year back, one of my friend was dead because of accident and due to not get on time emergency service , because he fell aside of the road and noone seen him and he can't make call for the emergency services. 

After seeing his death , we decided to create a device to help the people in those situations.

## What it does:
The divice insatlled in the vehical will detects the accidents or crash happened to the vehical ,if crash is detected it swithch on the buzzer and starts the timer for 15 seconds. we have given an option to stop the alert in the 20 seconds ,after the crash detected .Because if the person is safe and he is willing no need of ambulance ,then he can stop the alert with in the time . if the time ranout the alert will sent automatically with his geo location and makes a call to services , delivers the recorded messege with his location coordinates. the location is detected by the gps module. And msg ,call will send by gsm module .And also we have installed another feature to avoid accidents, that is avoiding triple riding . we installed a loadcell under seat ,if the load is more than 200kgs automatically the ignition will stop until the weight is decreased.

## Challenges we ran into :
Some challenges we faced were linking the geolocation data and sending alert call .And to get threshhold values to detect accident and calibaration.in the hardware installation process also.we have to make  sure the device should to fit in the vehical.

## What's next : 
- we are making to install the accident detection in the cars.
- we are testing and caliberating the values for detecting the crashes in the cars'
