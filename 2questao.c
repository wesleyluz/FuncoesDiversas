function pares (x, y) {
	var i = y - x;
	while(i>0){
		if(i%2==0){
			console.log(i+" ");
		}
		i -= 1;
	}
}
pares(2, 52);