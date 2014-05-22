      program poisson

       implicit none

       integer i,n

       real*8 t,fact,rate,coef
       real*8 sum,poiss
       

       write(6,*) 'Time width (nsec)'
       read(5,*) t

       write(6,*) 'Activity (Bq)'
       read(5,*) rate

       coef = rate * t * 1.E-9


       sum = 0.
       do n = 0,50

C---------Calculate exponential
          fact = 1
          do i=1,n
             fact = fact*i
          end do

          poiss = ( (coef**n) / fact )*exp(-coef)
          sum = sum + poiss

          

          write(6,*) 'Probability %:',n,100.*poiss,100.*sum


       end do

      stop
      end
