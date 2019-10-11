bool isLoggedIn(){
	string username, password, un, pw;

	cout << "Entre com nome de usuario: "<<endl;
	cin >> username;

	cout << "Entre com a senha: "<<endl;
	cin >> password;

	ofstream read;
		read.open("data\\" + username + ".txt");
		getline(read, username);
		getline(read, password);

	read.close();
}
