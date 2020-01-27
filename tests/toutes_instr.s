.name "ld"
.comment "I dont like underscore"

ld -1, r16
ld %12000, r0
ld %4235262, r2
ld %4235762, r3
ld %4245262, r4
ld %4275262, r5
ld %45262, r6
ld %4262, r7
ld %4285262, r8
ld %42885262, r9
ld %488882, r10
ld %435262, r11
ld %4262, r12
ld %42353662, r13
ld %987632, r14
ld %42111062, r15
add r3, r4, r5
st r5, 1000
sub r6, r7, r8
st r8, 1000
or %1111111, %2222222, r3
st r3, 1000
xor %35535335, %56436362, r4
st r4, 1000
and %9898989, 81073077, r5
st r5, 1000

sti r1,%:live,%1
live: live %0

lfork %1000
lld %4626246, r8
st r8, 1000
lldi 2000, %-40, r3
st r3, 1000 

ld %65, r2
ld %66, r3
ld %67, r4
ld %68, r5
ld %69, r6
st r2, 1000
st r3, 1000
st r4, 1000
st r5, 1000
st r6, 1000

aff r2
aff r3
aff r4
aff r5
aff r6






