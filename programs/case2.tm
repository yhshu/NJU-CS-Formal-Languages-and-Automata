; This program checks if the input string is in the form of 1^{m}x1^{n}=1^{mn}, m, n is positive integers
; Input: a string of 1's, x, and =, e.g., '11x111=111111'

; the finite set of states
#Q = {s0,mv,product,cmp,accept,accept2,accept3,accept4,halt_accept,reject,reject2,reject3,reject4,reject5,halt_reject}

; the finite set of input symbols
#S = {1,x,=}

; the complete set of tape symbols
#G = {1,x,=,t,r,u,e,f,a,l,s}

; the start state
#q0 = s0

; the blank symbol
#B = _

; the set of final states
#F = {halt_accept}

; the number of tapes
#N = 3

; the transition functions

; State s0: start state
s0 x__ x__ *** reject ; the string starts with x
s0 =__ =__ *** reject ; the string starts with =
s0 1__ 1__ *** mv

; State mv
mv 1__ _1_ rr* mv      ; continue moving
mv x__ ___ r** product ; start product
mv =__ =__ *** clean2_rej

; State product:
product x__ ___ rl* product


; State clean2_rej
clean2_rej =1_ =__ *l* clean2_reject
clean2_rej =__ =__ *** reject

; State accept*: write 'true' on 1st tape

; State reject*: write 'false' on 1st tape
reject =__ ___ r** reject  ; clean the 1st tape
reject 1__ ___ r** reject