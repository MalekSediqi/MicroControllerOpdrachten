;
; Opdracht1-A.asm
;
; Created: 8-4-2016 13:10:43
; Author : malek
;

;
.INCLUDE "m128def.inc"
;
.CSEG
.ORG 	$0000
		rjmp main
;
.CSEG
.ORG	$0200
;
; Replace with your application code
start:
	ldi r17,$55;
	
	st $0540,r17;
	st $0541,r17;
	st $0542,r17;
	st $0543,r17;
	st $0544,r17;
	st $0545,r17;
	st $0546,r17;
	st $0547,r17;
	st $0548,r17;
	no_end:   			; unlimited loop, when done
		rjmp no_end	
	