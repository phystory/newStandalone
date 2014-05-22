Readme for root script Nero_source_corr.C


Use: Calculate of background corrected rates, when you have a background run and a
source run. Right now, no errors are considered, so keep that in mind.


This script:

- loads a scaler file
- loads a second scaler file
- subtract one rate from the other rate
- creates an output
- calculates the efficiency



available functions:



readbackgr("filename.scalers")		reads the scalerfile, which will be the 
					subtrahend (b)

readsource("filename.scalers")		reads the scalerfile, which will be the
					minuend (a)

corr_source()				creates a new histo with 
					background-corrected rates (c) = (a) - (b)

Output("filename.XXX")			shows the corrected data in histograms for 
					all quads and saves canvas to filename.XXX
					to the current directory
					XXX can be pdf,ps,jpg,gif,c,...

efficiency(float nactivity)		calculates the efficiency, where the 
					nactivity is the neutron-activity of 
					the used n-source