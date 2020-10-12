-- [[ Lista de Exercícios Estruturas de Repetição UFMG ]]
--[[questão 1
for i = 0,50 do
	print(i)
end
]]

--[[ questão 2
for i = 1,100 do
	print(i)
end
]]

--[[ questão 3
i = 1
j = 101
while i >= 0 do
  j = j - 1
  print(j)
  if j == 1 then
  break
end
end
]]

--[[ questão 4
for i = 100,200, 1 do
print(i)
end
]]

--[[ questão 5
i = 201

while i >= 0 do
	i = i - 1
	print (i)
	if i == 100 then
	break
	end
end
]]
--[[ questão 6
j=0
for i = 5,500 do
	if i % 5 == 0 then
	print(i)
	end
end
]]

--[[ questão 7
for i = 1,100 do
	if i %2 == 0 then
	print (i)
	end
end
]]

--[[ questão 8
for i = 1,100 do
	if i %2 ~=0 then
	print(i)
	end
end
]]

--[[ questão 9
for i = 1,20 do
  n = i*i
	print(i.. '*'.. i.. '='.. n)
end
]]
--[[ questão 11
for i=  1,10 do
	print('informe um número')
	n = io.read ('*n')
	print('a metade de ' .. n  .. ' é ' .. n/2)
end
]]

--[[ questão 12
for i = 1,10 do
	print('informe um número')
	n = io.read('*n')
	print('O quadrado de ' .. n .. ' é ' .. n*n)

end
]]

--[[ questão 13
for i = 1,10 do
	print('informe um número')
	n = io.read ('*n')
	print('o cubo de ' .. n .. ' é '.. n^3)
end
]]

--[[ questão 14
for i = 1,15 do
	print('informe um número')
	n = io.read('*n')
	print('A raíz quadrada de ' .. n .. ' é '.. math.sqrt(n))
end
]]

 j = 0
for i = 1,100 do
	print(i)
	j = j+i
end
	print('a soma dos numeros de 1 a 100 é ' .. j)



















































