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
    ;inser??o do primeiro numero
    lea dx,msg1
    call string
    
    call ler
    mov bl,al
    
    
    ;leitura
    call ler
    mov cl,al
    
    mov ah,bl
    mov al,cl
    
    
    ;inser??o do segundo numero
    lea dx,msg2
    call string
    
    call ler
    mov dl,al
    
    call ler
    mov dh,al
    
    ;adi??o
    mov al,cl
    mov ah,bl
    add al,dh
    
    ;convers?o
    aaa
    add ax,3030h
    ;adi??o
    add ah,dl
    
    ;salvando unidade
    mov num1,al
    
    ;organizando
    mov al,ah
    mov ah,0; limpando ah
    
    ;convers?o
    aaa
    add ax,3030h
    
    ;salvando dezena
    mov num2,al
    
    ;salvando centena
    mov num3,ah
    
    ;resultado
    lea dx,msg3
    call string
    
    mov dl,num3
    call mostrar
    mov dl,num2
    call mostrar
    mov dl,num1
    call mostrar
    
    MOV AH, 4Ch
    INT 21h
inicio endp    
codigo ends
   end entrada