#Q = {q_1,q_2,q_acc,q_rej,q_3}

#S = {0,1}

#G = {0,1,B}

#q0 = q_1

#B = B

#F = {q_acc}

#N = 1

q_1 B B l q_2
q_1 0 0 r q_1
q_1 1 1 r q_1
q_2 B B r q_rej
q_2 0 B l q_acc
q_2 1 B l q_3
q_3 B 1 l q_acc
q_3 0 1 l q_acc
q_3 1 0 l q_3