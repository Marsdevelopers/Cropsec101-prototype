# Cropsec101-prototype
This contains prototype phase code base of hardware and software.
# Our Agro-Monitoring Rover MVP prototype

![photo_2024-07-30_10-03-30](https://github.com/user-attachments/assets/f6393191-7c1b-4f9d-b9de-083aa973085e)
![photo_2024-07-30_10-03-22](https://github.com/user-attachments/assets/026b65f6-f98a-4da5-a41b-47891821cd99)
![photo_2024-07-30_10-20-38](https://github.com/user-attachments/assets/b7c3b5f3-4fd5-42be-9c3b-318628329e7b)

Gooogle Drive Link: (https://drive.google.com/file/d/1clu-flHCxdKWIqSSvSEp7zsVxhTArVh0/view?usp=drivesdk)

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
4) Folders "templates","css" and "js" contains for frondend

   Data set used to train the model:(https://www.kaggle.com/datasets/rashikrahmanpritom/plant-disease-recognition-dataset)

# Architecture of the Rover
 ![508590_1_En_36_Fig2_HTML (1)](https://github.com/user-attachments/assets/6a20a2cb-6105-44f3-a674-0021a9aaa26a)

# Basic working diagram 

![applsci-12-03396-g007](https://github.com/user-attachments/assets/876ae808-48c1-43af-80b8-aa8771c60d3c)

# Future Implementations:
On the future updations we add different kinds of sensors to the rover such as
Humidity sensor,
Temparature sensor, 
Lidar,
UV sensor and
Soil NPK Sensor to get more data related to soil like its nitrogen and pottassium contents . Also we collect different
data regarding farms we analysis this data using different ml models . We will create a dedicate application that 
can sugggest what the farmer do for plant health as well as for maximum productivity.



# Sample video
https://github.com/user-attachments/assets/92622220-6efd-44ac-a240-37fa3be59e2d



