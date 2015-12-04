
.section .init @defined in linker-file
.global _start 

_start:
	bl main @first part of main

hang: b hang

.globl PUT32
PUT32:
    str r1,[r0]
    bx lr

.globl GET32
GET32:
    ldr r0,[r0]
    bx lr

.globl dummy
dummy:
    bx lr

.globl GETPC
GETPC:
    mov r0,lr
    bx lr

.globl BRANCHTO
BRANCHTO:
    bx r0
		
.section .text @will hold code
		
@main_asm:

	;@mov sp, #0x8000 

    ;@ (PSR_IRQ_MODE|PSR_FIQ_DIS|PSR_IRQ_DIS)
    @mov r0,#0xD2
    @msr cpsr_c,r0
    @mov sp,#0x8000

    ;@ (PSR_FIQ_MODE|PSR_FIQ_DIS|PSR_IRQ_DIS)
    @mov r0,#0xD1
    @msr cpsr_c,r0
    @mov sp,#0x4000

    ;@ (PSR_SVC_MODE|PSR_FIQ_DIS|PSR_IRQ_DIS)
    @mov r0,#0xD3
    @msr cpsr_c,r0
    @mov sp,#0x8000000

    ;@ SVC MODE, IRQ ENABLED, FIQ DIS
    ;@mov r0,#0x53
    ;@msr cpsr_c, r0

	@bl main	
@TODO difference between bl and b?
tloop$:
	b tloop$
	
