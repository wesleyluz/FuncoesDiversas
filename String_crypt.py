from cryptography.fernet import Fernet

#Encrypt string


#Get the key from the file
file = open('key.key', 'rb')
key = file.read()
file.close()

#Encode the message

message = 'my deep dark secret'
encoded = message.encode()

#Encrypt the message
f = Fernet(key)

encrypted = f.encrypt(encoded)
print(encrypted)

file = open('key.key', 'rb')
key2 = file.read()
file.close()

f2 = Fernet(key2)
decrypted = f2.decrypt(encrypted)

original_msg = decrypted.decode()

print(original_msg)