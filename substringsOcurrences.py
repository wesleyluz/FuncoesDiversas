frase = str(input("Digite a frase a se analisada: "))
palavra = str(input("Ocorrências da palavra/letra: "))

resultado = frase.count(palavra)

print(f"Na frase |{frase}|, a palavra/letra |{palavra}| apareceu {resultado} vezes")