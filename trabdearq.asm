Codigo segment
  assume cs:codigo, ds:codigo, es:codigo, ss:codigo
  org 100h
  entrada:jmp inicio
  ;mensagens
  msg1 db 13,10,"digite um numero de dois digitos o primeiro valor",0ah,0dh,"$"
  msg2 db 13,10,"digite um numero de dois digitos o segundo valor",0ah,0dh,"$"
  msg3 db 13,10,"resultado",0ah,0dh,"$"
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
    ;programa de inicio
    menu:
    ;mostra msg1
    mov dx, offset msg1
    call mostraString
    
    ;pega primeiro sinal
    call ler
    mov sinal1,al;pega o sinal em al e move para sinal1
    ;pega valores e coloca no buffer
    mov dx, offset var1
    call preencheVet;preenche o buffer1
    
    ;pra poder sair do programa
    cmp sinal1,'s'
    je sair 
    
    ;mostra msg2
    mov dx, offset msg2
    call mostraString
    
    ;pega segundo sinal
    call ler
    mov sinal2,al;pega o sinal em al e move para sinal2
    ;pega valores e coloca no buffer
    mov dx, offset var2
    call preencheVet
    
    ;jogos de sinais
    ;primeiro sinal
    teste1:
    mov al,sinal1
    
    cmp al,'+';se positivo verifica proximo sinal
    je testepos
    cmp al,'-';se negativo verifica proximo sinal
    je testeneg
    
    ;segundo sinal
    testepos:
    mov al,sinal2
    cmp al,'+';se os dois sao positivos soma
    je soma
    cmp al,'-';se sinais diferentes subtrai
    je subt
    
    testeneg:
    mov al,sinal2
    
    cmp al,'-';se os dois negativos soma
    je somaneg
    cmp al,'+';se positivo subtrai
    je subt2
     
    ;programa de soma
    soma:
    
    ;mostra msg "resultado"
    mov dx, offset msg3
    call mostraString

    ;somando
    mov al,var1+3
    mov ah,var1+2
    add al,var2+3
    ;apos a soma de unidade
    aaa ; conversao
    add ax,3030h ;adiciona 3030
    mov num1,al  ;salvo a unidade em num1
    add ah,var2+2

    mov al,ah; movo o valor de ah para al
    mov ah,0; limpo o ah

    aaa; conversao
    add ax,3030h; adiciona 3030

    mov num2,al;salvo a dezena em num2
    mov num3,ah;salvo a dezena em num3
    ;imprimir resultado
    mov dl,num3;centena
    call mostrarChar

    mov dl,num2;dezena
    call mostrarChar

    mov dl,num1;unidade
    call mostrarChar
    
    jmp menu
    
    somaneg:
    ;mostra msg "resultado"
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
    
    ;funcao que mostra o sinal negativo
    mov ah,06
    mov dl,2dh 
    int 21h
    
    mov dl,num3
    call mostrarChar

    mov dl,num2
    call mostrarChar

    mov dl,num1
    call mostrarChar
    
    jmp menu
    
    ;programa de subtracao
    subt:               
    ;imprime msg resultado
    mov dx, offset msg3
    call mostraString


    ;subtraction
    ;move os valores para bx
    mov bh,var1+2
    mov bl,var1+3
    ;move os valores para cx
    mov ch,var2+2
    mov cl,var2+3
                 
    ;teste                                      
    cmp bx,cx
    jg sub1  ;jump greater bx>cx of,sf,zf
    cmp bx,cx
    jl sub2  ;jump less bx<cx of,sf
    
    ;sub positiva
    sub1:
    sub bx, cx;
    mov num1,bh;salva a  dezena em num1
    
    mov ah,0;limpo o ah
    mov al,bl;movo para al, bl
    aas;conversao
    mov num2,al;
    
    add num1,30h
    add num2,30h
    ;imprime
    mov dl,num1 ;dezena
    call mostrarChar
    mov dl,num2 ;unidade
    call mostrarChar
    
    jmp menu
    
    ;sub negativa
    sub2:
    sub cx, bx
    mov num1,ch
    
    mov ah,0
    mov al,cl
    aas
    mov num2,al;salva o valor
    
    add num1,30h
    add num2,30h
    
    ;funcao que mostra o sinal negativo
    mov ah,06
    mov dl,2dh 
    int 21h
    
    mov dl,num1
    call mostrarChar
    mov dl,num2
    call mostrarChar
     
    ;volta pro inicio
    jmp menu
    
    subt2:               
    ;imprime msg resultado
    mov dx, offset msg3
    call mostraString


    ;subtraction
    
    mov bh,var1+2
    mov bl,var1+3
    
    mov ch,var2+2
    mov cl,var2+3
                 
    ;teste                                      
    cmp bx,cx
    jg sub11  ;jump greater bx>cx of,sf,zf
    cmp bx,cx
    jl sub22  ;jump less bx<cx of,sf
    
    ;sub positiva
    sub11:
    sub bx, cx
    mov num1,bh
    
    mov ah,0
    mov al,bl
    aas
    mov num2,al
    
    ;funcao que mostra o sinal negativo
    mov ah,06
    mov dl,2dh 
    int 21h
    
    add num1,30h
    add num2,30h
    mov dl,num1
    call mostrarChar
    mov dl,num2
    call mostrarChar
    
    jmp menu
    
    ;sub negativa
    sub22:
    sub cx, bx
    mov num1,ch
    
    mov ah,0
    mov al,cl
    aas
    mov num2,al
    
    add num1,30h
    add num2,30h
    
    mov dl,num1
    call mostrarChar
    mov dl,num2
    call mostrarChar
    
    jmp menu
    
    sair:
    ;encerra o programa
    MOV AH, 4Ch
    INT 21h
inicio endp    
codigo ends
   end entrada

