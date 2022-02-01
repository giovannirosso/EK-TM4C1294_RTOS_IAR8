          PUBLIC func_asm

          SECTION .text:CODE(2)
          THUMB
          
          ; int func_asm(int, int);
          ; input#1 in R0, input#2 in R1, output in R0
func_asm:
          add r0, r1
          bx lr

          END

