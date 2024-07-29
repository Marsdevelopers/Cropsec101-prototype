# Cropsec101-prototype
This contains prototype phase code base of hardware and software.

#Arduino:
This folder contains code for arduino and esp32 of the hardware section:

1) File "bluetooth_control.ino" contains code for controlling the rover using
   mobileapp and bluetooth module the app we are using is:(https://play.google.com/store/apps/details?id=com.abdert.selectorson&pcampaignid=web_share)
2) File "line_follower.ino" contains the code to move the rover in a specified path
3) The file "soil_Moisture_sensor.ino" and "wireless_setup_soilmoisture.ino" contains the code to fetch soil moisture information. wireless_setup_soilmoisture.ino use wifi and sent
   data to localserver or to the cloud using nodejs file called "serverside_code_formoisturesensor.js" at backend to receive data.
4) File "esp32cam.ino" contains the code to take images of the leaf this images is sent to a nodejs server in cloud containing a file "server_node.js"
   on this server we implement ml models for the plant disease predictions and we analyse the palnt health.

