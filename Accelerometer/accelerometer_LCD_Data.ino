/*
   Arduino and MPU6050 Accelerometer and Gyroscope Sensor Tutorial
   by Dejan, https://howtomechatronics.com
*/
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define TotalSamples 375
int runcount = 0;
unsigned int sampleTime[TotalSamples] = {};
//int16_t accX[TotalSamples] = {};
int16_t accY[TotalSamples] = {};
//int16_t accZ[TotalSamples] = {};
//float accX[TotalSamples] = {};
//float accY[TotalSamples] = {};
//float accZ[TotalSamples] = {};

const int MPU = 0x68; // MPU6050 I2C address
//float AccX, AccY, AccZ;
int16_t AccX, AccY, AccZ;
//float GyroX, GyroY, GyroZ;
//float accAngleX, accAngleY, gyroAngleX, gyroAngleY, gyroAngleZ;
//float roll, pitch, yaw;
//float AccErrorX, AccErrorY, GyroErrorX, GyroErrorY, GyroErrorZ;
//float elapsedTime, currentTime, previousTime;
//int c = 0;

void setup() {
  Serial.begin(9600);
  Wire.begin();                      // Initialize comunication
  Wire.beginTransmission(MPU);       // Start communication with MPU6050 // MPU=0x68
  Wire.write(0x6B);                  // Talk to the register 6B
  Wire.write(0x00);                  // Make reset - place a 0 into the 6B register
  Wire.endTransmission(true);        //end the transmission
  /*
  // Configure Accelerometer Sensitivity - Full Scale Range (default +/- 2g)
  Wire.beginTransmission(MPU);
  Wire.write(0x1C);                  //Talk to the ACCEL_CONFIG register (1C hex)
  Wire.write(0x10);                  //Set the register bits as 00010000 (+/- 8g full scale range)
  Wire.endTransmission(true);
  // Configure Gyro Sensitivity - Full Scale Range (default +/- 250deg/s)
  Wire.beginTransmission(MPU);
  Wire.write(0x1B);                   // Talk to the GYRO_CONFIG register (1B hex)
  Wire.write(0x10);                   // Set the register bits as 00010000 (1000deg/s full scale)
  Wire.endTransmission(true);
  delay(20);
  */
  //delay(1000);
}
void loop() {
  if (runcount < TotalSamples){
  // === Read acceleromter data === //
  Wire.beginTransmission(MPU);
  Wire.write(0x3B); // Start with register 0x3B (ACCEL_XOUT_H)
  Wire.endTransmission(false);
  Wire.requestFrom(MPU, 6, true); // Read 6 registers total, each axis value is stored in 2 registers
  //For a range of +-2g, we need to divide the raw values by 16384, according to the datasheet
  AccX = (Wire.read() << 8 | Wire.read()); // X-axis value
  AccY = (Wire.read() << 8 | Wire.read()); // Y-axis value
  AccZ = (Wire.read() << 8 | Wire.read()); // Z-axis value
  //AccX = (Wire.read() << 8 | Wire.read()) / 16384.0; // X-axis value
  //AccY = (Wire.read() << 8 | Wire.read()) / 16384.0; // Y-axis value
  //AccZ = (Wire.read() << 8 | Wire.read()) / 16384.0; // Z-axis value
  /*
  // Calculating Roll and Pitch from the accelerometer data
  accAngleX = (atan(AccY / sqrt(pow(AccX, 2) + pow(AccZ, 2))) * 180 / PI) + 0.66; // AccErrorX ~(-0.66) See the calculate_IMU_error()custom function for more details
  accAngleY = (atan(-1 * AccX / sqrt(pow(AccY, 2) + pow(AccZ, 2))) * 180 / PI) + 0.83; // AccErrorY ~(-0.83)
  // === Read gyroscope data === //
  previousTime = currentTime;        // Previous time is stored before the actual time read
  currentTime = millis();            // Current time actual time read
  elapsedTime = (currentTime - previousTime) / 1000; // Divide by 1000 to get seconds
  Wire.beginTransmission(MPU);
  Wire.write(0x43); // Gyro data first register address 0x43
  Wire.endTransmission(false);
  Wire.requestFrom(MPU, 6, true); // Read 4 registers total, each axis value is stored in 2 registers
  GyroX = (Wire.read() << 8 | Wire.read()) / 131.0; // For a 250deg/s range we have to divide first the raw value by 131.0, according to the datasheet
  GyroY = (Wire.read() << 8 | Wire.read()) / 131.0;
  GyroZ = (Wire.read() << 8 | Wire.read()) / 131.0;
  // Correct the outputs with the calculated error values
  GyroX = GyroX + 0.70; // GyroErrorX ~(-0.70)
  GyroY = GyroY - 0.86; // GyroErrorY ~(0.86)
  GyroZ = GyroZ - 1.14; // GyroErrorZ ~ (1.14)
  // Currently the raw values are in degrees per seconds, deg/s, so we need to multiply by sendonds (s) to get the angle in degrees
  gyroAngleX = gyroAngleX + GyroX * elapsedTime; // deg/s * s = deg
  gyroAngleY = gyroAngleY + GyroY * elapsedTime;
  yaw =  yaw + GyroZ * elapsedTime;
  // Complementary filter - combine acceleromter and gyro angle values
  roll = 0.96 * gyroAngleX + 0.04 * accAngleX;
  pitch = 0.96 * gyroAngleY + 0.04 * accAngleY;
  */
  sampleTime[runcount] = millis();
  //accX[runcount] = AccX;
  accY[runcount] = AccY;
  //accZ[runcount] = AccZ;
  runcount++;
  }
  if (runcount == TotalSamples){
    for (int i = 0; i < TotalSamples; i++){
  // Print the values on the serial monitor
  /*
  Serial.print(roll);
  Serial.print("/");
  Serial.print(pitch);
  Serial.print("/");
  Serial.println(yaw);
  */
  Serial.print(sampleTime[i]);
  Serial.print(",");
  //Serial.print(accX[i]);  
  Serial.print(accY[i]); 
  //Serial.print(accZ[i]); 
  Serial.println();
    }
    runcount++;
  }
  delay(10);
}
