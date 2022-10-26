/*******************************************Catatan**********************************************
-> Port arduino yang bisa di laptop Axioo hanya port COM12, COM6 
    Gerakan             ||    LeftHatX    ||    LeftHatY    ||    RightHatX    ||   RightHatY
->  Maju                ||      128       ||        0       ||        -        ||       -
->  Mundur              ||      128       ||       255      ||        -        ||       -
->  Kanan               ||      255       ||       128      ||        -        ||       -
->  Kiri                ||       0        ||       128      ||        -        ||       -
->  Serong Kanan Maju   ||       -        ||        -       ||      >128       ||     <128
->  Serong Kiri Maju    ||       -        ||        -       ||      <128       ||     <128
->  Serong Kanan Mundur ||       -        ||        -       ||      >128       ||     >128
->  Serong Kiri Mundur  ||       -        ||        -       ||      <128       ||     >128
Versi2
    Gerakan   ||    LeftHatX    ||    LeftHatY    ||    RightHatX    ||   RightHatY
->  Maju      ||   65-128-191   ||        0       ||        -        ||       -
->  Mundur    ||   65-128-191   ||       255      ||        -        ||       -
->  Kanan     ||      255       ||   65-128-191   ||        -        ||       -
->  Kiri      ||       0        ||   65-128-191   ||        -        ||       -
-> Untuk membuat tombol joystick yang digital terus memberikan nilai ketika ditekan, gunakan sintax getButtonPress()
   0, up 1 down -1            --0
   0, right 1 left -1         --1
   0, triangle 1 cross -1     --2
   0, circle 1 square -1      --3
   0, R1 1 L1 -1              --4
   0, option 1 share -1       --5
   0, touchpad 1 ps -1        --6
   0, R2                      --7
   0, L2                      --8
   0, leftHatX                --9
   0, leftHatY                --10
   0, RightHatX               --11
   0  RightHatY}              --12
Credit by : Robby Ikhfa
*************************************************************************************************/
