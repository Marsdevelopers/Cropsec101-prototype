# Cropsec101-prototype
This contains prototype phase code base of hardware and software.

# Arduino:
This folder contains code for arduino and esp32 of the hardware section:

1) File "bluetooth_control.ino" contains code for controlling the rover using
   mobileapp and bluetooth module the app we are using is:(https://play.google.com/store/apps/details?id=com.abdert.selectorson&pcampaignid=web_share)
2) File "line_follower.ino" contains the code to move the rover in a specified path
3) The file "soil_Moisture_sensor.ino" and "wireless_setup_soilmoisture.ino" contains the code to fetch soil moisture information. wireless_setup_soilmoisture.ino use wifi and sent
   data to localserver or to the cloud using nodejs file called "serverside_code_formoisturesensor.js" at backend to receive data.
4) File "esp32cam.ino" contains the code to take images of the leaf this images is sent to a nodejs server in cloud containing a file "server_node.js"
   on this server we implement ml models for the plant disease predictions and we analyse the palnt health.

# ML_model_ :
This folder contains machine learning models for predicting plants diseases by analysing plant leaf image :

1) "Model_Training.ipynb" is the model trained in our system it contains python code to predict the disease.
2) "notebook87349e5dic.ipynb" is the jupyter notebook  contains python code to predict the disease trained in Kaggle.
3) "app.py" is the file used to host the tarined model to predict diseases this cointains python code to deployment(Flask framework is used as backend)
4) Folders "templates","css" aand "js" contains for frondend

# Diagram of the Rover
   ![applsci-12-03396-g007](https://github.com/user-attachments/assets/2c07e097-b2ec-42ab-b65b-0c3f9c1e240f)
