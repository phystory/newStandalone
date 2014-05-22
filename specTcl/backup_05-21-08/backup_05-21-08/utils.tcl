##########################################
# dump all spectra defined into one file.
# However, it doesn't work for binary yet!
########################################## 
proc svall {fname} {
    set spectra [spectrum -list]
    set fd [open $fname w]
    foreach spectrum $spectra {
	set sname [lindex $spectrum 1]
	swrite -format ascii $fd $sname
    }
    close $fd
}

########################################
# read all spectra written in one file
#######################################
proc rdall {fname} {
    unbind -all
    set fd [open $fname r]
    while {![eof $fd]} {sread $fd}
    close $fd
}

########################################
# save 2D spectra to ascii file
########################################
proc sv2d {sname fname} {
    set fd [open $fname w]
    for { set i 10 } { $i < 800 } { incr i } {
	for { set j 10 } { $j < 800 } { incr j } {
	    set counts [channel -get $sname "$i $j"]
	    if {$counts > 0}  {puts $fd "$i $j $counts"}
	    flush $fd
	}   
    }   
}   


############################################



########################################
# save 1D spectra to ascii file
########################################
proc sv1d {sname fname} {
    set fd [open $fname w]
    for { set i 50 } { $i < 2000 } { incr i } {
	    set counts [channel -get $sname "$i"]
	    if {$counts > 0}  {puts $fd "$i $counts"}
	    flush $fd
	}   
    }



############################################
# projection to y axis for 2D histo        #
# pfm - 28dec2001                          #
# updated 28jan2002 by pfm                 #
############################################
proc projy {2dname x1 x2 1dname xtnt} {
    set fd [open $1dname w]
    swrite -format ascii $fd $1dname
    seek $fd -8 end
    for { set j 0 } { $j < $xtnt } { incr j } {
	set sum [expr 0]
        for { set i $x1 } { $i < $x2 } { incr i } {
	    set counts [channel -get $2dname "$i $j"]
	    set sum [expr {$sum + $counts}]
	}
	if {$sum > 0} {puts $fd "($j) $sum"}
	flush $fd
    }
    puts $fd "(-1) -1"
    close $fd
    set fd [open $1dname r]
    sread $fd
    close $fd
}

############################################
# projection to x axis for 2D histo        #
# pfm - 28dec2001                          #
# updated 28jan2002 by pfm                 #
############################################
proc projx {2dname y1 y2 1dname xtnt} {
    set fd [open $1dname w]
    swrite -format ascii $fd $1dname
    seek $fd -8 end
    for { set i 0 } { $i < $xtnt } { incr i } {
	set sum [expr 0]
        for { set j $y1 } { $j < $y2 } { incr j } {
	    set counts [channel -get $2dname "$i $j"]
	    set sum [expr {$sum + $counts}]
	}
	if {$sum > 0} {puts $fd "($i) $sum"}
	flush $fd
    }
    puts $fd "(-1) -1"
    close $fd
    set fd [open $1dname r]
    sread $fd
    close $fd
}
            
############################################
# Procedure for sorting multiple files
# fstart - run number to start with
# fstop - run number to stop with (inclusive)
#
# Written by M.Karny for experiment 01027, April 2003
# Modified for more general use by ACM, May 2003
# Modified to insert run number into analysis program, May29, 2003
############################################

proc bsort {dirname fstart fstop} {
    global RunState
    global bdecayv.corr.reset
    global bdecayv.runnum.run

# location of the event files 
	    
    set jj [expr $fstop - $fstart]
    for { set i  0} {$i <= $jj} {incr i} {
    set runnum [expr $fstart + $i]
    set fname $dirname
    append fname /run
    append fname $runnum /run
    append fname $runnum -4096.evt
    puts  -nonewline $fname
    set bdecayv.corr.reset 1
    set bdecayv.runnum.run $runnum
    attach -file $fname 
    start

# vwait  waits for variable to be set to 0 to proceed
    vwait RunState
    puts  "    SORTED"

    }
}
