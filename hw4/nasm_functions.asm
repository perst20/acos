extern strcmp

WisdomPunctuationDivide:
        mov     r8, QWORD [rdi+8]
        xor     rax, rax
        xor     rdx, rdx
for_i:
        mov     r9b, BYTE [r8]
        test    r9b, r9b
        je      for_i_end
        mov     rcx, punct
for_j:
        mov     r10b, BYTE [rcx]
        test    r10b, r10b
        je      for_j_end
        cmp     r10b, r9b
        jne     if_not
        inc     rdx
        jmp     for_j_end
if_not:
        inc     rcx
        jmp     for_j
for_j_end:
        inc     rax
        jmp     for_i
for_i_end:
        cvtsi2sd        xmm0, rdx
        cvtsi2sd        xmm1, rax
        divsd   xmm0, xmm1
        ret

ContainerSort:
        push    r14
        push    r13
        push    r12
        push    rbp
        push    rbx
        mov     rax, QWORD [rdi]
        lea     rbx, [rdi+8]
        lea     r12, [rbx+rax*8]
for_i2:
        cmp     rbx, r12
        je      for_i2_end
        add     rbx, 8
        mov     rbp, rbx
for_j2:
        cmp     rbp, r12
        je      for_i2
        mov     r14, QWORD [rbp]
        mov     r13, QWORD [rbx-8]
        mov     rsi, QWORD [r14+8]
        mov     rdi, QWORD [r13+8]
        call    strcmp
        test    eax, eax
        jle     nif
        mov     QWORD [rbx-8], r14
        mov     QWORD [rbp], r13
nif:
        add     rbp, 8
        jmp     for_j2
for_i2_end:
        pop     rbx
        pop     rbp
        pop     r12
        pop     r13
        pop     r14
        ret

section .data
        punct: db 33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,58,59,60,61,62,63,64,91,92,93,94,95,96,123,124,125,126,0