Codigo segment
  assume cs:codigo, ds:codigo, es:codigo, ss:codigo
  org 100h
  entrada:jmp inicio
  ;mensagens
  msg1 db 13,10,"digite o primeiro valor",0ah,0dh,"$"
  msg2 db 13,10,"digite o segundo valor",0ah,0dh,"$"
  msg3 db 13,10,"resultado",0ah,0dh,"$"
  msg4 db 13,10,"1-para multiplicar",0ah,0dh,"$"
  msg5 db 13,10,"2-para dividir",0ah,0dh,"$"
  msg6 db 13,10,"ERRO:divisao por zero",0ah,0dh,"$"
  msg7 db 13,10,"3-Sair",0ah,0dh,"$"
  msg8 db 13,10,"resto",0ah,0dh,"$"
  ;buffers de teclado
  var1 db 4, ? , 4 dup(?)
  var2 db 4, ? , 4 dup(?)
  ;vai imprimir o resultado
  num1 db ?
  num2 db ?
  num3 db ?
  ;vai guardar os sinais
  sinal1 db ?
  sinal2 db ?
  ;function de mostrar um caractere
  mostrarChar proc near
    mov ah,02
    int 21h
    ret
  mostrarChar endp
  ;function de ler caractere
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
    inicial:
    ;escolha mult ou div
    mov dx,offset msg4
    call mostraString
    
    mov dx,offset msg5
    call mostraString
    
    mov dx,offset msg7
    call mostraString
    
    call ler
    
    cmp al,'1'
    je mult
    cmp al,'2'
    je divisao
    cmp al,'3'
    je sair
    
    ;programa da multiplicacao
    mult:
    ;exibe msg3
    mov dx,offset msg1
    call mostraString
    ;ler primeiro sinal
    call ler
    mov sinal1,al
    ;ler primeiro numero
    call ler
    mov bl,al
    sub bl,30h
    ;exibe msg2
    mov dx,offset msg2
    call mostraString
    ;ler segundo sinal
    call ler
    mov sinal2,al
    ;ler segundo numero
    call ler
    sub al,30h
    mov bh,al
    ;exibe msg3
    mov dx,offset msg3
    call mostraString
 
    ;calculo da multiplicacao
    mov al,bh;move para al          
    ;al = multiplicando
    ;bl = multiplicador
    ;al x bl = produto
    mul bl
    mov ah,0
    aam ;conversao
    add ax,3030h
    
    mov num1,ah;salva a dezena
    
    mov num2,al;salva a unidade
    
    ;jogo de sinais
    cmp sinal1,'+'
    je teste1
    cmp sinal1,'-'
    je teste2
    cmp sinal1,'0'
    je imprimir1
    
    teste1:
    cmp sinal2,'+'
    je imprimir1
    cmp sinal2,'-'
    je imprimir2
    
    teste2:
    cmp sinal2,'-'
    je imprimir1
    cmp sinal2,'+'
    je imprimir2
    
    ;impressoes
    imprimir1:
    mov dl,num1
    call mostrarChar
    
    mov dl,num2
    call mostrarChar
              
    jmp inicial
    
    imprimir2:
    ;funcao que mostra o sinal negativo
    mov ah,06
    mov dl,2dh 
    int 21h
    
    mov dl,num1
    call mostrarChar
    
    mov dl,num2
    call mostrarChar
              
    jmp inicial
    
    ;calculo da divisao
    divisao:
    ;exibe msg1
    mov dx,offset msg1
    call mostraString
    ;ler primeiro numero
    call ler
    sub al,30h
    mov ch,al
    ;ler segundo numero
    call ler
    sub al,30h
    mov cl,al
    ;exibe msg2
    mov dx,offset msg2
    call mostraString
    ;ler segundo numero
    call ler
    ;se dividir por zero alerta
    cmp al,'0'
    je erro
    sub al,30h
    mov bl,al
    ;exibe o msg3
    mov dx,offset msg3
    call mostraString
    
    ;calculo da divisao
    ;ax = dividendo
    ;bl = divisor
    mov dx,0h
    mov ax,cx
    aad
    div bl
    
    ;apos o div
    ;al = quociente
    ;ah = resto 
    ;guardar o resto
    add ah,30h;corrige para decimal o resto
    mov num3,ah;guarda o resto em num3
        
    mov ah,0;limpa o ah
    aam;corrige para que haja a soma certa
    add ax,3030h
    
    mov num1,ah;salva a dezena
    
    mov num2,al;salva a unidade
    ;imprime o resultado
    mov dl,num1
    call mostrarChar
    
    mov dl,num2
    call mostrarChar
    ;imprime o resto
    mov dx,offset msg8
    call mostraString
    mov dl,num3
    call mostrarChar          
    jmp inicial
    
    erro:
         
    mov dx,offset msg6
    call mostraString
    
    jmp divisao    
    sair:
    ;encerra o programa
    MOV AH, 4Ch
    INT 21h
inicio endp    
codigo ends
   end entrada

