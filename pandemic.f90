program pandemic
	implicit none

	double precision :: P(4) = 0d0
	double precision :: dt   = 0.1
    double precision :: tf   = 100d0
    double precision :: t    = 0d0
	integer          :: Nt, n


	! Set the number of time steps
	Nt = floor(tf/dt) + 1


	! Set initial well population
	P(1) = 0.98d0


	! Set initial sick population
	P(2) = 1d0 - P(1)


	! Open printing files
	call openfiles()


	! Do the time loop
	do n=1, Nt
		call RK4(P,t,dt)
		call PrintP(P, t)
	end do


	call closefiles()


contains

	subroutine RK4(P,t,dt)
		double precision, intent(inout) :: P(4), t
		double precision, intent(in   ) :: dt
		double precision                :: K1(4), K2(4), K3(4), K4(4)

		K1 = dPdt(P         , t         )
		K2 = dPdt(P + K1/2d0, t + dt/2d0)
        K3 = dPdt(P + K2/2d0, t + dt/2d0)
        K4 = dPdt(P + K3    , t + dt    )

		t = t + dt
		P = P + (1/6d0) * (K1 + 2*(K1+K3) + K4)
	end subroutine


	function dPdt(P, t)
		double precision :: P(4), t
		double precision :: dPdt(4)
		double precision :: T1   = 3d0
		double precision :: T3   = 5d0
		double precision :: T4   = 4d0

		dPdt = 0d0

		dPdt(1) = - ((P(1)* P(2))/T1)
		dPdt(2) = + ((P(1)* P(2))/T1) - P(2)/T3 - P(2)/T4
		dPdt(3) = + P(2)/T3
		dPdt(3) = + P(2)/T4


	end function


	subroutine PrintP(P,t)
		double precision :: P(4), t

                write(101,*) t, P(1)
                write(102,*) t, P(2)
                write(103,*) t, P(3)
                write(104,*) t, P(4)
	end subroutine

	subroutine openfiles()
                open(file='P1.dat', unit=101)
                open(file='P2.dat', unit=102)
                open(file='P3.dat', unit=103)
                open(file='P4.dat', unit=104)
	end subroutine

	subroutine closefiles()
                close(101)
                close(102)
                close(103)
                close(104)
	end subroutine



end program
