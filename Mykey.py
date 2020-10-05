import base64
import os

from cryptography.hazmat.backends import default_backend
from cryptography.hazmat.primitives import hashes
from cryptography.hazmat.primitives.kdf.pbkdf2 import PBKDF2HMAC

## GENERATE KEY FROM PASSWORD

password_provided = 'pumpkin' #This is input in the form of a string
password = password_provided.encode() #convert to type byte

salt = b'\xbcLs\x91(n\xad#\x9f\x1b6\xf9\xe2\xbf\xa9k'

kdf = PBKDF2HMAC(
		algorithm = hashes.SHA256,
		length = 32,
		salt = salt, iterations = 100000, 
		backend = default_backend()
		)

key = base64.urlsafe_b64encode(kdf.derive(password)) #can only use kdf once
print(key)