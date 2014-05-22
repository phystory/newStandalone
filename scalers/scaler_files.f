      program scalerfiles

       implicit none
       
       logical ok

       character*80 infilename,outfilename,chaux

       integer i,lun1,lun2,ios,aux,tot
        
       real*4 ch,rate,dev,sumrate,bck,sumtot


       write(6,*) 'Input filename?'
       read(5,*) infilename
       write(6,*) 'Output filename?'
       read(5,*) outfilename


       lun1 = 11
       open(lun1,file=infilename,iostat=ios,status='unknown')
       if (ios.ne.0) then
          write(6,*) '*********Error in opening file',infilename
          stop
       end if

       lun2 = 12
       open(lun2,file=outfilename,iostat=ios,status='unknown')
       if (ios.ne.0) then
          write(6,*) '*********Error in opening file',outfilename
          stop
       end if


       do i = 1,7
          read(lun1,*) chaux
       end do

       sumrate = 0.
       sumtot = 0.
       ch = 0.
       ok = .true.
       i = 1
       do while(ok)

          read(lun1,*,end=111) chaux,tot,rate,dev
          sumrate = sumrate + rate
          sumtot = sumtot + tot
          if (rate.gt.0) ch = ch + 1.
            
          write(lun2,1001) i,rate
 1001     format(1x,i2,2x,f6.3)

       end do
 111   close(lun1)
       close(lun2)

       bck = sumrate 
       write(6,*) 'Total background rate:',bck
       write(6,*) 'Total number of events:',sumtot

      stop
      end
