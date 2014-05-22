# SpecTclInit.tcl -- SpecTcl initialization file
# Last modified 2005/01/09 by JPC
# Variables are initialized in bdecayV_standalone.h include file
# Set display memory for Xamine
set DisplayMegabytes 60

# Load Tcl utilities
source utils.tcl

# Start variable initialization


# Initializing NERO Spectra and Gates
#source nero_Spectra.tcl

# Initializing online checks 
source backup_newcheck1.tcl

# This command is necessary to initialize the spectra!
sbind -all
# end Initializing Spectra
