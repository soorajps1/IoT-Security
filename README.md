The Patient Temperature Monitoring System utilizes the MPU-6050 sensor to measure temperature data from patients. The collected temperature readings are processed and encoded into binary and grey code formats. The encoded data is then securely transmitted to the Thingspeak cloud platform for storage. Subsequently, a Python program is employed to retrieve the encoded data from Thingspeak, decrypt it using the grey code, and provide meaningful temperature readings for medical analysis.

Components:

MPU-6050 Sensor:
The MPU-6050 is an integrated motion-tracking device that includes a temperature sensor. In this project, we leverage its temperature sensing capabilities to monitor and collect patient temperature data.

Binary Encoding:
The temperature data collected from the MPU-6050 is converted into binary format. This binary representation is a series of 0s and 1s, providing a compact and efficient way to represent the temperature readings.

Grey Code Encoding:
To enhance security, the binary-encoded temperature data is further processed into grey code. Grey code is a binary numeral system where two consecutive values differ in only one bit. This encoding method helps prevent errors in data transmission and ensures data integrity.

Thingspeak Cloud Integration:
Thingspeak is a cloud platform that allows for the collection and visualization of IoT data. The binary and grey code encoded temperature data is securely transmitted to the Thingspeak cloud for storage and analysis.

Python Program for Data Retrieval and Decryption:
A Python program is developed to retrieve the encoded temperature data from Thingspeak. The program then decrypts the grey code, obtaining the original temperature readings. The decrypted data is presented in a human-readable format for further medical analysis.

Encryption and Decryption Mechanism:
The grey code serves as an encryption mechanism during data transmission to the cloud. The Python program includes a decryption process to revert the grey code back to binary and then to the original temperature readings. This ensures the confidentiality and integrity of the patient's temperature data.

Workflow:

Data Acquisition:

The MPU-6050 sensor collects temperature data from the patient.
The obtained temperature readings are then processed for further encoding.
Binary Encoding:

The temperature data is converted into binary format.
Grey Code Encoding:

The binary-encoded data is further processed into grey code.
Thingspeak Cloud Transmission:

The grey code encoded data is securely transmitted to the Thingspeak cloud.
Python Program Execution:

A Python program is executed to retrieve the encrypted data from Thingspeak.
Decryption Process:

The grey code is decrypted to obtain the binary representation.
The binary data is then converted back to the original temperature readings.
Medical Analysis:

The decrypted temperature readings are presented in a human-readable format.
Medical professionals can analyze the data for patient monitoring and diagnosis.
