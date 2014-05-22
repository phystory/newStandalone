#!/usr/bin/wish

# NSCL Buffer Dumper
# © 2005 D. Bazin, NSCL

proc SetupDump {} {
	global dump
	wm title . "NSCL Buffer Dumper"
	wm geometry . 400x600+100+100
	
	set dump(toplevel) .dump
	set dump(source) spdaq28
	set dump(filename) "File: unknown"
	set dump(skip) 0
	set dump(buffertype) any
	set dump(buffersize) 8192
	set dump(headersize) 16
	set dump(tags) [list 1900 2000 2100 2200 3000 3100 3200 5000 5800 5900 7000 7100 7200]
	set dump(devices) [list A1900 SeGA APEX BaF Miniball HiRA Lassa MoNA S800 Sweeper NMR Beta Trap]
	set dump(period) 2
	set w $dump(toplevel)
	frame $w
	pack $w -side top -expand 1 -fill both
	
	frame $w.online -borderwidth 2 -relief groove -bg lightgreen
	frame $w.file -borderwidth 2 -relief groove -bg lightpink
	frame $w.filter -borderwidth 2 -relief groove -bg lightyellow
	frame $w.header -borderwidth 2 -relief groove -bg lightblue
	frame $w.contents -borderwidth 2 -relief sunken
	frame $w.save -borderwidth 2 -relief groove
	grid $w.online  -sticky news
	grid $w.file  -sticky news
	grid $w.filter -sticky news
	grid $w.header -sticky news
	grid $w.contents -sticky news
	grid $w.save -sticky news
	grid rowconfigure $dump(toplevel) 0 -weight 0
	grid rowconfigure $dump(toplevel) 1 -weight 0
	grid rowconfigure $dump(toplevel) 2 -weight 0
	grid rowconfigure $dump(toplevel) 3 -weight 0
	grid rowconfigure $dump(toplevel) 4 -weight 1
	grid rowconfigure $dump(toplevel) 5 -weight 0
	grid columnconfigure $dump(toplevel) 0 -weight 1
	
	set w $dump(toplevel).online
	label $w.title -text "Online Buffer Source" -font "Helvetica -14" -bg lightgreen
	button $w.get -text "Get Online Buffer from:" -command WaitForOnlineBuffer -bg lightgreen
	entry $w.source -textvariable dump(source) -width 10 -bg white
	checkbutton $w.sample -text "Sample Buffer every" -command SampleOnlineBuffer -variable dump(sample) -bg lightgreen
	entry $w.period -textvariable dump(period) -width 5 -bg white
	label $w.seconds -text "Seconds" -bg lightgreen
	grid $w.title - - -sticky news
	grid $w.get - $w.source -sticky news
	grid $w.sample $w.period $w.seconds -sticky news
	grid columnconfigure $w 0 -weight 0
	grid columnconfigure $w 1 -weight 0
	grid columnconfigure $w 2 -weight 1
	
	set w $dump(toplevel).file
	label $w.title -text "Event File Buffer Source" -font "Helvetica -14" -bg lightpink
	button $w.open -text "Open .evt file" -command OpenClose -bg lightpink
	label $w.filename -textvariable dump(filename) -anchor w -bg lightpink
	button $w.get -text "Get next buffer" -command GetNextBuffer -bg lightpink
	button $w.rewind -text "Rewind" -command RewindFile -bg lightpink
	button $w.skip -text "Skip buffers:" -command SkipBuffers -bg lightpink
	entry $w.n -textvariable dump(skip) -width 4 -bg white
	grid $w.title - - -sticky news
	grid $w.get $w.rewind $w.open -sticky news
	grid $w.skip $w.n $w.filename -sticky news
	grid columnconfigure $w 0 -weight 0
	grid columnconfigure $w 1 -weight 0
	grid columnconfigure $w 2 -weight 1
	
	set w $dump(toplevel).filter
	label $w.label -text "Show only:" -bg lightyellow
	radiobutton $w.any -text "Any" -variable dump(buffertype) -value any -bg lightyellow
	radiobutton $w.begin -text "Begin" -variable dump(buffertype) -value begin -bg lightyellow
	radiobutton $w.end -text "End" -variable dump(buffertype) -value end -bg lightyellow
	radiobutton $w.pause -text "Pause" -variable dump(buffertype) -value pause -bg lightyellow
	radiobutton $w.resume -text "Resume" -variable dump(buffertype) -value resume -bg lightyellow
	radiobutton $w.data -text "Data" -variable dump(buffertype) -value data -bg lightyellow
	radiobutton $w.scaler -text "Scaler" -variable dump(buffertype) -value scaler -bg lightyellow
	grid $w.label $w.begin $w.end $w.pause $w.resume -sticky news
	grid x $w.any $w.data $w.scaler x -sticky news
	grid columnconfigure $w 0 -weight 1
	grid columnconfigure $w 1 -weight 1
	grid columnconfigure $w 2 -weight 1
	grid columnconfigure $w 3 -weight 1
	grid columnconfigure $w 4 -weight 1
	
	set w $dump(toplevel).header
	label $w.title -text "Header information" -font "helvetica -14" -bg lightblue
	label $w.ltype -text "Type:" -bg lightblue
	label $w.type -textvariable dump(type) -bg lightblue
	label $w.llength -text "Length (words):" -bg lightblue
	label $w.length -textvariable dump(length) -bg lightblue
	label $w.lrun -text "Run:" -bg lightblue
	label $w.run -textvariable dump(run) -bg lightblue
	label $w.lseq -text "Sequence:" -bg lightblue
	label $w.seq -textvariable dump(sequence) -bg lightblue
	grid $w.title - - - -sticky news
	grid $w.ltype $w.type $w.llength $w.length -sticky news
	grid $w.lrun $w.run $w.lseq $w.seq -sticky news
	grid columnconfigure $w 0 -weight 1
	grid columnconfigure $w 1 -weight 1
	grid columnconfigure $w 2 -weight 1
	grid columnconfigure $w 3 -weight 1
	
	set w $dump(toplevel).contents
	text $w.text -font "fixed -10" -background white 
	scrollbar $w.ybar -orient vertical -command "$w.text yview" -width 12
	$w.text configure -yscrollcommand "$w.ybar set"
	$w.text tag configure green -font "fixed -10" -foreground darkgreen
	$w.text tag configure red -font "fixed -10" -foreground red
	$w.text tag configure blue -font "fixed -10" -foreground blue
	$w.text tag configure black -font "fixed -10" -foreground black
	grid $w.text $w.ybar -sticky news
	grid columnconfigure $w 0 -weight 1
	grid columnconfigure $w 1 -weight 0
	grid rowconfigure $w 0 -weight 1
	
	set w $dump(toplevel).save
	button $w.save -text "Save to ASCII" -command SaveToASCII
	button $w.exit -text "Exit" -command exit
	grid $w.save $w.exit -sticky news
	grid columnconfigure $w 0 -weight 1
	grid columnconfigure $w 1 -weight 0
}

proc Connect {} {
	global dump
	if {[catch {set dump(sid) [open "|/usr/opt/daq/Bin/spectcldaq \"TCP://$dump(source):2602\"" r]} err]} {
		tk_messageBox -icon error -message "Error connecting to $dump(source):\n$err"
		return
	}
	fconfigure $dump(sid) -translation binary -buffersize 8192 -buffering full -blocking 1
	set dump(connected) 1
}

proc Disconnect {} {
	global dump
	fconfigure $dump(sid) -blocking 0
	if {[catch {close $dump(sid)} err]} {
#		tk_messageBox -icon error -message "Error disconnecting from $dump(source):\n$err"
	}
	set dump(connected) 0
}

proc WaitForOnlineBuffer {} {
	global dump
	Connect
	fileevent $dump(sid) readable GetOnlineBuffer
	set w $dump(toplevel).online
	$w.get configure -text "Waiting..." -state disabled
}

proc GetOnlineBuffer {} {
	global dump
	set dump(binary) [read $dump(sid) $dump(buffersize)]
	while {![ProcessBuffer]} {
		set dump(binary) [read $dump(sid) $dump(buffersize)]
	}
	fileevent $dump(sid) readable {}
	Disconnect
	set w $dump(toplevel).online
	$w.get configure -text "Get Online Buffer from:" -state normal
}

proc SampleOnlineBuffer {} {
	global dump
	if {$dump(sample)} {
		if {!$dump(connected)} {WaitForOnlineBuffer}
		set dump(schedule) [after [expr $dump(period)*1000] SampleOnlineBuffer]
	} else {
		if {[info exist dump(schedule)]} {after cancel $dump(schedule)}
	}
}

proc OpenClose {} {
	global dump
	set w $dump(toplevel).file.open
	if {[string match *Open* [$w cget -text]]} {
		OpenFile
		$w configure -text "Close .evt file"
	} else {
		CloseFile
		$w configure -text "Open .evt file"
	}
}

proc OpenFile {} {
	global dump
	set theFile [tk_getOpenFile -filetypes {{"NSCL event file" {.evt}}}]
	if {[string equal $theFile ""]} {return}
	set dump(file) [open $theFile r]
	fconfigure $dump(file) -encoding binary -translation binary
	set dump(filename) "File: $theFile"
}

proc CloseFile {} {
	global dump
	close $dump(file)
	set dump(filename) "File: unknown"
}

proc RewindFile {} {
	global dump
	close $dump(file)
	set theFile [string trimleft $dump(filename) "File: "]
	set dump(file) [open $theFile r]
	fconfigure $dump(file) -encoding binary -translation binary
}

proc GetNextBuffer {} {
	global dump
	if {[string match *unknown* $dump(filename)]} {return}
	set dump(binary) [read $dump(file) $dump(buffersize)]
	while {![ProcessBuffer] && ![eof $dump(file)]} {
		set dump(binary) [read $dump(file) $dump(buffersize)]
	}
}

proc SkipBuffers {} {
	global dump
	if {[string match *unknown* $dump(filename)]} {return}
	for {set i 0} {$i < $dump(skip)} {incr i} {
		read $dump(file) $dump(buffersize)
	}
}

proc SaveToASCII {} {
	global dump
	set theFile [tk_getSaveFile -filetypes {{"ASCII file" {.txt}}}]
	if {[string equal $theFile ""]} {return}
	set w $dump(toplevel).contents.text
	set file [open $theFile w]
	puts $file [$w get 1.0 end]
	close $file
}

proc ProcessBuffer {} {
	global dump
	if {![DecodeHeader]} {return 0}
	binary scan $dump(binary) "s4096" dump(buffer)
	$dump(toplevel).contents.text delete 1.0 end
	switch -- $dump(type) {
		data {DecodeData}
		scaler {DecodeScaler}
		begin {DecodeBegin}
		end {DecodeEnd}
		pause {DecodePause}
		resume {DecodeResume}
		unknown {DecodeUnknown}
		default {}
	}
	return 1
}

proc DecodeHeader {} {
	global dump
	binary scan $dump(binary) "s16" dump(header)
	set dump(type) [lindex $dump(header) 1]
	switch -- $dump(type) {
		1 {set dump(type) data}
		2 {set dump(type) scaler}
		3 {set dump(type) scaler}
		11 {set dump(type) begin}
		12 {set dump(type) end}
		13 {set dump(type) pause}
		14 {set dump(type) resume}
		default {set dump(type) unknown}
	}
	if {![string equal $dump(type) $dump(buffertype)]  && ![string equal $dump(buffertype) any]} {return 0}
	set dump(length) [lindex $dump(header) 0]
	set dump(run) [lindex $dump(header) 3]
	set dump(sequence) [LongWord header 4]
	set dump(nevents) [lindex $dump(header) 6]
	return 1
}

proc DecodeData {} {
	global dump
	set w $dump(toplevel).contents.text
	set bufpt $dump(headersize)
	set evtcounter 1
	$w insert end "$dump(nevents) event(s) in buffer...\n" "black"
# event loop
	while {$bufpt < $dump(length)} {
		set evtlength [lindex $dump(buffer) $bufpt]
		$w insert end "**** Event # $evtcounter ****" "black" " length = $evtlength words\n" "blue"
		set evtpt 1
# sub-event loop
		while {$evtpt < $evtlength} {
			set subevtlength [lindex $dump(buffer) [expr $bufpt+$evtpt]]
			set subevttag [HexWord [lindex $dump(buffer) [expr $bufpt+$evtpt+1]]]
			if {[set index [lsearch $dump(tags) [string trimright $subevttag " "]]] == -1} {
				set subevtdevice Unknown
			} else {
				set subevtdevice [lindex $dump(devices) $index]
			}
			$w insert end "---- $subevtdevice Sub-Event ----" "black" " length = $subevtlength words\n" "blue"
#			$w insert end "[HexWord $subevtlength]" "red" "$subevttag" "red"
			for {set i 0} {$i < $subevtlength} {incr i} {
				if {($i/10)*10 == $i} {$w insert end "[format %.4d $i]: " "black"}
				if {$i < 2} {
					$w insert end "[HexWord [lindex $dump(buffer) [expr $bufpt+$evtpt+$i]]]" "red"
				} else {
					$w insert end "[HexWord [lindex $dump(buffer) [expr $bufpt+$evtpt+$i]]]" "green"
				}
				if {(($i+1)/10)*10 == $i+1} {$w insert end "\n"}
			}
			$w insert end "\n"
			incr evtpt $subevtlength
		}
		incr bufpt $evtlength
		incr evtcounter
	}
}

proc DecodeScaler {} {
	global dump
	set w $dump(toplevel).contents.text
	set bufpt $dump(headersize)
	$w insert end "$dump(nevents) scaler(s) in buffer...\n" "black"
	set endtime [LongWord buffer $bufpt]
	incr bufpt 5
	set starttime [LongWord buffer $bufpt]
	incr bufpt 5
	$w insert end "Start time: $starttime seconds\n" "blue"
	$w insert end "End time: $endtime seconds\n" "blue"
	for {set i 0} {$i < $dump(nevents)} {incr i} {
		set scaler [LongWord buffer $bufpt]
		incr bufpt 2
		$w insert end "Scaler $i: " "black" "$scaler counts\n" "green"
	}
}

proc DecodeBegin {} {
	global dump
	set w $dump(toplevel).contents.text
	binary scan $dump(binary) "x32 A80 x4 s1 s1 s1 s1 s1 s1" dump(runtitle) mo da ye ho mi se
	set dump(runstart) [clock format [clock scan "$mo/$da/$ye $ho:$mi:$se"]]
	$w insert end "Title: " "black" "$dump(runtitle)\n" "blue"
	$w insert end "Started on : " "black" "$dump(runstart)\n" "blue"
}

proc DecodeEnd {} {
	global dump
	set w $dump(toplevel).contents.text
	binary scan $dump(binary) "x32 A80 i1 s1 s1 s1 s1 s1 s1" dump(runtitle) time mo da ye ho mi se
	set dump(runstart) [clock format [clock scan "$mo/$da/$ye $ho:$mi:$se"]]
	$w insert end "Title: " "black" "$dump(runtitle)\n" "blue"
	$w insert end "Ended on : " "black" "$dump(runstart)\n" "blue"
	$w insert end "Run lasted " "black" "[expr $time*1.0/10]" "blue" " seconds\n" "black"
}

proc DecodePause {} {
	global dump
	set w $dump(toplevel).contents.text
	binary scan $dump(binary) "x32 A80 i1 s1 s1 s1 s1 s1 s1" dump(runtitle) time mo da ye ho mi se
	set dump(runstart) [clock format [clock scan "$mo/$da/$ye $ho:$mi:$se"]]
	$w insert end "Title: " "black" "$dump(runtitle)\n" "blue"
	$w insert end "Paused on : " "black" "$dump(runstart)\n" "blue"
	$w insert end "after " "black" "[expr $time*1.0/10]" "blue" " seconds\n" "black"
}

proc DecodeResume {} {
	global dump
	set w $dump(toplevel).contents.text
	binary scan $dump(binary) "x32 A80 i1 s1 s1 s1 s1 s1 s1" dump(runtitle) time mo da ye ho mi se
	set dump(runstart) [clock format [clock scan "$mo/$da/$ye $ho:$mi:$se"]]
	$w insert end "Title: " "black" "$dump(runtitle)\n" "blue"
	$w insert end "Resumed on : " "black" "$dump(runstart)\n" "blue"
	$w insert end "after " "black" "[expr $time*1.0/10]" "blue" " seconds\n" "black"
}

proc DecodeUnknown {} {
	global dump
	$w insert end "Unkown buffer type!\n" "black"
}

proc HexWord {data} {
	if {$data < 0} {
		set str [format "%04x " [expr $data+65536]]
	} else {
		set str [format "%04x " $data]
	}
	return $str
}

proc LongWord {element index} {
	global dump
	set low [lindex $dump($element) $index]
	set high [lindex $dump($element) [expr $index+1]]
	if {$low < 0} {incr low 65536}
	if {$high < 0} {incr high 65536}
	set long [expr $low + 65536*$high]
	return $long
}

SetupDump
