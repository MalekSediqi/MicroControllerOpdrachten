;
; Opdracht1-A.asm
;
; Created: 8-4-2016 13:10:43
; Author : malek
;

;
;.INCLUDE "m128def.inc"
;
.CSEG
.ORG 	$0000
		rjmp main
;
.CSEG
.ORG	$0200
;
; Replace with your application code
main: 
start:
	ldi r17,$55;
	ldi XL,$40
	ldi XH,$05
	ldi r16,$8;
Loop:
	dec r16;
	st X+,r17;
	cpi r16,0
	brne Loop
	no_end:   			; unlimited loop, when done
		rjmp no_end	
	