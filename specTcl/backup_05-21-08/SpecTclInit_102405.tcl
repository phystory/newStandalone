# SpecTclInit.tcl -- SpecTcl initialization file
# SpecTcl source file: 01016_bdecayspec.cpp
# Last modified 2003/01/01 by ACM
# Last modified 2005/01/09 by JPC

# Set display memory for Xamine
set DisplayMegabytes 60


# Load Tcl utilities
source utils.tcl


# Start variable initialization

# Set clock parameters
#set bdecayv.clock.calib 0.1952
set bdecayv.clock.calib 0.00012666
#set bdecayv.clock.scale 32768
set bdecayv.clock.scale 50529027
set bdecayv.clock.max 2.0
set bdecayv.corr.minimplant 10.0

# Set temperature parameters
set bdecayv.temp.clockcalib 1.0


# Set PPAC parameters

set bdecayv.ppac01.udcal 256.0
set bdecayv.ppac01.lrcal 256.0
set bdecayv.ppac01.udthresh 150.0
set bdecayv.ppac01.lrthresh 150.0

# Set PIN parameters - PFM 2003/04/14, added PIN2alo and hi SNL 2003/04/20

set bdecayv.pin01.slope 1.0
set bdecayv.pin01.intercept 0.0
set bdecayv.pin01.thresh 100.0

set bdecayv.pin01a.slope 1.0
set bdecayv.pin01a.intercept 0.0
set bdecayv.pin01a.thresh 1500.0

set bdecayv.pin02.slope 1.0
set bdecayv.pin02.intercept 0.0
set bdecayv.pin02.thresh 100.0 
#change thresh from 0.0

set bdecayv.pin02alo.slope 1.0
set bdecayv.pin02alo.intercept 0.0
set bdecayv.pin02alo.thresh 28.0

set bdecayv.pin02a.loslope 1.0
set bdecayv.pin02a.lointercept 0.0
set bdecayv.pin02a.lothresh 128.0
#change from 0.0

set bdecayv.pin02ahi.slope 1.0
set bdecayv.pin02ahi.intercept 0.0
set bdecayv.pin02ahi.thresh 8.0

# added thresh and intercept 2004/02/25 SNL
#set bdecayv.pin02a.hislope 1.0
set bdecayv.pin02a.hislope 1.5487
set bdecayv.pin02a.hiintercept -136.28
set bdecayv.pin02a.hithresh 80.0

# added thresh and intercept 2004/02/25 SNL
#set bdecayv.pin03.slope 0.8951
set bdecayv.pin03.slope 0.92838
set bdecayv.pin03.intercept -103.98
set bdecayv.pin03.thresh 48.0

# added thresh and intercept 2004/02/25 SNL
#set bdecayv.pin04.slope 0.8974
set bdecayv.pin04.slope 0.92838  
set bdecayv.pin04.intercept -96.55
set bdecayv.pin04.thresh 56.0

# added thresh and intercept to Scintillators
set bdecayv.n3scint.slope 1.0  
set bdecayv.n3scint.intercept 0.0
set bdecayv.n3scint.thresh 0.0

set bdecayv.bscint.slope 1.0  
set bdecayv.bscint.intercept 0.0
set bdecayv.bscint.thresh 0.0

# Set time-of-flight and other corrections
set bdecayv.tac.rfcorr 0
set bdecayv.tac.i2scorr 0
set bdecayv.tac.xfpcorr 0
set bdecayv.tac.i2ncorr 0

# Set DSSD variables
source DSSDInit.tcl
source SSSDInit.tcl

# Set SeGA variables

source SeGAInit.tcl


# Set PID variables
set bdecayv.pid.i2s_scale 1
set bdecayv.pid.i2s_pos_corr 1
set bdecayv.pid.i2s_pos_offset 0

set bdecayv.pid.rf_pos_corr 1
set bdecayv.pid.rf_pos_offset 0

set bdecayv.pid.xfp_pos_corr 1
set bdecayv.pid.xfp_pos_offset 0

set bdecayv.pid.de1_tof_corr 1
set bdecayv.pid.de1_tof_offset 0

set bdecayv.pid.de2_tof_corr 1
set bdecayv.pid.de2_tof_offset 0

set bdecayv.pid.de2a_tof_corr 1
set bdecayv.pid.de2a_tof_offset 0

# seed initialization
set bdecayv.seed.reset 0

# End variable initialization

# Initializing Spectra
source bdecayspectra_standalone.tcl

# Initializing Spectra
source bdecaygates_standalone.tcl

# This command is necessary to initialize the spectra!
sbind -all
# end Initializing Spectra
