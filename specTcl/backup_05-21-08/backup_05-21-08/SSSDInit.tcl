# SSSDInit.tcl -- SSSD initialization file
# SpecTcl source file: 01016_bdecayspec.cpp
# Last modified 2003/01/05 by ACM to start DSSD and SSSD strip numbering at 01 instead of 00
# Last modified 2004/20/04 to change sssd offset, gain, thresh.

# Set SSSD1 ADC offsets (ACM, 2003/01/01)
# All ADC offsets are based on a 12-bit scale

set bdecayv.sssd1.offset.01 16
set bdecayv.sssd1.offset.02 40
set bdecayv.sssd1.offset.03 32
set bdecayv.sssd1.offset.04 32
set bdecayv.sssd1.offset.05 16
set bdecayv.sssd1.offset.06 16
set bdecayv.sssd1.offset.07 16
set bdecayv.sssd1.offset.08 24
set bdecayv.sssd1.offset.09 56
set bdecayv.sssd1.offset.10 16
set bdecayv.sssd1.offset.11 40
set bdecayv.sssd1.offset.12 16
set bdecayv.sssd1.offset.13 48
set bdecayv.sssd1.offset.14 16
set bdecayv.sssd1.offset.15 40
set bdecayv.sssd1.offset.16 16

# Set SSSD1 gains (PFM, 2003/04/14)
# All gains are based on peak positions on a 9-bit scale

set bdecayv.sssd1.slope.01 [expr 350.0/(352.0 - (${bdecayv.sssd1.offset.01}/8.0))]
set bdecayv.sssd1.slope.02 [expr 350.0/(364.0 - (${bdecayv.sssd1.offset.02}/8.0))]
set bdecayv.sssd1.slope.03 [expr 350.0/(340.0 - (${bdecayv.sssd1.offset.03}/8.0))]
set bdecayv.sssd1.slope.04 [expr 350.0/(378.0 - (${bdecayv.sssd1.offset.04}/8.0))]
set bdecayv.sssd1.slope.05 [expr 350.0/(333.0 - (${bdecayv.sssd1.offset.05}/8.0))]
set bdecayv.sssd1.slope.06 [expr 350.0/(373.0 - (${bdecayv.sssd1.offset.06}/8.0))]
set bdecayv.sssd1.slope.07 [expr 350.0/(337.0 - (${bdecayv.sssd1.offset.07}/8.0))]
set bdecayv.sssd1.slope.08 [expr 350.0/(348.0 - (${bdecayv.sssd1.offset.08}/8.0))]
set bdecayv.sssd1.slope.09 [expr 350.0/(352.0 - (${bdecayv.sssd1.offset.09}/8.0))]
set bdecayv.sssd1.slope.10 [expr 350.0/(349.0 - (${bdecayv.sssd1.offset.10}/8.0))]
set bdecayv.sssd1.slope.11 [expr 350.0/(358.0 - (${bdecayv.sssd1.offset.11}/8.0))]
set bdecayv.sssd1.slope.12 [expr 350.0/(358.0 - (${bdecayv.sssd1.offset.12}/8.0))]
set bdecayv.sssd1.slope.13 [expr 350.0/(348.0 - (${bdecayv.sssd1.offset.13}/8.0))]
set bdecayv.sssd1.slope.14 [expr 350.0/(363.0 - (${bdecayv.sssd1.offset.14}/8.0))]
set bdecayv.sssd1.slope.15 [expr 350.0/(353.0 - (${bdecayv.sssd1.offset.15}/8.0))]
set bdecayv.sssd1.slope.16 [expr 350.0/(350.0 - (${bdecayv.sssd1.offset.16}/8.0))]

# Set SSSD1 thresholds (SNL, 2003/06/30)

set bdecayv.sssd1.thresh.01 112.0
set bdecayv.sssd1.thresh.02 152.0
set bdecayv.sssd1.thresh.03 144.0
set bdecayv.sssd1.thresh.04 160.0
set bdecayv.sssd1.thresh.05 152.0
set bdecayv.sssd1.thresh.06 152.0
set bdecayv.sssd1.thresh.07 136.0
set bdecayv.sssd1.thresh.08 128.0
set bdecayv.sssd1.thresh.09 168.0
set bdecayv.sssd1.thresh.10 144.0
set bdecayv.sssd1.thresh.11 160.0
set bdecayv.sssd1.thresh.12 128.0
set bdecayv.sssd1.thresh.13 168.0
set bdecayv.sssd1.thresh.14 128.0
set bdecayv.sssd1.thresh.15 168.0
set bdecayv.sssd1.thresh.16 4095.0

# Set SSSD1 upper level discriminators (ACM, 2002/12/11)

set bdecayv.sssd1.uld.01 3400.0
set bdecayv.sssd1.uld.02 3400.0
set bdecayv.sssd1.uld.03 3400.0
set bdecayv.sssd1.uld.04 3400.0
set bdecayv.sssd1.uld.05 3400.0
set bdecayv.sssd1.uld.06 3400.0
set bdecayv.sssd1.uld.07 3400.0
set bdecayv.sssd1.uld.08 3400.0
set bdecayv.sssd1.uld.09 3400.0
set bdecayv.sssd1.uld.10 3400.0
set bdecayv.sssd1.uld.11 3400.0
set bdecayv.sssd1.uld.12 3400.0
set bdecayv.sssd1.uld.13 3400.0
set bdecayv.sssd1.uld.14 3400.0
set bdecayv.sssd1.uld.15 3400.0
set bdecayv.sssd1.uld.16 3400.0

# Set SSSD2 ADC offsets (ACM, 2003/01/01)

set bdecayv.sssd2.offset.01 16
set bdecayv.sssd2.offset.02 40
set bdecayv.sssd2.offset.03 24
set bdecayv.sssd2.offset.04 16
set bdecayv.sssd2.offset.05 24
set bdecayv.sssd2.offset.06 16
set bdecayv.sssd2.offset.07 24
set bdecayv.sssd2.offset.08 16
set bdecayv.sssd2.offset.09 40
set bdecayv.sssd2.offset.10 32
set bdecayv.sssd2.offset.11 24
set bdecayv.sssd2.offset.12 40
set bdecayv.sssd2.offset.13 32
set bdecayv.sssd2.offset.14 32
set bdecayv.sssd2.offset.15 48
set bdecayv.sssd2.offset.16 24

# Set SSSD2 gains (SNL, 2003/06/30)

set bdecayv.sssd2.slope.01 [expr 350.0/(371.0 - (${bdecayv.sssd2.offset.01}/8.0))]
set bdecayv.sssd2.slope.02 [expr 350.0/(392.0 - (${bdecayv.sssd2.offset.02}/8.0))]
set bdecayv.sssd2.slope.03 [expr 350.0/(394.0 - (${bdecayv.sssd2.offset.03}/8.0))]
set bdecayv.sssd2.slope.04 [expr 350.0/(381.0 - (${bdecayv.sssd2.offset.04}/8.0))]
set bdecayv.sssd2.slope.05 [expr 350.0/(368.0 - (${bdecayv.sssd2.offset.05}/8.0))]
set bdecayv.sssd2.slope.06 [expr 350.0/(382.0 - (${bdecayv.sssd2.offset.06}/8.0))]
set bdecayv.sssd2.slope.07 [expr 350.0/(400.0 - (${bdecayv.sssd2.offset.07}/8.0))]
set bdecayv.sssd2.slope.08 [expr 350.0/(407.0 - (${bdecayv.sssd2.offset.08}/8.0))]
set bdecayv.sssd2.slope.09 [expr 350.0/(364.0 - (${bdecayv.sssd2.offset.09}/8.0))]
set bdecayv.sssd2.slope.10 [expr 350.0/(409.0 - (${bdecayv.sssd2.offset.10}/8.0))]
set bdecayv.sssd2.slope.11 [expr 350.0/(376.0 - (${bdecayv.sssd2.offset.11}/8.0))]
set bdecayv.sssd2.slope.12 [expr 350.0/(386.0 - (${bdecayv.sssd2.offset.12}/8.0))]
set bdecayv.sssd2.slope.13 [expr 350.0/(386.0 - (${bdecayv.sssd2.offset.13}/8.0))]
set bdecayv.sssd2.slope.14 [expr 350.0/(380.0 - (${bdecayv.sssd2.offset.14}/8.0))]
set bdecayv.sssd2.slope.15 [expr 350.0/(371.0 - (${bdecayv.sssd2.offset.15}/8.0))]
set bdecayv.sssd2.slope.16 [expr 350.0/(391.0 - (${bdecayv.sssd2.offset.16}/8.0))]

# Set SSSD2 thresholds (SNL, 2003/06/30)

set bdecayv.sssd2.thresh.01 144.0
set bdecayv.sssd2.thresh.02 152.0
set bdecayv.sssd2.thresh.03 144.0
set bdecayv.sssd2.thresh.04 120.0
set bdecayv.sssd2.thresh.05 144.0
set bdecayv.sssd2.thresh.06 160.0
set bdecayv.sssd2.thresh.07 152.0
set bdecayv.sssd2.thresh.08 144.0
set bdecayv.sssd2.thresh.09 136.0
set bdecayv.sssd2.thresh.10 168.0
set bdecayv.sssd2.thresh.11 160.0
set bdecayv.sssd2.thresh.12 168.0
set bdecayv.sssd2.thresh.13 152.0
set bdecayv.sssd2.thresh.14 136.0
set bdecayv.sssd2.thresh.15 152.0
set bdecayv.sssd2.thresh.16 160.0

# Set SSSD2 upper level discriminators (ACM, 2002/12/11)

set bdecayv.sssd2.uld.01 3400.0
set bdecayv.sssd2.uld.02 3400.0
set bdecayv.sssd2.uld.03 3400.0
set bdecayv.sssd2.uld.04 3400.0
set bdecayv.sssd2.uld.05 3400.0
set bdecayv.sssd2.uld.06 3400.0
set bdecayv.sssd2.uld.07 3400.0
set bdecayv.sssd2.uld.08 3400.0
set bdecayv.sssd2.uld.09 3400.0
set bdecayv.sssd2.uld.10 3400.0
set bdecayv.sssd2.uld.11 3400.0
set bdecayv.sssd2.uld.12 3400.0
set bdecayv.sssd2.uld.13 3400.0
set bdecayv.sssd2.uld.14 3400.0
set bdecayv.sssd2.uld.15 3400.0
set bdecayv.sssd2.uld.16 3400.0

# Set SSSD3 ADC offsets

set bdecayv.sssd3.offset.01 16
set bdecayv.sssd3.offset.02 16
set bdecayv.sssd3.offset.03 16
set bdecayv.sssd3.offset.04 24
set bdecayv.sssd3.offset.05 16
set bdecayv.sssd3.offset.06 16
set bdecayv.sssd3.offset.07 16
set bdecayv.sssd3.offset.08 16
set bdecayv.sssd3.offset.09 24
set bdecayv.sssd3.offset.10 32
set bdecayv.sssd3.offset.11 16
set bdecayv.sssd3.offset.12 16
set bdecayv.sssd3.offset.13 16
set bdecayv.sssd3.offset.14 16
set bdecayv.sssd3.offset.15 24
set bdecayv.sssd3.offset.16 16

# Set SSSD3 gains (pfm 2003/04/14)

set bdecayv.sssd3.slope.01 [expr 350.0/(370.0 - (${bdecayv.sssd3.offset.01}/8.0))]
set bdecayv.sssd3.slope.02 [expr 350.0/(371.0 - (${bdecayv.sssd3.offset.02}/8.0))]
set bdecayv.sssd3.slope.03 [expr 350.0/(369.0 - (${bdecayv.sssd3.offset.03}/8.0))]
set bdecayv.sssd3.slope.04 [expr 350.0/(385.0 - (${bdecayv.sssd3.offset.04}/8.0))]
set bdecayv.sssd3.slope.05 [expr 350.0/(351.0 - (${bdecayv.sssd3.offset.05}/8.0))]
set bdecayv.sssd3.slope.06 [expr 350.0/(376.0 - (${bdecayv.sssd3.offset.06}/8.0))]
set bdecayv.sssd3.slope.07 [expr 350.0/(372.0 - (${bdecayv.sssd3.offset.07}/8.0))]
set bdecayv.sssd3.slope.08 [expr 350.0/(383.0 - (${bdecayv.sssd3.offset.08}/8.0))]
set bdecayv.sssd3.slope.09 [expr 350.0/(376.0 - (${bdecayv.sssd3.offset.09}/8.0))]
set bdecayv.sssd3.slope.10 [expr 350.0/(374.0 - (${bdecayv.sssd3.offset.10}/8.0))]
set bdecayv.sssd3.slope.11 [expr 350.0/(380.0 - (${bdecayv.sssd3.offset.11}/8.0))]
set bdecayv.sssd3.slope.12 [expr 350.0/(374.0 - (${bdecayv.sssd3.offset.12}/8.0))]
set bdecayv.sssd3.slope.13 [expr 350.0/(373.0 - (${bdecayv.sssd3.offset.13}/8.0))]
set bdecayv.sssd3.slope.14 [expr 350.0/(382.0 - (${bdecayv.sssd3.offset.14}/8.0))]
set bdecayv.sssd3.slope.15 [expr 350.0/(368.0 - (${bdecayv.sssd3.offset.15}/8.0))]
set bdecayv.sssd3.slope.16 [expr 350.0/(383.0 - (${bdecayv.sssd3.offset.16}/8.0))]

# Set SSSD3 thresholds (SNL, 2003/06/30)

set bdecayv.sssd3.thresh.01 216.0
set bdecayv.sssd3.thresh.02 192.0
set bdecayv.sssd3.thresh.03 136.0
set bdecayv.sssd3.thresh.04 160.0
set bdecayv.sssd3.thresh.05 136.0
set bdecayv.sssd3.thresh.06 144.0
set bdecayv.sssd3.thresh.07 152.0
set bdecayv.sssd3.thresh.08 160.0
set bdecayv.sssd3.thresh.09 160.0
set bdecayv.sssd3.thresh.10 176.0
set bdecayv.sssd3.thresh.11 168.0
set bdecayv.sssd3.thresh.12 176.0
set bdecayv.sssd3.thresh.13 136.0
set bdecayv.sssd3.thresh.14 184.0
set bdecayv.sssd3.thresh.15 168.0
set bdecayv.sssd3.thresh.16 136.0

# Set SSSD3 upper level discriminators (acm, 2002/12/11)

set bdecayv.sssd3.uld.01 3400.0
set bdecayv.sssd3.uld.02 3400.0
set bdecayv.sssd3.uld.03 3400.0
set bdecayv.sssd3.uld.04 3400.0
set bdecayv.sssd3.uld.05 3400.0
set bdecayv.sssd3.uld.06 3400.0
set bdecayv.sssd3.uld.07 3400.0
set bdecayv.sssd3.uld.08 3400.0
set bdecayv.sssd3.uld.09 3400.0
set bdecayv.sssd3.uld.10 3400.0
set bdecayv.sssd3.uld.11 3400.0
set bdecayv.sssd3.uld.12 3400.0
set bdecayv.sssd3.uld.13 3400.0
set bdecayv.sssd3.uld.14 3400.0
set bdecayv.sssd3.uld.15 3400.0
set bdecayv.sssd3.uld.16 3400.0

# Set SSSD4 ADC offsets

set bdecayv.sssd4.offset.01 24
set bdecayv.sssd4.offset.02 16
set bdecayv.sssd4.offset.03 24
set bdecayv.sssd4.offset.04 16
set bdecayv.sssd4.offset.05 16
set bdecayv.sssd4.offset.06 16
set bdecayv.sssd4.offset.07 16
set bdecayv.sssd4.offset.08 32
set bdecayv.sssd4.offset.09 16
set bdecayv.sssd4.offset.10 16
set bdecayv.sssd4.offset.11 24
set bdecayv.sssd4.offset.12 16
set bdecayv.sssd4.offset.13 24
set bdecayv.sssd4.offset.14 16
set bdecayv.sssd4.offset.15 32
set bdecayv.sssd4.offset.16 16

# Set SSSD4 gains (SNL 2003/06/30)

set bdecayv.sssd4.slope.01 [expr 350.0/(373.0 - (${bdecayv.sssd4.offset.01}/8.0))]
set bdecayv.sssd4.slope.02 [expr 350.0/(376.0 - (${bdecayv.sssd4.offset.02}/8.0))]
set bdecayv.sssd4.slope.03 [expr 350.0/(363.0 - (${bdecayv.sssd4.offset.03}/8.0))]
set bdecayv.sssd4.slope.04 [expr 350.0/(365.0 - (${bdecayv.sssd4.offset.04}/8.0))]
set bdecayv.sssd4.slope.05 [expr 350.0/(351.0 - (${bdecayv.sssd4.offset.05}/8.0))]
set bdecayv.sssd4.slope.06 [expr 350.0/(356.0 - (${bdecayv.sssd4.offset.06}/8.0))]
set bdecayv.sssd4.slope.07 [expr 350.0/(326.0 - (${bdecayv.sssd4.offset.07}/8.0))]
set bdecayv.sssd4.slope.08 [expr 350.0/(360.0 - (${bdecayv.sssd4.offset.08}/8.0))]
set bdecayv.sssd4.slope.09 [expr 350.0/(359.0 - (${bdecayv.sssd4.offset.09}/8.0))]
set bdecayv.sssd4.slope.10 [expr 350.0/(338.0 - (${bdecayv.sssd4.offset.10}/8.0))]
set bdecayv.sssd4.slope.11 [expr 350.0/(347.0 - (${bdecayv.sssd4.offset.11}/8.0))]
set bdecayv.sssd4.slope.12 [expr 350.0/(371.0 - (${bdecayv.sssd4.offset.12}/8.0))]
set bdecayv.sssd4.slope.13 [expr 350.0/(347.0 - (${bdecayv.sssd4.offset.13}/8.0))]
set bdecayv.sssd4.slope.14 [expr 350.0/(349.0 - (${bdecayv.sssd4.offset.14}/8.0))]
set bdecayv.sssd4.slope.15 [expr 350.0/(331.0 - (${bdecayv.sssd4.offset.15}/8.0))]
set bdecayv.sssd4.slope.16 [expr 350.0/(343.0 - (${bdecayv.sssd4.offset.16}/8.0))]

# Set SSSD4 thresholds (SNL, 2003/06/30)

set bdecayv.sssd4.thresh.01 200.0
set bdecayv.sssd4.thresh.02 152.0
set bdecayv.sssd4.thresh.03 160.0
set bdecayv.sssd4.thresh.04 160.0
set bdecayv.sssd4.thresh.05 136.0
set bdecayv.sssd4.thresh.06 136.0
set bdecayv.sssd4.thresh.07 136.0
set bdecayv.sssd4.thresh.08 152.0
set bdecayv.sssd4.thresh.09 160.0
set bdecayv.sssd4.thresh.10 136.0
set bdecayv.sssd4.thresh.11 160.0
set bdecayv.sssd4.thresh.12 176.0
set bdecayv.sssd4.thresh.13 192.0
set bdecayv.sssd4.thresh.14 160.0
set bdecayv.sssd4.thresh.15 168.0
set bdecayv.sssd4.thresh.16 144.0

# Set SSSD4 upper level discriminators (pfm, 2003/02/06)

set bdecayv.sssd4.uld.01 3400.0
set bdecayv.sssd4.uld.02 3400.0
set bdecayv.sssd4.uld.03 3400.0
set bdecayv.sssd4.uld.04 3400.0
set bdecayv.sssd4.uld.05 3400.0
set bdecayv.sssd4.uld.06 3400.0
set bdecayv.sssd4.uld.07 3400.0
set bdecayv.sssd4.uld.08 3400.0
set bdecayv.sssd4.uld.09 3400.0
set bdecayv.sssd4.uld.10 3400.0
set bdecayv.sssd4.uld.11 3400.0
set bdecayv.sssd4.uld.12 3400.0
set bdecayv.sssd4.uld.13 3400.0
set bdecayv.sssd4.uld.14 3400.0
set bdecayv.sssd4.uld.15 3400.0
set bdecayv.sssd4.uld.16 3400.0

# Set SSSD5 ADC offsets

set bdecayv.sssd5.offset.01 16
set bdecayv.sssd5.offset.02 16
set bdecayv.sssd5.offset.03 32
set bdecayv.sssd5.offset.04 24
set bdecayv.sssd5.offset.05 16
set bdecayv.sssd5.offset.06 24
set bdecayv.sssd5.offset.07 40
set bdecayv.sssd5.offset.08 16
set bdecayv.sssd5.offset.09 24
set bdecayv.sssd5.offset.10 0
set bdecayv.sssd5.offset.11 40
set bdecayv.sssd5.offset.12 24
set bdecayv.sssd5.offset.13 40
set bdecayv.sssd5.offset.14 32
set bdecayv.sssd5.offset.15 16
set bdecayv.sssd5.offset.16 0

# Set SSSD5 gains  (SNL 2003/06/30)
 
set bdecayv.sssd5.slope.01 [expr 350.0/(333.0 - (${bdecayv.sssd5.offset.01}/8.0))]
set bdecayv.sssd5.slope.02 [expr 350.0/(381.0 - (${bdecayv.sssd5.offset.02}/8.0))]
set bdecayv.sssd5.slope.03 [expr 350.0/(344.0 - (${bdecayv.sssd5.offset.03}/8.0))]
set bdecayv.sssd5.slope.04 [expr 350.0/(363.0 - (${bdecayv.sssd5.offset.04}/8.0))]
set bdecayv.sssd5.slope.05 [expr 350.0/(336.0 - (${bdecayv.sssd5.offset.05}/8.0))]
set bdecayv.sssd5.slope.06 [expr 350.0/(354.0 - (${bdecayv.sssd5.offset.06}/8.0))]
set bdecayv.sssd5.slope.07 [expr 350.0/(335.0 - (${bdecayv.sssd5.offset.07}/8.0))]
set bdecayv.sssd5.slope.08 [expr 350.0/(339.0 - (${bdecayv.sssd5.offset.08}/8.0))]
set bdecayv.sssd5.slope.09 [expr 350.0/(338.0 - (${bdecayv.sssd5.offset.09}/8.0))]
set bdecayv.sssd5.slope.10 [expr 350.0/(350.0 - (${bdecayv.sssd5.offset.10}/8.0))]
set bdecayv.sssd5.slope.11 [expr 350.0/(361.0 - (${bdecayv.sssd5.offset.11}/8.0))]
set bdecayv.sssd5.slope.12 [expr 350.0/(358.0 - (${bdecayv.sssd5.offset.12}/8.0))]
set bdecayv.sssd5.slope.13 [expr 350.0/(367.0 - (${bdecayv.sssd5.offset.13}/8.0))]
set bdecayv.sssd5.slope.14 [expr 350.0/(356.0 - (${bdecayv.sssd5.offset.14}/8.0))]
set bdecayv.sssd5.slope.15 [expr 350.0/(356.0 - (${bdecayv.sssd5.offset.15}/8.0))]
set bdecayv.sssd5.slope.16 [expr 350.0/(350.0 - (${bdecayv.sssd5.offset.16}/8.0))]

# Set SSSD5 thresholds (SNL, 2003/06/30)

set bdecayv.sssd5.thresh.01 144.0
set bdecayv.sssd5.thresh.02 176.0
set bdecayv.sssd5.thresh.03 160.0
set bdecayv.sssd5.thresh.04 160.0
set bdecayv.sssd5.thresh.05 136.0
set bdecayv.sssd5.thresh.06 144.0
set bdecayv.sssd5.thresh.07 152.0
set bdecayv.sssd5.thresh.08 136.0
set bdecayv.sssd5.thresh.09 168.0
set bdecayv.sssd5.thresh.10 4095.0
set bdecayv.sssd5.thresh.11 200.0
set bdecayv.sssd5.thresh.12 160.0
set bdecayv.sssd5.thresh.13 152.0
set bdecayv.sssd5.thresh.14 144.0
set bdecayv.sssd5.thresh.15 176.0
set bdecayv.sssd5.thresh.16 4095.0

# Set SSSD5 upper level discriminators (ACM, 2002/12/11)

set bdecayv.sssd5.uld.01 3400.0
set bdecayv.sssd5.uld.02 3400.0
set bdecayv.sssd5.uld.03 3400.0
set bdecayv.sssd5.uld.04 3400.0
set bdecayv.sssd5.uld.05 3400.0
set bdecayv.sssd5.uld.06 3400.0
set bdecayv.sssd5.uld.07 3400.0
set bdecayv.sssd5.uld.08 3400.0
set bdecayv.sssd5.uld.09 3400.0
set bdecayv.sssd5.uld.10 3400.0
set bdecayv.sssd5.uld.11 3400.0
set bdecayv.sssd5.uld.12 3400.0
set bdecayv.sssd5.uld.13 3400.0
set bdecayv.sssd5.uld.14 3400.0
set bdecayv.sssd5.uld.15 3400.0
set bdecayv.sssd5.uld.16 3400.0

# Set SSSD6 ADC offsets

set bdecayv.sssd6.offset.01 16
set bdecayv.sssd6.offset.02 16
set bdecayv.sssd6.offset.03 32
set bdecayv.sssd6.offset.04 16
set bdecayv.sssd6.offset.05 16
set bdecayv.sssd6.offset.06 16
set bdecayv.sssd6.offset.07 16
set bdecayv.sssd6.offset.08 16
set bdecayv.sssd6.offset.09 32
set bdecayv.sssd6.offset.10 24
set bdecayv.sssd6.offset.11 32
set bdecayv.sssd6.offset.12 16
set bdecayv.sssd6.offset.13 16
set bdecayv.sssd6.offset.14 0
set bdecayv.sssd6.offset.15 16
set bdecayv.sssd6.offset.16 16

# Set SSSD6 gains (SNL, 2003/06/30)

set bdecayv.sssd6.slope.01 [expr 350.0/(354.0 - (${bdecayv.sssd6.offset.01}/8.0))]
set bdecayv.sssd6.slope.02 [expr 350.0/(357.0 - (${bdecayv.sssd6.offset.02}/8.0))]
set bdecayv.sssd6.slope.03 [expr 350.0/(351.0 - (${bdecayv.sssd6.offset.03}/8.0))]
set bdecayv.sssd6.slope.04 [expr 350.0/(366.0 - (${bdecayv.sssd6.offset.04}/8.0))]
set bdecayv.sssd6.slope.05 [expr 350.0/(344.0 - (${bdecayv.sssd6.offset.05}/8.0))]
set bdecayv.sssd6.slope.06 [expr 350.0/(374.0 - (${bdecayv.sssd6.offset.06}/8.0))]
set bdecayv.sssd6.slope.07 [expr 350.0/(350.0 - (${bdecayv.sssd6.offset.07}/8.0))]
set bdecayv.sssd6.slope.08 [expr 350.0/(361.0 - (${bdecayv.sssd6.offset.08}/8.0))]
set bdecayv.sssd6.slope.09 [expr 350.0/(356.0 - (${bdecayv.sssd6.offset.09}/8.0))]
set bdecayv.sssd6.slope.10 [expr 350.0/(361.0 - (${bdecayv.sssd6.offset.10}/8.0))]
set bdecayv.sssd6.slope.11 [expr 350.0/(341.0 - (${bdecayv.sssd6.offset.11}/8.0))]
set bdecayv.sssd6.slope.12 [expr 350.0/(366.0 - (${bdecayv.sssd6.offset.12}/8.0))]
set bdecayv.sssd6.slope.13 [expr 350.0/(355.0 - (${bdecayv.sssd6.offset.13}/8.0))]
set bdecayv.sssd6.slope.14 [expr 350.0/(350.0 - (${bdecayv.sssd6.offset.14}/8.0))]
set bdecayv.sssd6.slope.15 [expr 350.0/(359.0 - (${bdecayv.sssd6.offset.15}/8.0))]
set bdecayv.sssd6.slope.16 [expr 350.0/(377.0 - (${bdecayv.sssd6.offset.16}/8.0))]

# Set SSSD6 thresholds (SNL, 2003/06/30)

set bdecayv.sssd6.thresh.01 192.0
set bdecayv.sssd6.thresh.02 160.0
set bdecayv.sssd6.thresh.03 176.0
set bdecayv.sssd6.thresh.04 168.0
set bdecayv.sssd6.thresh.05 136.0
set bdecayv.sssd6.thresh.06 144.0
set bdecayv.sssd6.thresh.07 144.0
set bdecayv.sssd6.thresh.08 160.0
set bdecayv.sssd6.thresh.09 160.0
set bdecayv.sssd6.thresh.10 152.0
set bdecayv.sssd6.thresh.11 160.0
set bdecayv.sssd6.thresh.12 136.0
set bdecayv.sssd6.thresh.13 152.0
set bdecayv.sssd6.thresh.14 4095.0
set bdecayv.sssd6.thresh.15 160.0
set bdecayv.sssd6.thresh.16 152.0

# Set SSSD6 upper level discriminators (ACM, 2002/12/11)

set bdecayv.sssd6.uld.01 3400.0
set bdecayv.sssd6.uld.02 3400.0
set bdecayv.sssd6.uld.03 3400.0
set bdecayv.sssd6.uld.04 3400.0
set bdecayv.sssd6.uld.05 3400.0
set bdecayv.sssd6.uld.06 3400.0
set bdecayv.sssd6.uld.07 3400.0
set bdecayv.sssd6.uld.08 3400.0
set bdecayv.sssd6.uld.09 3400.0
set bdecayv.sssd6.uld.10 3400.0
set bdecayv.sssd6.uld.11 3400.0
set bdecayv.sssd6.uld.12 3400.0
set bdecayv.sssd6.uld.13 3400.0
set bdecayv.sssd6.uld.14 3400.0
set bdecayv.sssd6.uld.15 3400.0
set bdecayv.sssd6.uld.16 3400.0

# end of variable initialization

