                     Codigo segment
    assume cs:codigo, ds:codigo, es:codigo, ss:codigo
  org 100h
  entrada:jmp inicio

  msg1 db 13,10,"digite um numero de dois digitos o primeiro valor",0ah,0dh,"$"
  msg2 db 13,10,"digite um numero de dois digitos o segundo valor",0ah,0dh,"$"
  msg3 db 13,10,"resultado",0ah,0dh,"$"

  var1 db 4, ? , 4 dup(?)
  var2 db 4, ? , 4 dup(?)
  
  num1 db ?
  num2 db ?
  num3 db ?

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

    ;somando
    mov al,var1+3
    mov ah,var1+2
    add al,var2+3

    aaa
    add ax,3030h
    mov num1,al
    add ah,var2+2


    mov al,ah
    mov ah,0

    aaa
    add ax,3030h

    mov num2,al
    mov num3,ah

    mov dl,num3
    call mostrarChar

    mov dl,num2
    call mostrarChar

    mov dl,num1
    call mostrarChar

    ;encerra o programa
    MOV AH, 4Ch
    INT 21h
inicio endp    
codigo ends
   end entrada