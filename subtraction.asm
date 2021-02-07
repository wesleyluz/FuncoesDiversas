  Codigo segment
  assume cs:codigo, ds:codigo, es:codigo, ss:codigo
  org 100h
  entrada:jmp inicio

  msg1 db 13,10,"digite um numero de dois digitos o primeiro valor",0ah,0dh,"$"
  msg2 db 13,10,"digite um numero de dois digitos o segundo valor",0ah,0dh,"$"
  msg3 db 13,10,"resultado",0ah,0dh,"$"
  msg4 db 13,10,"teste1",0ah,0dh,"$"
  msg5 db 13,10,"teste2",0ah,0dh,"$"
  msg6 db 13,10,"teste3",0ah,0dh,"$"

  var1 db 4, ? , 4 dup(?)
  var2 db 4, ? , 4 dup(?)
  
  num1 db ?
  num2 db ?
  num3 db ? 10

  quebra db 13,10," ",0ah,0dh,"$"
  
  mostrarChar proc near
    mov ah,02
    int 21h
    ret
  mostrarChar endp

  ler proc near
     mov ah,01
     int 21h
     ret
  ler endp  
  
  mostraString proc near
    mov ah,09
    int 21h
    ret
  mostraString endp

  preencheVet proc near
    mov ah,0Ah
    int 21h
    ret
  preencheVet endp

inicio proc near    
    
    ;pega o primeiro valor
    mov dx, offset msg1
    call mostraString

    mov dx, offset var1
    call preencheVet

    ;pega o segundo valor
    mov dx, offset msg2
    call mostraString

    mov dx, offset var2
    call preencheVet

    ;pega o terceiro valor
    mov dx, offset msg3
    call mostraString


    ;subtraction
    
    mov bh,var1+2
    mov bl,var1+3
    
    mov ch,var2+2
    mov cl,var2+3
                 
    ;teste
    cmp bx,cx
    jg sub1
    cmp bx,cx
    jl sub2
    
    sub1:
    sub bx, cx
    mov num1,bh
    
    mov ah,0
    mov al,bl
    aas
    mov num2,al
    
    add num1,30h
    add num2,30h
    mov dl,num1
    call mostrarChar
    mov dl,num2
    call mostrarChar
    ret
    
    sub2:
    sub cx, bx
    mov num1,ch
    
    mov ah,0
    mov al,cl
    aas
    mov num2,al
    
    add num1,30h
    add num2,30h
    
    mov ah,06
    mov dl,2dh ;displays the negative sign
    int 21h
    
    mov dl,num1
    call mostrarChar
    mov dl,num2
    call mostrarChar
    ret
    
    
    
    
    
    ;encerra o programa
    MOV AH, 4Ch
    INT 21h
inicio endp    
codigo ends
   end entrada