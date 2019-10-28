Codigo segment
    assume cs:codigo, ds:codigo, es:codigo, ss:codigo
  org 100h
  entrada:jmp inicio
  msg1 db 13,10,"digite o primeiro numero",0ah,0dh,"$"
  msg2 db 13,10,"digite o segundo numero",0ah,0dh,"$"
  msg3 db 13,10,"resultado",0ah,0dh,"$"
  
  num1 db ?
  num2 db ?
  num3 db ?
  
  mostrar proc near
    mov ah,02
    int 21h
    ret
  mostrar endp

  ler proc near
     mov ah,01
     int 21h
     ret
  ler endp  
  
  string proc near
    mov ah,09
    int 21h
    ret
  string endp

inicio proc near
    
    call ler
    mov bl,al
    sub bl,30h
    
    call ler
    sub al,30h
    
    mul bl
    
    aam
    add ax,3030h
    
    mov num1,ah
    
    mov num2,al
    
    mov dl,num1
    call mostrar
    
    mov dl,num2
    call mostrar
    
    MOV AH, 4Ch
    INT 21h
inicio endp    
codigo ends
   end entrada