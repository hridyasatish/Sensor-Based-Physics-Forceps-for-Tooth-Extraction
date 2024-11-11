# Sensor-Based Physics Forceps for Tooth Extraction

## Abstract
Tooth extractions, though routine, can be challenging procedures that require careful application of force to avoid injury to surrounding tissues. This project introduces an innovative **sensor-based physics forceps system** designed to enhance the safety, precision, and comfort of tooth extractions. By integrating **Force Sensing Resistors (FSR)** and an **MPU6050 sensor** with a wearable wristband, this system monitors the pressure applied during the procedure, as well as detects **rocking** and **twisting movements**. The system alerts the dentist in real-time via a buzzer if the applied force exceeds safe limits, thus minimizing the risk of injury and improving the overall extraction process. The data is displayed through the **Blynk mobile app**, providing valuable feedback to the dental practitioner.

## Introduction
Tooth extraction is a delicate procedure that demands high precision to avoid damage to the surrounding bone and soft tissue. Traditional forceps rely on the dentist’s skill to apply the right amount of pressure, but these methods lack a reliable feedback system to ensure optimal force application. This project seeks to solve that problem by introducing a **sensor-based system** that continuously monitors the **force**, **rocking**, and **twisting movements** during the extraction. The system leverages **Force Sensing Resistors (FSR)** to measure the force exerted and an **MPU6050** sensor for detecting angular movements, providing real-time feedback to the dentist via a **wearable wristband**. This ensures more controlled and safe extractions, especially in challenging cases or for patients of different age groups.

## Methodology

### 1. **Design of Physics Forceps with FSR**
The **Force Sensing Resistor (FSR)** is a critical component of this system. It acts as a variable resistor whose resistance changes according to the amount of pressure applied. As force is exerted during tooth extraction, the FSR's resistance decreases, and this change is used to calculate the applied force. The FSR is integrated into a **voltage divider circuit** along with a fixed 10k resistor, allowing the **Arduino** microcontroller to read the changing resistance. This resistance is then converted to force data, which is essential for ensuring that the correct amount of pressure is applied during the extraction. The system also includes a **buzzer** to alert the dentist if the applied force exceeds a predefined threshold, which is customized based on the age and condition of the patient’s teeth.

### 2. **Interfacing MPU6050 with ESP32 for Rocking and Twisting Movements**
The **MPU6050** sensor is a **6-axis accelerometer** and **gyroscope** that provides data on both **acceleration** and **angular velocity**. The sensor is used to detect **rocking** and **twisting movements** made during tooth extraction. The **ESP32** microcontroller interfaces with the MPU6050 using the **I2C protocol** to read the sensor’s raw data. The data is processed to calculate the **roll** (rocking) and **pitch** (twisting) angles, which are crucial for monitoring the movements during extraction. The **Blynk mobile app** is used to display the real-time angles of the extraction forceps, giving the dentist immediate feedback on the procedure. This integration of motion sensing helps ensure that excessive twisting or rocking does not occur, minimizing the risk of damaging the tooth or surrounding tissue.

## Results and Discussions

### 1. **Force Detection Results**
The system successfully calculates the applied force during tooth extraction by taking into account age-specific limits for force application. The force is displayed on the **Blynk app**, and a **buzzer** alerts the dentist if the force exceeds a safe threshold. The system ensures that force is controlled and applied appropriately, reducing the risk of complications during the extraction. For various age groups, force limitations are adjusted, and the system offers a safer, more controlled method for tooth extractions.

### 2. **Rocking and Twisting Movements**
The system tracks and displays the **rocking** and **twisting movements** during extraction, helping to ensure that the forceps are used correctly. The data, including time-stamped measurements, is shown in the **Blynk app**, allowing the dentist to make real-time adjustments. This feature is critical in preventing unnecessary force and movement that could lead to complications or prolonged extraction times. The accuracy and consistency of the recorded movements allow for more precise extractions.

### 3. **Wearable Wristband for Angle Detection**
A prototype **wearable wristband** was developed to monitor the angle of the extraction forceps. This device, worn by the dentist, communicates wirelessly with the **ESP32 microcontroller** to continuously monitor the angle in real-time. The wristband provides an additional layer of feedback to the dentist, ensuring that the forceps are used within the recommended angular range during the extraction. This wearable system ensures that the dentist can work with minimal distractions, while still receiving accurate real-time data on the extraction process.
### Hardware Setup

Here is an image of the hardware setup used for the force sensing device and the wearable device:

![Hardware Setup](https://github.com/hridyasatish/Sensor-Based-Physics-Forceps-for-Tooth-Extraction/blob/main/Hardware%20Setup.jpg)
## Conclusion
The **sensor-based physics forceps** system significantly improves the precision and safety of tooth extractions. By integrating **Force Sensing Resistors** (FSRs) for pressure detection and the **MPU6050** sensor for motion detection, the system ensures accurate and controlled force application. The use of a **wearable wristband** and real-time feedback through the **Blynk mobile app** empowers the dentist to perform extractions with greater confidence and precision, minimizing the risk of tissue damage and improving patient outcomes.

Compared to traditional forceps, the sensor-based forceps provide **more predictable** and **atraumatic extractions**, especially in challenging cases. The system reduces the likelihood of fractures to the tooth, root, and surrounding bone, while improving both **operator comfort** and **patient safety**. This technology has the potential to revolutionize tooth extraction procedures, offering significant benefits for both novice and experienced dentists.

## Future Work
One promising area for enhancement involves the integration of a **dynamic pressure calculation system** that accounts for the **specific tooth type** being extracted. Since the force required for tooth extraction varies depending on the type of tooth—molars, incisors, or premolars—this dynamic system could adjust the **pressure limits** based on the **tooth type** and **age** of the patient. Age-related factors such as bone density could also influence the force needed, and these variations would be incorporated into the system to ensure a safer, more efficient extraction process. 

By developing an **algorithm** to adjust the applied force dynamically, this system would offer an even more personalized approach to tooth extraction. Such improvements would further **reduce the risk of injury**, increase **precision**, and enhance the overall success rate of extractions, particularly for older patients with more fragile bone structures. In the future, the use of this intelligent, adaptive system could become a standard in dental practices, offering a safer, more effective way to perform extractions.
## Patent Documentation

### Patent Publication
Published on October 28, 2022.  
![Patent Publication](https://github.com/hridyasatish/Sensor-Based-Physics-Forceps-for-Tooth-Extraction/blob/main/Patent%20Publication.png)

### Patent Granted
Granted on July 26, 2024.  
![Patent Granted](https://github.com/hridyasatish/Sensor-Based-Physics-Forceps-for-Tooth-Extraction/blob/main/Patent%20Granted.png)

