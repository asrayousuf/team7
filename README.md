Problem Statement: Design an odometer that can have numbers only from 1-9. Digits of the reading should be in strictly ascending order only. The range of numbers can vary from 2 digits to 8 digits
Eg. 13789 will have next reading of 14567


Functions implemented:
Previous Reading 
Next Reading
Difference between readings: 
If it is a valid number or not

Approach:
Create a isValid function which checks if a number is a valid reading or not. To find next reading, check each number after it to find if it is valid or not
