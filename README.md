# Hampton_CSCI2270_FinalProject
The working title for my project is Liam's bad uses of good data. A METAR is a small two line print out that contains temperatures, winds, visibility, cloud cover/cloud ceilings and altimiter settings for aviation. Every major airport produces dozens a day and they are widely disseminated to ensure safety. The AWC under NOAA maintains a searchable database of CSV METARs. They offer a detailed glance at the weather of the nearby area and if you compile multiple sites into a database, you have essentially created a standardized weather map of the world. 

My program in it's current form relies on a two day old txt file I made of the METARs for 9 Cities. I sampled twelve hours of METAR data so there are 128 in total. I broke the data apart by group and airport and created 8 airport structs (Turns out Boulder doesn't produce one) with many different parameters inside of each extracted from the METAR (Time/Date, Wind speeds, temperatures, precipitation). I havestarted the framing what will become complete searchability to get the complete readings from one city in particular or to compare it to other cities to determine max and min values. 

The current build 
