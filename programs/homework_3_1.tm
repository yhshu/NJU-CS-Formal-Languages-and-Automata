#Q = {q_1,q_2,q_3,q_4,q_5,q_acc,q_rej}

#S = {0}

#G = {0,1,B}

#q0 = q_1

#B = B

#F = {q_acc}

#N = 1

q_1 B B r q_rej
q_1 0 B r q_2
q_1 1 1 r q_rej
q_2 B B r q_acc
q_2 0 1 r q_3
q_2 1 1 r q_2
q_3 B B l q_5
q_3 0 0 r q_4
q_3 1 1 r q_3
q_4 B B r q_rej
q_4 0 1 r q_3
q_4 1 1 r q_4
q_5 B B r q_2
q_5 0 0 l q_5
q_5 1 1 l q_5